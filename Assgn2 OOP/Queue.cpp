#include "Queue.h"


Queue::Queue()
{
	front = nullptr;
	end = nullptr;
}


bool Queue::isEmpty()
{
	return	!front;
}

void Queue::enqueue(GuessWord gw)
{
	QNode* newNode = new QNode(gw);
	if (isEmpty())//if the list is empty
		front = end = newNode;
	else//if the list is not empty
	{
		end->next = newNode;
		end = newNode;
	}
}

GuessWord Queue::dequeue()
{
	assert(!isEmpty());
	GuessWord gw = front->gWord;
	QNode* temp = front->next;
	delete front;
	front = temp;
	return gw;
}



void Queue::clear()
{
	GuessWord temp;// temp object
	while (!isEmpty())
		temp = dequeue();
}




Queue::~Queue()
{
	clear();
}