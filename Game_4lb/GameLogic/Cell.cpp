#include "Cell.h"

bool Cell::isOnCell() const {
    return onCell_;
}

void Cell::setOnCell(bool onCell) {
    this->onCell_ = onCell;
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
}

Cell::Cell(const Cell& other) :
    onCell_(other.onCell_),
    available_(other.available_) {
    if (other.event_ != nullptr) {
        event_ = other.event_->GetCopy();
    } else {
        event_ = nullptr;
    }
}

Cell& Cell::operator=(Cell&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    delete event_;

    onCell_ = other.onCell_;
    available_ = other.available_;
    event_ = other.event_;
    other.event_ = nullptr;

    return *this;
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other) {
        return *this;
    }
    delete event_;

    onCell_ = other.onCell_;
    available_ = other.available_;
    if (other.event_ != nullptr) {
        event_ = other.event_->GetCopy();
    } else {
        event_ = nullptr;
    }
    return *this;
}

void Cell::setEvent(Event* event) {
    //event_ = nullptr;
    event_ = event;
}

Event* Cell::getEvent() const {
    return event_;
}

Cell::~Cell() {
    delete event_;
}



