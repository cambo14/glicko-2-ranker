//Copyright(C) 2021 Campbell Rowland
//see license file for more information
#ifndef _TEAM_H_
#define _TEAM_H_
#include <iostream>
#include <vector>

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

	std::vector<float> rateHist;
};


#endif

