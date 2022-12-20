#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;
class Player
{
private:
	string playerName; 
	string teamName;
public:
	Player() { playerName = teamName = ""; } // Default Constructor
	~Player() { playerName = teamName = ""; } // Destructor
	
	// Mutator 
	void setPlayerAndTeam(string, string); 
	
	// Accessors
	string getPlayerName();
	string getTeamName();
	
	// operator overloading function to be used when returning a player object from the SLL
	void operator=(const Player&);
};

#endif