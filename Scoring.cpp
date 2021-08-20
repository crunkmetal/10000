#include "Scoring.h"
// #include "Rolling.h"
#include <vector>
#include <string>
#include <iostream>
#include "Rolling.h"
using namespace std;

int Scoring::scoring(int rolloverScore, int diceRoll[], bool reRollers[])
{
	// reset each variable to zero at roll start
	int oneDie = 0;
	int twoDie = 0;
	int threeDie = 0;
	int fourDie = 0;
	int fiveDie = 0;
	int sixDie = 0;
	int score = 0;
	// reset value of non-scoring dice to zero (redundant)
	reRollingDice = 0;
	// loop through all six die to determine point value of roll
	for (int i = 0; i < NUM_DICE; i++)
	{
		switch (diceRoll[i])
		{
			// if this die is equal to a one...
		case 1:
			// each 'one' is worth 100 points
			score += 100;
			// this 'one' is set to non-rerollable status
			reRollers[i] = false;
			// increment the number of 'one' die
			oneDie++;
			// then break from swich statement
			break;
			// if this die is equal to two...
		case 2:
			twoDie++;
			// add to dice to be rerolled count
			reRollingDice++;
			// this die is set to re-rollable status
			reRollers[i] = true;
			break;
		case 3:
			threeDie++;
			// add to dice to be rerolled count
			reRollingDice++;
			reRollers[i] = true;
			break;
		case 4:
			fourDie++;
			// add to dice to be rerolled count
			reRollingDice++;
			reRollers[i] = true;
			break;
		case 5:
			score += 50;
			reRollers[i] = false;
			fiveDie++;
			break;
		case 6:
			sixDie++;
			// add to dice to be rerolled count
			reRollingDice++;
			reRollers[i] = true;
			break;
		}
	}
	// rolling all ones wins the game
	if (oneDie == 6)
	{
		std::cout << "\n\t***** 10000! *****\n";
		std::cout << "\nYou rolled all ones... 1 1 1 1 1 1\n";

		// six ones is equal to 10000
		score += MAX_SCORE;

		// all of which become re-rollable die to surpass score of 10000
		for (int i = 0; i < NUM_DICE; ++i)
		{
			reRollers[i] = true;
			// all of which become re-rollable die to surpass score of 10000
		}
		reRollingDice = 6;
		//return score;
	}
	// scoring for straight (123456)
	if (oneDie == 1 && twoDie == 1 && threeDie == 1 && fourDie == 1 && fiveDie == 1 && sixDie == 1)
	{	// subtract individual accumulated scores (from switch)from ones from score and add the value of a one threesome
		score = (score - 150) + 3000;
		std::cout << "\nYou rolled a straight... 1 2 3 4 5 6\n";

		// all die status changed to rerollable
		for (int i = 0; i < NUM_DICE; ++i)
		{
			reRollers[i] = true;
		}
		reRollingDice = 6;
	}

	// scoring for ones rolled
	if (oneDie == 5)
	{
		score = (score - 500) + 1200;
	}
	else if (oneDie == 4)
	{
		score = (score - 400) + 1100;
	}
	else if (oneDie == 3)
	{
		score = (score - 300) + 1000;
	}// end of scoring for 1s







	// scoring for twos (for six 2s)
	if (twoDie == 6)
	{
		score += 400;
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 2, set reRoller status to false
			if (diceRoll[i] == 2)
			{
				reRollers[i] = true;
			}
			reRollingDice = 6;
		}
	}
	else if (twoDie == 4 || twoDie == 5)
	{
		score += 200;
		int dieCountOver3Count = 0;
		// if 2 die count is four or five, change re-roll status for only three 2s
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 2, set reRoller status to false
			if (diceRoll[i] == 2 && dieCountOver3Count < 3)
			{
				++dieCountOver3Count;
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// scoring for twos (for three 2s)
	else if (twoDie == 3)
	{
		score += 200;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 2)
			{
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// end of scoring for twos





	// scoring for threes (for six 3s)
	if (threeDie == 6)
	{
		score += 600;
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 3, set reRoller status to false
			if (diceRoll[i] == 3)
			{
				reRollers[i] = true;
			}
			reRollingDice = 6;
		}
	}
	else if (threeDie == 4 || threeDie == 5)
	{
		score += 300;
		int dieCountOver3Count = 0;
		// if 3 die count is over three but less than 6, change reroll status for only three 3s
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 3, set reRoller status to false
			if (diceRoll[i] == 3 && dieCountOver3Count < 3)
			{
				dieCountOver3Count++;
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// scoring for threes (for three 2s)
	else if (threeDie == 3)
	{
		score += 300;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 3)
			{
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// end of scoring for threes




	// scoring for fours (for six 4s)
	if (fourDie == 6)
	{
		score += 800;
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 4, set reRoller status to false
			if (diceRoll[i] == 4)
			{
				reRollers[i] = true;
			}
			reRollingDice = 6;
		}
	}
	else if (fourDie == 4 || fourDie == 5)
	{
		score += 400;
		int dieCountOver3Count = 0;
		// if 4 die count is over three but less than 6, change reroll status for only three 4s
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 4, set reRoller status to false
			if (diceRoll[i] == 4 && dieCountOver3Count < 3)
			{
				dieCountOver3Count++;
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// scoring for fours (for between three and five 4s)
	else if (fourDie == 3)
	{
		score += 400;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 4)
			{
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// end of scoring for fours




	// scoring for fives (for between three and five 4s)
	if (fiveDie == 6)
	{
		score = (score - 300) + 1000;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 5)
			{
				reRollers[i] = true;
			}
			reRollingDice = 6;
		}
	}
	else if (fiveDie == 5)
	{
		score = (score - 250) + 600;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 5)
			{
				reRollers[i] = false;
			}
		}
	}
	else if (fiveDie == 4)
	{
		score = (score - 200) + 550;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 5)
			{
				reRollers[i] = false;
			}
		}
	}
	else if (fiveDie == 3)
	{
		score = (score - 150) + 500;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 5)
			{
				reRollers[i] = false;
			}
		}
	}// end of fives scoring


	// scoring for sixes (for six 6s)
	if (sixDie == 6)
	{
		score += 1200;
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 6, set reRoller status to false
			if (diceRoll[i] == 6)
			{
				reRollers[i] = true;
			}
			reRollingDice = 6;
		}
	}
	else if (sixDie == 4 || sixDie == 5)
	{
		score += 600;
		int dieCountOver3Count = 0;
		// if 6 die count is four or five, change reroll status for only three 6s
		for (int i = 0; i < NUM_DICE; i++)
		{
			// if Die is a 6, set reRoller status to false
			if (diceRoll[i] == 6 && dieCountOver3Count < 3)
			{
				dieCountOver3Count++;
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}	// scoring for sixes (for three 6s)
	else if (sixDie == 3)
	{
		score += 600;
		for (int i = 0; i < NUM_DICE; i++)
		{
			if (diceRoll[i] == 6)
			{
				reRollers[i] = false;
				reRollingDice--;
			}
		}
	}// end of scoring for sixes
	// if statement for farkle roll, no re-rolling die and no score = F A R K L E !
	if (reRollingDice == 6 && score == 0)
	{
		cout << "\n\t\t F A R K L E !\n";
		score = 0;
		rolloverScore = 0;
		for (int i = 0; i < NUM_DICE; i++)
		{
			reRollers[i] = false;
		}
		reRollingDice = 0;
		// return score, rolloverScore;
	}
	// reset value of global var to zero before...
	scoreThisRound = 0;
	// set value of global var to this player's score
	scoreThisRound = score + rolloverScore;

	// cout << "\n  value of score:\t" << score << "\n";
	// cout << "  value of rollover score: " << rolloverScore << "\n";

	return scoreThisRound, reRollingDice;
}	// end of scoring()


void Scoring::initPlayerScores(int num, vector<int>& pscores)
{
	// set each player score to 0
	for (int i = 0; i < num; i++)
	{
		pscores.push_back(0);
	}
}




int Scoring::getScoreThisRound()
{
	return scoreThisRound;
}

void Scoring::setScoreThisRound(int roundScore)
{
	scoreThisRound += roundScore;
}

/*
void Scoring::reachMinScoreToStartGame(int roster, vector<int>& pscores, vector<string>& names)
{
	int playerCount = roster;

	for (int i = 0; i < playerCount; i++)
	{
		if (pscores.at(i) < 1000)
		{
			int tempScore = getScoreThisRound();
			while (tempScore < 1000 && gameStartStatus == false)
			{
				for (int i = 0; i < playerCount; ++i)
				{
					cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
					cout << " PLAYER:\t" << names.at(i) << " " << names.at(i) << " " << names.at(i) << " " << names.at(i) << " " << names.at(i) << "\n";
					// invoke roll function (pre -1000pts)
					// firstRoll(); // --------------------------------------------------------------------------------------------------------

					if (tempScore == 0)
					{
						pscores[i] = 0;
						cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
					}
					else if (tempScore >= 1000)
					{
						pscores[i] = tempScore;
						cout << "Round Score:\t" << tempScore << "\n\n";
						tempScore = 0;

						break;
					}
					else
					{
						tempScore = 0;
					}
				}
			}
		}
	}

}





void Scoring::displayScores(int num, vector<string>& names, vector<int>& pscores)
{
	cout << "\t\t  PLAYER SCORES\n\n";
	for (int i = 0; i < num; ++i)
	{
		cout << "\t  " << names.at(i) << ":\t  " << pscores.at(i) << "\n";
	}
}


*/