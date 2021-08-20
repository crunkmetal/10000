#pragma once
#include <vector>
#include <string>
#include "Roster.h"
// #include "Rolling.h"

class Scoring : public Roster
{
public:

	int rolloverScore = 0;
	int reRollingDice;
	bool gameStartStatus = false;
	const int NUM_DICE = 6;
	const int MAX_SCORE = 10000;

	int scoring(int, int[], bool[]);
	int getScoreThisRound();
	void setScoreThisRound(int);
	void initPlayerScores(int, vector<int>&);



	

	/*
	void displayScores(int, vector<string>&, vector<int>&);
	void reachMinScoreToStartGame(int, vector<int>&, vector<string>&);*/
	
	
private:
	int scoreThisRound = 0;
};





// LOVE THIS

/*
vector<Type> vect;
// will allocate the 'vector' on the stack,
// but the elements on the free store ("heap").

vector<Type> *vect = new vector<Type>;
// allocates everything on the free store.

vector<Type*> vect;
*/