#include "IntegerNumber.h"

IntegerNumber::IntegerNumber(long long int value) : m_value(value) {}

IntegerNumber &IntegerNumber::setValue(long long int value) {
    m_value = value;
    return *this;
}

// Arithmetic operators
IntegerNumber IntegerNumber::operator+(const IntegerNumber &number) const {
    return IntegerNumber(m_value + number.m_value);
}

IntegerNumber IntegerNumber::operator-(const IntegerNumber &number) const {
    return IntegerNumber(m_value - number.m_value);
}

IntegerNumber IntegerNumber::operator*(const IntegerNumber &number) const {
    return IntegerNumber(m_value * number.m_value);
}

IntegerNumber IntegerNumber::operator/(const IntegerNumber &number) const {
    if (number.m_value == 0) {
        throw invalid_argument("Can't divide by 0.");
    }

    return IntegerNumber(m_value / number.m_value);
}


// Stream output operator
std::ostream &operator<<(std::ostream &out, const IntegerNumber &number) {
    out << number.m_value;
    return out;
}