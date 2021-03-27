#ifndef PROIECT_POO_RATIONALNFIELD_H
#define PROIECT_POO_RATIONALNFIELD_H

#include "BaseMathField.h"
#include "../number/IntegerModuloNNumber.h"

class IntegersModuloNField : public BaseMathField {
public:
    explicit IntegersModuloNField(long long modulus);

    string getName() const override;

    long long getModulus() const;

    IntegerModuloNNumber createNumber() const;

private:
    long long m_modulus;
};

#endif //PROIECT_POO_RATIONALNFIELD_H
