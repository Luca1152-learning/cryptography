#include "IntegersModuloNField.h"

IntegersModuloNField::IntegersModuloNField(long long int n) : m_n(n) {}

IntegerModuloNNumber IntegersModuloNField::createNumber() const {
    return IntegerModuloNNumber(m_n);
}
