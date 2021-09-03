#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<assert.h>
#include <functional>


template<class T>
class SortedList;


    template<class T>
    class List{  //Internal Class
        private:
        T data;
        List* next;
        List* prev;
        friend class SortedList<T>;
        
        public:
        List();
        ~List() = default ;//need to build custom destructor 

        /** Getters/Setters */
        T    getData() const;
        List* getNext() const;
        List* getPrev() const;
        void setData(const T& input); 
        void setNext(List* input);
        void setPrev(List* input);
    };

    template<class T>
    List<T>::List() : data(*(new T())), next(NULL), prev(NULL) {}



    /**===Getters===*/
    template<class T>
    T List<T>::getData() const{
        return data;
    }
    template<class T>
    List<T>* List<T>::getNext() const{
        return this->next;
    }
    template<class T>
    List<T>* List<T>::getPrev() const{
        return this->prev;
    }  
    /**===Setters===*/
    template<class T>
    void List<T>::setData(const T& input){
        this->data = input;
    }
    template<class T>
    void List<T>::setNext(List* input){
        next = input;
    }
    template<class T>
    void List<T>::setPrev(List* input){
        prev = input;
    }

    template<class T>
    void cloneList(const List<T>* source_list ,List<T>* dest_list, int size){
    for(int i = 0 ; i < size; i++){
                //copy current data
                dest_list->setData(source_list->getData()); 
                //create and link next Node
                if(i != size-1 ){
                List<T>* newNode = new List<T>();
                newNode->setPrev(dest_list);
                dest_list->setNext(newNode);
                }
                //iterate
                source_list = source_list->getNext();
                dest_list = dest_list->getNext();
            }
    }

    template<class T>
    static List<T>* getNodeBefore( List<T>* list_ptr, T new_item){
    List<T>* current = list_ptr;
    List<T>* previous = NULL;
    while(current != NULL 
        && current->getData() < new_item){
        previous = current;
        current = current->getNext();
    }
    return previous;
    }



template<class T>
class SortedList{
    private:
    List<T>* list_head;
    unsigned int size;
    bool operator==(const SortedList& other) const; //Internal usage only (unrequired)

    public:
        SortedList();

        /**===Big three===*/
        ~SortedList();
        SortedList(const SortedList& source);
        SortedList& operator=(const SortedList& source);

        unsigned int length() const;
        void insert(const T& new_item);
        SortedList& remove( typename SortedList::const_iterator it);

        template<class Predicate>
        SortedList filter(Predicate c) const;
        template<class R>
        SortedList<R> apply(std::function<R(const T&)> Condition);
        typename SortedList<T>::const_iterator begin() const;
        typename SortedList<T>::const_iterator end() const;
        class const_iterator;

        void printList();// Debugging purposes only

};

/**Constructor*/
template<class T>
SortedList<T>::SortedList() : list_head(new List<T>()), size(0) {} 

/**Destructor*/
template<class T>
SortedList<T>::~SortedList(){ 
    delete this->list_head;
} 
/**Copy Constructor*/
template<class T>
SortedList<T>::SortedList(const SortedList<T>& source) : 
list_head(new List<T>()), size(source.size){

        cloneList(source.list_head, list_head, size);
        
}

/**Assignment Operator*/
template<class T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& source){
    if(this == &source){
        return *this;
    }
    delete list_head; //unsure of this line
    size = source.size;
    // List<T>* list_head = new List<T>(); //unsure of this line
    cloneList((source.list_head), this->list_head , source.size);
    return *this;
}



template<class T>
unsigned int SortedList<T>::length() const {
    return size;
}


template<class T>
void SortedList<T>::insert(const T& new_item){
    if(size == 0){ //empty list case
        this->list_head->setData(new_item);
        size++;
        return;
    }
    List<T>* new_node = new List<T>(); 
    new_node->setData(new_item);

    List<T>* node_before = getNodeBefore( list_head, new_item);

    if(node_before == NULL){
        new_node->next = list_head;
        list_head->prev = new_node;
        list_head = list_head->prev;
       size++;
    } else {
        List<T>* node_after = node_before->next;
        if(node_after != NULL){
            node_after->prev = new_node;
        }
        node_before->next = new_node;

        new_node->prev = node_before;
        new_node->next = node_after;
        size++;
    }
    
}




template<class T>
SortedList<T>& SortedList<T>::remove( typename SortedList<T>::const_iterator it){
List<T>* node_before = getNodeBefore<T>(list_head , *it);
List<T>* node_after = (node_before->getNext())->getNext();
//possible memory leak
if(node_before != NULL){
    node_before->setNext(node_after);
}
if(node_after != NULL){
    node_after->setPrev(node_before);
}
return *this;
}

template<class T>
template<class Predicate>
SortedList<T> SortedList<T>::filter(Predicate c) const{
    SortedList<T>* result = new SortedList<T>;
    for(typename SortedList<T>::const_iterator it = begin(); !(it == end()); ++it){
        if (c(*it)) { 
           result->insert(*it); 
        }      
    }
    return *result;
}

template<class T>
template<class R>
SortedList<R> SortedList<T>::apply(std::function<R(const T&)> Condition){
    SortedList<R>* result = new SortedList<R>;
    for(typename SortedList<T>::const_iterator it = begin(); !(it == end()); ++it){
        R applied = Condition(*it);
        result->insert(applied);
    }
    return *result;
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const {
    return(const_iterator(this, 0));
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return(const_iterator(this, size));
}


template<class T>
bool SortedList<T>::operator==(const SortedList& other) const{
    if(size != other.size){
        return false;
    }
    List<T>* list1_ptr = list_head;
    List<T>* list2_ptr = other->list_head;
    while(list1_ptr != NULL){
        if(list1_ptr->data != list2_ptr->data){
            return false;
        }
        list1_ptr = list1_ptr->next;
        list2_ptr = list2_ptr->next;
    }
    return true;
}

template<class T>
void SortedList<T>::printList() {
        List<T>* ptr = list_head;
        while(ptr != NULL){
            std::cout << ptr->data << " , " ;
            ptr = ptr->next;
            
        }
    }


template<class T>
class SortedList<T>::const_iterator {

    private:

    const SortedList<T>* sorted_list;
    unsigned int index;
    const_iterator(const SortedList<T>* sorted_list, int index); 
    friend class SortedList<T>;

    public:
    /**===Big three===*/
    ~const_iterator(); 
    const_iterator(const const_iterator& source); 
    const_iterator& operator=(const const_iterator& source); 

    /**===Overloaded Operators===*/
    const_iterator& operator++(); 
    bool operator==(const const_iterator& it) const; 
    const T& operator*();
};

/**Internal Constructor*/
template <class T>
SortedList<T>::const_iterator::const_iterator(const SortedList<T>* sorted_list, int index) :
sorted_list(sorted_list), index(index) {}

/**Destructor*/
template<class T>
SortedList<T>::const_iterator::~const_iterator(){} //need to build

/**Copy Constructor*/
template<class T>
SortedList<T>::const_iterator::const_iterator(const const_iterator& source) :
 sorted_list(source.sorted_list), index(source.index) {}

/**Assigment operator*/
template<class T>
typename SortedList<T>::const_iterator& 
SortedList<T>::const_iterator::operator=(const const_iterator& source){
    index = source.index;
    *sorted_list = *(source.sorted_list);
}

template<class T>
typename SortedList<T>::const_iterator& 
SortedList<T>::const_iterator::operator++(){
    ++index;
    return *this;
}

template<class T>
bool SortedList<T>::const_iterator::operator==(const const_iterator& it) const{
    assert(sorted_list == it.sorted_list);
    return (index == it.index);
}


template<class T>
const T& SortedList<T>::const_iterator::operator*(){
  if( index < 0 || index > sorted_list->size){
      throw std::out_of_range("out of range");
  }  
  List<T>* list_ptr = sorted_list->list_head;
  for(unsigned int i = 0; i < index; i++){
      list_ptr = list_ptr->next;
  }
  return list_ptr->data;
}


#endif


