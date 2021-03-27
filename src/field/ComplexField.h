#ifndef PROIECT_POO_COMPLEXFIELD_H
#define PROIECT_POO_COMPLEXFIELD_H

#include "BaseMathField.h"
#include "../number/ComplexNumber.h"
#include "BaseMathField.h"

class ComplexField : public BaseMathField {
public:
    ComplexNumber createNumber() const;
};

#endif //PROIECT_POO_COMPLEXFIELD_H
