#pragma once

#include "../GameLogic/Field.h"
#include "WrongRuleException.h"
#include <cstdint>

template<uint16_t number_of_barriers>
class BarrierRule {
 public:
    void SetRule(Field& field) {
        if (field.getWidth() * field.getHeight() / 4 < number_of_barriers) {
            throw WrongRuleException("Too much barriers!");
        }
        for (int i = 0; i < number_of_barriers; i++) {
            int x, y;
            do {
                x = rand() % field.getWidth();
                y = rand() % field.getHeight();
            } while (field.getCell(x, y).getEvent() != nullptr || !field.getCell(x, y).isAvailable());
            field.getCell(x, y).setAvailable(false);
        }
    }
};
