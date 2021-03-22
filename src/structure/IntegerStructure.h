#ifndef PROIECT_POO_RATIONALFIELD_H
#define PROIECT_POO_RATIONALFIELD_H

#include "BaseMathStructure.h"
#include "../number/IntegerNumber.h"
#include "BaseMathStructure.h"

class IntegerStructure : public BaseMathStructure {
public:
    IntegerStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);

    IntegerNumber createNumber() const;
};

#endif //PROIECT_POO_RATIONALFIELD_H
