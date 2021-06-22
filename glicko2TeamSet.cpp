#include "glicko2TeamSet.h"

glicko2TeamSet::glicko2TeamSet(std::string testVal) : teamSet(), matchSet()
{
	test = testVal;
}

void glicko2TeamSet::addTeam(std::string name, float rating, float RD)
{
	teamSet.push_back(team(name, rating, RD));
}

size_t glicko2TeamSet::getLowestRating()
{
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

size_t glicko2TeamSet::getHighestRating()
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
