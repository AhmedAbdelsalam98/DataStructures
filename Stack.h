//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#ifndef AHMED_STACK
#define AHMED_STACK
#include "LinkedList.h"
#include <cstdlib>
using namespace std;

template <typename object>
class Stack
{
public:
    //constructor
    Stack();
    //destructor
    ~Stack();
    //adds object to stack(tail)
    void push(const object& data_);
    //removes object from stack(tail) and returns copy
    object pop();
    //returns size of stack
    int size() const;
    //returns true if stack is empty
    bool is_empty() const;
    //returns reference of object on top of the stack
    object& top();
private:
    LinkedList<object>* data;
    int used;
};
template <typename object>
ostream& operator <<(ostream& out, Stack<object>& input);

#include "Stack.hpp"

#endif

