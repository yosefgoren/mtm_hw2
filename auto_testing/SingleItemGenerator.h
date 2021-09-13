#ifndef SINGLE_ITEM_GENERATOR_H
#define SINGLE_ITEM_GENERATOR_H

#include "Generator.h"
#include <string>

/**
 * The template class always expects 'ResultType' to implement the following:
 *      ResultType(const ResultType&)
 * 
 * Some of the methods of SingleItemGenerator require further implementations.
 */
template <class ResultType>
class SingleItemGenerator : public Generator<ResultType>{
public:
    /**
     * Using this c'tor will require 'ResultType()' to be defined.
     * A generator created by this c'tor will return instances of 'ResultType()'.
     */
    SingleItemGenerator():instance_source(ResultType()){}
    /**
     * A generator created by this c'tor will result instances copied from 'source'.
     */
    SingleItemGenerator(const ResultType& source):instance_source(source){}

    virtual ResultType get() override{
        return instance_source;
    }
private:
    const ResultType instance_source;
};

#endif