#pragma once

#include "../GameLogic/Field.h"
#include "../Event/FieldEvent/KeyEvent.h"
#include "WrongRuleException.h"
#include <cstdint>

template<uint16_t default_x, uint16_t default_y>
class KeyRule {
 public:
    void SetRule(Field& field) {
        if (default_x >= field.getWidth() || default_y >= field.getHeight()) {
            throw WrongRuleException("Default position is out of field!");
        }
        auto& default_cell = field.getCell(default_x, default_y);
        if (default_cell.isAvailable() && default_cell.getEvent() == nullptr) {
            default_cell.setEvent(new KeyEvent());
            return;
        }
        int x, y;
        do {
            x = rand() % field.getWidth();
            y = rand() % field.getHeight();
        } while (!field.getCell(x, y).isAvailable() || field.getCell(x, y).getEvent() != nullptr);
        field.getCell(x, y).setEvent(new KeyEvent());
    }
};
