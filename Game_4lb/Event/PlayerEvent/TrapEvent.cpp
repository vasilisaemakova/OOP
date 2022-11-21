#include "TrapEvent.h"

ReturnEvent TrapEvent::make(Player *player) {
    int a = player->getHealth();
    a-=value;
    if (a<=0){
        player->setHealth(0);
        return lose;
    }
    player->setHealth(a);
    return damaged;
}

TrapEvent::TrapEvent(int value) : EventPlayer(value) {}
