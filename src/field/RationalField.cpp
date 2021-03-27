#include "RationalField.h"

string RationalField::getName() const {
    return "Rational numbers";
}

RationalNumber RationalField::createNumber() const {
    return RationalNumber();
}