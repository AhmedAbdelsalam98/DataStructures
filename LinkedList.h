//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916

#ifndef AHMED_LINKEDLIST
#define AHMED_LINKEDLIST
#include "node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList
{
public:

    typedef Student dataType;

    //constructor
    LinkedList();

    //destructor
    ~LinkedList();

    //clears list
    void clearList();

    //adds node to head
    void addToHead(const dataType& data);

    //adds node to tail
    void addToTail(const dataType& data);

    //adds node to current
    void addToCurrent(const dataType& data);

    //remove from tail
    void removeFromTail();

    //remove from head
    void removeFromHead();

    //removes node from current
    void removeFromCurrent();

    //points current to head
    void start();

    //points current to tail
    void end();

    //points current one forward
    void forward();

    //points current one back
    void back();

    //removes nodes with corresponding data name
    void remove(string name);

    //sorts nodes by names alphabetically
    void order();

    //adds nodes of another linkedList
    void operator +=(LinkedList& list);

    //swaps node positions
    void swapNode(node* const n1, node* const n2);

    //swaps node pointers
    void swapPtr(node*& p1, node*& p2);

    //returns current pointer
    node* getCurrent() const;

    //counts nodes with corresponding data name
    int count(string name);

    //calculate average scores
    double calcAverage();

    //returns length
    int size() const;

private:
    node* head;
    node* tail;
    node* current;
    int length;
};
//overloaded ostream operator
ostream& operator <<(ostream& out, LinkedList& list);

//converts string to lower case
string toLowerCase(string str);
#endif