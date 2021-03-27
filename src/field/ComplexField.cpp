#include "ComplexField.h"

string ComplexField::getName() const {
    return "Complex numbers";
}

ComplexNumber ComplexField::createNumber() const {
    return ComplexNumber();
}