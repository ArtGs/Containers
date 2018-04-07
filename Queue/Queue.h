//
// Created by Artem Gusev on 27.03.2018.
//
#pragma once

#include <iostream>

//====================================================
// Queue
template <class type>
class Queue{
    type *queue;
    unsigned short int maxSize;

    unsigned short int size;
    unsigned short int first_position;
    unsigned short int last_position;

public:
    // Constructors && Destructors
    Queue(int size);
    ~Queue();

    // Methods
    void push(type value);
    type pop();

    // SET && GET
    unsigned short int getSize();
    unsigned short int getMaxSize();
    unsigned short int getFirstPos();
    unsigned short int getLastPos();

    // DEBUG ONLY!!!!
    void showStructure();   // Show elements from [0] to [maxSize]
    void showElements();    // Show Elements from first to last
};

//====================================================
// Constructors && Destructors
template <class type>
Queue<type>::Queue(int size) {
    queue = new type [size];
    this->maxSize = size;
    this->size = 0;

}

template <class type>
Queue<type>::~Queue() {
    delete [] queue;
}

// Methods
template <class type>
void Queue<type>::push(type value) {
    if(size == maxSize){
        std::cout << "Queue overFlow" << std::endl;
        return;
    }
    if(size == 0){
        queue[0] = value;
        first_position = 0;
        last_position = 0;
        size ++;
        return;
    }
    last_position = (last_position + 1) % maxSize;
    queue[last_position] = value;
    size ++;
}

template <class type>
type Queue<type>::pop() {
    if(size == 0){
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    int tmp = first_position;
    first_position = (first_position + 1) % maxSize;
    size--;
    return queue[tmp];
}

// DEBUG
template <class type>
void Queue<type>::showStructure() {
    for(int i = 0 ; i < maxSize; i++){
        std::cout << queue[i] << std::endl;
    }
}

template <class type>
void Queue<type>::showElements() {
    if(size != 0){
        if(first_position > last_position){
            for(int i = first_position; i < maxSize; i++){
                std::cout << queue[i] << std::endl;
            }
            for(int i = 0; i <= last_position; i++){
                std::cout << queue[i] << std::endl;
            }
        }
        if(first_position < last_position){
            for(int i = first_position; i <= last_position; i++){
                std::cout << queue[i] << std::endl;
            }
        }
    }

}

// SET && GET
template <class type>
unsigned short int Queue<type>::getSize() {
    return this->size;
}

template <class type>
unsigned short int Queue<type>::getMaxSize() {
    return this->maxSize;
}

template <class type>
unsigned short int Queue<type>::getFirstPos() {
    return this->first_position;
}

template <class type>
unsigned short int Queue<type>::getLastPos() {
    return this->last_position;
}
