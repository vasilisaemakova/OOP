#include <iostream>
#include "Player.h"
#include <string>

Player::Player(size_t health, size_t power, const std::string &nick) : healthLevel_(health), damage_(power), name_(nick){
    x_ = 0;
    y_ = 0;
    win_ = false;
}

std::string Player::getNick() const {
    return name_;
}
void Player::setNick(const std::string &nick) {
    name_ = nick;
}

Player::Player(){
    healthLevel_ = 100;
    damage_ = 10;
    name_ = "player1";
    x_ = 0;
    y_ = 0;
    win_ = false;
    key_ = false;
}
size_t Player::getPosX() const {
    return x_;
}
void Player::setPosX(size_t x) {
    x = x;
}
size_t Player::getPosY() const {
    return y_;
}
void Player::setPosY(size_t y) {
    y = y;
}
void Player::setPos(size_t x, size_t y) {
    this->x_ = x;
    this->y_ = y;
}

void Player::setPower(size_t power) {
    damage_ = power;
}

size_t Player::getPower() const {
    return damage_;
}

size_t Player::getHealth() const {
    return healthLevel_;
}

void Player::setHealth(size_t health) {
    healthLevel_ = health;
}

bool Player::haveKey() const {
    return key_;
}
void Player::setKey(bool key_) {
    this->key_ = key_;
}

void Player::setWin(){
    win_ = true;
}

bool Player::getWin() const{
    return win_;
}

void Player::setPos(size_t posX) {

}


