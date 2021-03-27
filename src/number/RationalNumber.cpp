#include "RationalNumber.h"
#include <iostream>

RationalNumber::RationalNumber(double value) : m_value(value) {}

RationalNumber &RationalNumber::setValue(double value) {
    m_value = value;
    return *this;
}

RationalNumber decodeExpressionResult(const RationalNumber &left, char op, const RationalNumber &right) {
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
RationalNumber RationalNumber::operator+(const RationalNumber &number) const {
    return RationalNumber(m_value + number.m_value);
}

RationalNumber RationalNumber::operator-(const RationalNumber &number) const {
    return RationalNumber(m_value - number.m_value);
}

RationalNumber RationalNumber::operator*(const RationalNumber &number) const {
    return RationalNumber(m_value * number.m_value);
}

RationalNumber RationalNumber::operator/(const RationalNumber &number) const {
    if (number.m_value == 0.0) {
        throw invalid_argument("Can't divide by 0.");
    }

    return RationalNumber(m_value / number.m_value);
}

bool RationalNumber::operator==(const RationalNumber &number) const {
    return m_value == number.m_value;
}

bool RationalNumber::operator!=(const RationalNumber &number) const {
    return !(number == *this);
}

// Stream operators
ostream &operator<<(ostream &out, const RationalNumber &number) {
    out << number.m_value;
    return out;
}

istream &operator>>(istream &in, RationalNumber &number) {
    in >> number.m_value;
    return in;
}