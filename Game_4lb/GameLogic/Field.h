#pragma once

#include <iostream>
#include "Cell.h"

class Field {
public:

    Field() = default;

    Field(size_t width, size_t height);

    size_t getWidth() const;

    size_t getHeight() const;

    void printField();

    void updateIsAvailable(bool available, int x, int y);

    void updateOnCell(bool onCell, int x, int y);

    Cell & getCell(int x, int y);

    Field(const Field &other);
    Field &operator = (const Field &other);
    Field(Field &&other) noexcept;
    Field &operator = (Field &&other);

    ~Field();
private:
    size_t width_ = 1;
    size_t height_ = 1;
    Cell** cells = nullptr;

};
