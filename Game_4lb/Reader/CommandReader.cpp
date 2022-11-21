#include "CommandReader.h"
#include <iostream>
#include <string>

std::string CommandReader::read() {
    std::string str;
    std::cin >> str;
    return str;
}
