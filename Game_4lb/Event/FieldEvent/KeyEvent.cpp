#include "KeyEvent.h"

ReturnEvent KeyEvent::make(Player *player) {
    player->setKey(true);
    return keyup;
}
