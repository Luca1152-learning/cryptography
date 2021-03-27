#include "IntegersModuloNField.h"

#include "../math/MathUtils.h"
#include "../exceptions/NotAFieldException.h"

IntegersModuloNField::IntegersModuloNField(long long int modulus) : m_modulus(modulus) {
    if (not MathUtils::isPrime(modulus)) {
        throw NotAFieldException();
    }
}

string IntegersModuloNField::getName() const {
    return "Integers modulo " + to_string(m_modulus);
}

long long IntegersModuloNField::getModulus() const {
    return m_modulus;
}

IntegerModuloNNumber IntegersModuloNField::createNumber() const {
    return IntegerModuloNNumber(m_modulus);
}