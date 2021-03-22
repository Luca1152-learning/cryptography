#include "IntegerStructure.h"

IntegerStructure::IntegerStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide)
        : BaseMathStructure(canAdd, canSubtract, canMultiply, canDivide) {}

IntegerNumber IntegerStructure::createNumber() const {
    return IntegerNumber();
}
