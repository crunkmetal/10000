#include "About.h"
#include <iostream>		// for cout
using std::cout;	// using this instead of entire std namespace

// function to display game rules/introduction
void About::intro()
{	
	cout << "\n\n\t [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	cout << "\t [] [] [] [] [] [] [] 10000 [] [] [] [] [] [] [] [] \n";
	cout << "\t [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";

	cout << "\t\t\t ... a dice game.\n\n\n";

	cout << "  OBJECT OF THE GAME :\n\n";
	cout << "  Player with the highest score after the point\n";
	cout << "  threshold (10,000) has been met, wins.\n\n";

	cout << "  EQUIPMENT :\n\n";
	cout << "  To play 10000, you'll need the following items:\n";
	cout << "\t  (6) 6-sided dice\n";
	cout << "\t  A score sheet and pencil for keeping score.\n\n";

	cout << "  NUMBER OF PLAYERS:\n\n";
	cout << "  10000 can be played by 2 or more players, but is best with\n";
	cout << "  3 - 8 players.\n\n";
	cout << "  [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	system("pause>nul|set/p =more ...");
	system("CLS");

	cout << "  \n\nHOW TO PLAY 10000:\n\n";
	cout << "  The following 10000 rules are the most commonly used, but there are \n";
	cout << "  numerous variations to choose from(see Variations below).Before the game\n";
	cout << "  begins, players should establish which rules or variations will be used.  \n";
	cout << "  Our scoring summary chart makes this process easy and provides for endless \n";
	cout << "  variety in your 10000 games!\n\n";

	cout << "  One player is chosen to begin and play moves clockwise around the table.  \n";
	cout << "  Each player in turn rolls all six dice and checks to see if they have rolled \n";
	cout << "  any scoring dice or combinations. (See Scoring below.) Any dice that score \n";
	cout << "  may be set aside and then the player may choose to roll all the remaining \n";
	cout << "  dice.  The player must set aside at least one scoring die of their choice if \n";
	cout << "  possible but is not required to set aside all scoring dice.\n\n";

	cout << "  For example, if a player rolled 1 - 2 - 2 - 5 - 5 - 6 on their turn, they \n";
	cout << "  could set aside the 1 and the two 5's for scoring, or they could choose to \n";
	cout << "  set aside only the 1. Any scoring dice that are not set aside may be \n";
	cout << "  re-rolled along with the non-scoring dice.\n\n";
	system("pause>nul|set/p =more ...");
	system("CLS");

	cout << "\n\n  If all six dice have been set aside for scoring(known as having 'hot dice'),\n";
	cout << "  the player can choose to roll all six dice again and continue adding to their\n";
	cout << "  accumulated score or they can bank their points, end their turn, and pass the\n";
	cout << "  dice to the next player.\n\n";

	cout << "  A player's turn continues until either they decide to stop (at which point\n";
	cout << "  they then score their accumulated points) or until they fail to roll any scoring\n";
	cout << "  dice on a throw.\n\n";

	cout << "  If a player scores no points on a roll, this is known as a Farkle.  The \n";
	cout << "  player may continue to roll any dice that have not been previously set \n";
	cout << "  aside for scoring, but all of their points gained so far that turn are lost.\n\n";

	cout << "  At the end of a player's turn, any points they have scored are written \n";
	cout << "  down and the dice are passed to the next player.\n\n";
	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	system("pause>nul|set/p =more ...");
	system("CLS");

	cout << "\n\n  SCORING:\n\n";
	cout << "\t1\t\t100 points\n";
	cout << "\t5\t\t50 points\n";
	cout << "\tThree 1's\t1,000 points\n";
	cout << "\tThree 2's\t200 points\n";
	cout << "\tThree 3's\t300 points\n";
	cout << "\tThree 4's\t400 points\n";
	cout << "\tThree 5's\t500 points\n";
	cout << "\tThree 6's\t600 points\n";
	cout << "\t1 - 2 - 3 - 4 - 5 - 6\t3000 points\n";
	cout << "\t1 - 1 - 1 - 1 - 1 - 1\t10000 points and game is won!\n\n";

	cout << "  *** Note that scoring combinations only count when made with a single \n";
	cout << "  throw. (Example: If a player rolls a 1 and sets it aside and then rolls \n";
	cout << "  two 1's on their next throw, they only score 300 points, not 1000.)\n\n";
	system("pause>nul|set/p =more ...");
	system("CLS");

	cout << "\n\n  Sometimes a single roll will provide multiple ways to score.  For example, \n";
	cout << "  a player rolling 1 - 2 - 4 - 5 - 5 - 5 could score one of the following :\n\n";

	cout << "\t100 points for the 1\n";
	cout << "\t150 points for the 1 and a 5\n";
	cout << "\t500 points for the three 5's\n";
	cout << "\t600 points for the 1 and the three 5's\n\n\n";

	cout << "  WINNING:\n\n";
	cout << "  The first player to score a total of 10,000 or more points wins, provided \n";
	cout << "  that no other players with a remaining turn can exceed that score.\n\n";
	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n\n";

	cout << "  OPENING SCORE:\n\n";
	cout << "  One person, at random, rolls the dice once.  The first person to score 1000\n";
	cout << "  points or more, starts the game and keeps those points.\n\n";
	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n\n";


	cout << "  THREE FARKLES:\n\n";
	cout << "  A player who rolls three Farkles in a row loses 1000 points.\n\n";
	cout << " [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n\n";
	system("pause>nul|set/p =Press any key to start ...");
	system("CLS");
}