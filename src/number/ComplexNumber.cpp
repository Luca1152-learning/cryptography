#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {}

ComplexNumber &ComplexNumber::setValue(double real, double imaginary) {
    m_real = real;
    m_imaginary = imaginary;
    return *this;
}

ComplexNumber decodeExpressionResult(const ComplexNumber &left, char op, const ComplexNumber &right) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }
    throw invalid_argument("The provided operator couldn't be decoded.");
}

// Arithmetic operators
ComplexNumber ComplexNumber::operator+(const ComplexNumber &number) const {
    return ComplexNumber(m_real + number.m_real, m_imaginary + number.m_imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &number) const {
    return ComplexNumber(m_real - number.m_real, m_imaginary - number.m_imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &number) const {
    auto newReal = m_real * number.m_real - m_imaginary * number.m_imaginary;
    auto newImaginary = m_imaginary * number.m_real + m_real * number.m_imaginary;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &number) const {
    auto denominator = number.m_real * number.m_real + number.m_imaginary + number.m_imaginary;
    if (denominator == 0.0) {
        throw invalid_argument("Can't divide by 0.");
    }

    auto newReal = (m_real * number.m_real + m_imaginary * number.m_imaginary) / denominator;
    auto newImaginary = (m_imaginary * number.m_real - m_real * number.m_imaginary) / denominator;
    return ComplexNumber(newReal, newImaginary);
}

// Stream operators
ostream &operator<<(ostream &out, const ComplexNumber &number) {
    out << number.m_real << (number.m_imaginary >= 0 ? "+" : "") << number.m_imaginary << "i";
    return out;
}

istream &operator>>(istream &in, ComplexNumber &number) {
    char imaginarySign, iLetter;
    // TODO
    in >> number.m_real >> imaginarySign >> number.m_imaginary >> iLetter;
    return in;
}
