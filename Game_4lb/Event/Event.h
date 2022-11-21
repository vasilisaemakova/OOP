#pragma once
#include <iostream>
#include "../GameLogic/Player.h"
#include "ReturnEvent.h"

class Event {
public:
    virtual ReturnEvent make(Player* player) = 0;
    virtual ~Event()=default;
};
