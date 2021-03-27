#ifndef CRYPTOGRAPHY_NOTAFIELDEXCEPTION_H
#define CRYPTOGRAPHY_NOTAFIELDEXCEPTION_H

#include <iostream>

using namespace std;

class NotAFieldException : public runtime_error {
public:
    NotAFieldException();

    const char *what() const _NOEXCEPT override;
};

#endif //CRYPTOGRAPHY_NOTAFIELDEXCEPTION_H
