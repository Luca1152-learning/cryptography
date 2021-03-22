#ifndef CRIPTOGRAPHY_RATIONALSTRUCTURE_H
#define CRIPTOGRAPHY_RATIONALSTRUCTURE_H

#include "BaseMathStructure.h"

class RationalStructure : public BaseMathStructure {
public:
    explicit RationalStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);
};

#endif //CRIPTOGRAPHY_RATIONALSTRUCTURE_H
