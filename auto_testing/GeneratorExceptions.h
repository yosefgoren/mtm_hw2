#ifndef GENERATOR_EXCEPTIONS_H
#define GENERATOR_EXCEPTIONS_H

#include <exception>
#include <string>

class GeneatorException : public std::exception{
public:
    GeneatorException():exception(){}
    GeneatorException(const std::string& msg):msg(msg){}
    virtual const char* what() const noexcept override{
        return msg.c_str();
    }
private:
    std::string msg;
};

class IncorrectProbabilitySum : public GeneatorException{
public:
    IncorrectProbabilitySum():GeneatorException(){}
    IncorrectProbabilitySum(const std::string& msg):GeneatorException(msg){}
};
class InternalError : public GeneatorException{
public:
    InternalError():GeneatorException(){}
    InternalError(const std::string& msg):GeneatorException(msg){}
};
class IndexOutOfRange : public GeneatorException{};
class MethodNotFound : public GeneatorException{};


#endif