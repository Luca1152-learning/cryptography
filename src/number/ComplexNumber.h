#ifndef CRIPTOGRAPHY_COMPLEXNUMBER_H
#define CRIPTOGRAPHY_COMPLEXNUMBER_H

#include <ostream>

using namespace std;

class ComplexNumber {
public:
    explicit ComplexNumber(double real = 0.0, double imaginary = 0.0);

    ComplexNumber &setValue(double real, double imaginary);

    // Arithmetic operators
    ComplexNumber operator+(const ComplexNumber &number) const;

    ComplexNumber operator-(const ComplexNumber &number) const;

    ComplexNumber operator*(const ComplexNumber &number) const;

    ComplexNumber operator/(const ComplexNumber &number) const;

    // Stream output operator
    friend ostream &operator<<(ostream &out, const ComplexNumber &number);

private:
    double m_real, m_imaginary;
};

#endif //CRIPTOGRAPHY_COMPLEXNUMBER_H
