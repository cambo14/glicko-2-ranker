//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "glicko2TeamSet.h"
#include "nonFatalErrorDialog.h"
#define _USE_MATH_DEFINES
#include <cmath>

glicko2TeamSet::glicko2TeamSet() : teamSet(), matchSet()
{
}

void glicko2TeamSet::addTeam(std::string name, float rating, float RD) //a function that allows teams to be added to the system
{
	teamSet.push_back(team(name, rating, RD));
}

void glicko2TeamSet::rateTeams() //a slot to run all of the teams in the system
{
	auto g = [](float newRD) ->float {return 1 / (sqrt(1 + (3 * pow(newRD, 2)) / pow(M_PI, 2))); };	//define the lamda expressions for small functions that are used regularly
	auto E = [&](float newRating, float oppRating, float oppRD) ->float {return 1 / (1 + exp(-g(oppRD)*(newRating-oppRating))); }; //lamda function names use the same name as the function name in the Glicko-2 paper by Mark Glickmand
	auto newRate = [](float oldRating) ->float {return (oldRating - 1500) / 173.7178; };
	auto newRatDev = [](float oldRD) ->float { return oldRD / 173.7178; };
	auto resultCalc = [](uint8_t res) ->float {switch (res) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 0.5;
	}};
	for (size_t i = 0; i < teamSet.size(); i++) {
		float v = 0;
		float quantity = 0;
		float newRating = newRate(teamSet[i].rating);
		float newRD = newRatDev(teamSet[i].RD);
		for (size_t x = 0; x < teamSet[i].matchResults.size(); x++) {
			v += pow(g(newRatDev(std::get<1>(teamSet[i].matchResults[x]))),2)*E(newRating, newRate(std::get<0>(teamSet[i].matchResults[x])), newRatDev(std::get<1>(teamSet[i].matchResults[x])))*(1- E(newRating, newRate(std::get<0>(teamSet[i].matchResults[x])), newRatDev(std::get<1>(teamSet[i].matchResults[x]))));
		}
		v = pow(v, -1);
		for (size_t x = 0; x < teamSet[i].matchResults.size(); x++) {
			quantity += g(newRatDev(std::get<1>(teamSet[i].matchResults[x]))) * (resultCalc(std::get<2>(teamSet[i].matchResults[x])) - E(newRating, newRate(std::get<0>(teamSet[i].matchResults[x])), newRatDev(std::get<1>(teamSet[i].matchResults[x]))));
		}
		quantity = quantity * v;

		float a = log(pow(teamSet[i].volatility,2));
		float vol = teamSet[i].volatility;

		auto f = [&](float x, float vol) ->float {return (exp(x) * (pow(quantity,2) - pow(newRD,2) - v - exp(x)))/
			(2*pow((pow(newRD,2) + v + exp(x)),2)) - ((x-a) /pow(DEFSYSCON,2)) ; };

		float A = a;
		float B;
		if (pow(quantity, 2) > pow(newRD, 2) + v) {
			B = log(pow(quantity, 2) - pow(newRD, 2) - v);
		}
		else {
			int k = 1;
			while (f(a - k * DEFSYSCON, vol) < 0)k++;
			B = a - k * DEFSYSCON;
		}
		float fA = f(A, vol);
		float fB = f(B, vol);
		while (abs(B - A) > CONTOL) {
			float C = A + (A - B) * fA / (fB - fA);
			float fC = f(C, vol);
			if (fC * fB < 0) {
				A = B;
				fA = fB;
			}
			else {
				fA = fA / 2;
			}
			B = C;
			fB = fC;
		}
		teamSet[i].volatility = exp(A / 2);
		teamSet[i].RD = sqrt(pow(newRD,2) + pow(teamSet[i].volatility,2));
		teamSet[i].RD = 1 / sqrt(1/pow(teamSet[i].RD,2) + 1/v);
		float count = 0;
		for (int x = 0; x < teamSet[i].matchResults.size(); x++) {
			count += g(newRatDev(std::get<1>(teamSet[i].matchResults[x]))) * (resultCalc(std::get<2>(teamSet[i].matchResults[x]))- E(newRating, newRate(std::get<0>(teamSet[i].matchResults[x])), newRatDev(std::get<1>(teamSet[i].matchResults[x]))));
		}
		teamSet[i].rating = newRate(teamSet[i].rating) + pow(teamSet[i].RD, 2) * count;
		teamSet[i].rating = 173.7178 * teamSet[i].rating + 1500;
		teamSet[i].rateHist.push_back(teamSet[i].rating);
		teamSet[i].addGraphVal();
		teamSet[i].RD = 173.7178 * teamSet[i].RD;
		teamSet[i].matchResults.clear();
		//matchSet.clear();
	}
}

const size_t glicko2TeamSet::getLowestRating() const //find the index of the team with the lowest rating in the system. Will give first if multiple teams have the lowest index
{
	switch (teamSet.size()) {
	case 0:{
#ifdef _DEBUG //abort program if in debugging mode
		abort(); //aborting program as there is no teamset to 
#endif
		nonFatalErrorDialog errorDialog(nullptr, "Team Set is empty", "getLowestRating was called on the teamset while it was empty");	//provide error dialog if running in release mode
		errorDialog.deleteLater(); }
	case 1:
		return 0;
	default:
		float lowest = teamSet[0].rating;
		size_t lowestIndex = 0;
		for (size_t i = 1; i < teamSet.size(); i++) {
			if (teamSet[i].rating < lowest) {
				lowest = teamSet[i].rating;
				lowestIndex = i;
			}
		}
		return lowestIndex;
	}
}

const size_t glicko2TeamSet::getHighestRating() const //find the index of the team with the highest rating in the system. Will give first if multiple teams have the highest rating
{
	float highest = teamSet[0].rating;
	size_t highestIndex = 0;
	for (size_t i = 1; i < teamSet.size(); i++) {
		if (teamSet[i].rating > highest) {
			highest = teamSet[i].rating;
			highestIndex = i;
		}
	}
	return highestIndex;
}
