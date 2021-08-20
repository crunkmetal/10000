#pragma once
#include "Roster.h"
#include "Player.h"

class Collate : public Roster
{
public:
    void objVector(int, vector<Player*>&, vector<int>&, vector<string>&);
    void showObjVector(int, vector<Player*>&);
};

