#pragma once
#include <iostream>
#include "../GameLogic/Player.h"
#include "ReturnEvent.h"
#include "EventType.h"

class Event {
public:
    virtual ReturnEvent make(Player* player) = 0;
    virtual ~Event() = default;
    virtual Event* GetCopy() = 0;
    virtual EventType GetType() = 0;
};
