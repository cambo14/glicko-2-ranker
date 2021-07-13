#include "glicko2TeamSet.h"
#include "nonFatalErrorDialog.h"

glicko2TeamSet::glicko2TeamSet(std::string testVal) : teamSet(), matchSet()
{
	test = testVal;
}

void glicko2TeamSet::addTeam(std::string name, float rating, float RD)
{
	teamSet.push_back(team(name, rating, RD));
}

const size_t glicko2TeamSet::getLowestRating()
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

const size_t glicko2TeamSet::getHighestRating()
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
