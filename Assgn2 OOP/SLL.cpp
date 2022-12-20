#include "SLL.h"
#include<cassert>




// adding a player to the SLL
void SLL::addPlayer(const Player& pl)
{
	Node* newNode = new Node(pl);
	
	if (!head)// if the list is empty
		head = newNode;
	else
	{
		Node* cur = head; 
		for( ; cur->next ; cur = cur->next) {}//getting the last node to be "cur"
		cur->next = newNode; 

	}
	++count;
	
}

// get the player by his or her number
Player SLL::getPlayerByNum(int num)
{
	assert((num >= 1  && num <= count));
	
	int  i = 1;
	for (Node* cur = head  ;  cur  ; cur = cur->next, ++i)
		if (i == num)
			return cur->myPlayer;
}

void SLL::destroy() //deleting the whole list
{
	Node* tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
		--count;
	}
}

SLL::~SLL()
{
	destroy();
}