#ifndef PTR_ARRAY_H
#define PTR_ARRAY_H

#include <vector>

class PtrArray{
public:
    /**
     * creates a new array, independent of the data within ptr_vec after intialization is over.
     */
    PtrArray(std::vector<void*> ptr_vec);
    /**
     * copy c'tor is 'by reference' meaning that making chnages to the newly created array will affect the old one.
     */
    PtrArray(PtrArray& other);
    ~PtrArray();
    /**
     * returns a 'by reference' copy of the array
     *      , but the first item of the new array is the second one of 'this' array.
     */
    operator std::vector<void*>() const; 
    PtrArray withoutHead();
    void* getHead();
private:    
    PtrArray(void** data, int size);
    
    void** data;
    int size;
    bool is_original_array;
};

#endif