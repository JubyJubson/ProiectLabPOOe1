#ifndef OOP_INVALISPONSORNAMEEXCEPTION_H
#define OOP_INVALISPONSORNAMEEXCEPTION_H

#include <exception>
class InvalidSponsorNameException :virtual public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};
#endif //OOP_INVALISPONSORNAMEEXCEPTION_H
