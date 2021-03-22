#include "BaseMathStructure.h"

BaseMathStructure::BaseMathStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide)
        : m_canAdd(canAdd), m_canSubtract(canSubtract), m_canMultiply(canMultiply), m_canDivide(canDivide) {}
