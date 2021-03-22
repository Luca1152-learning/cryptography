#include "StructureFactory.h"
#include "../math/MathUtils.h"
#include "RealStructure.h"
#include "IntegerStructure.h"
#include "ComplexStructure.h"
#include "NaturalStructure.h"
#include "RationalStructure.h"
#include "IntegerModuloNStructure.h"

BaseMathStructure *StructureFactory::promptStructureCreation() {
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

    bool canAdd = false, canSubtract = false, canMultiply = false, canDivide = false;

    if (setChoice == 3 and MathUtils::isPrime(modulus)) {
        // Integers modulo p (Zp) with p prime
        canAdd = canSubtract = canMultiply = canDivide = true;
        cout << "\nThe most containing mathematical structure for the given set is a FIELD.\n";
        return new IntegerModuloNStructure(modulus, canAdd, canSubtract, canMultiply, canDivide);
    } else if (setChoice == 4) {
        // Rational numbers (Q)
        canAdd = canSubtract = canMultiply = canDivide = true;
        cout << "\nThe most containing mathematical structure for the given set is a FIELD.\n";
        return new RationalStructure(canAdd, canSubtract, canMultiply, canDivide);
    } else if (setChoice == 5) {
        // Real numbers (R)
        canAdd = canSubtract = canMultiply = canDivide = true;
        cout << "\nThe most containing mathematical structure for the given set is a FIELD.\n";
        return new RealStructure(canAdd, canSubtract, canMultiply, canDivide);
    } else if (setChoice == 6) {
        // Complex numbers (C)
        canAdd = canSubtract = canMultiply = canDivide = true;
        cout << "\nThe most containing mathematical structure for the given set is a FIELD.\n";
        return new ComplexStructure(canAdd, canSubtract, canMultiply, canDivide);
    }

    // Pick the operation for all non-field sets
    int operationChoice;
    while (true) {
        cout << "\n"
                "(1) Addition (+)\n"
                "(2) Multiplication (*)\n"
                "Choose the operation (1-2): ";
        if (cin >> operationChoice and operationChoice >= 1 and operationChoice <= 2) {
            break;
        } else {
            cout << "\nPlease enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    if (setChoice == 1) {
        // Natural numbers (N)
        if (operationChoice == 1) {
            // Addition
            canAdd = true;
            cout << "\nThe most containing mathematical structure for the given set is an ADDITIVE MONOID.\n";
        } else if (operationChoice == 2) {
            // Multiplication
            canMultiply = true;
            cout << "\nThe most containing mathematical structure for the given set is a MULTIPLICATIVE MONOID.\n";
        }
        return new NaturalStructure(canAdd, canSubtract, canMultiply, canDivide);
    } else if (setChoice == 2) {
        // Integers (Z)
        if (operationChoice == 1) {
            // Addition
            canAdd = canSubtract = true;
            cout << "\nThe most containing mathematical structure for the given set is an ADDITIVE GROUP.\n";
        } else if (operationChoice == 2) {
            // Multiplication
            canMultiply = true;
            cout << "\nThe most containing mathematical structure for the given set is a MULTIPLICATIVE MONOID.\n";
        }
        return new IntegerStructure(canAdd, canSubtract, canMultiply, canDivide);
    } else if (setChoice == 3) {
        // Integers modulo n (Zn) with n not a prime number
        if (operationChoice == 1) {
            // Addition
            canAdd = canSubtract = true;
            cout << "\nThe most containing mathematical structure for the given set is an ADDITIVE GROUP.\n";
        } else if (operationChoice == 2) {
            // Multiplication
            canMultiply = true;
            cout << "\nThe most containing mathematical structure for the given set is a MULTIPLICATIVE MONOID.\n";
        }
        return new IntegerModuloNStructure(modulus, canAdd, canSubtract, canMultiply, canDivide);
    }

    throw logic_error("This set isn't being handled yet.");
}
