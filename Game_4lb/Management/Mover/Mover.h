#pragma once

#include "../Enums/Direction.h"

#include <string>

class Mover {
 public:
    virtual void loadCustomSettings(const std::string& settings_path) = 0;
    virtual Direction move() = 0;
};
