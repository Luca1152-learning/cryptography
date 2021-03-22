#ifndef PROIECT_POO_BASEFIELD_H
#define PROIECT_POO_BASEFIELD_H

#include <stdexcept>
#include <iostream>

using namespace std;

class BaseMathField {
public:
    // Required for dynamic_cast() to work (there must be at least one virtual function within the class)
    virtual ~BaseMathField() = default;
};

#endif //PROIECT_POO_BASEFIELD_H
