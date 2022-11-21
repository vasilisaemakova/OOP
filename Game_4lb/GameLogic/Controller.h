#pragma once

#include "Cell.h"
#include "Player.h"
#include "Field.h"
#include "../Views/PlayerView.h"
#include "../Observers/Observable/Observable.h"

class Controller {
private:
    Field* field_;
    Player* player_;
    PlayerView* playerView_;
    Observable* observable_;
public:
    Controller(Field* field, Player* player, Observable* observable);
    bool move(int x, int y);
//    void down();
//    void left();
//    void right();
    void printField();
    bool canMove(int x, int y);

};
