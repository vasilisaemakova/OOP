#pragma once

#include "../Enums/ObserverLevel.h"

class Logger {
 public:
    virtual void log(ObserverLevel level, const std::string& update) = 0;
    virtual ~Logger() = default;
};
