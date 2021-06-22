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

enum class matchMemType : unsigned short { //an enum that allows easy differentiation between the three different fields in the class
	team1,									//this is used heavily when matches are being edited from outside of this class
	team2,
	result
};

enum class result :unsigned short {			//an enum that provides access to the three possible results of a match
	team1 = 0,
	team2 = 1,
	draw = 2
};

class match
{
public:
	team* team1;
	team* team2;
	result winner;
	match(team* t1, team* t2, result win);
};
#endif

