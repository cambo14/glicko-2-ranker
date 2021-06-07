#ifndef _GLICKO2TEAMSET_H_
#define _GLICKO2TEAMSET_H_

#include <vector>
#include <iostream>
#include "match.h"
#include "team.h"

/*
* A class to handle all the information and
* calculations associated with the glicko-2 system
* and to store all matches and teams
*/

//TODO: implement class

class glicko2TeamSet
{
public:
	std::string test;
	std::vector<match> matchSet;
	std::vector<team> teamSet;

	glicko2TeamSet(std::string testVal);

	void addTeam(std::string name, float rating, float RD);
};

#endif