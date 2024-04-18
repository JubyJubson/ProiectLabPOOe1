#include "InvalidSponsorNameException.h"

const char *InvalidSponsorNameException::what() const noexcept {
    return "Invalid sponsor name. Please provide a non-empty name.";
}