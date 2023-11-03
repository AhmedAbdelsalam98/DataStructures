//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916

#ifndef AHMED_NODE
#define AHMED_NODE
#include "Student.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class node {
public:
    //Type definition
    typedef Student dataType;

    //Constructor
    node (const dataType& data_ = dataType(), node* next_ = NULL, node* prev_ = NULL);

    //Destructor
    ~node();

    //Setters
    void setNext(node* next_);
    void setPrev(node* prev_);
    void setData(const dataType& data_);
    
    //Getters
    node* getNext() const;
    node* getPrev() const;
    dataType getData() const;
    
private:
    node* next;
    node* prev;
    dataType data;
};
ostream& operator <<(ostream& out, node* input);
#endif
