#pragma once

#include "Observer.h"

#include <list>

class GameObserver : public Observer {
 private:
    std::list<Logger*> loggers_;
    std::list<ObserverLevel> levels_;
 public:
    void addLogger(Logger* logger) override;
    void addLevel(ObserverLevel level) override;

    void update(ObserverLevel level, const std::string& update) override;
};
