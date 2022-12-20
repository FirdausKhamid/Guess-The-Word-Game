#include "Player.h"


// Mutator 
void Player::setPlayerAndTeam(string p, string t)
{
	playerName = p;
	teamName = t;
}

//Accessors 
string Player::getPlayerName()
{
	return playerName;
}

string Player::getTeamName()
{
	return teamName;
}

// Overloading operator for Node class usage 
void Player::operator=(const Player& rhs)
{
	playerName = rhs.playerName;
	teamName = rhs.teamName;
}
