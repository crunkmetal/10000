#pragma once

#include <iostream>
#include <vector>

#include "Roster.h"
using namespace std;

class Player : public Roster
{
public:
	string getName();
	int getScore();
	void setName(string);
	void setScore(int);

	// constructor
    Player() {}
    Player(int score)
    {
        Player::setScore(score);
    }
    Player(string name, int score)
    {
        Player::setName(name);
        Player::setScore(score);
    }


    ~Player() { cout << ".."; }


    //// constructors
    //Processing() { cout << "  *** Memory allocated thru constructor.\n"; }      // default constructor

    //Processing(string a, string b, string c, string d)                      // constructor taking four params
    //{
    //    cout << "  *** Memory allocated thru parameterized constructor.\n";
    //    author = a;
    //    year = b;
    //    title = c;
    //    publisher = d;
    //}
    //~Processing() { cout << "  *** Memory deallocation from destructor.\n"; }   // destructor


private:
	string pvt_name;
	int pvt_score = 0;
};

