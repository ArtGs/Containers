//
// Created by Artem Gusev on 22.03.2018.
//

#pragma once

#include "NListElement.h"
#include <iostream>


//====================================================
// Class NList;

template <class type>
class NList{
private:
    NListElement<type> *first;
    NListElement<type> *last;

public:
    NList();
    unsigned int size;

    // ADD / DELETE ELEMENTS
    void pushBack(type value);
    void pushFront(type value);
    void insert(type value, int position);

    type popBack();
    type popFront();
    type popFromPosition(int position);
    void deleteElement(int position);

    // SET && GET
    type getFirst();
    type getLast();
    int getSize();

    // DEBUG ONLY!!!!!
    void show();

};

//====================================================
// Methods

template <class type>
NList<type>::NList() {
    size = 0;
    first = NULL;
    last = NULL;
}

template <class type>
void NList<type>::show() {
    NListElement<type> *cell;
    cell = first;
    while (cell != NULL){
        std::cout << cell->value << std::endl;
        cell = cell->next;
    }
}

// SET && GET
template <class type>
type NList<type>::getFirst() {
    return this->first->value;
}

template <class type>
type NList<type>::getLast() {
    return this->last->value;
}

template <class type>
int NList<type>::getSize() {
    return size;
}

// ADD / DELETE ELEMENTS
template <class type>
void NList<type>::pushBack(type value) {
    NListElement<type> *cell = new NListElement<type>;
    cell->value = value;
    if(first == NULL){
        first = cell;
        last = first;
    } else{
        last->next = cell;
        last = cell;
    }
    size++;
}

template <class type>
void NList<type>::pushFront(type value) {
    NListElement<type> *cell = new NListElement<type>;
    cell->value = value;
    if (first != NULL){
        cell->next = first;
        first = cell;
    } else{
        first = cell;
        last = first;
    }
    size++;
}

template <class type>
type NList<type>::popBack() {
    if(size == 0) {
        return -1;
    }

    NListElement<type> *cell = first;
    while (cell->next->next!= NULL){
        cell = cell->next;
    }
    type tmp = cell->next->value;
    delete (cell->next);
    cell->next = NULL;
    size --;
    return tmp;

}

template <class type>
type NList<type>::popFront() {
    if(size == 0){
        return -1;
    }
    NListElement<type> tmp;
    tmp.value = first->value;
    NListElement<type> *cell = first->next;
    delete(first);
    first = cell;
    size --;
    return tmp.value;
}

template <class type>
void NList<type>::insert(type value, int position) {
    if(position > size + 1){
        return;
    }
    if(position == size + 1){
        pushBack(value);
        return;
    }
    if(position == 0){
        pushFront(value);
        return;
    }

    NListElement<type> *cell = first;
    for(int i = 0; i < position; i++){
        cell = cell->next;

    }
    NListElement<type> *next_connection = cell->next;
    NListElement<type> *inserted = new NListElement<type>;

    inserted->value = value;
    inserted->next = next_connection;

    cell->next = inserted;
    size ++;

}

template <class type>
void NList<type>::deleteElement(int position) {
    if(position > size){
        return;
    }
    if(position == size){
        popBack();
        return;
    }
    if(position == 0){
        popFront();
        return;
    }
    NListElement<type> *cell = first;
    for(int i = 0; i < position - 1; i++){
        cell = cell->next;
    }
    NListElement<type> *tmp = cell->next->next;
    delete (cell->next);
    cell->next = tmp;

}

template <class type>
type NList<type>::popFromPosition(int position) {
    NListElement<type> *cell = first;
    if(position > size){
        return -1;
    }

    if(position == 0){
        return popFront();
    }
    if(position == size - 1){
        return popBack();
    }

    for(int i = 0; i < position - 1; i++){
        cell = cell->next;
    }
}
