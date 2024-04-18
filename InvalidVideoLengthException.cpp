#include "InvalidVideoLengthException.h"

const char *InvalidVideoLengthException::what() const noexcept {
    return "Invalid video length. Please provide a positive number.";
}
