//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "team.h"

team::team(std::string nam, float ratin, float R)
{
	name = nam;
	rating = ratin;
	RD = R;
	volatility = 0.06; //TODO allow default vol value to be changed in settings
	rateHist.push_back(ratin);
	addGraphVal();
}

bool team::operator==(const team& r)
{
	if (name != r.name) return false;
	if (rating != r.rating) return false;
	if (RD != r.RD) return false;
	if (volatility != r.volatility) return false;
	return true;
}

void team::addGraphVal() //TODO cap size of history stored
{
	rateHisty.push_back(rateHist.back());
	rateHistx.push_back(rateHistx.size() + 1);
}

const float team::getHighestRateHist()
{
	float highestRate = 0;
	for (size_t i = 0; i < rateHist.size(); i++) if (rateHist[i] > highestRate) highestRate = rateHist[i];
	return highestRate;
}
