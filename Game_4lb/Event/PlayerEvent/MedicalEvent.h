#pragma once

#include "EventPlayer.h"

class MedicalEvent: public EventPlayer {
public:
    ReturnEvent make(Player *player) override;

    MedicalEvent(int value);
};
