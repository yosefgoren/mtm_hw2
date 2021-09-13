#ifndef PARAMETER_GENRATOR_H
#define PARAMETER_GENRATOR_H

#include "Generator.h"
#include "GeneratorExceptions.h"
#include <string>
#include <vector>
#include <utility>
#include <map>

template <class ResultType>
class DiscreteGenerator : public Generator<ResultType>{
public:
    /** for every item in 'result_options' 
     *      the generator will produce 'item.first' with probability 'item.second'.
     * @throw 'IncorrectProbabilitySum' if the sum of probabilities in the parameter is not 1. 
     */
    DiscreteGenerator(std::vector<std::pair<ResultType, double>> results_and_probabilities)
            :results_and_probabilities(results_and_probabilities){
        double sum = 0.0;
        for(auto pair : results_and_probabilities){
            sum += pair.second;
        }
        if(!closeToOne(sum)){
            throw IncorrectProbabilitySum("The sum of probobilities must be 1.");
        }
    }
    DiscreteGenerator(const std::map<ResultType, double>& result_probability_map){
        for(const std::pair<ResultType, double>& pair : result_probability_map){
            results_and_probabilities.push_back(pair);
        }
    }
    
    /** for every item in 'result_options' 
     *      the generator will produce 'item' with probability '1/result_options.size()'.
     * @throw 'IncorrectProbabilitySum' the parameter is empty.
     */
    DiscreteGenerator(std::vector<ResultType> result_options){
        if(result_options.size() == 0){
            throw IncorrectProbabilitySum("'result_options' must not be empty.");
        }
        double single_probability = 1.0/double(result_options.size());
        for(auto result : result_options){
            results_and_probabilities.push_back(std::pair<ResultType, double>(result, single_probability));
        }
    }

    virtual ResultType get() override{
        double probability_sum = 0;
        double random_num = getRandomUniform();
        for(auto pair : results_and_probabilities){
            probability_sum += pair.second;
            if(probability_sum >= random_num){
                return pair.first;
            }
        }
        throw InternalError("The sum of probabilities stored within 'results_and_probabilities' is "
                + std::to_string(probability_sum) + " and must should be close to 1.");
    }
    
private:
    std::vector<std::pair<ResultType, double>> results_and_probabilities;
};

#endif