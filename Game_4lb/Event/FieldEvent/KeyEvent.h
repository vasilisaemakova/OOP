#pragma once

#include "EventField.h"

class KeyEvent: public EventField{
    ReturnEvent make(Player *player) override;
};
