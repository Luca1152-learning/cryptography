#include "FieldEquationsPrompter.h"

void FieldEquationsPrompter::promptForEquations(BaseMathField *field) {
    auto *integersModuloNField = dynamic_cast<IntegersModuloNField *>(field);
    if (integersModuloNField) {
        promptForEquationsInIntegersModuloNField(*integersModuloNField);
    } else {
        auto *rationalField = dynamic_cast<RationalField *>(field);
        if (rationalField) {
            promptForEquationsInRationalField(*rationalField);
        } else {
            auto *realField = dynamic_cast<RealField *>(field);
            if (realField) {
                promptForEquationsInRealField(*realField);
            } else {
                auto *complexField = dynamic_cast<ComplexField *>(field);
                if (complexField) {
                    promptForEquationsInComplexField(*complexField);
                }
            }
        }
    }
}

char FieldEquationsPrompter::promptForOperator() {
    while (true) {
        cout << "Enter the operator (+, -, *, /): ";
        string inputString;
        getline(cin, inputString);
        if (inputString == "+" or inputString == "-" or inputString == "*" or inputString == "/") {
            return (char) inputString[0];
        } else {
            cout << "[!] Please enter a valid operator.\n";
        }
    }
}

void FieldEquationsPrompter::promptForEquationsInIntegersModuloNField(const IntegersModuloNField &field) {
    auto promptForNumberModuloN = [](IntegerModuloNNumber &value) {
        while (true) {
            cout << "Enter the operand: ";
            if (cin >> value) {
                cin.get();
                break;
            } else {
                cout << "[!] Please enter a valid operand.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    };

    IntegerModuloNNumber result = field.createNumber();
    promptForNumberModuloN(result);
    while (true) {
        char op = promptForOperator();
        IntegerModuloNNumber currentNumber = field.createNumber();
        promptForNumberModuloN(currentNumber);
        result = decodeExpressionResult(result, op, currentNumber);
        cout << "Result: " << result << "\n";
    }
}

void FieldEquationsPrompter::promptForEquationsInRationalField(const RationalField &field) {
    auto promptForRationalNumber = [](RationalNumber &value) {
        while (true) {
            cout << "Enter the operand: ";
            if (cin >> value) {
                cin.get();
                break;
            } else {
                cout << "[!] Please enter a valid operand.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    };

    RationalNumber result = field.createNumber();
    promptForRationalNumber(result);
    while (true) {
        char op = promptForOperator();
        RationalNumber currentNumber = field.createNumber();
        promptForRationalNumber(currentNumber);
        result = decodeExpressionResult(result, op, currentNumber);
        cout << "Result: " << result << "\n";
    }
}

void FieldEquationsPrompter::promptForEquationsInRealField(const RealField &field) {
    auto promptForRealNumber = [](RealNumber &value) {
        while (true) {
            cout << "Enter the operand: ";
            if (cin >> value) {
                cin.get();
                break;
            } else {
                cout << "[!] Please enter a valid operand.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    };

    RealNumber result = field.createNumber();
    promptForRealNumber(result);
    while (true) {
        char op = promptForOperator();
        RealNumber currentNumber = field.createNumber();
        promptForRealNumber(currentNumber);
        result = decodeExpressionResult(result, op, currentNumber);
        cout << "Result: " << result << "\n";
    }
}

void FieldEquationsPrompter::promptForEquationsInComplexField(const ComplexField &field) {
    auto promptForComplexNumber = [](ComplexNumber &value) {
        while (true) {
            cout << "Enter the operand: ";
            if (cin >> value) {
                break;
            } else {
                cout << "[!] Please enter a valid operand.\n";
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    };

    ComplexNumber result = field.createNumber();
    promptForComplexNumber(result);
    while (true) {
        char op = promptForOperator();
        ComplexNumber currentNumber = field.createNumber();
        promptForComplexNumber(currentNumber);
        result = decodeExpressionResult(result, op, currentNumber);
        cout << "Result: " << result << "\n";
    }
}