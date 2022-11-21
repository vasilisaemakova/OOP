#pragma once

#include "EventPlayer.h"
#include "../ReturnEvent.h"

class TrapEvent: public EventPlayer {
public:
    ReturnEvent make(Player *player) override;

    TrapEvent(int value);
};
