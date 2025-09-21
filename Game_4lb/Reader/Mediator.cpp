#include "Mediator.h"
#include "../Event/FieldEvent/WallLockEvent.h"
#include "../Event/PlayerEvent/TrapEvent.h"
#include "../Event/FieldEvent/KeyEvent.h"
#include "../Observers/Observable/GameObservable.h"
#include "../Observers/Observer/GameObserver.h"
#include "../Observers/Logger/ConsoleLogger.h"
#include "../Observers/Logger/FileLogger.h"
#include "../Management//Mover/ConsoleMover.h"
#include "../FiledGenerator/FieldGenerator.h"

#include "../Save/Saver.h"
#include "../Load/Loader.h"


#include <iostream>

void Mediator::createObservable() {
    observable_ = new GameObservable;
    auto* state_observer = new GameObserver;

    state_observer->addLevel(ObserverLevel::State);
    state_observer->addLevel(ObserverLevel::Error);
    state_observer->addLevel(ObserverLevel::Info);
    state_observer->addLogger(new ConsoleLogger());

    observable_->addObserver(state_observer);
}

void Mediator::switchToConsoleLogger() {
    observable_->changeLogger(new ConsoleLogger());
}

void Mediator::switchToFileLogger() {
    observable_->changeLogger(new FileLogger("logger.txt"));
}

void Mediator::createMover() {
    mover_ = new ConsoleMover;
}

void Mediator::createFirstLevel() {
    FieldGenerator<FieldRule<10, 10>,
                   KeyRule<7, 7>,
                   BarrierRule<5>,
                   MedkitRule<2, 40>,
                   TrapRule<5, 60>,
                   WinStateRule<3, 3>> generator;

    field_ = new Field(generator.GenerateField(FieldRule<10, 10>(), KeyRule<7, 7>(), BarrierRule<5>(),
                             MedkitRule<2, 40>(), TrapRule<5, 60>(),
                            WinStateRule<3, 3>()));
}


void Mediator::createSecondLevel() {
    FieldGenerator<FieldRule<20, 20>,
                   BarrierRule<10>,
                   KeyRule<15, 15>,
                   MedkitRule<4, 40>,
                   TrapRule<10, 60>,
                   WinStateRule<10, 10>> generator;

    field_ = new Field(generator.GenerateField(FieldRule<20, 20>(), BarrierRule<10>(),
                            KeyRule<15, 15>(), MedkitRule<4, 40>(), TrapRule<10, 60>(),
                            WinStateRule<10, 10>()));
}

void Mediator::createField() {
    int operation;
    std::cout << "Choose level (1 or 2): ";
    std::cin >> operation;
    while (operation != 1 && operation != 2) {
        std::cout << "Wrong input! Choose 1 or 2: ";
        std::cin >> operation;
    }
    if (operation == 1) {
        createFirstLevel();
    } else {
        createSecondLevel();
    }
}

Mediator::Mediator(size_t width, size_t height) /*: field_(width, height), controller_(&field_, &player_) */{
    //player_->setPos(2,2);
    loader_ = new Loader("save.txt");
    createObservable();
    createMover();

    //mover_->loadCustomSettings("settings.txt");
    createField();
    player_ = new Player();
    controller_ = new Controller(field_, player_, observable_);

}

Mediator::~Mediator() {
    delete observable_;
    delete player_;
    delete field_;
    delete controller_;
    delete mover_;
    delete loader_;
}

void Mediator::SaveGame() {
    Saver saver("save.txt");
    saver.Save(*this);
    delete loader_;
    loader_ = new Loader("save.txt");
}

void Mediator::LoadGame() {
    try {
        loader_->SetMediator(this);
    } catch (const std::exception& ex) {
        observable_->notifyObservers(ObserverLevel::Error, ex.what());
    }
}

void Mediator::start() {
    controller_->printField();
    bool work = true;
    while (work) {
        MoverResponse response = mover_->move();
        switch (response) {
            case WRONG:observable_->notifyObservers(ObserverLevel::Error, "Wrong input");
                controller_->printField();
                break;
            case CONSOLE_LOGGER:switchToConsoleLogger();
                break;
            case FILE_LOGGER:switchToFileLogger();
                break;
            case SAVE:
                SaveGame();
                break;
            case LOAD:
                LoadGame();
                break;
            case EXIT:work = false;
                break;
            default:
                if (control(response)) {
                    work = false;
                }
                break;
        }
        controller_->printField();
    }
}

bool Mediator::control(MoverResponse direction) {
    bool flag = false;
    switch (direction) {
        case UP:flag = controller_->move(-1, 0);
            break;
        case DOWN:flag = controller_->move(1, 0);
            break;
        case LEFT:flag = controller_->move(0, -1);
            break;
        case RIGHT:flag = controller_->move(0, 1);
            break;
        default:break;
    }
    return flag;
}

