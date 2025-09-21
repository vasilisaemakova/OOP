#pragma once

#include "../GameLogic/Field.h"
#include "../Event/PlayerEvent/TrapEvent.h"
#include "WrongRuleException.h"

template<uint16_t number_of_traps, uint16_t damage>
class TrapRule {
 public:
    void SetRule(Field& field) {
        if (field.getWidth() * field.getHeight() / 4 < number_of_traps) {
            throw WrongRuleException("Too much traps!");
        }
        for (int i = 0; i < number_of_traps; i++) {
            int x, y;
            do {
                x = rand() % field.getWidth();
                y = rand() % field.getHeight();
            } while (!field.getCell(x, y).isAvailable() || field.getCell(x, y).getEvent() != nullptr);
            field.getCell(x, y).setEvent(new TrapEvent(damage));
        }
    }
};
