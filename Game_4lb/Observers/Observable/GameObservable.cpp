#include "GameObservable.h"

void GameObservable::addObserver(Observer* observer) {
    observers_.push_back(observer);
}

void GameObservable::removeObserver(Observer* observer) {
    observers_.remove(observer);
}

void GameObservable::notifyObservers(ObserverLevel level, const std::string& update) {
    for (Observer* observer: observers_) {
        observer->update(level, update);
    }
}

void GameObservable::changeLogger(Logger* logger) {
    for (auto& observer: observers_) {
        observer->removeAllLoggers();
        observer->addLogger(logger);
    }
}

GameObservable::~GameObservable() noexcept {
    for (auto observer: observers_) {
        delete observer;
    }
}
