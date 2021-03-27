#include "RationalField.h"

string RationalField::getName() const {
    return "Rational numbers";
}

bool RationalField::isIsomorphicTo(BaseMathField *field) const {
    // The complex field is isomorphic only to other rational fields
    if (dynamic_cast<RationalField *>(field)) {
        return true;
    } else {
        return false;
    }
}

RationalNumber RationalField::createNumber() const {
    return RationalNumber();
}