//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916
#include <iostream>
#include <cstdlib>


//constructor
template <typename object>
LinkedList<object>::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
    length = 0;
}

//destructor
template <typename object>
LinkedList<object>::~LinkedList()
{
    clearList();    //calls clearList()
}

//VOID MEMBER FUNCTIONS

//clear list
template <typename object>
void LinkedList<object>::clearList()   //deletes LinkedList nodes
{
    while (head != NULL)    //loops while head is not NULL and calls removeFromHead()
    {
        removeFromHead();
    }
}

//add node<object> to head
template <typename object>
void LinkedList<object>::addToHead(const object& data)
{
    start();    //points current to head and calls addToCurrent()
    addToCurrent(data);
}


//add node<object> to tail
template <typename object>
void LinkedList<object>::addToTail(const object& data)
{
    current = NULL;     //sets current NULL and calls addToCurrent()
    addToCurrent(data);
}

//add node<object> before current
template <typename object>
void LinkedList<object>::addToCurrent(const object& data)
{   
    Node<object>* newNode = new Node<object>(data);
	newNode->setNext(current);
	if (current != NULL) {
        newNode->setPrev(current->getPrev());
		current->setPrev(newNode);
	}
	else {
        newNode->setPrev(tail);
		tail = newNode;
	}
	if (newNode->getPrev() != NULL) {
		(newNode->getPrev())->setNext(newNode);
	}
	else {
		head = newNode;
    }
    length++;
}

//remove node from tail
template <typename object>
object LinkedList<object>::removeFromTail() //points current to tail and calls removeFromCurrent(), returns copy of data
{
    end();
    return removeFromCurrent();
}

//remove node from head
template <typename object>
object LinkedList<object>::removeFromHead() //points current to head and calls removeFromCurrent(), returns copy of data
{
    start();
    return removeFromCurrent();
}

//remove node from current
template <typename object>
object LinkedList<object>::removeFromCurrent()  //deletes node pointed by current and returns copy of data
{
    if (current != NULL) {
	if (current->getNext() != NULL) {
		(current->getNext())->setPrev(current->getPrev());
    }
	else {
		tail = current->getPrev();
	}
	if (current->getPrev() != NULL) {
		(current->getPrev())->setNext(current->getNext());
    }
	else {
		head = current->getNext();
	}
	Node<object>* temp = current;   //temp node pointer to copy current pointer
    object data = current->getData();   //copy data in current
	current = current->getNext();   //point current to next
	delete temp;    //delete temp pointer
    length--;
    return data;    //return copy of data
    }
	else {  //if current is NULL, nothing to delete
	cout << "Cannot delete" << endl;
	}
}

//removes node(s) with corresponding data name
template <typename object>
void LinkedList<object>::remove(string name)
{
    int count = 0;
    name = toLowerCase(name);           //converts parameter name to lower case
    string name2;
    start();
    while(current != NULL)              //loops while current is not NULL from start()
    {
        name2 = toLowerCase((current->getData()).get_name());           //converts current data name to lower case
        if(name2 == name)                                       //compares both names and removes from current if they match
        {                                                       //updates the counter for how many removed
            removeFromCurrent();
            count++;
        }
        else {
            forward();
        }
    }
    cout << "removed " << count << " students" << endl;             //prints counter
}

//point current to head
template <typename object>
void LinkedList<object>::start()
{
    current = head;
}

//point current to tail
template <typename object>
void LinkedList<object>::end()
{
    current = tail;
}

//point current forward by one
template <typename object>
void LinkedList<object>::forward()
{
    if (current != NULL) {
    current = current->getNext();
    }
}

//point current backward by one
template <typename object>
void LinkedList<object>::back()
{
    if (current != NULL) {
    current = current->getPrev();
    }
}

//add content of another list
template <typename object>
void LinkedList<object>::operator +=(LinkedList<object>& list)
{
    list.start();
    while (list.getCurrent() != NULL)           //loops from current start, while current is not NULL and AddToTail(current->data) to list 
    {
        addToTail((list.getCurrentData()));
        list.forward();
    }
}

//copy content of another list
template <typename object>
void LinkedList<object>::operator =(LinkedList<object>& list)
{
    clearList();
    list.start();
    while (list.getCurrent() != NULL)           //loops from current start, while current is not NULL and AddToTail(current->data) to list 
    {
        addToTail((list.getCurrentData()));
        list.forward();
    }
}

//order LinkedList
template <typename object>
void LinkedList<object>::order()    //sort list by alphabetical order and scores
{
    Node<object>* current2;                 //current2 pointer
    string name1;
    string name2;
    for (start(); current != NULL ; forward()) {              //loops from start() while current is not NULL 
        for (current2 = current->getNext(); current2 != NULL ; current2 = current2->getNext()) {   //current2 loops and compares every following Node data to current's
                name1 = current2->getData().get_name();
                name1 = toLowerCase(name1);
                name2 = (current->getData()).get_name();
                name2 = toLowerCase(name2);  
                if (name1.compare(name2) < 0) {         //compared using .compare() function if < 0 then
                    swapNode(current2, current);        //current and current2 Node positions are swapped
                    swapPtr(current2, current);         //current and current2 pointers are swapped
                }
                else if (name1.compare(name2) == 0) {       //if .compare() == 0 then
                    if ((current2->getData()).get_score() > (current->getData()).get_score()) {     //if current2 score > current score
                        swapNode(current2, current);        //swaps Node positions
                        swapPtr(current2, current);         //swaps pointers
                    }
                }
        }  
    }
}

//swap nodes
template <typename object>
void LinkedList<object>::swapNode(Node<object>* const n1, Node<object>* const n2)   //swaps Node positions through relative links
{
    Node<object>* temp1 = n1->getNext();
    Node<object>* temp2 = n1->getPrev();
    if (temp1 != NULL) {temp1->setPrev(n2); }
    else {tail = n2; }
    if (temp2 != NULL) {temp2->setNext(n2); }
    else {head = n2; }
    n1->setNext(n2->getNext());
    n1->setPrev(n2->getPrev());
    n2->setNext(temp1);
    n2->setPrev(temp2);
    if (n1->getNext() != NULL)  {(n1->getNext())->setPrev(n1); }
    else {tail = n1; }
    if (n1->getPrev() != NULL)  {(n1->getPrev())->setNext(n1); }
    else {head = n1; }
}

//node pointers swap
template <typename object>
void LinkedList<object>::swapPtr(Node<object>*& p1, Node<object>*& p2)
{
    Node<object>* temp = p2;
    p2 = p1;
    p1 = temp;
}

//count names
template <typename object>
int LinkedList<object>::count(string name)  //count corresponding names in list
{
    int count = 0;
    name = toLowerCase(name);
    string name2;
    start();
    while(current != NULL)
    {
        name2 = toLowerCase((current->getData()).get_name());
        if(name2 == name)
        {
            count++;
        }
        forward();
    }
   return count;
}

//average scores
template <typename object>
double LinkedList<object>::calcAverage()    //calculates average scores of list
{
    double count = 0;   //double count var created, recieves all scores of students and divides over list length
    start();
    while(current != NULL)
    {
        count += (current->getData()).get_score();
        forward();
    }
    count /= length;
    return count;
}

//return reference to data object in the node pointed by the current pointer
template <typename object>
object& LinkedList<object>::getCurrentData()
{
    if (current != NULL) {
        return current->getData();
    }
}

//return LinkedList length
template <typename object>
int LinkedList<object>::size() const
{
    return length;
}

//return const current pointer (private)
template <typename object>
const Node<object>* LinkedList<object>::getCurrent() const
{
    return current;
}

//NON-MEMBER FUNCTIONS

//overloaded ostream operator
template <typename object>
ostream& operator <<(ostream& out, LinkedList<object>& list)
{   
    list.start();
    for (int i = 0; i < list.size(); i++) {
        out << list.getCurrentData();
        list.forward();
    }
    return out;
}