#ifndef CRIPTOGRAPHY_INTEGERNUMBER_H
#define CRIPTOGRAPHY_INTEGERNUMBER_H

#include <ostream>

using namespace std;

class IntegerNumber {
public:
    explicit IntegerNumber(long long value = 0);

    IntegerNumber &setValue(long long value);

    // Arithmetic operators
    IntegerNumber operator+(const IntegerNumber &number) const;

    IntegerNumber operator-(const IntegerNumber &number) const;

    IntegerNumber operator*(const IntegerNumber &number) const;

    IntegerNumber operator/(const IntegerNumber &number) const;

    // Stream output operator
    friend ostream &operator<<(ostream &out, const IntegerNumber &number);

private:
    long long m_value;
};

#endif //CRIPTOGRAPHY_INTEGERNUMBER_H
