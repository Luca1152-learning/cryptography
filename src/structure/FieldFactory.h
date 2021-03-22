#ifndef CRIPTOGRAPHY_FIELDFACTORY_H
#define CRIPTOGRAPHY_FIELDFACTORY_H

#include "BaseMathField.h"

class NotAFieldException : public runtime_error {
public:
    NotAFieldException();

    const char *what() const _NOEXCEPT override;
};

class FieldFactory {
public:
    static BaseMathField *promptFieldCreation();
};

#endif //CRIPTOGRAPHY_FIELDFACTORY_H
