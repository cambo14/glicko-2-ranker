//Copyright(C) 2021 Campbell Rowland
//see license file for more information
#ifndef _TEAM_H_
#define _TEAM_H_
#include <iostream>
#include <tuple>
#include <vector>

/*
* a class that holds the values for each individual team
*/

//TODO finish removeing use of match class and use vector of pairs

class team
{
public:
	team(std::string nam, float ratin, float R);
	bool operator==(const team& r);		//check if two teams are the same

	std::string name;
	float rating;
	float RD;
	float volatility;
	int matchWonCount = 0;
	int matchLostCount = 0;
	int matchDrawnCount = 0;

	std::vector<float> rateHist;
	std::vector<std::tuple<float, float, uint8_t>> matchResults;	//a vector that holds all the results of the matches the team is in in the current period
};


#endif

