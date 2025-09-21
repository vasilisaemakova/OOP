#pragma once

#include "../GameLogic/Controller.h"
#include "../Event/PlayerEvent/MedicalEvent.h"
#include "../Observers/Observable/Observable.h"
#include "../Management/Mover/Mover.h"

class ILoader;

class Mediator {
private:
    friend class Saver;
    friend class Loader;

    Observable* observable_;
    Player* player_;
    Field* field_;
    Controller* controller_;
    Mover* mover_;
    ILoader* loader_;

    void SaveGame();
    void LoadGame();
    void createFirstLevel();
    void createSecondLevel();
    void createField();
    bool control(MoverResponse direction);
    void createObservable();
    void createMover();
    void switchToConsoleLogger();
    void switchToFileLogger();

public:
    Mediator() = default;
    Mediator(size_t width, size_t height);
    ~Mediator();
    void start();
};

class ILoader {
 public:
    virtual void SetMediator(Mediator* other_mediator) = 0;
};


