#include "Mediator.h"
#include "../Event/FieldEvent/WallLockEvent.h"
#include "../Event/PlayerEvent/TrapEvent.h"
#include "../Event/FieldEvent/KeyEvent.h"
#include "../Observers/Observable/GameObservable.h"
#include "../Observers/Observer/GameObserver.h"
#include "../Observers/Logger/ConsoleLogger.h"
#include "../Observers/Logger/FileLogger.h"
#include "../Management//Mover/ConsoleMover.h"

#include <iostream>

void Mediator::createObservable() {
    observable_ = new GameObservable;
    auto* state_observer = new GameObserver;

    state_observer->addLevel(ObserverLevel::State);
    state_observer->addLevel(ObserverLevel::Error);
    state_observer->addLevel(ObserverLevel::Info);
    state_observer->addLogger(new ConsoleLogger());
    state_observer->addLogger(new FileLogger("logger.txt"));

    observable_->addObserver(state_observer);
}

void Mediator::createMover() {
    mover_ = new ConsoleMover;
}

Mediator::Mediator(size_t width, size_t height) /*: field_(width, height), controller_(&field_, &player_) */{
    //player_->setPos(2,2);
    createObservable();
    createMover();

    mover_->loadCustomSettings("settings.txt");

    field_ = new Field(width, height);
    player_ = new Player();
    controller_ = new Controller(field_, player_, observable_);

    field_->updateIsAvailable(false, 0, 1);
    field_->updateIsAvailable(false, 0, 4);
    field_->updateIsAvailable(false, 3, 4);
    field_->updateIsAvailable(false, 4, 2);

    field_->getCell(2, 2).setEvent(new MedicalEvent(40));
    field_->getCell(2, 3).setEvent(new TrapEvent(60));
    field_->getCell(3, 1).setEvent(new TrapEvent(60));

    field_->getCell(4, 4).setEvent(new WallLockEvent());
    field_->getCell(4, 0).setEvent(new KeyEvent());
//    field_->getCell(1,3).setEvent()
}

void Mediator::start() {
    controller_->printField();

    Direction dir = mover_->move();
    while (dir != Direction::EXIT) {
        if (dir == Direction::WRONG) {
            observable_->notifyObservers(ObserverLevel::Error, "Wrong input");
            controller_->printField();
        }
        else if (control(dir))
            break;
        dir = mover_->move();
    }
}

bool Mediator::control(Direction direction) {
    bool flag = false;
    switch (direction) {
        case UP:flag = controller_->move(-1, 0);
            break;
        case DOWN:flag = controller_->move(1, 0);
            break;
        case LEFT:controller_->move(0, -1);
            break;
        case RIGHT:flag = controller_->move(0, 1);
            break;
        default:
            break;
    }
    controller_->printField();
    return flag;
}


/*
void Mediator::createField(){
    Field field2 = Field();
    return field2;
}
*/

