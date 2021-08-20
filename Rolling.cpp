#include "Rolling.h"
#include <iostream>
#include "Scoring.h"
#include "Player.h"

using namespace std;

void Rolling::recursiveLooptoGameStart(vector<string>& p_player_names, vector<Player*>& p_Players)
{
	int pnum = p_Players.size();
	for(int i = 0; i < pnum; i++)
	{
		if (gameStartStatus == false)
		{
			cout << "\n\n  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
			cout << "  Player " << (i + 1) << " >>>>>>>> " << p_Players[i]->getName() << "\n\n";
			firstRoll();
			if (getScoreThisRound() < 1000)
			{
				cout << "\n\n\n";
				cout << "\n  [X X] [X X]\t\t " << getScoreThisRound() << "\t\t[X X] [X X]\n";
				cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
				cout << "    You failed to roll enough points to start game.\n\n\n";
				setScoreThisRound(0);
				system("pause>nul|set/p =  Roll dice ...");
				system("CLS");
				cout << "\n";

			}
			else  // if player rolls more than 1000 points
			{
				system("CLS");
				cout << "\n\n  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
				cout << "  Player " << (i + 1) << " >>>>>>>> " << p_Players[i]->getName() << "\n\n";
				cout << "\n\n\n";
				cout << "  [X X] [X X]\t\t " << getScoreThisRound() << "\t\t[X X] [X X]\n";
				cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
				cout << "  You scored over 1000 points!  Let the games begin!\n\n\n";
				gameStartStatus = true;		// change game play status to scorekeeping
				p_Players[i]->setScore(getScoreThisRound());
			}
		}
		else
		{
			// print nothing to run out remaining elements in for loop to continue
		}
	}	// end of for loop
	if (gameStartStatus == false) // if after iteration of all players startstatus remains equal to false, initiate recursive loop
	{
		recursiveLooptoGameStart(p_player_names, p_Players);
	}
}

int Rolling::firstRoll()
{
	// invoke function to roll dice array
	rollDice();
	cout << "\n\n\n";
	cout << "\t";
	// invoke function to show new dice array
	displayDiceRoll();
	// invoke function to score new dice array
	scoring(rolloverScore, diceRoll, reRollers);
	// if player rolls less than 1000 points show score
	//if (getScoreThisRound() < 1000)	//  && gameStartStatus == false
	//{
	//	cout << "\n\n\n";
	//	cout << "\n  [X X] [X X]\t  \t+ " << getScoreThisRound() << "\t\t[X X] [X X]\n";
	//	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	//	cout << "    You failed to roll enough points to start game.\n\n\n";
	//	setScoreThisRound(0);

	//	system("pause>nul|set/p =  Roll dice ...");
	//	system("CLS");
	//	cout << "\n";
	//	return getScoreThisRound();
	//}
	//else  // if player rolls more than 1000 points
	//{
	//	cout << "\n\n\n\n";
	//	cout << "[X X] [X X]\t\t" << getScoreThisRound() << "\t\t[X X] [X X]\n";
	//	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	//	cout << "You scored over 1000 points!  Let the games begin!\n\n\n";
	//	
	//	gameStartStatus = true;		// change game play status to scorekeeping
	//	return getScoreThisRound();
	//}
	return getScoreThisRound();
}

int* Rolling::rollDice()
{
	cout << "\n";
	// for each of the six die...
	for (int i = 0; i < NUM_DICE; i++)
	{	// pick a number by random
		int randomDiceRoll = 1 + (rand() % 6);
		// this die assigned value of random roll
		diceRoll[i] = randomDiceRoll;
	}
	cout << "\n";
	// return value of dice roll array
	return diceRoll;
}

void Rolling::displayDiceRoll()
{
	cout << "\tNew Roll: ";
	for (int i = 0; i < NUM_DICE; i++)
	{
		cout << diceRoll[i] << " ";
	}
}

/*

void Rolling::gameBegins(vector<int>)
{
	// for each player
	for (unsigned int i = 0; i < player_score.size(); ++i)
	{
		rolloverScore = 0;
		cout << "\n\n\n";
		cout << player_names[i];
		// game paused (with non-default comment)
		system("pause>nul|set/p ='s turn to roll...");
		// clear screen of previous output
		system("CLS");

		cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
		cout << "PLAYER:\t" << player_names[i] << " " << player_names[i] << " " << player_names[i] << " " << player_names[i] << " " << player_names[i] << "\n";
		cout << "\n\n\n";
		// invoke function to roll dice
		rollDice();
		// invoke function to display the dice array
		displayDiceRoll();
		cout << "\n";
		scoring();
		displayReRollers();
		cout << "\n\n\n\n\n";
		cout << player_names[i] << " scored " << scoreThisRound << " points.\n";
		cout << "[X X] [X X]\t\t+ " << scoreThisRound << "\t\t[X X] [X X]\n";
		cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
		// while values of prevArray are not equal to values of reRollers, execute reRollResponse
		while ((reRollingDice != 0) && !(std::equal(std::begin(prevArray), std::end(prevArray), std::begin(reRollers))))
		{
			if (reRollingDice == 6 && scoreThisRound > 0)
			{
				player_score[i] += scoreThisRound;
				cout << "\n\n";
				displayScores(player_score);
				reRollAllReRollable();
			}
			reRollResponse(player_score);
		}
		// place value of dice array scoring into this player's score
		player_score[i] += scoreThisRound;

		cout << "\n";
		cout << "Score after re-roll: " << player_score[i];
		// invoke function to display new dice array
		displayScores(player_score);
		// if player's score is greater than game point, escape loop
		if (player_score[i] >= MAX_SCORE)
		{
			gamePoint(player_score);
			return;
		}
	}
	gameBegins(player_score);
}

void Rolling::gamePoint(vector<int>)
{
	cout << "\n\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "[] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	cout << "\n\t\tG A M E  O V E R !\n";
	// invoke function to display final scores
	displayScores(player_score);
	cout << "\n\n";
	cout << "[] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
}

void Rolling::displayScores(vector<int>)
{
	cout << "\n\n\n\n\n";
	cout << "\t\tPLAYER SCORES\n";
	// display player scores
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "\t\t" << player_names[i] << ":\t" << player_score[i] << "\n";
	}
}

void Rolling::playAgain()
{
	char playAgainResponse;
	cout << "\nWould you like to play again? (Y or N)\t";
	cin >> playAgainResponse;
	// if player does not wish to replay
	if (playAgainResponse == 'N' || playAgainResponse == 'n')
	{
		// exit the application entirely
		exit(0);
	}
	// if player wishes to play again
	if (playAgainResponse == 'Y' || playAgainResponse == 'y')
	{	// reset value players' scores to zero before game restart
		for (unsigned int i = 0; i < player_score.size(); ++i)
		{
			player_score[i] = 0;
		}
		// reset switch for game status to start position
		gameStartStatus = false;
		// loop back to main to start game over
		main();
	}
	// handle invalid user input
	else
	{
		cout << "\nYou have entered an invalid response.";
		playAgain();
	}
}

int Rolling::pointScore(vector<int>)
{
	return 0;
}

int Rolling::reRoll(bool*)
{
	makePrevReRollerArray();

	// prints original roll
	cout << "\tOld Roll: ";
	for (int i = 0; i < NUM_DICE; i++)
	{
		cout << diceRoll[i] << " ";
	}
	// re-rolls all non-scoring die
	for (int i = 0; i < NUM_DICE; i++)
	{
		if (reRollers[i] == true)
		{
			diceRoll[i] = (rand() % 6 + 1);
		}
	}
	displayReRollers();
	// reset all reRoller values to false
	//resetRerollStatus(reRollers);
	// reset the value of dice to be re-rolled to zero
	//reRollingDice = 0;

	return diceRoll, reRollingDice;
}

void Rolling::reRollResponse(vector<int>)
{
	char rollAgain = 'n';
	cout << "\nYou have " << reRollingDice << " non-scoring die.\n";
	cout << "Would you like to roll them? (Y or N)\t";
	std::cin >> rollAgain;
	cout << "\n\n\n";
	// user choice keeps current score
	if (rollAgain == 'N' || rollAgain == 'n')
	{
		resetRerollStatus(reRollers);
		return;
	}
	// user choice rolls non-scoring dice again
	if (rollAgain == 'Y' || rollAgain == 'y')
	{
		// invoke function to re-roll dice
		reRoll(reRollers);
		cout << "\n";
		// invoke function to display new dice array
		displayDiceRoll();
		resetRerollStatus(reRollers);
		// invoke function to score new dice array
		scoring();
		displayReRollers();
		displayScores(player_score);
		cout << "\n\n\n";
		cout << "Score this round:\t" << scoreThisRound;

		//cout << "\n";
		// if all die are scoring die, add this score to player score and continue rolling
		if ((reRollingDice == 0) && (scoreThisRound > 0))
		{
			rolloverScore += scoreThisRound;
			cout << "\nSo far, your score is: " << scoreThisRound << ".";
			reRollAllReRollable();
		}
	}
	// handle incorrect user response
	else
	{
		cout << "\nYou have entered an invalid response.";
		// invoke this function again
		reRollResponse(player_score);
	}
}

int Rolling::resetRerollStatus(bool*)
{
	for (int i = 0; i < NUM_DICE; i++)
	{
		reRollers[i] = false;
	}
	reRollingDice = 0;
	return reRollingDice;
}

void Rolling::displayReRollers()
{
	cout << "\n";
	cout << "\tRe-Rolls: ";
	for (int i = 0; i < NUM_DICE; i++)
	{
		cout << reRollers[i] << " ";
	}
}

void Rolling::makePrevReRollerArray()
{
	for (int i = 0; i < NUM_DICE; i++)
	{
		prevArray[i] = reRollers[i];
	}
}

void Rolling::showPrevReRollArray()
{
	for (int i = 0; i < NUM_DICE; i++)
	{
		cout << prevArray[i] << " ";
	}
}

void Rolling::reRollAllReRollable()
{
	// just in case, resetting all reRoller values to true
	for (int i = 0; i < NUM_DICE; i++)
	{
		reRollers[i] = true;
	}
	reRollingDice = 6;
	//cout << "\n\n\n";

	cout << "\nRe-rolling your hot dice.\n";
	system("pause");
	// invoke function to re-roll dice
	cout << "\n\n";
	reRoll(reRollers);
	cout << "\n";
	// invoke function to display new dice array
	displayDiceRoll();
	// invoke function to score new dice array
	scoring();
	displayReRollers();
	cout << "\n";
}

*/