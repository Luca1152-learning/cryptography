#ifndef PROIECT_POO_REALFIELD_H
#define PROIECT_POO_REALFIELD_H

#include "BaseMathStructure.h"
#include "../number/RealNumber.h"
#include "BaseMathStructure.h"

class RealStructure : public BaseMathStructure {
public:
    RealStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);

    RealNumber createNumber() const;
};

#endif //PROIECT_POO_REALFIELD_H
