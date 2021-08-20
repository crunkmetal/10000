#include "Player.h"
// #include "Roster.h"

string Player::getName()
{
	string name = pvt_name;
	return name;
}

int Player::getScore()
{
	int score = pvt_score;
	return score;
}

void Player::setName(string name)
{
	pvt_name = name;
}

void Player::setScore(int score)
{
	pvt_score = score;
}
