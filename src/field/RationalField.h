#ifndef CRIPTOGRAPHY_RATIONALFIELD_H
#define CRIPTOGRAPHY_RATIONALFIELD_H

#include "BaseMathField.h"
#include "../number/RationalNumber.h"

class RationalField : public BaseMathField {
public:
    string getName() const override;

    RationalNumber createNumber() const;
};

#endif //CRIPTOGRAPHY_RATIONALFIELD_H
