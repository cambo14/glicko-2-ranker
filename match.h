//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _MATCH_H_
#define _MATCH_H_

#include "team.h"

/*
* A class to hold information about the various
* matches included in the teamset
*/

//TODO: IMPLEMENT

class match
{
public:
	team* team1;
	team* team2;
	uint8_t winner;
	match(team* t1, team* t2, uint8_t win);
};
#endif

