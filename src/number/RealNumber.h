#ifndef CRIPTOGRAPHY_REALNUMBER_H
#define CRIPTOGRAPHY_REALNUMBER_H

#include "BaseNumber.h"
#include <ostream>

using namespace std;

class RealNumber : public BaseNumber {
public:
    explicit RealNumber(double value = 0.0);

    RealNumber &setValue(double value);

    // Arithmetic operators
    RealNumber operator+(const RealNumber &number) const;

    RealNumber operator-(const RealNumber &number) const;

    RealNumber operator*(const RealNumber &number) const;

    RealNumber operator/(const RealNumber &number) const;

    // Stream output operator
    friend ostream &operator<<(ostream &out, const RealNumber &number);

private:
    double m_value;
};

#endif //CRIPTOGRAPHY_REALNUMBER_H
