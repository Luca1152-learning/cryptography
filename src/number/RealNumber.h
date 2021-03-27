#ifndef CRIPTOGRAPHY_REALNUMBER_H
#define CRIPTOGRAPHY_REALNUMBER_H

#include "BaseNumber.h"
#include <ostream>

using namespace std;

class RealNumber : public BaseNumber {
public:
    explicit RealNumber(double value = 0.0);

    RealNumber &setValue(double value);

    friend RealNumber decodeExpressionResult(const RealNumber &left, char op, const RealNumber &right);

    // Arithmetic operators
    RealNumber operator+(const RealNumber &number) const;

    RealNumber operator-(const RealNumber &number) const;

    RealNumber operator*(const RealNumber &number) const;

    RealNumber operator/(const RealNumber &number) const;

    // Stream operators
    friend ostream &operator<<(ostream &out, const RealNumber &number);

    friend istream &operator>>(istream &in, RealNumber &number);

private:
    double m_value;
};

#endif //CRIPTOGRAPHY_REALNUMBER_H
