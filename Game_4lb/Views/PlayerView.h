#pragma once
#include "../GameLogic/Player.h"

class PlayerView {
private:
    Player* player;
public:
    PlayerView(Player *player);
    void printPlayer();
};
