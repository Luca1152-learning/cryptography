#include "RealNumber.h"

RealNumber::RealNumber(double value) : m_value(value) {}

RealNumber &RealNumber::setValue(double value) {
    m_value = value;
    return *this;
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


// Stream output operator
ostream &operator<<(ostream &out, const RealNumber &number) {
    out << number.m_value;
    return out;
}