#ifndef INVOKER_H
#define INVOKER_H

#include <functional>
#include <tuple>
#include <vector>

template <class ObjectClass, class ResultType, class ... TupleTypes, class VectorBackType, class ... VectorTypes>
ResultType invokeWith(ObjectClass* obj, 
        std::function<ResultType(ObjectClass*, TupleTypes ..., VectorTypes ...)>& method, 
        std::tuple<TupleTypes ...> converted_parameters, std::vector<void*> unconverted_parameters);

template <class ObjectClass, class ResultType, class ... Parameters>
class Invoker{
public:
    Invoker(ObjectClass& obj, const std::function<ResultType(ObjectClass*, Parameters ...)>& method)
            :obj(obj),method(method){}
    ResultType invoke(Parameters... parameters){
        return method(&obj, parameters...);
    }
    ResultType invoke(std::tuple<Parameters ...> parameters){
        return std::apply(method, std::tuple_cat(std::make_tuple(&obj), parameters));
    }
    ResultType invoke(std::vector<void*> parameter_ptrs){
        return invokeWith<ObjectClass, ResultType, Parameters ...>(&obj, method, std::make_tuple(), parameter_ptrs);
    }

    ObjectClass& obj;
    const std::function<ResultType(ObjectClass*, Parameters ...)>& method;
};

template <class ObjectClass, class ResultType, class ... TupleTypes, class VectorBackType, class ... VectorTypes>
ResultType invokeWith(ObjectClass* obj, 
        std::function<ResultType(ObjectClass*, TupleTypes ..., VectorTypes ...)>& method, 
        std::tuple<TupleTypes ...> converted_parameters, std::vector<void*> unconverted_parameters){
    if(unconverted_parameters.empty()){
        return Invoker(*obj, method).invoke(converted_parameters);
    }
    VectorBackType* first = static_cast<VectorBackType*>(unconverted_parameters.back());
    unconverted_parameters.pop_back();
    return invokeWith(std::tuple_cat(converted_parameters, std::make_tuple(first)), unconverted_parameters);
}   

#endif