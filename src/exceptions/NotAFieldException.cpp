#include "NotAFieldException.h"

NotAFieldException::NotAFieldException() : runtime_error("The given structure is not a field.") {}

const char *NotAFieldException::what() const _NOEXCEPT {
    return "The given structure is not a field.";
}
