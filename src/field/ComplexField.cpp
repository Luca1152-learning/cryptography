#include "ComplexField.h"

string ComplexField::getName() const {
    return "Complex numbers";
}

bool ComplexField::isIsomorphicTo(BaseMathField *field) const {
    // The complex field is isomorphic only to other complex fields
    if (dynamic_cast<ComplexField *>(field)) {
        return true;
    } else {
        return false;
    }
}

ComplexNumber ComplexField::createNumber() const {
    return ComplexNumber();
}