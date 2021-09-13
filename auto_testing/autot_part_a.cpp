#include "GroupComparisonGenerator.h"
#include "InvocationGenerator.h"
#include "DiscreteGenerator.h"
#include "SingleItemGenerator.h"
#include <iostream>

#include "../part_a/SortedList.h"
#include <functional>

using namespace std;
using namespace mtm;

typedef SortedList<int> List;
typedef function<int(bool)> ListFilter;

int main(){
    List list;
    
    InvocationGenerator<List, int> length_invoker(list, List::length, {});

    // ListFilter is_above_5([](int num) -> int { return num > 5;});
    // SingleItemGenerator<ListFilter> filter_generator(is_above_5);
    // vector<void*> filter_invoker_generator_vector = {&filter_generator};
    // InvocationGenerator<List, List, ListFilter> 
    //         filter_invoker(list, List::filter<ListFilter>, filter_invoker_generator_vector);
    
    vector<void*> invocation_generator_vector = {&length_invoker};
    DiscreteGenerator<int> index_generator(std::vector<int>({0}));
    PtrArray p(invocation_generator_vector);

    GroupComparisonGenerator<int> comperator(p, p ,&index_generator);
    cout << comperator.get() << endl;

    cout << "finished autot part a" << endl;
}