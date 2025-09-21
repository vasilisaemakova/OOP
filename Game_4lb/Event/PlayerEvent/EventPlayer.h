#pragma once

#include "../Event.h"

class EventPlayer: public Event{
protected:
    int value;
public:
    int GetValue() const {
        return value;
    }
    EventPlayer(int value);
};
