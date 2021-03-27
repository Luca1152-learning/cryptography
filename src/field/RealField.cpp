#include "RealField.h"

string RealField::getName() const {
    return "Real numbers";
}

bool RealField::isIsomorphicTo(BaseMathField *field) const {
    // The real field is isomorphic only to other real fields
    if (dynamic_cast<RealField *>(field)) {
        return true;
    } else {
        return false;
    }
}

RealNumber RealField::createNumber() const {
    return RealNumber();
}