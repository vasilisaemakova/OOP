cmake_minimum_required(VERSION 3.20)
project(oop2_v)

set(CMAKE_CXX_STANDARD 23)

add_executable(oop2_v main.cpp GameLogic/Player.cpp GameLogic/Player.h Reader/Mediator.cpp Reader/Mediator.h Views/FieldView.cpp Views/FieldView.h GameLogic/Field.cpp GameLogic/Field.h Event/Event.h GameLogic/Controller.cpp GameLogic/Controller.h Views/CellView.cpp Views/CellView.h GameLogic/Cell.cpp GameLogic/Cell.h Event/EventType.h Event/PlayerEvent/EventPlayer.cpp Event/PlayerEvent/EventPlayer.h Event/PlayerEvent/TrapEvent.cpp Event/PlayerEvent/TrapEvent.h Event/ReturnEvent.h Event/PlayerEvent/MedicalEvent.cpp Event/PlayerEvent/MedicalEvent.h Event/FieldEvent/EventField.h Event/FieldEvent/KeyEvent.cpp Event/FieldEvent/KeyEvent.h Event/FieldEvent/WallLockEvent.cpp Event/FieldEvent/WallLockEvent.h Views/PlayerView.cpp Views/PlayerView.h
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
        Management/Enums/MoverResponse.h
        Management/Enums/MoverResponse.cpp
        # Rules
        Rules/MedkitRule.h
        Rules/FieldRule.h
        Rules/BarrierRule.h
        Rules/KeyRule.h
        Rules/TrapRule.h
        Rules/WinStateRule.h
        Rules/WrongRuleException.h
        # FieldGenerator
        FiledGenerator/FieldGenerator.h
        # Save
        Save/Saver.h
        Save/Saver.cpp
        # Load
        Load/Loader.h
        Load/Loader.cpp
        # Exceptions
        Load/Exception/missing_file.h
        Load/Exception/missing_section.h
        Load/Exception/invalid_format.h
        Load/Exception/extra_values.h
        Load/Exception/wrong_type.h
        Load/Exception/missing_value.h
        Load/Exception/file_changed.h
        )
