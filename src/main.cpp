#include "math/FieldEquationsPrompter.h"
#include "math/FieldFactory.h"
#include <iostream>

int main() {
    cout << "Choose the field you want to create.\n\n";
    auto field = FieldFactory::promptFieldCreation();
    cout << "\nField successfully created! Now you can perform mathematical operations on it.\n\n";
    FieldEquationsPrompter::promptForEquations(field);
    delete field;
}