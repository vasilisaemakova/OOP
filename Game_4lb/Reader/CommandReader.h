#pragma once
#include "../GameLogic/Cell.h"
#include "../GameLogic/Player.h"
#include "../GameLogic/Field.h"
#include "../GameLogic/Controller.h"

class CommandReader {
public:
    std::string read();
};
