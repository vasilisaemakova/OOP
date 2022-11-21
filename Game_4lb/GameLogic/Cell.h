#pragma once
#include "Player.h"
#include "../Event/Event.h"


class Cell {
public:
    Cell();

    bool isOnCell() const;

    void setOnCell(bool onCell);

    bool isAvailable() const;

    void setAvailable(bool available);
    void setEvent(Event *event);
    Event *getEvent() const;
    ~Cell();


private:
    bool onCell_ = false;
    bool available_ = false;
    int typeEvent = 0;
    bool key_ = false;
    Event* event_;

};


