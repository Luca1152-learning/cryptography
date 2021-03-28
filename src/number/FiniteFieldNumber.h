#ifndef CRYPTOGRAPHY_FINITEFIELDNUMBER_H
#define CRYPTOGRAPHY_FINITEFIELDNUMBER_H

#include <ostream>
#include <iosfwd>
#include "BaseNumber.h"

using namespace std;

class FiniteField;

class FiniteFieldNumber : public BaseNumber {
public:
    FiniteFieldNumber(FiniteField *field, double value = 0.0);

    FiniteFieldNumber &setValue(double value);

    friend FiniteFieldNumber decodeExpressionResult(
            const FiniteFieldNumber &left, char op, const FiniteFieldNumber &right
    );

    // Arithmetic operators
    FiniteFieldNumber operator+(const FiniteFieldNumber &number) const;

    FiniteFieldNumber operator-(const FiniteFieldNumber &number) const;

    FiniteFieldNumber operator*(const FiniteFieldNumber &number) const;

    FiniteFieldNumber operator/(const FiniteFieldNumber &number) const;

    bool operator==(const FiniteFieldNumber &number) const;

    bool operator!=(const FiniteFieldNumber &number) const;

    // Stream operators
    friend ostream &operator<<(ostream &out, const FiniteFieldNumber &number);

    friend istream &operator>>(istream &in, FiniteFieldNumber &number);

private:
    FiniteField *m_field;
    double m_value;
};

#endif //CRYPTOGRAPHY_FINITEFIELDNUMBER_H
