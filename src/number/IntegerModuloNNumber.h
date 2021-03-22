#ifndef CRIPTOGRAPHY_INTEGERMODULONNUMBER_H
#define CRIPTOGRAPHY_INTEGERMODULONNUMBER_H

#include "BaseNumber.h"

using namespace std;

class IntegerModuloNNumber : BaseNumber {
public:
    explicit IntegerModuloNNumber(long long n, long long value = 0);

private:
    long long m_n, m_value;
};

#endif //CRIPTOGRAPHY_INTEGERMODULONNUMBER_H
