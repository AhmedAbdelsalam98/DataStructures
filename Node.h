//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#ifndef AHMED_NODE
#define AHMED_NODE
#include "Student.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename object>
class Node {
public:

    //Constructor
    Node (const object& data_ = object(), Node<object>* next_ = NULL, Node<object>* prev_ = NULL);

    //Destructor
    ~Node();

    //Setters
    void setNext(Node<object>* next_);
    void setPrev(Node<object>* prev_);
    void setData(const object& data_);
    
    //Getters
    Node<object>* getNext() const;
    Node<object>* getPrev() const;
    object& getData();
    
private:
    Node* next;
    Node* prev;
    object data;
};
template <typename object>
ostream& operator <<(ostream& out, Node<object>* input);

#include "Node.hpp"

#endif
