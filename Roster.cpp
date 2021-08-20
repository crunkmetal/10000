#include <iostream>
#include <vector>
#include <string>
#include "Roster.h"
// #include "Player.h"


using namespace std;
// populate a vector with a user names
void Roster::populateNames(vector<string> &pn)
{
	string userName;
	int num = getNumPlayers();
	int i = 0;
	// loop through players, have user assign a name for each
	do
	{
		cout << "\n  What is the name of Player " << i + 1 << "?\t";
		cin >> userName;

		pn.push_back(userName);
		// clear screen
		system("CLS");
		i++;
	} while (i < num);
}

// user input/get number of players in the game
void Roster::playerCount()
{
	int userChoice = 0;
	cout << "\n\n  How many players for this game?\n";
	cout << "  (Enter a number between 2 - 8)\t";
	cin >> userChoice;

	// check to verify there are between 2 - 8 players
	if (userChoice > 1 && userChoice < 9)
	{
		setNumPlayers(userChoice);
		system("CLS");
	}
	else // if not between 2 - 8 players, inform and ask again
	{
		system("CLS");
		cout << "\n\n  Please enter a number between 2 and 8...\n  ";
		system("pause");
		system("CLS");
		playerCount();
	}
}

int Roster::getNumPlayers()
{
	return numPlayers;
}

void Roster::setNumPlayers(int X)
{
	numPlayers = X;
}
