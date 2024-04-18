#ifndef OOP_INVALIDVIDEOLENGTHEXCEPTION_H
#define OOP_INVALIDVIDEOLENGTHEXCEPTION_H
#include <exception>
 class InvalidVideoLengthException :virtual public std::exception{
 public:
     [[nodiscard]] const char *what() const noexcept override;
 };


#endif //OOP_INVALIDVIDEOLENGTHEXCEPTION_H
