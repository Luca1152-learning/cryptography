#ifndef PROIECT_POO_BASEFIELD_H
#define PROIECT_POO_BASEFIELD_H

#include <stdexcept>
#include <iostream>

using namespace std;

class BaseMathStructure {
public:
    BaseMathStructure(bool canAdd, bool canSubtract, bool canMultiply, bool canDivide);

    // Required for dynamic_cast() to work (there must be at least one virtual function within the class)
    virtual ~BaseMathStructure() = default;

private:
    bool m_canAdd = false, m_canSubtract = false, m_canMultiply = false, m_canDivide = false;
};

#endif //PROIECT_POO_BASEFIELD_H
