#include "CellView.h"
#include "../Event/FieldEvent/KeyEvent.h"
#include "../Event/PlayerEvent/MedicalEvent.h"
#include "../Event/PlayerEvent/TrapEvent.h"
#include "../Event/FieldEvent/WallLockEvent.h"


char CellView::getCell(Cell & cell){
    if(cell.isOnCell()) return 'P';
    else if (cell.getEvent()){
        Event* event = cell.getEvent();
        Event* e1 = dynamic_cast<KeyEvent*>(event);
        Event* e2 = dynamic_cast<MedicalEvent*>(event);
        Event* e3 = dynamic_cast<TrapEvent*>(event);
        Event* e4 = dynamic_cast<WallLockEvent*>(event);
        if (e1) return 'K';
        else if (e2) return '+';
        else if (e3) return 'o';
        else if (e4) return 'X';
        else return '_';
    }
    else if(cell.isAvailable()) return '_';
    else return '#';
}