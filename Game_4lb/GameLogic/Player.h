#pragma once

#include <string>

class Player {
private:
    int healthLevel_{};
    size_t damage_{};
    std::string name_;
    size_t x_;
    size_t y_;
    bool key_;
    bool win_;
public:
    size_t getHealth() const;
    void setHealth(size_t health);

    size_t getPower() const;
    void setPower(size_t power);

    bool haveKey() const;
    void setKey(bool key);

    std::string getNick() const;
    void setNick(const std::string &nick);


    Player();


    void setPos(size_t x, size_t y);
    void setPos(size_t posX);

    size_t getPosX() const;
    void setPosX(size_t x);

    size_t getPosY() const;
    void setPosY(size_t PosY);

    void setWin();
    bool getWin() const;

    Player(size_t health, size_t power, const std::string &nick);

};

