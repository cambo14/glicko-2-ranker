//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _GLICKO2TEAMSET_H_
#define _GLICKO2TEAMSET_H_

#include <vector>
#include <iostream>
#include <QObject>
#include "match.h"
#include "team.h"

#define DEFSYSCON 0.5 //the default value for the system constant
#define CONTOL 0.000001 //the convergence tolerance of the system TODO allow it to be changed by the system

/*
* A class to handle all the information and
* calculations associated with the glicko-2 system
* and to store all matches and teams
*/

//TODO: implement class

class glicko2TeamSet : public QObject
{
public:
	int numMatchesComplete = 0;
	float sysCon = DEFSYSCON;
	std::string test;

	std::vector<match> matchSet;
	std::vector<team> teamSet;

	void addTeam(std::string name, float rating, float RD);



	const size_t getLowestRating() const; //find the index of the team with the lowest rating in the system. Will give first if multiple teams have the lowest index
	const size_t getHighestRating() const; //find the index of the team with the highest rating in the system. Will give first if multiple teams have the highest rating
	//TODO sort by rating


	glicko2TeamSet(std::string testVal);
public slots:
	void rateTeams();
};

#endif