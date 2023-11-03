//Course: SENG1120
//Coded by: Ahmed Abdelsalam ID:3275916

//Class definition of LinkedList.h

#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

LinkedList::LinkedList() //Default constructor
{
    head = NULL;
    tail = NULL;
    current = NULL;
    length = 0;
}

//Destructor

LinkedList::~LinkedList()
{
    clearList();    //calls clearList()
}

//VOID MEMBER FUNCTIONS

//delete list nodes

void LinkedList::clearList()
{
    while (head != NULL)        //loops while head is not NULL and calls removeFromHead()
    {
        removeFromHead();
    }
}

//add node to head

void LinkedList::addToHead(const dataType& data)
{
    node* newnode = new node(data);     
    if (head == NULL) {            //if no nodes in list, assigns tail and head
        head = newnode;
        tail = head;
    }
    else {
        head->setPrev(newnode);         //if there are nodes, extends from head
        newnode->setNext(head);
        head = newnode;
    }
    length++;
}

//add node to tail

void LinkedList::addToTail(const dataType& data)
{
    node* newnode = new node(data); 
    if (tail == NULL) {                 //if no nodes in list, assigns tail and head
        tail = newnode;
        head = tail; 
    }
    else {
        tail->setNext(newnode);            //if there are nodes, extends from tail
        newnode->setPrev(tail);
        tail = newnode;
    }
    length++;
}

//add node to current

void LinkedList::addToCurrent(const dataType& data)
{   
    if (current == NULL) {          //if current == NULL adds to tail
        addToTail(data);
    }
    else {
        node* newnode = new node(data);         //otherwise adds before current, maintaining same list position as current before
        newnode->setNext(current);
        newnode->setPrev(current->getPrev());
        current->setPrev(newnode);
        if (newnode->getPrev() == NULL) {
            head = newnode;
        }
        else {
            (newnode->getPrev())->setNext(newnode);
        }
        length++;
    }
}

//remove node from tail

void LinkedList::removeFromTail()
{
    if (tail == NULL) {             //if tail is NULL, just prints message
        cout << "Tail is NULL, therefore cannot be removed" << endl;
    }
    else {
        node* temp = tail;
        tail = tail->getPrev();
        delete temp;             //otherwise updates new tail and deletes old
        length--;
        if (tail != NULL) {             //if new tail is NULL, head is NULL, otherwise new tail next pointer is updated
        tail->setNext(NULL);
        }
        else {
        head = NULL;
        }
    }
}

//remove node from head

void LinkedList::removeFromHead()
{
    if (head == NULL) {
        cout << "head is NULL, therefore cannot be removed" << endl;        //if head is NULL, just prints message
    }
    else {
        node* temp = head;
        head = head->getNext();
        delete temp;                    //otherwise updates new head, and deletes old
        length--;
        if (head != NULL) {                //if new head is NULL, tail is NULL, otherwise new head prev pointer is updated
        head->setPrev(NULL);
        }
        else {
        tail = NULL;
        }
    }
}

//remove node from current

void LinkedList::removeFromCurrent()
{
    if (current == NULL) {
        cout << "Current is NULL, therefore cannot be deleted" << endl;     //if current == NULL, just prints message
    }
    else if (current == head) {         //if current == head, calls RemoveFromHead()
        removeFromHead();
        current = head;
    }
    else if (current == tail) {         //if current == tail, calls RemoveFromTail()
        removeFromTail();
        current = NULL;
    }
    else {
        (current->getNext())->setPrev(current->getPrev());          //otherwise updates current's adjacent nodes pointers and deletes current node
        (current->getPrev())->setNext(current->getNext());          //current pointer is updated to next node
        node* temp = current;
        current = current->getNext();
        delete temp;
        length--;
    }
}

//remove nodes by data name

void LinkedList::remove(string name)
{
    int count = 0;
    name = toLowerCase(name);           //converts parameter name to lower case (probably was unnecessary)
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

void LinkedList::start()
{
    current = head;
}

//point current to tail

void LinkedList::end()
{
    current = tail;
}

//point current forward by one

void LinkedList::forward()
{
    current = current->getNext();
}

//point current backward by one

void LinkedList::back()
{
    current = current->getPrev();
}

//add another list to list
void LinkedList::operator +=(LinkedList& list)
{
    list.start();
    while (list.getCurrent() != NULL)           //loops from current start, while current is not NULL and AddToTail(current->data) to list 
    {
        addToTail((list.getCurrent())->getData());
        list.forward();
    }
}

//sort list by alphabetical order and scores

void LinkedList::order()
{
    node* current2;                 //current2 pointer
    string name1;
    string name2;
    for (start(); current != NULL ; forward()) {              //loops from start() while current is not NULL
        for (current2 = current->getNext(); current2 != NULL ; current2 = current2->getNext()) {   //current2 loops and compares every following node data to current's
                name1 = current2->getData().get_name();
                name1 = toLowerCase(name1);
                name2 = (current->getData()).get_name();
                name2 = toLowerCase(name2);         //current and current2 data names are converted to lower case
                if (name1.compare(name2) < 0) {         //compared using .compare() function if < 0 then
                    swapNode(current2, current);        //current and current2 node positions are swapped
                    swapPtr(current2, current);         //current and current2 pointers are swapped
                }
                else if (name1.compare(name2) == 0) {       //if .compare() == 0 then
                    if ((current2->getData()).get_score() > (current->getData()).get_score()) {     //if current2 score > current score
                        swapNode(current2, current);        //swaps node positions
                        swapPtr(current2, current);         //swaps pointers
                    }
                }
        }  
    }
}

//swap nodes

void LinkedList::swapNode(node* const n1, node* const n2)   //swaps node positions through relative links
{
    node* temp1 = n1->getNext();
    node* temp2 = n1->getPrev();
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

//swap pointers

void LinkedList::swapPtr(node*& p1, node*& p2)
{
    node* temp = p2;
    p2 = p1;
    p1 = temp;
}

//RETURN MEMBER FUNCTIONS

//count corresponding names in list

int LinkedList::count(string name)                   //same idea as remove(name) but without removeFromCurrent()
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

//calculate average score of list

double LinkedList::calcAverage()
{
    double count = 0;                           //double count var created, recieves all scores of students and divided over list length
    start();
    while(current != NULL)
    {
        count += (current->getData()).get_score();
        forward();
    }
    count /= length;
    return count;
}

//returns current pointer

node* LinkedList::getCurrent() const
{
    return current;
}

//returns length of list

int LinkedList::size() const
{
    return length;
}

//NON-MEMBER FUNCTIONS

//convert string to lower case

string toLowerCase(string str) {
    for (unsigned int i=0; i < str.length(); i++) str[i] = tolower(str[i]);
    return str;
}

//overloaded ostream operator

ostream& operator <<(ostream& out, LinkedList& list)
{
    for (list.start(); list.getCurrent() != NULL; list.forward()) {
        out << list.getCurrent();
    }
    return out;
}