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

#define DEFSYSCON 0.8 //the default value for the system constant

class glicko2TeamSet
{
public:
	int numMatchesComplete = 0;
	float sysCon = DEFSYSCON;
	std::string test;

	std::vector<match> matchSet;
	std::vector<team> teamSet;

	void addTeam(std::string name, float rating, float RD);
	const size_t getLowestRating(); //find the index of the team with the lowest rating in the system. Will give first if multiple teams have the lowest index
	const size_t getHighestRating(); //find the index of the team with the highest rating in the system. Will give first if multiple teams have the highest rating
	//TODO sort by rating


	glicko2TeamSet(std::string testVal);
};

#endif