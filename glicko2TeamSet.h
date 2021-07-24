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
#define CONTOL 0.000001 //the convergence tolerance of the system

/*
* A class to handle all the information and
* calculations associated with the glicko-2 system
* and to store all matches and teams
*/


class glicko2TeamSet : public QObject
{
public:
	int numMatchesComplete = 0; //the number of matches that have been completed in the current system
	float sysCon = DEFSYSCON;	//the system constant variable for the system

	std::vector<match> matchSet; //a vector that contains all the matches that have not yet been processed by the system
	std::vector<team> teamSet;	 //a vector that contains all the teams in the system

	void addTeam(std::string name, float rating, float RD);	//a function that allows teams to be added to the system

	const size_t getLowestRating() const; //find the index of the team with the lowest rating in the system. Will give first if multiple teams have the lowest index
	const size_t getHighestRating() const; //find the index of the team with the highest rating in the system. Will give first if multiple teams have the highest rating


	glicko2TeamSet();
public slots:
	void rateTeams();	//a slot to run all of the teams in the system
};

#endif