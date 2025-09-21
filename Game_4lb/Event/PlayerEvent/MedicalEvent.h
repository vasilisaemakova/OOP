#pragma once

#include "EventPlayer.h"

class MedicalEvent: public EventPlayer {
public:
    ReturnEvent make(Player *player) override;

    explicit MedicalEvent(int value);

    Event* GetCopy() override {
        Event* result = new MedicalEvent(*this);
        return result;
    };

    EventType GetType() override {
        return EventType::kMedicalEvent;
    }
};
