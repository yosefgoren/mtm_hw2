#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

namespace mtm
{
    class Exception : public std::exception{
    public:
        virtual const char* what() const noexcept override{
            return (std::string("A game related error has occurred: ") + exception_name).c_str();   
        }
    private:
        const std::string exception_name = "Exception";
    };
    class IllegalArgument : public Exception{
    private:
        const std::string exception_name = "IllegalArgument";
    }; 
    class IllegalCell : public Exception{
    private:
        const std::string exception_name = "IllegalCell";
    }; 
    class CellEmpty : public Exception{
    private:
        const std::string exception_name = "CellEmpty";
    }; 
    class MoveTooFar : public Exception{
    private:
        const std::string exception_name = "MoveTooFar";
    }; 
    class CellOccupied : public Exception{
    private:
        const std::string exception_name = "CellOccupied";
    }; 
    class OutOfRange : public Exception{
    private:
        const std::string exception_name = "OutOfRange";
    }; 
    class OutOfAmmo : public Exception{
    private:
        const std::string exception_name = "OutOfAmmo";
    }; 
    class IllegalTarget : public Exception{
    private:
        const std::string exception_name = "IllegalTarget";
    }; 
}

#endif