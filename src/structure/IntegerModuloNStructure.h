#ifndef PROIECT_POO_RATIONALNFIELD_H
#define PROIECT_POO_RATIONALNFIELD_H

#include "BaseMathStructure.h"
#include "../number/IntegerModuloNNumber.h"

class IntegerModuloNStructure : public BaseMathStructure {
public:
    explicit IntegerModuloNStructure(long long n, bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);

    IntegerModuloNNumber createNumber() const;

private:
    long long m_n;
};

#endif //PROIECT_POO_RATIONALNFIELD_H
