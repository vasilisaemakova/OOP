#pragma once

#include "../Observer/Observer.h"

class Observable {
 public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(ObserverLevel level, const std::string& update) = 0;
};
