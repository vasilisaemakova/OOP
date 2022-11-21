#include "Cell.h"

bool Cell::isOnCell() const {
    return onCell_;
}

void Cell::setOnCell(bool onCell) {
    Cell::onCell_ = onCell;
}

bool Cell::isAvailable() const {
    return available_;
//    && event_->isAvailable(player);
}

void Cell::setAvailable(bool available) {
    available_ = available;
}

Cell::Cell() {
    onCell_ = false;
    available_ = true;
    event_ = nullptr;
    key_ = false;
}

void Cell::setEvent(Event *event)
{
    //event_ = nullptr;
    event_ = event;
}


Event *Cell::getEvent() const
{
    return event_;
}

Cell::~Cell() {
    delete event_;
}
