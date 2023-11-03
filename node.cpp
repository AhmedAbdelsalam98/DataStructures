//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916

//Class definition of node.h

#include <iostream>
#include <cstdlib>
#include "node.h"

//Constructor
//Precondition: data can be initiated with dataType , next and prev pointers can be initiated with node pointers.
//Postcondition: if nothing is initiated, data is initiated with default dataType constructor and pointers are initiated with NULL.
node::node(const dataType& data_, node* next_, node* prev_)
{
    this->data=data_;
    this->next=next_;
    this->prev=prev_;
}

//Empty destructor
node::~node(){}

//Members that mutate

//Sets node pointer
void node::setNext(node* next_)
{
    this->next = next_;
}

//Sets prev pointer
void node::setPrev(node* prev_)
{
    this->prev = prev_;
}

//Sets data
void node::setData(const node::dataType& data_)
{
    this->data = data_;
}

//Non-mutating members

//returns next
node* node::getNext() const
{
    return this->next;
}

//returns prev
node* node::getPrev() const
{
    return this->prev;
}

//returns data
node::dataType node::getData() const
{
    return this->data;
}

//Non-member functions

//Overloaded ostream operator
ostream& operator <<(ostream& out, node* input)
{
    if (input != NULL) {
        out << input->getData();
    }
    return out;
}