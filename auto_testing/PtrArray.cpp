#include "PtrArray.h"

PtrArray::PtrArray(std::vector<void*> ptr_vec) 
        :data(new void*[ptr_vec.size()]), size(ptr_vec.size()), is_original_array(true){
    int index = 0;
    for(void* item : ptr_vec){
        data[index++] = item; 
    }
}
PtrArray::PtrArray(PtrArray& other):data(other.data), size(other.size), is_original_array(false){}
PtrArray::~PtrArray(){
    if(is_original_array){
        delete[] data;
    }
}


PtrArray::operator std::vector<void*>() const{
    std::vector<void*> result = {};
    for(int i = size-1; i >= 0; i--){
        result.push_back(data[i]);
    }
    return result;
}

PtrArray PtrArray::withoutHead(){
    return PtrArray(data+1, size-1);
}
void* PtrArray::getHead(){
    return data[0];
}

PtrArray::PtrArray(void** data, int size):data(data), size(size), is_original_array(false){}