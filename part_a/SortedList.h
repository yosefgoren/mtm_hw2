#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<assert.h>


namespace mtm{
    
    template<class T>
    class SortedList{
        private:
        class Node{  
            private:
            T* data;
            Node* next;
            Node* prev;
            void cloneList(Node* source_list, int size); 
            Node* getNodeBefore(T new_item); 
            friend class SortedList;

            public:
            Node() : data(NULL), next(NULL), prev(NULL) {}
            ~Node() = default;
         };

        Node* list_head;
        unsigned int size;

        bool operator==(const SortedList& other) const; //Internal usage only (unrequired)
        void deallocate(); 

        public:
            SortedList(); 
            ~SortedList(); 
            SortedList(const SortedList& source); 
            SortedList& operator=(const SortedList& source); 
            unsigned int length() const; 
            void insert(const T& new_item); 
            class const_iterator;
            SortedList& remove( typename SortedList::const_iterator it); 
            template<class Predicate>
            SortedList filter(Predicate c) const; 
            template<class Mapper>
            SortedList apply(Mapper mapper); 
            typename SortedList<T>::const_iterator begin() const; 
            typename SortedList<T>::const_iterator end() const; 



    };

    // Node functions:
     
    template<class T>
    void SortedList<T>::Node::cloneList(Node* source_list, int size){
        SortedList<T>::Node* dest_list = this;
        for(int i = 0 ; i < size; i++){
            // Copy current Data 
             dest_list->data = new T(source_list->data) ;
            // Create and link next Node
            if(i != size - 1 ){ // Do not create next node if we are at the last node.
                SortedList<T>::Node* new_node = new Node();
                new_node->prev = dest_list;
                dest_list->next = new_node;
            }
            // Iterate
            source_list = source_list->next;
            dest_list = dest_list->next;
        }
    }

    template<class T>
    typename SortedList<T>::Node* SortedList<T>::Node::getNodeBefore(T new_item){
        SortedList<T>::Node* current = this;
        SortedList<T>::Node* previous = NULL; 
        while(current != NULL && *(current->data) < new_item){ //possible segmentation fault
            previous = current;
            current = current->next;
        }
        return previous;
    }

    //SortedList functions:

    template <class T>
    void SortedList<T>::deallocate(){
        SortedList<T>::Node* current_node = list_head;
        while(current_node != nullptr){
            SortedList<T>::Node* tmp_node = current_node;
            current_node = current_node->next;
            delete tmp_node;
        }
    }

    template<class T>
    bool SortedList<T>::operator==(const SortedList& other) const{
        if(size != other.size){
            return false;
        }
        SortedList<T>::Node* list1_ptr = list_head;
        SortedList<T>::Node* list2_ptr = other->list_head;
        while(list1_ptr != NULL){
            if(*(list1_ptr->data) != *(list2_ptr->data)){
                return false;
            }
            list1_ptr = list1_ptr->next;
            list2_ptr = list2_ptr->next;
        }
        return true;
    }

    /**Constructor*/
    template<class T>
    SortedList<T>::SortedList() : list_head(new Node()), size(0) {} 

    /**Destructor*/
    template<class T>
    SortedList<T>::~SortedList(){ 
        deallocate();
    } 

    /**Copy Constructor*/
    template<class T>
    SortedList<T>::SortedList(const SortedList<T>& source) : 
    list_head(new Node()), size(source.size){
            this->list_head->cloneList(source.list_head, size); 
    }

    /**Assignment Operator*/
    template<class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList<T>& source){
        if(this == &source){
            return *this;
        }
        deallocate();
        size = source.size;
        list_head = new Node(); 
        this->list_head->cloneList(source.list_head, source.size); 
        return *this;
    }

    template<class T>
    unsigned int SortedList<T>::length() const {
        return size;
    }   

    template<class T>
    void SortedList<T>::insert(const T& new_item){
        if(size == 0){ //empty list case
            this->list_head->data = new T(new_item);
            size++;
            return;
        }
        SortedList<T>::Node* new_node = new Node();
        *(new_node->data) = new_item;

        SortedList<T>::Node* node_before = this->list_head->getNodeBefore(new_item); 

        if(node_before == NULL){
            new_node->next = list_head;
            list_head->prev = new_node;
            list_head = list_head->prev;
            size++;
        } 
        else{
            SortedList<T>::Node* node_after = node_before->next;
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
        SortedList<T>::Node* node_before = list_head->getNodeBefore(*it);
        SortedList<T>::Node* node_after = node_before->next->next;
        delete node_before->next;
        
        if(node_before != NULL){
            node_before->next = node_after;
        }
        if(node_after != NULL){
            node_after->prev = node_before;
        }
        return *this;
    }

    template<class T>
    template<class Predicate>
    SortedList<T> SortedList<T>::filter(Predicate c) const{
        SortedList<T> result;
        for(typename SortedList<T>::const_iterator it = begin(); !(it == end()); ++it){
            if (c(*it)) { 
                result.insert(*it); 
            }      
        }
        return result;
    }

    template<class T>
    template<class Mapper>
    SortedList<T> SortedList<T>::apply(Mapper mapper){
        SortedList<T> result;
        for(typename SortedList<T>::const_iterator it = begin(); !(it == end()); ++it){
            T applied = mapper(*it);
            result.insert(applied);
        }
        return result;
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
    class SortedList<T>::const_iterator {
        private:
        const SortedList<T>* sorted_list;
        unsigned int index;
        const_iterator(const SortedList<T>* sorted_list, int index); 
        friend class SortedList<T>;

        public:
        const_iterator(const const_iterator& source); 
        const_iterator& operator=(const const_iterator& source); 
        ~const_iterator() = default; 

        /**===Overloaded Operators===*/
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& it) const; 
        const T& operator*();
    };

    /**Private Constructor*/
    template <class T>
    SortedList<T>::const_iterator::const_iterator(const SortedList<T>* sorted_list, int index) :
    sorted_list(sorted_list), index(index) {}


    /**Copy Constructor*/
    template<class T>
    SortedList<T>::const_iterator::const_iterator(const const_iterator& source) :
    sorted_list(source.sorted_list), index(source.index) {}

    /**Assigment operator*/
    template<class T>
    typename SortedList<T>::const_iterator& 
    SortedList<T>::const_iterator::operator=(const const_iterator& source){
        index = source.index;
        sorted_list = source.sorted_list;
        return *this;
    }

    /** Prefix operator++ */
    template<class T>
    typename SortedList<T>::const_iterator& 
    SortedList<T>::const_iterator::operator++(){
        if( index == sorted_list->size ){
            throw std::out_of_range("out of range");
        }  
        ++index;
        return *this;
    }

    /** Postfix operator++ */
    template<class T>
    typename SortedList<T>::const_iterator 
    SortedList<T>::const_iterator::operator++(int){
        const_iterator result = *this;
        ++(*this);
        return result;
    }


    template<class T>
    bool SortedList<T>::const_iterator::operator==(const const_iterator& it) const{
        return (index == it.index && sorted_list == it.sorted_list );
    }


    template<class T>
    const T& SortedList<T>::const_iterator::operator*(){
    if( index < 0 || index > sorted_list->size){
        throw std::out_of_range("out of range");
    }  
    SortedList<T>::Node* list_ptr = sorted_list->list_head;
    for(unsigned int i = 0; i < index; i++){
        list_ptr = list_ptr->next;
    }
    return *(list_ptr->data);
    }







}

#endif