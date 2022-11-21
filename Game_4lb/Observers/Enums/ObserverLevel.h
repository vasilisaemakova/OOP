#pragma once

#include <iostream>

enum ObserverLevel
{
    Info,
    State,
    Error
};

inline std::ostream& operator <<(std::ostream& out, ObserverLevel level)
{
    switch(level)
    {
        case Info:
            out << "|INFO|";
            break;
        case State:
            out << "|STATE CHANGE|";
            break;
        case Error:
            out << "|ERROR|";
            break;
    }
    return out;
}

