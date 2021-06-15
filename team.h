#ifndef _TEAM_H_
#define _TEAM_H_
#include <iostream>

/*
* a class that holds the value for each individual team
*/

class team
{
public:
	team(std::string nam, float ratin, float R);

	std::string name;
	float rating;
	float RD;
	float volatility;
	int matchWonCount = 0;
	int matchLostCount = 0;
	int matchDrawnCount = 0;
};

#endif

