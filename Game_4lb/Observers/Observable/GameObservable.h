#pragma once

#include "Observable.h"

#include <list>

class GameObservable : public Observable {
 private:
    std::list<Observer*> observers_;
 public:
    void addObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers(ObserverLevel level, const std::string& update) override;
};
