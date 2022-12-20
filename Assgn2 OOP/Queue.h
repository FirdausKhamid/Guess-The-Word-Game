#ifndef QUEUE_H
#define QUEUE_H
#include "GuessWord.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class QNode
{
public:
	GuessWord gWord; // making the GuessWord object the data part of the Queue node
	QNode* next;
	QNode() { next = nullptr; }; // Default Constructor
	QNode(GuessWord gW) { gWord = gW; next = nullptr; }; // Alternate Constructor 
};

class Queue
{
private: 
	QNode* front, *end;
	
public: 
	Queue();	// Constructor
	~Queue();	// Destructor
	bool isEmpty();  // to check if the queue is empty or not
	void enqueue(GuessWord); // to enqueue 
	GuessWord dequeue(); // to dequeue
	void clear();// to clear the queue

};
#endif 
