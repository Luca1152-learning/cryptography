#include "IntegersModuloNField.h"

#include "../math/MathUtils.h"
#include "../exceptions/NotAFieldException.h"
#include "FiniteField.h"

IntegersModuloNField::IntegersModuloNField(long long int modulus) : m_modulus(modulus) {
    if (not MathUtils::isPrime(modulus)) {
        throw NotAFieldException();
    }
}

string IntegersModuloNField::getName() const {
    return "Integers modulo " + to_string(m_modulus);
}

bool IntegersModuloNField::isIsomorphicTo(BaseMathField *field) const {
    auto *integersModuloNField = dynamic_cast<IntegersModuloNField *>(field);
    if (integersModuloNField and m_modulus == integersModuloNField->getModulus()) {
        return true;
    }

    auto *finiteField = dynamic_cast<FiniteField *>(field);
    if (finiteField and m_modulus == finiteField->getSize()) {
        return true;
    }

    return false;
}

long long IntegersModuloNField::getModulus() const {
    return m_modulus;
}

IntegerModuloNNumber IntegersModuloNField::createNumber() const {
    return IntegerModuloNNumber(m_modulus);
}