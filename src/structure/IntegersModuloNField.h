#ifndef PROIECT_POO_RATIONALNFIELD_H
#define PROIECT_POO_RATIONALNFIELD_H

#include "BaseMathField.h"
#include "../number/IntegerModuloNNumber.h"

class IntegersModuloNField : public BaseMathField {
public:
    explicit IntegersModuloNField(long long n);

    IntegerModuloNNumber createNumber() const;

private:
    long long m_n;
};

#endif //PROIECT_POO_RATIONALNFIELD_H
