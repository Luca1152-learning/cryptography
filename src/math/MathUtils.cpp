#include "MathUtils.h"

bool MathUtils::isPrime(long long int value) {
    if (value <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}
