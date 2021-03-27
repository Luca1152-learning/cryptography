#include "RealNumber.h"
#include <iostream>

RealNumber::RealNumber(double value) : m_value(value) {}

RealNumber &RealNumber::setValue(double value) {
    m_value = value;
    return *this;
}

RealNumber decodeExpressionResult(const RealNumber &left, char op, const RealNumber &right) {
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
RealNumber RealNumber::operator+(const RealNumber &number) const {
    return RealNumber(m_value + number.m_value);
}

RealNumber RealNumber::operator-(const RealNumber &number) const {
    return RealNumber(m_value - number.m_value);
}

RealNumber RealNumber::operator*(const RealNumber &number) const {
    return RealNumber(m_value * number.m_value);
}

RealNumber RealNumber::operator/(const RealNumber &number) const {
    if (number.m_value == 0.0) {
        throw invalid_argument("Can't divide by 0.");
    }

    return RealNumber(m_value / number.m_value);
}

// Stream operators
ostream &operator<<(ostream &out, const RealNumber &number) {
    out << number.m_value;
    return out;
}

istream &operator>>(istream &in, RealNumber &number) {
    in >> number.m_value;
    return in;
}