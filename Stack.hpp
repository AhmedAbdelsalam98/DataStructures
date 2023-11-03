//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#include <cstdlib>
#include <iostream>

//constructor
template <typename object>
Stack<object>::Stack()
{
    data = new LinkedList<object>();
    used = 0;
}

//destructor
template <typename object>
Stack<object>::~Stack() 
{
    delete data;
}

//add object to stack (tail)
template <typename object>
void Stack<object>::push(const object& data_)
{
    data->addToTail(data_);
    ++used;
}

//remove object from stack (tail) and returns copy of object
template <typename object>
object Stack<object>::pop()
{
    --used;
    return data->removeFromTail();
}

//return size of stack
template <typename object>
int Stack<object>::size() const
{
    return used;
}

//returns true if stack is empty, otherwise returns false
template <typename object>
bool Stack<object>::is_empty() const
{
    if (used == 0) {
        return true;
    }
    else {
        return false;
    }
}

//returns reference to object on top of the stack
template <typename object>
object& Stack<object>::top()
{
    if (is_empty() == false) {
        data->end();
        return data->getCurrentData();
    }
    else {
        cout << "empty stack!"  << endl;
    }
}

//overload cout operator
template <typename object>
ostream& operator <<(ostream& out, Stack<object>& input)
{
    out << "( ";
    while (input.size() != 0) {
        out << input.pop() << " ";  //removes from stack to get visibility of objects
    }
    out << ")";
    return out;
}


