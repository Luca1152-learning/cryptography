#include "ComplexStructure.h"

ComplexStructure::ComplexStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide) :
        BaseMathStructure(canAdd, canSubtract, canMultiply, canDivide) {}

ComplexNumber ComplexStructure::createNumber() const {
    return ComplexNumber();
}
