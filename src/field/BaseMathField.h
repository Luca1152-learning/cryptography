#ifndef PROIECT_POO_BASEFIELD_H
#define PROIECT_POO_BASEFIELD_H

#include <stdexcept>
#include <iostream>

using namespace std;

class BaseMathField {
public:
    virtual string getName() const = 0;

    virtual ~BaseMathField() = default;
};

#endif //PROIECT_POO_BASEFIELD_H
