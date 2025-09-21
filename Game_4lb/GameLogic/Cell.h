#pragma once
#include "Player.h"
#include "../Event/Event.h"

class Cell {
 public:
    Cell();

    ~Cell(); // по правилу 5 (3) мы должны оперделить остальные методы

    Cell(const Cell& other);

    Cell(Cell&& other) noexcept:
        onCell_(other.onCell_),
        available_(other.available_),
        event_(other.event_) {
        other.event_ = nullptr;
    };

    Cell& operator=(const Cell& other);

    Cell& operator=(Cell&& other) noexcept;

    bool isOnCell() const;

    bool isAvailable() const;

    void setOnCell(bool onCell);

    void setAvailable(bool available);

    void setEvent(Event* event);

    Event* getEvent() const;

 private:
    bool onCell_ = false;
    bool available_ = false;
    Event* event_;

};


