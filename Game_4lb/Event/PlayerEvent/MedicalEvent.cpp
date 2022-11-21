#include "MedicalEvent.h"

ReturnEvent MedicalEvent::make(Player *player) {
    int a = player->getHealth();
    a+=value;
    player->setHealth(a);
    return health;
}

MedicalEvent::MedicalEvent(int value) : EventPlayer(value) {}
