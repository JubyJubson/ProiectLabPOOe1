#ifndef OOP_INVALIDSPONSORNAMEEXCEPTION_H
#define OOP_INVALIDSPONSORNAMEEXCEPTION_H
#include <exception>
class InvalidSponsorNameException :virtual public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};
#endif //OOP_INVALIDSPONSORNAMEEXCEPTION_H
