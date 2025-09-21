#pragma once

#include "../GameLogic/Field.h"
#include "WrongRuleException.h"
#include <cstdint>

template<uint16_t width, uint16_t height>
class FieldRule {
 public:
    void SetRule(Field& field) {
        if (static_cast<uint64_t>(width) * height * sizeof(Cell) > 1'000'000'000) {
            throw WrongRuleException("Too big field!");
        }
        field = Field(width, height);
    }
};