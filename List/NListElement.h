//
// Created by Artem Gusev on 27.03.2018.
//

#pragma once

#include <iostream>

//====================================================
// NListElement
template <class type>
class NListElement{
public:
    NListElement();

    type value;
    NListElement *next; // Link to next element
    void show();
};

//====================================================
// Methods

template <class type>
NListElement<type>::NListElement() {
    next = NULL;
}

template <class type>
void NListElement<type>::show() {
    std::cout << value << std::endl;
    std::cout << next << std::endl;
}
