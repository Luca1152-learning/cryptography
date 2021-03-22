#include "structure/FieldFactory.h"
#include "structure/ComplexField.h"
#include <iostream>

using namespace std;

BaseMathField *getInputField() {
    cout << "Choose the field you want to create.\n\n";
    return FieldFactory::promptFieldCreation();
}

int main() {
    auto field = getInputField();
    auto *complexField = dynamic_cast<ComplexField *>(field);
    if (complexField) {
        auto complexNumber = complexField->createNumber().setValue(2.3, 7);
        cout << complexNumber;
    }
    delete field;
}