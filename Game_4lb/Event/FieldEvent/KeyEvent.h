#pragma once

#include "EventField.h"


class KeyEvent: public EventField {
    ReturnEvent make(Player *player) override;
    Event* GetCopy() override {
        Event* result = new KeyEvent(*this);
        return result;
    };

    EventType GetType() override {
        return EventType::kKeyEvent;
    }
};
