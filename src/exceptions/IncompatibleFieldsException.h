#ifndef CRYPTOGRAPHY_INCOMPATIBLEFIELDSEXCEPTION_H
#define CRYPTOGRAPHY_INCOMPATIBLEFIELDSEXCEPTION_H

#include <iostream>

using namespace std;

class IncompatibleFieldsException : public runtime_error {
public:
    IncompatibleFieldsException();

    const char *what() const _NOEXCEPT override;
};

#endif //CRYPTOGRAPHY_INCOMPATIBLEFIELDSEXCEPTION_H
