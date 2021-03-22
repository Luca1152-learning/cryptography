#ifndef PROIECT_POO_REALFIELD_H
#define PROIECT_POO_REALFIELD_H

#include "BaseMathField.h"
#include "../number/RealNumber.h"
#include "BaseMathField.h"

class RealField : public BaseMathField {
public:
    RealNumber createNumber() const;
};

#endif //PROIECT_POO_REALFIELD_H
