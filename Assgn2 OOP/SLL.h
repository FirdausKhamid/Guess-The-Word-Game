#ifndef SLL_H
#define SLL_H
#include"Player.h"

class Node {
public:
	Player myPlayer; // making the Player object the data part of the SLL node
	Node* next;
	Node() { next = nullptr; }// default constructor
	Node(Player pl) { myPlayer = pl; next = nullptr; }//alternate constructor
};

// Single Linked List
class SLL
{
private:
	Node* head; 
	int count;
public:
	SLL() { head = nullptr; count = 0; }//default constructor
	~SLL();//destructor
	void addPlayer(const Player&); // to add player to the list
	Player getPlayerByNum(int);// to return a player by his/her number
	void destroy();//to empty the whole SLL
};

#endif