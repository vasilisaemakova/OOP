#include "GameObserver.h"

#include <algorithm>

void GameObserver::addLogger(Logger* logger) {
    loggers_.push_back(logger);
}

void GameObserver::addLevel(ObserverLevel level) {
    levels_.push_back(level);
}

void GameObserver::update(ObserverLevel level, const std::string& update) {
    // std::find(begin, end, value) ищет значение, и возвращает указатель на найденное значение
    // если значения нет, то возвращает указатель на конец
    if (std::find(levels_.begin(), levels_.end(), level) != levels_.end()) {
        for (Logger* logger: loggers_) {
            logger->log(level, update);
        }
    }
}