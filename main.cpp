// 10000+

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
	
	Xfiles ext;
	ext.loadPages();
	for (int i = 0; i < ext.Pages.size(); i++)
	{
		ext.loadFile(ext.Pages[i]);
	}

	Roster User;									// instantiate an object of Roster class
	User.playerCount();								// get a count/number of players
	roster = User.getNumPlayers();							// var roster equals the number of players
	// cout << "  Number of players: " << roster << "\n";				// for testing
	User.populateNames(User.p_player_names);					// push player names into a vector

	Scoring Score;									// instantiate an object of Scoring class
	Score.initPlayerScores(roster, User.p_player_scores);				// initiate player scores to a vector
	
	Player Play;									// instantiate an object of Player class
	vector<Player*> Players;							// initialize a vector of pointers to Player objects
	vector<Player*>& p_Players = Players;						// initialize a vector of pointers to Player objects reference
	Collate Coll;									// instantiate an object of Collate class
	Coll.objVector(roster, p_Players, User.p_player_scores, User.p_player_names);	// invoke objVector() function from Collate class

	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "      *** SCORE 1000 POINTS TO START THE GAME ***\n\n\n";
	Coll.showObjVector(roster, p_Players);					// invoke function from Collate class to display each players objects member values
	cout << "\n\n\n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	system("pause>nul|set/p =  START...");					// WinOS specific command to pause for	 user input
	system("CLS");								// WinOS specific command to clear console

	Rolling Roll;	// instantiating an object of Rolling class
	Roll.recursiveLooptoGameStart(Play.p_player_names, p_Players);

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

