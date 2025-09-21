#include "ConsoleMover.h"
#include "WrongSettingsException.h"

#include <iostream>
#include <fstream>
#include <set>

void ConsoleMover::loadCustomSettings(const std::string& settings_path) {
    std::ifstream input(settings_path);
    std::set<std::string> settings_names;
    settings_.clear();
    for (int i = 0; i < 4; i++) {
        std::string setting;
        std::string value;

        input >> setting;
        if (input.eof()) {
            input.close();
            throw WrongSettingsException("Not enough values");
        }
        input >> value;
        try {
            settings_.at(value);
            throw WrongSettingsException("This key is already taken");
        } catch (const std::out_of_range& exception) {
            if (settings_names.find(setting) != settings_names.end()) {
                throw WrongSettingsException("This setting name is already taken");
            }
            settings_[value] = CreateMoverResponseFromString(setting);
        }
    }
    input.close();
};

MoverResponse ConsoleMover::move() {
    std::string where;
    std::cin >> where;

    try {
        return settings_.at(where);
    } catch (const std::out_of_range& exception) {
        return MoverResponse::WRONG;
    }
}

ConsoleMover::ConsoleMover() {
    settings_["w"] = MoverResponse::UP;
    settings_["s"] = MoverResponse::DOWN;
    settings_["a"] = MoverResponse::LEFT;
    settings_["d"] = MoverResponse::RIGHT;
    settings_["console-logger"] = MoverResponse::CONSOLE_LOGGER;
    settings_["file-logger"] = MoverResponse::FILE_LOGGER;
    settings_["exit"] = MoverResponse::EXIT;
    settings_["save"] = MoverResponse::SAVE;
    settings_["load"] = MoverResponse::LOAD;
}
