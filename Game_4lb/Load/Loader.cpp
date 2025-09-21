#include "Loader.h"
#include "Exception/missing_file.h"
#include "Exception/missing_section.h"
#include "Exception/extra_values.h"
#include "Exception/wrong_type.h"
#include "Exception/missing_value.h"
#include "Exception/file_changed.h"
#include "../Event/FieldEvent/KeyEvent.h"
#include "../Event/FieldEvent/WallLockEvent.h"
#include "../Event/PlayerEvent/MedicalEvent.h"
#include "../Event/PlayerEvent/TrapEvent.h"

#include <fstream>
#include <sstream>
#include <unordered_map>

int GetInt(const std::string& key, const std::string& value) {
    if (value.empty() || !std::all_of(value.begin(), value.end(), isdigit)) {
        throw wrong_type(key, value);
    }
    return std::stoi(value);
};

bool GetBool(const std::string& key, const std::string& value) {
    if (value == "0") {
        return false;
    } else if (value == "1") {
        return true;
    }
    throw wrong_type(key, value);
};

struct Data {
    size_t x;
    size_t y;
    bool on_cell;
    bool available;
    EventType type;
};

Data GetData(const std::string& x,
             const std::string& y,
             const std::string& on_cell,
             const std::string& available,
             const std::string& type_number) {
    if (x.empty()) {
        throw missing_value("X coordinate");
    } else if (y.empty()) {
        throw missing_value("Y coordinate");
    } else if (on_cell.empty()) {
        throw missing_value("Y coordinate");
    } else if (available.empty()) {
        throw missing_value("Y coordinate");
    } else if (type_number.empty()) {
        throw missing_value("Y coordinate");
    }
    Data result;
    result.x = GetInt("X coordinate", x);
    result.y = GetInt("Y coordinate", y);
    result.on_cell = GetBool("OnCell", on_cell);
    result.available = GetBool("Available", available);
    int type = GetInt("EventType", type_number);
    if (type < 0 || type > 4) {
        throw wrong_type("EventType", type_number);
    }
    result.type = static_cast<EventType>(type);

    return result;
}

void Loader::ReadField(std::ifstream& fin) {
    std::string line;
    std::stringstream stream;
    std::string key, value;
    bool was_width, was_height;
    was_width = was_height = false;
    size_t width, height;
    for (int i = 0; i < 2; i++) {
        std::getline(fin, line);
        stream = std::stringstream(line);
        stream >> key >> value;
        if (key == "width") {
            width = GetInt(key, value);
            was_width = true;
        } else if (key == "height") {
            height = GetInt(key, value);
            was_height = true;
        } else {
            throw extra_values("Key [" + key + "] | Value [" + value + "]");
        }
    }
    if (!was_width) {
        throw missing_value("Width");
    }
    if (!was_height) {
        throw missing_value("Height");
    }
    mediator_->field_ = new Field(width, height);
    for (size_t i = 0; i < width * height; i++) {
        if (fin.eof()) {
            throw missing_value("Not enough values for field");
        }
        std::string x, y, on_cell, available, type_number, value;
//        int y, x;
//        bool on_cell, available;
//        int type_number, value;

        fin >> x >> y >> on_cell >> available >> type_number;
        Data data = GetData(x, y, on_cell, available, type_number);
        if (data.x > mediator_->field_->getWidth()) {
            throw std::out_of_range("[X coordinate] is out of range");
        }
        if (data.y > mediator_->field_->getHeight()) {
            throw std::out_of_range("[Y coordinate] is out of range");
        }
        Cell& cell = mediator_->field_->getCell(data.x, data.y);
        cell.setOnCell(data.on_cell);
        cell.setAvailable(data.available);
        switch (data.type) {
            case kKeyEvent:cell.setEvent(new KeyEvent());
                break;
            case kWallLockEvent:cell.setEvent(new WallLockEvent());
                break;
            case kMedicalEvent:fin >> value;
                cell.setEvent(new MedicalEvent(GetInt("Optional value", value)));
                break;
            case kTrapEvent:fin >> value;
                cell.setEvent(new TrapEvent(GetInt("Optional value", value)));
                break;
            case kEmptyEvent:break;
        }
        if (!stream.eof()) {
            std::string problem_string = stream.str();
            throw extra_values(std::string(problem_string.begin() + stream.tellg(), problem_string.end()));
        }
    }
}

void Loader::ReadPlayer(std::ifstream& fin) {
    std::string line;
    std::stringstream stream;
    std::string key, value;
    std::unordered_map<std::string, bool> was;
    was["name"] = was["health_level"] = was["damage"] =
    was["x"] = was["y"] = was["key"] = was["win"] = false;
    for (int i = 0; i < 7; i++) {
        std::getline(fin, line);
        stream = std::stringstream(line);
        key = value = "";
        stream >> key >> value;
        if (!stream.eof()) {
            std::string problem_string = stream.str();
            throw extra_values(std::string(problem_string.begin() + stream.tellg(), problem_string.end()));
        }
        if (key == "name") {
            mediator_->player_->setNick(value);
            was["name"] = true;
        } else if (key == "health_level") {
            mediator_->player_->setHealth(GetInt(key, value));
            was["health_level"] = true;
        } else if (key == "damage") {
            mediator_->player_->setPower(GetInt(key, value));
            was["damage"] = true;
        } else if (key == "x") {
            mediator_->player_->setPosX(GetInt(key, value));
            was["x"] = true;
        } else if (key == "y") {
            mediator_->player_->setPosY(GetInt(key, value));
            was["y"] = true;
        } else if (key == "key") {
            int key_value = GetInt(key, value);
            if (key_value < 0 || key_value > 1) {
                throw wrong_type(key, value);
            }
            mediator_->player_->setKey(bool(key_value));
            was["key"] = true;
        } else if (key == "win") {
            int win_value = GetInt(key, value);
            if (win_value < 0 || win_value > 1) {
                throw wrong_type(key, value);
            }
            mediator_->player_->setKey(bool(win_value));
            was["win"] = true;
        } else {
            throw extra_values("Key [" + key + "] | Value [" + value + "]"); // Key [abc] | Value [qwe]
        }
    }
    for (const auto& it : was) { // auto <=> std::pair<std::string, bool>
        if (!it.second) {
            throw missing_value(it.first);
        }
    }
}

void Loader::Load() {
    mediator_->player_ = new Player();
    std::ifstream fin(file_path_);
    if (!fin) {
        throw missing_file(file_path_);
    }
    std::string line;

    std::getline(fin, line);
    if (line != "Player" && line != "Field") {
        throw missing_section("Player|Field");
    }
    if (line == "Player") {
        ReadPlayer(fin);
        std::getline(fin, line);
        if (line != "Field") {
            throw missing_section("Field");
        }
        ReadField(fin);
    } else {
        ReadField(fin);
        std::getline(fin, line);
        if (line != "Player") {
            throw missing_section("Player");
        }
        ReadPlayer(fin);
    }
}

bool Loader::CompareField(Field& other) {
    if (other.getWidth() != mediator_->field_->getWidth()) {
        return false;
    }
    if (other.getHeight() != mediator_->field_->getHeight()) {
        return false;
    }
    for (int i = 0; i < other.getWidth(); i++) {
        for (int j = 0; j < other.getHeight(); j++) {
            auto other_cell = other.getCell(i, j);
            auto my_cell = mediator_->field_->getCell(i, j);
            if (other_cell.isOnCell() != my_cell.isOnCell()) {
                return false;
            }
            if (other_cell.isAvailable() != my_cell.isAvailable()) {
                return false;
            }
            if (other_cell.getEvent() != nullptr) {
                if (my_cell.getEvent() == nullptr) {
                    return false;
                }
                if (other_cell.getEvent()->GetType() != my_cell.getEvent()->GetType()) {
                    return false;
                }
            } else { // other_cell.getEvent() == nullptr
                if (my_cell.getEvent() != nullptr) {
                    return false;
                }
            }

        }
    }
    return true;
}

bool Loader::ComparePlayer(Player& other) {
    auto my_player = mediator_->player_;
    if (my_player->getPosX() != other.getPosX() || my_player->getPosY() != other.getPosY()) {
        return false;
    }
    if (my_player->getWin() != other.getWin() || my_player->getNick() != other.getNick()) {
        return false;
    }
    if (my_player->getPower() != other.getPower() || my_player->getHealth() != other.getHealth()) {
        return false;
    }
    return true;
}

void Loader::SetMediator(Mediator* other_mediator) {
    auto* tmp = new Mediator(*mediator_);
    Load();
    if (!CompareField(*tmp->field_) || !ComparePlayer(*tmp->player_)) {
        throw file_changed();
    }
    *other_mediator->player_ = *mediator_->player_;
    *other_mediator->field_ = *mediator_->field_;
    other_mediator->controller_ =
        new Controller(other_mediator->field_, other_mediator->player_, other_mediator->observable_);
}