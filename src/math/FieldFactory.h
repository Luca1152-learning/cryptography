#ifndef CRIPTOGRAPHY_FIELDFACTORY_H
#define CRIPTOGRAPHY_FIELDFACTORY_H

#include "../field/BaseMathField.h"

class FieldFactory {
public:
    static BaseMathField *promptFieldCreation();
};

#endif //CRIPTOGRAPHY_FIELDFACTORY_H
