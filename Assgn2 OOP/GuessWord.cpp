#include "GuessWord.h"




//Mutator 
void GuessWord::setWordAndHint(string w, string h)
{
	word = w;
	hint = h;
}

// Accessor for the word
string GuessWord::getWord()
{
	return word;
}
// Accessor for the hint
string GuessWord::getHint()
{
	return hint;
}

// operator overloading function
void GuessWord::operator=(const GuessWord& rhs)
{
	word = rhs.word;
	hint = rhs.hint;
}

