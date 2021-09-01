#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<assert.h>

typedef int T; 

    class List{ //internal class
        public:
        T data;
        List* next;
        List* prev;
        friend class SortedList;
        friend void cloneList(const List* source_list ,List* dest_list, int size);
        List();
        ~List() = default; //unsure if default destructor is enough
        void setData(T input); 
        T getData() const;
    };


    void List::setData(T input){
        this->data = input;
    }

    T List::getData() const{
        return data;
    }



List::List() : data(0), next(NULL), prev(NULL) {}

// List::~List(){ //i was unable to build a working List destructor
//     List* current_node  = this; //segmentation fault
//     while(current_node){
//         List* next_node = current_node->next;
//         delete current_node;
//         List* current = next_node;
//     }
// }


class SortedList{
    private:
    List* list_head;
    unsigned int size;
    public:
        SortedList();
        ~SortedList() = default;
        SortedList(const SortedList& source);
        unsigned int length() const;
        SortedList& operator=(const SortedList& source);
        void insert(const T& new_item);
        void printList();//debugging purposes only
        
        // SortedList& remove( SortedList::iterator it);
        // SortedList filter{std::function<bool(const T&)> predicate);
        // template <class R>
        // SortedList<R> apply(std::function<R(const T&)> mapper);

        // SortedList::iterator begin() const;
        // SortedList::iterator end() const;
        // class iterator;
        // class const_iterator;
};

SortedList::SortedList() : list_head(new List()), size(0) {} 

void cloneList(const List* source_list ,List* dest_list, int size){
    for(int i = 0 ; i < size; i++){
                //copy current data
                dest_list->data = source_list->data; 
                //create and link next Node
                if(i != size-1 ){
                List* newNode = new List();
                newNode->prev = dest_list;
                dest_list->next = newNode;
                }
                //iterate
                source_list = source_list->next;
                dest_list = dest_list->next;
            }
}

SortedList::SortedList(const SortedList& source) : list_head(new List()), size(source.size) {

        cloneList(source.list_head, list_head, size);
        
}


SortedList& SortedList::operator=(const SortedList& source){
    if(this == &source){
        return *this;
    }
    delete list_head; //unsure of this line
    size = source.size;
    List* list_head = new List();
    cloneList((source.list_head),list_head , source.size);
    return *this;
}



unsigned int SortedList::length() const {
    return size;
}

static List* getNodeBefore( List* list_ptr, T new_item){
    List* current = list_ptr;
    List* previous = NULL;
    while(current != NULL 
        && current->getData() < new_item){
        previous = current;
        current = current->next;
    }
    return previous;
}


void SortedList::insert(const T& new_item){
    if(size == 0){ //empty list
        this->list_head->data = new_item;
        size++;
        return;
    }
    List* new_node = new List(); 
    new_node->data = new_item;

    List* node_before = getNodeBefore( list_head, new_item);

    if(node_before == NULL){
        new_node->next = list_head;
        list_head->prev = new_node;
        list_head = list_head->prev;
       size++;
    } else {
        List* node_after = node_before->next;
        if(node_after != NULL){
            node_after->prev = new_node;
        }
        node_before->next = new_node;

        new_node->prev = node_before;
        new_node->next = node_after;
        size++;
    }
    
}

void SortedList::printList() {
        List* ptr = list_head;
        while(ptr != NULL){
            std::cout << ptr->data << " , " ;
            ptr = ptr->next;
            
        }
    }




#endif


