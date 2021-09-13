#ifndef INVOCATION_GENERATOR_H
#define INVOCATION_GENERATOR_H

#include "Generator.h"
#include "Invoker.h"
#include "TupleGenerator.h"

template <class ObjectClass, class ResultType, class ...Parameters>
class InvocationGenerator : public Generator<ResultType>, private Invoker<ObjectClass, ResultType, Parameters ...>{
public:
    InvocationGenerator(ObjectClass& object
            , const std::function<ResultType(ObjectClass*, Parameters ...)>& method
            , std::vector<void*> parameter_generator_ptrs)
            :Invoker<ObjectClass, ResultType, Parameters  ...>(object, method)
            , parameters_tuple_generator(parameter_generator_ptrs){}
    
    virtual ResultType get() override{
        return Invoker<ObjectClass, ResultType, Parameters ...>::invoke(parameters_tuple_generator.get());
    }
private:
    TupleGenerator<Parameters ...> parameters_tuple_generator;
};

#endif