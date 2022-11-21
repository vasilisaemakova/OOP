#include "../GameLogic/Field.h"
#include "CellView.h"
class FieldView {
public:
    FieldView() = default;

    FieldView(const CellView &cellView);

    void printField(Field *field);
private:
    //Field  field_;
    CellView cellView;
};
