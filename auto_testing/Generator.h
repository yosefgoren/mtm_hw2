#ifndef GENERATOR_H
#define GENERATOR_H

#include "Auxiliaries.h"
#include "GeneratorExceptions.h"

template<class ResultType>
class Generator{
public:
    virtual ResultType get() = 0;
};

#endif