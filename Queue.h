//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#ifndef AHMED_QUEUE
#define AHMED_QUEUE
#include "LinkedList.h"
#include <cstdlib>
using namespace std;

template <typename object>
class Queue
{
public:
    //constructor
    Queue();
    //destructor
    ~Queue();
    //adds object to tail
    void enqueue(const object& data_);
    //removes object from head and returns copy
    object dequeue();
    //returns size of queue
    int size() const;
    //checks if queue is empty
    bool is_empty() const;
    //returns reference to object in front
    object& front();
    //returns minimum object
    object minimum();
    //returns maximum object
    object maximum();
    //returns average of numbers in double
    double average();
    //returns standard deviation of numbers in double
    double stdeviation();
    //sorts objects in queue by min to max
    void sort();
private:
    LinkedList<object>* data;
    int used;
};

#include "Queue.hpp"

#endif