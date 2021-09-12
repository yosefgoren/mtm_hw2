#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

namespace mtm
{
    class Exception : public std::exception{
    public:
        virtual const char* what() const noexcept override = 0;
    };

    #define CREATE_EXCEPTION(NAME)\
    class NAME : public Exception{\
    public:\
        virtual const char* what() const noexcept override{\
            return (std::string("A game related error has occurred: ")\
                + std::string(#NAME)).c_str();\
        }\
    };
    CREATE_EXCEPTION(IllegalArgument)
    CREATE_EXCEPTION(IllegalCell)
    CREATE_EXCEPTION(CellEmpty)
    CREATE_EXCEPTION(MoveTooFar)
    CREATE_EXCEPTION(CellOccupied)
    CREATE_EXCEPTION(OutOfRange)
    CREATE_EXCEPTION(OutOfAmmo)
    CREATE_EXCEPTION(IllegalTarget)
}

#endif