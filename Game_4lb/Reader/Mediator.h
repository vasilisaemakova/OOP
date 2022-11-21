#pragma once

#include "../GameLogic/Controller.h"
#include "CommandReader.h"
#include "../Event/PlayerEvent/MedicalEvent.h"
#include "../Observers/Observable/Observable.h"
#include "../Management//Mover/Mover.h"

class Mediator {
private:
    Observable* observable_;
    Player* player_;
    Field* field_;
    Controller* controller_;
    CommandReader* command_;
    Mover* mover_;

    //void createField();
    bool control(Direction direction);
    void createObservable();
    void createMover();

public:
    Mediator(size_t width, size_t height);
    void start();
};


