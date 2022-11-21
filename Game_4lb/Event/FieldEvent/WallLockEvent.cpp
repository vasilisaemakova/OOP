#include "WallLockEvent.h"

ReturnEvent WallLockEvent::make(Player *player) {
    if (player->haveKey()){
        return win;
    }
    return stay;
}
