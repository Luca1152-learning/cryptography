#include "IntegerModuloNStructure.h"

IntegerModuloNStructure::IntegerModuloNStructure(long long int n, bool canAdd, bool canSubtract, bool canMultiply,
                                                 bool canDivide) :
        BaseMathStructure(canAdd, canSubtract, canMultiply, canDivide), m_n(n) {}

IntegerModuloNNumber IntegerModuloNStructure::createNumber() const {
    return IntegerModuloNNumber(m_n);
}
