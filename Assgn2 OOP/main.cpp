/*************************************************************************************************************
CPT113 : Assignment 2 | Hackathon 2                                                                           *
Project: Guess the word game using OOP and Data structures                                                    *
Group: 41                                                                                                     *
Names and ID:                                                                                                 *
1)MOHAMAD FIRDAUS BIN KASAH HAMID @ KASMIDY,  152954                                                          *
2)HAZEM AHMED MOHAMED NABIL ABDELRAOUF,       154648                                                          *
                                                                                                              *
Data strcuture choice : 1)SLL  2) Queue                                                                       *     
Reason behind Data structures choice:-                                                                        *
                                                                                                              *
1)SLL:we used it to only retain the players' info (i.e. player name and team name),                           *
by inserting them 1 by 1 in the back and for searching the list for them and returning the searched player    *
                                                                                                              * 
2)Queue: we used it to hold the guess words info (i.e. the words and its hints), by adding and retaining them * 
in a queue form and then processing them 1 by 1 from the front of the queue fulfiling the FIFO principle      *
                                                                                                              *
Reason behind having the txt file as a source of input:                                                       *
This txt file contains the guess words and their hints, so we used as a word bank for our game                *
                                                                                                              *                                       
***************************************************************************************************************/

#include <iostream>
#include<string>
#include<fstream>
#include"SLL.h" //including the SLL class
#include"Queue.h" //including the Queue class
using namespace std;

// Declaration of functions
void instructions();// display instructions of game
void header(); // function to maintain the title of the game up in the display
void printWordWithHints(string, string, int);// it prints the words with their hints
void endGameMessage(string, string, int);// displaying the ending messgage indicating game over when a team wins or both lose
int getAndValidateNumOfPlayers();// getting and validating the number of players per team

int main()
{
    
    const int WIN_CODE = 1, // the code to indicate that a team won
              LOSE_CODE = 0;// the code to indicate that both teams lost
    
    //Multi-purpose temp variables and objects
    string name, team1Name, team2Name, w, h;
    Player currentPlayer;// to the player info in multiple occasions
    GuessWord word; //to the word info in multiple occasions

    
    
    //Data structure objects
    Queue wordQueue;//Queue to hold the words
    SLL team1, //SLL object to hold the players of team 1
        team2; //SLL object to hold the players of team 2
    
    int numOfPlayers;// to hold the num of the players per team
    string guess; // to hold the guess of the players
    bool guessedIt = false;// to determine if a player has guessed the word correctly or not
    char again;//sentinel for do while loop   
    ifstream inFile;
    
    inFile.open("word bank.txt");
    if (!inFile)
    {
        cout << "The word bank.txt can't be reached please put it in the directory of this program "
            << "and re-run again\n";
        return 0;
    }
    //getting the words with their hints from the txt file into the queue
    while (!inFile.eof())
    {
        getline(inFile, w, ';');
        getline(inFile, h);
        word.setWordAndHint(w, h);
        wordQueue.enqueue(word);
    }
   

    instructions(); //displaying instructions
    numOfPlayers = getAndValidateNumOfPlayers();// getting the number of players in each team and validating them
    
    cout << "\nPlease enter the name of team 1:"; //getting the name of team 1
    getline(cin,team1Name);

    cout << "Please enter the name of team 2:";//getting the name of team 2
    getline(cin, team2Name);
   
    //loop for recieving the players name for both teams  
    for (int i = 1; i <= numOfPlayers; ++i) {
        
        cout << "Please Enter the name of player " << i << " in team " << team1Name<<" :";
        getline(cin, name);
        currentPlayer.setPlayerAndTeam(name, team1Name);
        team1.addPlayer(currentPlayer);
        
        cout << "Please Enter the name of player " << i << " in team " << team2Name << " :";
        getline(cin, name);
        currentPlayer.setPlayerAndTeam(name, team2Name);
        team2.addPlayer(currentPlayer);

    }

    do//the start of the game loop  
    {
        system("CLS");
        if (!wordQueue.isEmpty()) // to get a word from our Queue
            word = wordQueue.dequeue();
        else {
            cout << "Congrats you used all available game words\nIf you want to play again please rerun the program.\n";
            return 0;  
        }
        
        w = word.getWord();// keeping the actual word in to use it directly below 
        
        //The rounds loop  
        for (int round = 1; round <= w.size() - 1  ; )//increment part later below
        {
            printWordWithHints(word.getWord(),word.getHint(), round);//print the word letters and blanks and the hint 

                //The players' turns loop
                for (int playerNum = 1; playerNum <= numOfPlayers; ++playerNum)
                {
                    currentPlayer = team1.getPlayerByNum(playerNum);//getting player with his/her correct order from SLL of team 1 to play his/her turn
                    cout << "It's " << currentPlayer.getPlayerName() << "'s turn from team " << currentPlayer.getTeamName() << endl;
                    cout << "Please enter your guess:";
                    getline(cin, guess);
                    if (guess == w)// comparing the guess with the actual word
                    {
                        endGameMessage(currentPlayer.getTeamName(), word.getWord(), WIN_CODE);//to show the end game message with winning code
                        guessedIt = true;// made true to escape the outer for loop i.e. the rounds loop
                        break;// to escape this loop i.e. the turns loop
                    }
                    else
                        cout << "Wrong Guess.\n\n";

                    currentPlayer = team2.getPlayerByNum(playerNum); //getting player with his/her correct order from SLL of team 2 to play his/her turn
                    cout << "It's " << currentPlayer.getPlayerName() << "'s turn  from team " << currentPlayer.getTeamName() << endl;
                    cout << "Please enter your guess:";
                    getline(cin, guess);
                    if (guess == w)
                    {
                        endGameMessage(currentPlayer.getTeamName(), word.getWord(), WIN_CODE);//to show the end game message with winning code
                        guessedIt = true;
                        break;
                    }
                    else
                        cout << "Wrong Guess.\n\n";

                }

            if (guessedIt)//to get out of the rounds loop and ask if you want to play another game or not
                break;

            //increment of round loop is here
            if (++round == w.size())//to check if both teams couldn't guess the word 
                endGameMessage("", word.getWord(), LOSE_CODE);//code zero to say both teams lost
            else
                system("CLS");

        }

        
        guessedIt = false;//resetting gusessedIt for the next game beforehand 
        cout << "Do you want to play a new game and try to guess another word?(Y/N) :";
        cin >> again;
	cin.clear();
	cin.ignore(100,'\n'); 
    } while (again == 'Y' || again=='y');
    
    return 0;
}

// instructions display function 
void instructions() 
{
    system("CLS");
    cout << "\n\n";
    cout << "\t******************************************************************************************" << endl;
    cout << "\t<<<<<<<<<<<<<<<<<<          Welcome to Guess The Word Game              >>>>>>>>>>>>>>>>>>" << endl;
    cout << "\t******************************************************************************************" << endl;
    cout << "\n\n\tHow to play :" << endl;
	cout << "\t1. Register 2 teams and 2-4 players per team" << endl;
	cout << "\t2. The game will start" << endl;
	cout << "\t3. A hint will pop up for each round" << endl;
	cout << "\t4. each player from every team will take turn until one gets it right or both teams lose" << endl;
	cout << "\t5. All letters of the words are in small-case."<<endl;
    cout << "\n\t =========>    Press any keys to START YOUR GAME!  <========== \n\n";
    system("PAUSE");
    system("CLS");
}

// Aesthetic Function to keep the title of the game at the top of the console
void header()
{
    system("CLS");
    cout << "\t******************************************************************************************" << endl;
    cout << "\t<<<<<<<<<<<<<<<<<<               Guess The Word Game                    >>>>>>>>>>>>>>>>>>" << endl;
    cout << "\t******************************************************************************************" << endl;
    cout << "\n\n\n";
}

// Word and Hint Display Function
void printWordWithHints(string curWord,string curHint, int roundNum)  
{
    header();
    cout << "\t\t====================      Game Start        ===================\n";
    cout << "\t\t====================      round: " << roundNum << "/" << curWord.size() - 1 << "        ===================\n";
    cout << "\n\t\tThe hint is: \"" << curHint << " \"\n\n\t\t\t\t\t";

    for (int i = 0; i < roundNum ; ++i)// to print the hint letters 
        cout << curWord[i] << " ";
    for (int j = 1; j <= curWord.size() - roundNum; ++j)//to print blank spaces
        cout << "_ ";
    
    cout << endl;
}

// Input validation function for numOfPlayers
int getAndValidateNumOfPlayers()
{
    header();
    int num;
    cout << "Please enter the number of players in each team (2-4): ";
    cin >> num;
    while (!num || num < 2 || num>4)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter only 2, 3 or 4:";
        cin >> num;

    }
    cin.clear();
    cin.ignore(100, '\n');
    return num;
}

//to print the correct end game message depending on the code passed
void endGameMessage(string team, string word, int code)
{
    if (code == 0) { // message for losing code
        cout << "\n--------------------------------------------------------------\n";
        cout << "\t\tBoth teams lost, The word is " << word << endl;
        cout << "--------------------------------------------------------------\n";
    }
        
    else // message for winnig code
    {
        cout << "*************************************************************************\n";
        cout << "\tCongratulations team " << team << " you guessed the word right!!!!   " << endl;
        cout << "*************************************************************************\n";
    }
}


