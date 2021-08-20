#pragma once
#include <vector>
#include <string>
// #include "Player.h"

using namespace std;

class Roster
{

public:
	void populateNames(vector<string>&);

	void playerCount();
	
	void setNumPlayers(int);

	int getNumPlayers();

	vector<string> &p_player_names = player_names;
	vector<int> &p_player_scores = player_scores;

private:
	int numPlayers;
	vector<string> player_names{};
	vector<int> player_scores{};
};

