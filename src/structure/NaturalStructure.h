#ifndef CRIPTOGRAPHY_NATURALSTRUCTURE_H
#define CRIPTOGRAPHY_NATURALSTRUCTURE_H

#include "BaseMathStructure.h"

class NaturalStructure : public BaseMathStructure {
public:
    explicit NaturalStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);
};

#endif //CRIPTOGRAPHY_NATURALSTRUCTURE_H
