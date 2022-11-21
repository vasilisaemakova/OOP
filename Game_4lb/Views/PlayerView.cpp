#include <iostream>
#include "PlayerView.h"

PlayerView::PlayerView(Player *player) : player(player) {}

void PlayerView::printPlayer() {
    std::cout << player->getNick() << "  Health:" << player->getHealth() << "  Power:" << player->getPower() << "\n";
}
