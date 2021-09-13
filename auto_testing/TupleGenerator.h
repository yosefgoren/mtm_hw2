#ifndef TUPLE_GENERATOR_H
#define TUPLE_GENERATOR_H

#include "Generator.h"
#include "PtrArray.h"
#include <tuple>
#include <vector>

class GenericTupleGenerator{
public:
    GenericTupleGenerator(std::vector<void*> item_generators):item_generators(item_generators){}
    GenericTupleGenerator(PtrArray item_generators):item_generators(item_generators){}
    PtrArray item_generators;
};

template <class ... ItemTypes>
class TupleGenerator : public Generator<std::tuple<ItemTypes ...>>, public GenericTupleGenerator{
public:
    virtual std::tuple<ItemTypes ...> get() override;
};

template <class FirstItemType, class ... ItemTypes>
class TupleGenerator<FirstItemType, ItemTypes ...> 
        : public Generator<std::tuple<FirstItemType, ItemTypes ...>>, public GenericTupleGenerator{
public:
    using GenericTupleGenerator::GenericTupleGenerator;
    virtual std::tuple<FirstItemType, ItemTypes ...> get() override{
        Generator<FirstItemType>* generator = static_cast<Generator<FirstItemType>*>(item_generators.getHead());
        std::tuple<FirstItemType> head = std::make_tuple(generator->get());
        std::tuple<ItemTypes ...> tail = TupleGenerator<ItemTypes ...>(item_generators.withoutHead()).get();
        return std::tuple_cat(head, tail);
    }
};

template <>
class TupleGenerator<> : public Generator<std::tuple<>>, public GenericTupleGenerator{
public:
    using GenericTupleGenerator::GenericTupleGenerator;
    virtual std::tuple<> get() override{
        return std::make_tuple();
    }
};

#endif