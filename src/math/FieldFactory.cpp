#include "FieldFactory.h"
#include "MathUtils.h"
#include "../field/RealField.h"
#include "../field/ComplexField.h"
#include "../field/RationalField.h"
#include "../field/IntegersModuloNField.h"
#include "../exceptions/NotAFieldException.h"
#include "../field/FiniteField.h"

BaseMathField *FieldFactory::promptFieldCreation() {
    int setChoice;
    while (true) {
        cout << "(1) Finite set\n"
                "(2) Integers modulo n\n"
                "(3) Rational numbers\n"
                "(4) Real numbers\n"
                "(5) Complex numbers\n"
                "(6) Exit\n"
                "Choose the set (1-6): ";
        if (cin >> setChoice and setChoice >= 1 and setChoice <= 6) {
            break;
        } else {
            cout << "\n[!] Please enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    // Prompt for the modulus value for the integers modulo n (Zn)
    long long modulus;
    if (setChoice == 2) {
        while (true) {
            cout << "\nChoose the modulus (>1): ";
            if (cin >> modulus and modulus > 1) {
                break;
            } else {
                cout << "\n[!] Please enter a valid modulus.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    }

    if (setChoice == 1) {
        auto field = new FiniteField();
        field->promptCreation();
        return field;
    } else if (setChoice == 2 and MathUtils::isPrime(modulus)) {
        // Integers modulo p (Zp) with p prime
        return new IntegersModuloNField(modulus);
    } else if (setChoice == 3) {
        // Rational numbers (Q)
        return new RationalField();
    } else if (setChoice == 4) {
        // Real numbers (R)
        return new RealField();
    } else if (setChoice == 5) {
        // Complex numbers (C)
        return new ComplexField();
    } else if (setChoice == 6) {
        cout << "\n";
        return nullptr;
    }

    throw NotAFieldException();
}

