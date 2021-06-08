#include "glicko2TeamSet.h"

glicko2TeamSet::glicko2TeamSet(std::string testVal) : teamSet(), matchSet()
{
	test = testVal;
}

void glicko2TeamSet::addTeam(std::string name, float rating, float RD)
{
	teamSet.push_back(team(name, rating, RD));
}
