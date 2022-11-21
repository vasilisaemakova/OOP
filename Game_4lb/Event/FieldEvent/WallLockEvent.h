#pragma once

#include "EventField.h"

class WallLockEvent: public EventField{
    ReturnEvent make(Player *player) override;
};
