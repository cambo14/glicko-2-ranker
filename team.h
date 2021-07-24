//Copyright(C) 2021 Campbell Rowland
//see license file for more information
#ifndef _TEAM_H_
#define _TEAM_H_
#include <iostream>
#include <tuple>
#include <vector>
#include <QVector>

/*
* a class that holds the values for each individual team
*/

class team
{
public:
	team(std::string nam, float ratin, float R);
	bool operator==(const team& r);		//check if two teams are the same

	void addGraphVal(); //a function to be called when a new rating is added to the teams rating history

	const float getHighestRateHist(); //a function to get the highest rating in the teams rating history

	std::string name;	//the name of the team
	float rating;	//the teams rating
	float RD;	//the teams rating deviation
	float volatility;	//the teams volatility
	int matchWonCount = 0;	//the number of matches the team has won
	int matchLostCount = 0;	//the number of matches the team has lost
	int matchDrawnCount = 0;//the number of matches the team has drawn

	QVector<double> rateHistx, rateHisty; //Qvectors holding the teams x and y values for the rating history graph

	std::vector<float> rateHist;	//a vector of floats containing all of the previous ratings that the team has had
	std::vector<std::tuple<float, float, uint8_t>> matchResults;	//a vector that holds all the results of the matches the team is in in the current period
};


#endif

