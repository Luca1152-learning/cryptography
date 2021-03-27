#include "RealField.h"

string RealField::getName() const {
    return "Real numbers";
}

RealNumber RealField::createNumber() const {
    return RealNumber();
}
