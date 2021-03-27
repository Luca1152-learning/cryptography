#include "IntegersModuloNField.h"

#include "../math/MathUtils.h"
#include "../exceptions/NotAFieldException.h"

IntegersModuloNField::IntegersModuloNField(long long int modulus) : m_modulus(modulus) {
    if (not MathUtils::isPrime(modulus)) {
        throw NotAFieldException();
    }
}

long long IntegersModuloNField::getModulus() {
    return m_modulus;
}

IntegerModuloNNumber IntegersModuloNField::createNumber() const {
    return IntegerModuloNNumber(m_modulus);
}