#include "ConsoleLogger.h"

#include <iostream>

void ConsoleLogger::log(ObserverLevel level, const std::string& update) {
    std::cout << level << " " << update << std::endl;
}
