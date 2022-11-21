#pragma once

#include "../Enums/ObserverLevel.h"
#include "../Logger/Logger.h"

class Observer {
 public:
    virtual void addLogger(Logger* logger) = 0;
    virtual void addLevel(ObserverLevel level) = 0;

    virtual void update(ObserverLevel level, const std::string& update) = 0;
};