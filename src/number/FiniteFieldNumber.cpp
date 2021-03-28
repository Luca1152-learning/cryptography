#include "FiniteFieldNumber.h"
#include "../exceptions/IncompatibleFieldsException.h"
#include "../field/FiniteField.h"

FiniteFieldNumber::FiniteFieldNumber(FiniteField *field, double value) {
    m_field = field;
    m_value = value;
}

FiniteFieldNumber &FiniteFieldNumber::setValue(double value) {
    m_value = value;
    return *this;
}

FiniteFieldNumber decodeExpressionResult(const FiniteFieldNumber &left, char op, const FiniteFieldNumber &right) {
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
FiniteFieldNumber FiniteFieldNumber::operator+(const FiniteFieldNumber &number) const {
    if (m_field != number.m_field) {
        throw IncompatibleFieldsException();
    }

    double newValue = m_field->getAdditionMappings()[m_field->getIndexInSet(m_value)][m_field->getIndexInSet(
            number.m_value)];
    return FiniteFieldNumber(m_field, newValue);
}

FiniteFieldNumber FiniteFieldNumber::operator-(const FiniteFieldNumber &number) const {
    if (m_field != number.m_field) {
        throw IncompatibleFieldsException();
    }

    int numberIndexInSet = m_field->getIndexInSet(number.m_value);
    for (int i = 0; i < m_field->getSize(); i++) {
        if (m_field->getAdditionMappings()[numberIndexInSet][i] == m_value) {
            return FiniteFieldNumber(m_field, m_field->getSet()[i]);
        }
    }
    throw runtime_error("Unexpected. An inverse should have been found.");
}

FiniteFieldNumber FiniteFieldNumber::operator*(const FiniteFieldNumber &number) const {
    if (m_field != number.m_field) {
        throw IncompatibleFieldsException();
    }

    double newValue = m_field->getAdditionMappings()[m_field->getIndexInSet(m_value)][m_field->getIndexInSet(
            number.m_value)];
    return FiniteFieldNumber(m_field, newValue);
}

FiniteFieldNumber FiniteFieldNumber::operator/(const FiniteFieldNumber &number) const {
    if (m_field != number.m_field) {
        throw IncompatibleFieldsException();
    }
    if (abs(number.m_value - 0.0) <= 1e-6) {
        throw invalid_argument("Can't divide by 0.");
    }

    int numberIndexInSet = m_field->getIndexInSet(number.m_value);
    for (int i = 0; i < m_field->getSize(); i++) {
        if (m_field->getMultiplicationMappings()[numberIndexInSet][i] == m_value) {
            return FiniteFieldNumber(m_field, m_field->getSet()[i]);
        }
    }
    throw runtime_error("Unexpected. An inverse should have been found.");
}

bool FiniteFieldNumber::operator==(const FiniteFieldNumber &number) const {
    if (m_field != number.m_field) {
        throw IncompatibleFieldsException();
    }

    return m_value == number.m_value;
}

bool FiniteFieldNumber::operator!=(const FiniteFieldNumber &number) const {
    return !(number == *this);
}

// Stream operators
ostream &operator<<(ostream &out, const FiniteFieldNumber &number) {
    out << number.m_value;
    return out;
}

istream &operator>>(istream &in, FiniteFieldNumber &number) {
    in >> number.m_value;
    if (number.m_field->getIndexInSet(number.m_value) == -1) {
        // Set so the 'if (cin >> finiteFieldNumber)' fails
        in.setstate(std::ios::failbit);
    }
    return in;
}