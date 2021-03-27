#ifndef CRIPTOGRAPHY_RATIONALNUMBER_H
#define CRIPTOGRAPHY_RATIONALNUMBER_H

#include <ostream>
#include "BaseNumber.h"

using namespace std;

class RationalNumber : BaseNumber {
public:
    explicit RationalNumber(double value = 0.0);

    RationalNumber &setValue(double value);

    friend RationalNumber decodeExpressionResult(const RationalNumber &left, char op, const RationalNumber &right);

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber &number) const;

    RationalNumber operator-(const RationalNumber &number) const;

    RationalNumber operator*(const RationalNumber &number) const;

    RationalNumber operator/(const RationalNumber &number) const;

    bool operator==(const RationalNumber &number) const;

    bool operator!=(const RationalNumber &number) const;

    // Stream operators
    friend ostream &operator<<(ostream &out, const RationalNumber &number);

    friend istream &operator>>(istream &in, RationalNumber &number);

private:
    double m_value;
};

#endif //CRIPTOGRAPHY_RATIONALNUMBER_H
