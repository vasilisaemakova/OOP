#pragma once

#include "EventField.h"

class WallLockEvent: public EventField{
    ReturnEvent make(Player *player) override;

    Event* GetCopy() override {
        Event* result = new WallLockEvent(*this);
        return result;
    };

    EventType GetType() override {
        return EventType::kWallLockEvent;
    }
};
