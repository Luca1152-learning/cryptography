#include "IncompatibleFieldsException.h"

IncompatibleFieldsException::IncompatibleFieldsException() :
        runtime_error("A mathematical operation was attempted between two numbers from incompatible fields.") {}

const char *IncompatibleFieldsException::what() const _NOEXCEPT {
    return "A mathematical operation was attempted between two numbers from incompatible fields.";
}