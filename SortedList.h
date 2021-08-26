#ifndef SORTED_LIST
#define SORTED_LIST

#include <functional>

namespace mtm{
    template <class T>
    class SortedList{
    public:
        SortedList();
        ~SortedList();
        SortedList(const SortedList& source);
        SortedList& operator=(const SortedList& source);
        SortedList& insert(const T& new_item);
        SortedList& remove(SortedList::iterator it);
        SortedList filter{std::function<bool(const T&)> predicate);
        template <class R>
        SortedList<R> apply(std::function<R(const T&)> mapper);
        unsigned int length() const;
        iterator begin() const;
        iterator end() const;

        class iterator;
        class const_iterator;
    };
}

#endif