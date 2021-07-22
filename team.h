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

	std::string name;
	float rating;
	float RD;
	float volatility;
	int matchWonCount = 0;
	int matchLostCount = 0;
	int matchDrawnCount = 0;

	QVector<double> rateHistx, rateHisty; //Qvectors holding the teams x and y values for the rating history graph

	std::vector<float> rateHist;
	std::vector<std::tuple<float, float, uint8_t>> matchResults;	//a vector that holds all the results of the matches the team is in in the current period
};


#endif

