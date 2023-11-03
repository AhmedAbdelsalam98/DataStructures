//GradesDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of queues and stacks. 

#include <iostream>
#include <cstdlib>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main()
{
	Queue<int> marks;
	//int vectorMarks[] = {12, 18, 26, 34, 40, 43, 50, 60, 62, 65, 67, 69, 69, 70, 71, 72, 74, 75, 80, 80, 81, 84, 90, 91, 98};

	// FOR SENG6120 students (and extra bonus)
	int vectorMarks[] = {69, 84, 40, 65, 72, 34, 80, 43, 74, 98, 60, 62, 81, 67, 12, 69, 70, 50, 71, 75, 18, 80, 26, 90, 91};

    cout << sizeof(vectorMarks)/sizeof(vectorMarks[0]) << endl << endl;

	for (int i=0; i<sizeof(vectorMarks)/sizeof(vectorMarks[0]); i++) {marks.enqueue(vectorMarks[i]);}
    
	// counts the marks in each grade band.
    Stack<int> numberFF;
	Stack<int> numberP;
	Stack<int> numberC;
	Stack<int> numberD;
	Stack<int> numberHD;

	// FOR SENG6120 students (or extra bonus)
	marks.sort();

    // prints the average, minimum and maximum score for the class.
	cout << "Average: " << marks.average() << endl;
	cout << "Min: " << marks.minimum() << endl;
	cout << "Max: " << marks.maximum() << endl;
	cout << "Stdev: " << marks.stdeviation() << endl << endl;

	// populates the stacks.
	for (int i=0; i<sizeof(vectorMarks)/sizeof(vectorMarks[0]); i++)
	{
		if (marks.front() < 50) {numberFF.push(marks.front());} // case FF
		else if ((marks.front() >= 50) && (marks.front() < 65)) {numberP.push(marks.front());} // case P
		else if ((marks.front() >= 65) && (marks.front() < 75)) {numberC.push(marks.front());} // case C
        else if ((marks.front() >= 75) && (marks.front() < 85)) {numberD.push(marks.front());} // case D
		else {numberHD.push(marks.front());} // case HD

		marks.dequeue();
	    
	}

	// prints the marks in each grade band.
	cout << "Number of FF: " << numberFF.size() << "  " << numberFF << endl;
	cout << "Number of P: " << numberP.size() << "  " << numberP << endl;
	cout << "Number of C: " << numberC.size() << "  " << numberC << endl;
	cout << "Number of D: " << numberD.size() << "  " << numberD << endl;
	cout << "Number of HD: " << numberHD.size() << "  " << numberHD << endl;

	cout << "The program has finished." << endl;
	return 0;
}
