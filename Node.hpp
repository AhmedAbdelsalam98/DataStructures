//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#include <iostream>
#include <cstdlib>

//Constructor
//Precondition: data can be initiated with an object, next and prev pointers can be initiated with Node pointers.
//Postcondition: if nothing is initiated, data is initiated with default dataType constructor and pointers are initiated with NULL.
template <typename object>
Node<object>::Node(const object& data_, Node<object>* next_, Node<object>* prev_)
{
    this->data=data_;
    this->next=next_;
    this->prev=prev_;
}

//Destructor

template <typename object>
Node<object>::~Node() {
    next = NULL;
    prev = NULL;
}

//Members that mutate

//Sets next pointer
template <typename object>
void Node<object>::setNext(Node<object>* next_)
{
    this->next = next_;
}

//Sets prev pointer
template <typename object>
void Node<object>::setPrev(Node<object>* prev_)
{
    this->prev = prev_;
}

//Sets data
template <typename object>
void Node<object>::setData(const object& data_)
{
    this->data = data_;
}

//Non-mutating members

//returns next
template <typename object>
Node<object>* Node<object>::getNext() const
{
    return this->next;
}

//returns prev
template <typename object>
Node<object>* Node<object>::getPrev() const
{
    return this->prev;
}

//returns reference of data object
template <typename object>
object& Node<object>::getData()
{
    return data;
}

//Non-member functions

//Overloaded ostream operator
template <typename object>
ostream& operator <<(ostream& out, Node<object>* input)
{
    if (input != NULL) {
        out << input->getData();
    }
    return out;
}