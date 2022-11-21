#include "ConsoleMover.h"
#include "WrongSettingsException.h"

#include <iostream>
#include <fstream>

void ConsoleMover::loadCustomSettings(const std::string& settings_path) {
    std::ifstream input(settings_path);
    up_ = down_ = left_ = right_ = "";
    for (int i = 0; i < 4; i++) {
        std::string setting;
        std::string value;

        input >> setting;
        if (input.eof()) {
            input.close();
            throw WrongSettingsException("Not enough values");
        }
        input >> value;
        if (setting == "up") {
            up_ = value;
        } else if (setting == "down") {
            down_ = value;
        } else if (setting == "left") {
            left_ = value;
        } else if (setting == "right") {
            right_ = value;
        } else {
            input.close();
            throw WrongSettingsException("Wrong setting argument: [" + setting + "]");
        }
    }
    input.close();
    if (up_.empty() || down_.empty() || left_.empty() || right_.empty()) {
        throw WrongSettingsException("There's missing of an argument");
    }
};

Direction ConsoleMover::move() {
    std::string where;
    std::cin >> where;

    if (where == up_) {
        return Direction::UP;
    } else if (where == down_) {
        return Direction::DOWN;
    } else if (where == left_) {
        return Direction::LEFT;
    } else if (where == right_) {
        return Direction::RIGHT;
    } else if (where == exit_) {
        return Direction::EXIT;
    } else {
        return Direction::WRONG;
    }
}
