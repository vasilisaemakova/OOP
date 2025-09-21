#pragma once

#include "EventPlayer.h"
#include "../ReturnEvent.h"

class TrapEvent: public EventPlayer {
public:
    ReturnEvent make(Player *player) override;

    explicit TrapEvent(int value);

    Event* GetCopy() override {
        Event* result = new TrapEvent(*this);
        return result;
    };

    EventType GetType() override {
        return EventType::kTrapEvent;
    }
};
