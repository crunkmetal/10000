// 10000+

/*
The application should not be something just to demonstrate the requirements, it should "do" something, be innovative.
Be clever, not complex.
This application is required to have a good UX.
This application is required to be over commented.
Create a C++ application or game of your choice. It must meet each the requirements of the items listed below:
Note: You can opt-out of a maximum of 5 items below which don't fit into your project, but not more than 5.

Opening screen with a description of the application and instructions [] (done here, but make an i/o op)
Menu for the user to choose options			[]	(kinda - numPlayers & names)
At least 4 classes total					[]	(given here)
Inheritance (minimum 2 derived classes)		[]	(base: Roster/derived: Player, Scoring & base: Scoring/derived: GameStart)
Polymorphism (Overloading and overriding)
Encapsulation								[]  (private member access found in Roster, Player and Scoring)
File input and output processing
Multi-Threading
Templates
Vectors										[]	( three so far, Roster.h, main, Collate.cpp )
Iterators									[]	( shown in Collate::objVector() )
Recursion									[]  ( i.e Collate::recursiveLooptoGameStart )
Exception handling
Abstraction									[]  ( found in Classes Roster, Player and Scoring via public/pvt access modifiers)

Submission
A screenshot of your application running
The project source code files.

// TODO: farkle give 50 pts?

*/

#include <iostream>
#include <vector>
#include <string>

#include "About.h"
#include "Scoring.h"
#include "Roster.h"
#include "Player.h"
#include "Collate.h"
#include "Rolling.h"
#include "Xfiles.h"

// #define NUM_DICE = 6

using namespace std;

// global directives
int roster = 0;
//const int MAX_SCORE = 10000;
//const int NUM_DICE = 6;
//int rolloverScore = 0;
//int diceRoll[6];
//int reRollingDice;
//int scoreThisRound;
//bool reRollers[6] = { false };
//bool prevArray[NUM_DICE] = { false };

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	
	// TODO:	switch the intro into an i/o operation, may have to break one file into many
	//About A;
	//A.intro();
	Xfiles ext;
	ext.loadPages();
	// string page = "xfiles//xfile_1.txt";
	for (int i = 0; i < ext.Pages.size(); i++)
	{
		ext.loadFile(ext.Pages[i]);
	}


	Roster User;											// instantiate an object of Roster class
	User.playerCount();										// get a count/number of players
	roster = User.getNumPlayers();						// var roster equals the number of players
	// cout << "  Number of players: " << roster << "\n";		// for testing
	User.populateNames(User.p_player_names);				// push player names into a vector

	Scoring Score;											// instantiate an object of Scoring class
	Score.initPlayerScores(roster, User.p_player_scores);	// initiate player scores to a vector
	
	Player Play;											// instantiate an object of Player class
	vector<Player*> Players;								// initialize a vector of pointers to Player objects
	vector<Player*>& p_Players = Players;					// initialize a vector of pointers to Player objects reference
	Collate Coll;											// instantiate an object of Collate class
	Coll.objVector(roster, p_Players, User.p_player_scores, User.p_player_names);	// invoke objVector() function from Collate class

	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "      *** SCORE 1000 POINTS TO START THE GAME ***\n\n\n";
	Coll.showObjVector(roster, p_Players);					// invoke function from Collate class to display each players objects member values
	cout << "\n\n\n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	system("pause>nul|set/p =  START...");					// WinOS specific command to pause for	 user input
	system("CLS");											// WinOS specific command to clear console


	Rolling Roll;	// instantiating an object of Rolling class
	Roll.recursiveLooptoGameStart(Play.p_player_names, p_Players);






	// THE FOLLOWING CODE ONLY KINDA WORKS >>>
	/*for (int i = 0; i < p_Players.size(); i++)
	{
		while (Score.gameStartStatus == false)
		{
			if (Score.gameStartStatus == false && Score.getScoreThisRound() < 1000)
				Roll.firstRoll();

		}
	};*/  // run code block until gameStartStatus is changed to true (1000pts scored)








	cout << "  a pause before deleting objects in vector.\n\n  ";
	system("pause");	cout << "\n\n";

	// deallocate new obj memory when you are done with your vector
	for (int i = 0; i < roster; i++)
	{
		delete p_Players.at(i);
	}
	cout << "\n\n  ";	system("pause");	cout << "\n\n  ";
	return 0;
}

