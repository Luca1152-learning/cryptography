#include "IntegerModuloNNumber.h"
#include "../exceptions/IncompatibleFieldsException.h"
#include <iostream>

IntegerModuloNNumber::IntegerModuloNNumber(long long int modulus, long long int value) :
        m_modulus(modulus), m_value(value) {}

IntegerModuloNNumber &IntegerModuloNNumber::setValue(double value) {
    m_value = value;
    return *this;
}

IntegerModuloNNumber decodeExpressionResult(
        const IntegerModuloNNumber &left, char op, const IntegerModuloNNumber &right
) {
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
IntegerModuloNNumber IntegerModuloNNumber::operator+(const IntegerModuloNNumber &number) const {
    if (m_modulus != number.m_modulus) {
        throw IncompatibleFieldsException();
    }

    return IntegerModuloNNumber(m_modulus, (m_value + number.m_value) % m_modulus);
}

IntegerModuloNNumber IntegerModuloNNumber::operator-(const IntegerModuloNNumber &number) const {
    if (m_modulus != number.m_modulus) {
        throw IncompatibleFieldsException();
    }

    int newValue = m_value - number.m_value;
    if (newValue < 0) {
        newValue += m_modulus;
    }
    return IntegerModuloNNumber(m_modulus, newValue % m_modulus);
}

IntegerModuloNNumber IntegerModuloNNumber::operator*(const IntegerModuloNNumber &number) const {
    if (m_modulus != number.m_modulus) {
        throw IncompatibleFieldsException();
    }

    return IntegerModuloNNumber(m_modulus, (m_value * number.m_value) % m_modulus);
}

IntegerModuloNNumber IntegerModuloNNumber::operator/(const IntegerModuloNNumber &number) const {
    if (m_modulus != number.m_modulus) {
        throw IncompatibleFieldsException();
    }
    if (number.m_value == 0) {
        throw invalid_argument("Can't divide by 0.");
    }

    for (long long inverse = 0; inverse < m_modulus; inverse++) {
        if ((inverse * number.m_value) % m_modulus == m_value) {
            return IntegerModuloNNumber(m_modulus, inverse);
        }
    }
    throw runtime_error("Unexpected. An inverse should have been found.");
}

bool IntegerModuloNNumber::operator==(const IntegerModuloNNumber &number) const {
    if (m_modulus != number.m_modulus) {
        throw IncompatibleFieldsException();
    }

    return m_value == number.m_value;
}

bool IntegerModuloNNumber::operator!=(const IntegerModuloNNumber &number) const {
    return !(number == *this);
}

// Stream operators
ostream &operator<<(ostream &out, const IntegerModuloNNumber &number) {
    out << number.m_value << " (mod " << number.m_modulus << ")";
    return out;
}

istream &operator>>(istream &in, IntegerModuloNNumber &number) {
    in >> number.m_value;
    if (number.m_value < 0 or number.m_value >= number.m_modulus) {
        // Set so the 'if (cin >> moduloNNumber)' fails
        in.setstate(std::ios::failbit);
    }
    return in;
}