#ifndef GUESSWORDS_H
#define GUESSWORDS_H

#include <iostream>
#include <string>

using namespace std;

class GuessWord
{
private : 
	string word;//To store the actual word
	string hint;//to store the hint
public :
	GuessWord() { word = ""; hint = ""; } 			// Default Constructor
	~GuessWord() { word = ""; hint = ""; } 	    // Destructor
	
	// Mutator 
	void setWordAndHint(string w, string h);
	// Accessor
	string getWord();
	string getHint();

	// operator overloading function to be used when dequeue from the Queue
	void operator=(const GuessWord&);
};

#endif 

