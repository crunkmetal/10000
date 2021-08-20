#include "Collate.h"
#include "Player.h"
#include "Roster.h"
#include <iterator>
#include <vector>


void Collate::objVector(int roster, vector<Player*>& p_Players, vector<int>& p_player_scores, vector<string>& p_player_names)
{
	vector<string>::iterator it;	// Declaring iterator to a vector
	// create a new player object for each player in roster, using an iterator
	for (it = p_player_names.begin(); it < p_player_names.end(); it++)
	{
		Player* newPlayer = new Player();
		p_Players.push_back(newPlayer);
	}

	// pull data from prev two vectors and put it in another vector
	for (int i = 0; i < roster; i++)
	{
		string& name = p_player_names.at(i);
		// cout << "  Player name from Vector in for loop: " << name << "\n";
		p_Players.at(i)->setName(name);
		int& score = p_player_scores.at(i);
		// cout << "  Player score from Vector in for loop: " << score << "\n";
		p_Players.at(i)->setScore(score);
	}
}

void Collate::showObjVector(int roster, vector<Player*>& p_Players)
{
	cout << "\n";
	// display vector<object> Players' contents to console
	for (int i = 0; i < roster; i++)
	{
		cout << "  \t\t" << p_Players[i]->getName() << ":\t" << p_Players[i]->getScore() << " points.\n";
	}
	cout << "\n";
}
