#pragma once

#include "Mover.h"

class ConsoleMover : public Mover {
 private:
    // Standard Values
    std::string up_ = "w";
    std::string down_ = "s";
    std::string left_ = "a";
    std::string right_ = "d";
    std::string exit_ = "exit";
 public:
    void loadCustomSettings(const std::string& settings_path) override;
    Direction move() override;

};
