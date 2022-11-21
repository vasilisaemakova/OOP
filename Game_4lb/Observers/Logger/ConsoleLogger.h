#pragma once

#include "Logger.h"

class ConsoleLogger : public Logger {
    void log(ObserverLevel level, const std::string& update) override;
};
