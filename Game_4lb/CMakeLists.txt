cmake_minimum_required(VERSION 3.20)
project(oop2_v)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop2_v main.cpp GameLogic/Player.cpp GameLogic/Player.h Reader/Mediator.cpp Reader/Mediator.h Views/FieldView.cpp Views/FieldView.h GameLogic/Field.cpp GameLogic/Field.h Event/Event.h GameLogic/Controller.cpp GameLogic/Controller.h Reader/CommandReader.cpp Reader/CommandReader.h Views/CellView.cpp Views/CellView.h GameLogic/Cell.cpp GameLogic/Cell.h Event/PlayerEvent/EventPlayer.cpp Event/PlayerEvent/EventPlayer.h Event/PlayerEvent/TrapEvent.cpp Event/PlayerEvent/TrapEvent.h Event/ReturnEvent.h Event/PlayerEvent/MedicalEvent.cpp Event/PlayerEvent/MedicalEvent.h Event/FieldEvent/EventField.h Event/FieldEvent/KeyEvent.cpp Event/FieldEvent/KeyEvent.h Event/FieldEvent/WallLockEvent.cpp Event/FieldEvent/WallLockEvent.h Views/PlayerView.cpp Views/PlayerView.h
        # Observers
        Observers/Logger/Logger.h
        Observers/Logger/ConsoleLogger.h
        Observers/Logger/ConsoleLogger.cpp
        Observers/Logger/FileLogger.h
        Observers/Logger/FileLogger.cpp
        Observers/Enums/ObserverLevel.h
        Observers/Observer/Observer.h
        Observers/Observer/GameObserver.h
        Observers/Observer/GameObserver.cpp
        Observers/Observable/Observable.h
        Observers/Observable/GameObservable.h
        Observers/Observable/GameObservable.cpp
        # Management
        Management/Mover/Mover.h
        Management/Mover/ConsoleMover.h
        Management/Mover/ConsoleMover.cpp
        Management/Mover/WrongSettingsException.h
        Management/Enums/Direction.h
        )
