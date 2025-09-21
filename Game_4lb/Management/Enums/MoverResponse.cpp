#include "MoverResponse.h"
#include "../Mover/WrongSettingsException.h"

MoverResponse CreateMoverResponseFromString(const std::string& str) {
    if (str == "up") {
        return MoverResponse::UP;
    } else if (str == "down") {
        return MoverResponse::DOWN;
    } else if (str == "left") {
        return MoverResponse::LEFT;
    } else if (str == "right") {
        return MoverResponse::RIGHT;
    } else if (str == "exit") {
        return MoverResponse::EXIT;
    } else if (str == "console-logger") {
        return MoverResponse::CONSOLE_LOGGER;
    } else if (str == "file-logger") {
        return MoverResponse::FILE_LOGGER;
    } else {
        throw WrongSettingsException("Wrong setting argument: [" + str + "]");
    }
}