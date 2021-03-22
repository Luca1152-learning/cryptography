#ifndef PROIECT_POO_COMPLEXFIELD_H
#define PROIECT_POO_COMPLEXFIELD_H

#include "BaseMathStructure.h"
#include "../number/ComplexNumber.h"
#include "BaseMathStructure.h"

class ComplexStructure : public BaseMathStructure {
public:
    ComplexStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);

    ComplexNumber createNumber() const;
};

#endif //PROIECT_POO_COMPLEXFIELD_H
