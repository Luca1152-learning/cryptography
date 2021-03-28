#ifndef CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H
#define CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H

#include <iostream>
#include "../field/BaseMathField.h"
#include "../field/RealField.h"
#include "../field/ComplexField.h"
#include "../field/RationalField.h"
#include "../field/IntegersModuloNField.h"
#include "../field/FiniteField.h"

using namespace std;

class FieldEquationsPrompter {
public:
    static void promptForEquations(BaseMathField *field);

private:
    static char promptForOperator();

    static void promptForEquationsInFiniteField(FiniteField &field);

    static void promptForEquationsInIntegersModuloNField(const IntegersModuloNField &field);

    static void promptForEquationsInRationalField(const RationalField &field);

    static void promptForEquationsInRealField(const RealField &field);

    static void promptForEquationsInComplexField(const ComplexField &field);
};

#endif //CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H