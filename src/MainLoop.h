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
    MainLoop();

    MainLoop(const MainLoop &mainLoop);

    MainLoop &operator=(const MainLoop &mainLoop);

    void run();

    ~MainLoop();

private:
    // Pointers array
    vector<BaseMathField *> m_fields;

    void copyMainLoop(const MainLoop &mainLoop);

    void deallocateSpace();

    bool promptCommand();

    void listAllFields(string headerText = "", bool extraNewLineAtTheEnd = false) const;

    void promptFieldCreation();

    void promptMathOperations() const;

    void promptFieldIsomorphism() const;
};

#endif //CRYPTOGRAPHY_MAINLOOP_H
