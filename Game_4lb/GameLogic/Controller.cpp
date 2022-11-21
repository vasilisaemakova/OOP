#include "Controller.h"
#include "../Event/ReturnEvent.h"

Controller::Controller(Field *field, Player *player, Observable* observable) {
    this->field_ = field;
    this->player_ = player;
    this->playerView_ = new PlayerView(player);
    this->observable_ = observable;
    player->setPos(0, 0);
    field->updateOnCell(true, 0, 0);
}
//нажал на w вызывается метод makeMove(-1,0)
bool Controller::move(int x_, int y_){
    int height = field_->getHeight();
    int width = field_->getWidth();
    int x = player_->getPosX();
    int y = player_->getPosY();

    int newX = x + x_ >= 0 ? (x + x_) % height : x + x_ + height; //(2;2) -> (2;3%3)  или (0;0)-> (-1;0)->(2;0) типо -1+3=2
    int newY = y + y_ >= 0 ? (y + y_) % width : y + y_ + width;
    //std::cout<<newX<<std::endl;
    //std::cout<<newY<<std::endl;
    if (!canMove(newX, newY)) {
        observable_->notifyObservers(ObserverLevel::Error, "Can't move");
        return false;
    }

    Event* event = field_->getCell(newX,newY).getEvent();
    if (event) {
        ReturnEvent ret = event->make(player_);

        switch (ret) {
            case win:
                std::cout << "Win!!!\n";
                field_->updateOnCell(false, x, y);
                field_->updateOnCell(true, newX, newY);
                player_->setPos(newX, newY);

                observable_->notifyObservers(ObserverLevel::Info, "Player position changed");
                observable_->notifyObservers(ObserverLevel::State, "Win");
                return true;
            case stay:
                observable_->notifyObservers(ObserverLevel::State, "Stay");
                return false;
            case keyup:
            case health:
                observable_->notifyObservers(ObserverLevel::State, "Clean");
                field_->updateOnCell(false, x, y);
                field_->updateOnCell(true, newX, newY);
                player_->setPos(newX, newY);
                field_->getCell(newX, newY).setEvent(nullptr);

                observable_->notifyObservers(ObserverLevel::Info, "Player position changed");
                if (ret == keyup)
                    observable_->notifyObservers(ObserverLevel::Info, "Key has been picked up");
                else {
                    observable_->notifyObservers(ObserverLevel::Info, "Med-kit has been picked up");
                    observable_->notifyObservers(ObserverLevel::Info, "Player health grew up");
                }
                return false;
            case lose:
                observable_->notifyObservers(ObserverLevel::State, "Lose");
                std::cout << "Lose!!!\n";
                field_->updateOnCell(false, x, y);
                field_->updateOnCell(true, newX, newY);
                player_->setPos(newX, newY);

                observable_->notifyObservers(ObserverLevel::Info, "Player position changed");
                return true;
            case damaged:
                observable_->notifyObservers(ObserverLevel::Info, "Player took damage");
                break;
        }
    }
    field_->updateOnCell(false, x, y);
    field_->updateOnCell(true, newX, newY);
    player_->setPos(newX, newY);

    observable_->notifyObservers(ObserverLevel::Info, "Player position changed");
    return false;
}


void Controller::printField() {
    field_->printField();
    playerView_->printPlayer();
}

bool Controller::canMove(int x,int y) {
    return field_->getCell(x,y).isAvailable();
}


//
//void Controller::down() {
//    int height = field_->getHeight();
//    int x_ = player_->getPosX();
//    int y_ = player_->getPosY();
//    int lastY = y_;
//    if (y_ + 1 == height) {
//        y_ -= height;
//    }
//    y_++;
//    if (!canMove(x_, y_)) {
//        return;
//    }
//    field_->updateOnCell(false, x_, lastY);
//    field_->updateOnCell(true, x_, y_);
//    player_->setPos(x_, y_);
//}
//
//void Controller::left(){
//    int width = field_->getWidth();
//
//    int x_ = player_->getPosX();
//    int y_ = player_->getPosY();
//    int lastX = x_;
//    if (x_ == 0) {
//        x_ += width;
//    }
//    x_--;
//    if (!canMove(x_,y_)) {
//        return;
//    }
//    field_->updateOnCell(false, lastX, y_);
//    field_->updateOnCell(true, x_, y_);
//    player_->setPos(x_, y_);
//}
//
//void Controller::right(){
//    int width = field_->getWidth();
//
//    int x_ = player_->getPosX();
//    int y_ = player_->getPosY();
//    int lastX = x_;
//    if (x_ + 1 == width) {
//        x_ -= width;
//    }
//    x_++;
//    if (!canMove(x_,y_)) {
//        return;
//    }
//    field_->updateOnCell(false, lastX, y_);
//    field_->updateOnCell(true, x_, y_);
//    player_->setPos(x_, y_);
//}