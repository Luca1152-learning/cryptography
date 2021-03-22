#include "structure/StructureFactory.h"
#include "structure/ComplexStructure.h"
#include <iostream>

using namespace std;

int main() {
    auto structure = StructureFactory::promptStructureCreation();
    auto *complexStructure = dynamic_cast<ComplexStructure *>(structure);
    if (complexStructure) {
        auto complexNumber = complexStructure->createNumber().setValue(2.3, 7);
        cout << complexNumber;
    }
}