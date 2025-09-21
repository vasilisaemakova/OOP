#pragma once

#include "../Enums/MoverResponse.h"

#include <string>

class Mover {
 public:
    virtual void loadCustomSettings(const std::string& settings_path) = 0;
    virtual MoverResponse move() = 0;
    virtual ~Mover() = default;
};
