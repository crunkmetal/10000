#pragma once
#include <vector>
#include "Scoring.h"
#include "Player.h"

using namespace std;

class Rolling : public Scoring
{
public:
	
	int diceRoll[6];
	void recursiveLooptoGameStart(vector<string>&, vector<Player*>&);
	
	bool reRollers[6] = { false };
	// bool prevArray[ NUM_DICE ] = { false };

	int firstRoll();
	int* rollDice();
	void displayDiceRoll();



	/*void gameBegins(vector<int>);
	void gamePoint(vector<int>);
	void displayScores(vector<int>);
	void playAgain();
	int pointScore(vector<int>);
	int reRoll(bool*);
	void reRollResponse(vector<int>);
	int resetRerollStatus(bool*);
	void displayReRollers();
	void makePrevReRollerArray();
	void showPrevReRollArray();
	void reRollAllReRollable();*/
};

