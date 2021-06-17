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
}

bool team::operator==(const team& r)
{
	if (name != r.name) return false;
	if (rating != r.rating) return false;
	if (RD != r.RD) return false;
	if (volatility != r.volatility) return false;
	return true;
}
