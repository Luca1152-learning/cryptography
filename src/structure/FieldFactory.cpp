#include "FieldFactory.h"
#include "../math/MathUtils.h"
#include "RealField.h"
#include "ComplexField.h"
#include "RationalField.h"
#include "IntegersModuloNField.h"

// Custom exceptions
NotAFieldException::NotAFieldException() : runtime_error("The given structure is not a field.") {}

const char *NotAFieldException::what() const _NOEXCEPT {
    return "The given structure is not a field.";
}

// FieldFactory actual code
BaseMathField *FieldFactory::promptFieldCreation() {
    int setChoice;
    while (true) {
        cout << "(1) Natural numbers\n"
                "(2) Integers\n"
                "(3) Integers modulo n\n"
                "(4) Rational numbers\n"
                "(5) Real numbers\n"
                "(6) Complex numbers\n"
                "Choose the set (1-6): ";
        if (cin >> setChoice and setChoice >= 1 and setChoice <= 6) {
            break;
        } else {
            cout << "\nPlease enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    // Prompt for the modulus value for the integers modulo n (Zn)
    long long modulus;
    if (setChoice == 3) {
        while (true) {
            cout << "\n"
                    "Choose the modulus (>1): ";
            if (cin >> modulus and modulus > 1) {
                break;
            } else {
                cout << "\nPlease enter a valid modulus.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    }

    if (setChoice == 3 and MathUtils::isPrime(modulus)) {
        // Integers modulo p (Zp) with p prime
        return new IntegersModuloNField(modulus);
    } else if (setChoice == 4) {
        // Rational numbers (Q)
        return new RationalField();
    } else if (setChoice == 5) {
        // Real numbers (R)
        return new RealField();
    } else if (setChoice == 6) {
        // Complex numbers (C)
        return new ComplexField();
    }

    throw NotAFieldException();
}

