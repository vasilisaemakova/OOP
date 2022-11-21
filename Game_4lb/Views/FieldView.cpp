#include <iostream>
#include "FieldView.h"
#include "../GameLogic/Field.h"

void FieldView::printField(Field *field) {

    int height_ = field->getHeight();
    int width_ = field->getWidth();
    //Cell cells= field->getCell();
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j)
            std::cout << cellView.getCell(field->getCell(i, j))<<' ';
        std::cout << '\n';
    }
}

FieldView::FieldView(const CellView &cellView) : cellView(cellView) {}
