#ifndef CRIPTOGRAPHY_INTEGERMODULONNUMBER_H
#define CRIPTOGRAPHY_INTEGERMODULONNUMBER_H

#include <ostream>
#include "BaseNumber.h"

using namespace std;

class IntegerModuloNNumber : BaseNumber {
public:
    explicit IntegerModuloNNumber(long long modulus, long long value = 0);

    IntegerModuloNNumber &setValue(double value);

    friend IntegerModuloNNumber
    decodeExpressionResult(const IntegerModuloNNumber &left, char op, const IntegerModuloNNumber &right);

    // Arithmetic operators
    IntegerModuloNNumber operator+(const IntegerModuloNNumber &number) const;

    IntegerModuloNNumber operator-(const IntegerModuloNNumber &number) const;

    IntegerModuloNNumber operator*(const IntegerModuloNNumber &number) const;

    IntegerModuloNNumber operator/(const IntegerModuloNNumber &number) const;

    bool operator==(const IntegerModuloNNumber &number) const;

    bool operator!=(const IntegerModuloNNumber &number) const;

    // Stream operators
    friend ostream &operator<<(ostream &out, const IntegerModuloNNumber &number);

    friend istream &operator>>(istream &in, IntegerModuloNNumber &number);

private:
    long long m_modulus, m_value;
};

#endif //CRIPTOGRAPHY_INTEGERMODULONNUMBER_H
