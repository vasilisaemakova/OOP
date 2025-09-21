#pragma once

#include "../GameLogic/Field.h"
#include "../Event/PlayerEvent/MedicalEvent.h"
#include "WrongRuleException.h"

#include <random>

template<uint16_t number_of_medkits, uint16_t heal_size>
class MedkitRule {
 public:
    void SetRule(Field& field) {
        if (field.getWidth() * field.getHeight() / 4 < number_of_medkits) {
            throw WrongRuleException("Too much med kits!");
        }
        for (int i = 0; i < number_of_medkits; i++) {
            int x, y;
            do {
                x = rand() % field.getWidth();
                y = rand() % field.getHeight();
            } while (!field.getCell(x, y).isAvailable() || field.getCell(x, y).getEvent() != nullptr);
            field.getCell(x, y).setEvent(new MedicalEvent(heal_size));
        }
    }
};
