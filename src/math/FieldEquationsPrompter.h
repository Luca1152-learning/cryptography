#ifndef CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H
#define CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H

#include <iostream>
#include "../field/BaseMathField.h"
#include "../field/RealField.h"
#include "../field/ComplexField.h"
#include "../field/RationalField.h"
#include "../field/IntegersModuloNField.h"

using namespace std;

class FieldEquationsPrompter {
public:
    static void promptForEquations(BaseMathField *field);

private:
    static char promptForOperator();

    [[noreturn]] static void promptForEquationsInIntegersModuloNField(const IntegersModuloNField &field);

    [[noreturn]] static void promptForEquationsInRationalField(const RationalField &field);

    [[noreturn]] static void promptForEquationsInRealField(const RealField &field);

    [[noreturn]] static void promptForEquationsInComplexField(const ComplexField &field);
};

#endif //CRYPTOGRAPHY_FIELDEQUATIONSPROMPTER_H