#ifndef OOP_INVALIDVIDEOLENGTHEXCEPTION_H
#define OOP_INVALIDVIDEOLENGTHEXCEPTION_H
#include <exception>

class InvalidVideoLengthException :virtual public std::exception{
public:
    static const char* something() noexcept;
};


#endif //OOP_INVALIDVIDEOLENGTHEXCEPTION_H