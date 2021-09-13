#ifndef GROUP_COMPARISON_GENERATOR_H
#define GROUP_COMPARISON_GENERATOR_H

#include <memory>
#include "Generator.h"
#include "InvocationGenerator.h"
#include "PtrArray.h"
#include "IntRangeGenerator.h"

template<int SizeOfGroup>
class GenericGroupComparisonGenerator : public Generator<bool>{
public:
    GenericGroupComparisonGenerator(PtrArray first_generator_set, PtrArray second_generator_set
            , Generator<int>* index_generator// = nullptr 
            , bool compare_stdout = false, bool compare_stderr = false)
            :first_generator_set(first_generator_set)
            ,second_generator_set(second_generator_set)
            ,index_generator(index_generator)
            ,compare_stdout_sel(compare_stdout)
            ,compare_stderr_sel(compare_stderr){
        // if(index_generator == nullptr){
        //     index_generator = new IntRangeGenearator(0, SizeOfGroup);
        // }
    }

    virtual bool get() override{
        int comparison_index = index_generator->get();
        return compareResultsForIndex(comparison_index);
    }

    virtual bool compareResultsForIndex(int index) = 0;

    PtrArray first_generator_set;
    PtrArray second_generator_set;
    Generator<int>* index_generator;
    bool compare_stdout_sel;
    bool compare_stderr_sel;

    // static void* constexpr USE_DEFAULT_INDEX_GENERATOR = nullptr;
    // static void* constexpr INDEX_GENERATOR_NOT_REQUIRED = nullptr;
};

template <class ... ResultTypes>
class GroupComparisonGenerator : public GenericGroupComparisonGenerator<sizeof...(ResultTypes)>{
public:
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)>::GenericGroupComparisonGenerator;
    virtual bool compareResultsForIndex(int index) override;
};

template <class FirstItemType, class ... ResultTypes>
class GroupComparisonGenerator<FirstItemType, ResultTypes ...> 
        : public GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>{
public:
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::GenericGroupComparisonGenerator;
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::first_generator_set;
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::second_generator_set;
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::index_generator;
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::compare_stdout_sel;
    using GenericGroupComparisonGenerator<sizeof...(ResultTypes)+1>::compare_stderr_sel;

    virtual bool compareResultsForIndex(int index) override{
        if(index == 0){
            auto first_generator =  static_cast<Generator<FirstItemType>*>(first_generator_set.getHead());
            auto second_generator =  static_cast<Generator<FirstItemType>*>(second_generator_set.getHead());
            return first_generator->get() == second_generator->get();
        }
        return GroupComparisonGenerator<ResultTypes ...>(first_generator_set.withoutHead()
            , second_generator_set.withoutHead()
            , index_generator
            , compare_stdout_sel
            , compare_stderr_sel).compareResultsForIndex(index-1);
    }
};

template <>
class GroupComparisonGenerator<> : public GenericGroupComparisonGenerator<0>{
public:
    using GenericGroupComparisonGenerator<0>::GenericGroupComparisonGenerator;
    virtual bool compareResultsForIndex(int index) override{
        throw IndexOutOfRange();
    }
};

#endif