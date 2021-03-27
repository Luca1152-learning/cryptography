#ifndef CRYPTOGRAPHY_MAINLOOP_H
#define CRYPTOGRAPHY_MAINLOOP_H

#include <iostream>
#include <vector>
#include "field/BaseMathField.h"
#include "field/ComplexField.h"
#include "math/FieldEquationsPrompter.h"
#include "math/FieldFactory.h"
#include "exceptions/NotAFieldException.h"

using namespace std;

class MainLoop {
public:
    void run();

    ~MainLoop();

private:
    // Pointers array
    vector<BaseMathField *> m_fields;

    bool promptCommand();

    void listAllFields(string headerText = "", bool extraNewLineAtTheEnd = false) const;

    void promptFieldCreation();

    void promptMathOperations() const;
};

#endif //CRYPTOGRAPHY_MAINLOOP_H
