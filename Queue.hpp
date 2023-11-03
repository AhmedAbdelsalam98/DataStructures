//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#include <iostream>
#include <cstdlib>
#include <cmath>

//constructor
template <typename object>
Queue<object>::Queue()
{
    data = new LinkedList<object>();
    used = 0;
}

//destructor
template <typename object>
Queue<object>::~Queue()
{
    delete data;
}

//add object to tail
template <typename object>
void Queue<object>::enqueue(const object& data_)
{
    data->addToTail(data_);
    ++used;
}

//remove object from head and returns copy of head object
template <typename object>
object Queue<object>::dequeue()
{
    --used;
    return data->removeFromHead();
}

//return size of queue
template <typename object>
int Queue<object>::size() const
{
    return used;
}

//returns true if queue is empty, otherwise false
template <typename object>
bool Queue<object>::is_empty() const
{
    if (used == 0) {
        return true;
    }
    else {
        return false;
    }
}

//returns reference to object in front
template <typename object>
object& Queue<object>::front()
{
    if (is_empty() == false) {
        data->start();
        return data->getCurrentData();
    }
    else {
        cout << "empty Queue!"  << endl;
    }
}

//returns minimum object by manipulating the queue
template <typename object>
object Queue<object>::minimum() 
{
    object min = front();
    for (int i = 0; i < size(); i++) {
        if (front() < min) {
            min = front();
        }
        enqueue(front());
        dequeue();
    }
    return min;
}

//returns maximum object
template <typename object>
object Queue<object>::maximum() 
{
    object max = front();
    for (int i = 0; i < size(); i++) {
        if (front() > max) {
            max = front();
        }
        enqueue(front());
        dequeue();
    }
    return max;
}

//returns average of all objects in queue
template <typename object>
double Queue<object>::average()
{
    double result = front();    //initiation
    enqueue(front());
    dequeue();
    for (int i = 1; i < size(); i++) {
        result += front();
        enqueue(front());
        dequeue();
    }
    result = result/ (double)size();
    return result;
}

//returns standard deviation of all objects in queue
template <typename object>
double Queue<object>::stdeviation() 
{
    double avg = average(); //store average()
    double result = pow((front() - avg), 2);    //initiation
    enqueue(front());
    dequeue();
    for (int i = 1; i < size(); i++) {
        result += pow((front() - avg), 2);
        enqueue(front());
        dequeue();
    }
    result = sqrt(result/size());
    return result;
}

//sorts queue in ascending
template <typename object>
void Queue<object>::sort()
{
    int length = size();
    object* order[length];  //pointer array to store every minimum()
    for (int i = 0; i < length; i++) {
        object min = minimum();
        order[i] = new object(min);
        while (front() != min) {  //brings minimum to front
            enqueue(front());
            dequeue();
        }
        dequeue(); //removes minimum() from queue
    }
    for (int i=0; i < length; i++) {
        enqueue(*(order[i]));   //adds first minimum() til last minimum() == maximum()
        delete order[i];    //delete each array pointer to avoid memory leakage.
    }
}






