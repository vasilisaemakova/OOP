#pragma once

#include <string>

enum MoverResponse {
    UP, DOWN, LEFT, RIGHT, WRONG, CONSOLE_LOGGER, FILE_LOGGER, EXIT, SAVE, LOAD
};

MoverResponse CreateMoverResponseFromString(const std::string& str);