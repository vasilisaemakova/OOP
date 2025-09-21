#pragma once

#include "Mover.h"

#include <unordered_map>

class ConsoleMover : public Mover {
 private:
    // Standard Values
    std::unordered_map<std::string, MoverResponse> settings_;

 public:
    ConsoleMover();
    void loadCustomSettings(const std::string& settings_path) override;
    MoverResponse move() override;
};
