#pragma once

#include "../Event.h"

class EventPlayer: public Event{
protected:
    int value;
public:
    EventPlayer(int value);
};
