#ifndef PROIECT_POO_COMPLEXFIELD_H
#define PROIECT_POO_COMPLEXFIELD_H

#include "BaseMathField.h"
#include "../number/ComplexNumber.h"
#include "BaseMathField.h"

class ComplexField : public BaseMathField {
public:
    string getName() const override;

    bool isIsomorphicTo(BaseMathField *field) const override;

    ComplexNumber createNumber() const;
};

#endif //PROIECT_POO_COMPLEXFIELD_H
