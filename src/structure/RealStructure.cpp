#include "RealStructure.h"

RealStructure::RealStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide) : BaseMathStructure(
        canAdd, canSubtract, canMultiply, canDivide) {}

RealNumber RealStructure::createNumber() const {
    return RealNumber();
}

