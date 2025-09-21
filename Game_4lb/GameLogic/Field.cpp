#include "Field.h"
#include "../Views/FieldView.h"
Field::Field(size_t width, size_t height) :
    width_(width), height_(height)/*, cells(new Cell*[height])*/ {
    cells = new Cell* [height];
    for (int i = 0; i < height_; i++) {
        cells[i] = new Cell[width_]{};
    }
}

size_t Field::getWidth() const {
    return width_;
}

size_t Field::getHeight() const {
    return height_;
}

void Field::updateIsAvailable(bool available, int x, int y) {
    cells[y][x].setAvailable(available);
}

void Field::printField() {
    FieldView().printField(this);
}

void Field::updateOnCell(bool onCell, int x, int y) {
    cells[y][x].setOnCell(onCell);
}

Cell& Field::getCell(int x, int y) {
//    return const_cast<const Cell**>(cells); //то, что лежит под указателем селл, является константой
    return cells[y][x];
}

Field::Field(const Field& other) {
    this->height_ = other.height_;
    this->width_ = other.width_;

    cells = new Cell* [height_];
    for (int i = 0; i < height_; i++) {
        cells[i] = new Cell[width_];
    }
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        for (int i = 0; i < height_; i++) {
            delete[] cells[i];
        }
        delete cells;
        height_ = other.height_;
        width_ = other.width_;
        cells = new Cell* [height_];
        for (int i = 0; i < height_; i++) {
            cells[i] = new Cell[width_];
        }
        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < width_; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;

}

Field::Field(Field&& other) noexcept {
    cells = new Cell* [height_];
    for (int i = 0; i < height_; i++) {
        cells[i] = new Cell[width_];
    }
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
    other.height_ = 0;
    other.width_ = 0;
}

Field& Field::operator=(Field&& other) {
    if (this != &other) {
        if (cells != nullptr) {
            for (int i = 0; i < height_; i++) {
                delete[] cells[i];
            }
        }
        delete cells;
        height_ = other.height_;
        width_ = other.width_;
        cells = new Cell* [height_];
        for (int i = 0; i < height_; i++) {
            cells[i] = new Cell[width_];
        }
        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < width_; j++) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
}

Field::~Field() {
    for (int i = 0; i < height_; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}
