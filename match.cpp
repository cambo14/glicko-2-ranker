//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "match.h"

match::match(team* t1, team* t2, result win)
{
	team1 = t1;
	team2 = t2;
	winner = win;
	switch (win) {
	case result::team1:
		t1->matchResults.push_back(std::tuple(t2->rating, t2->RD, 0));
		t1->matchWonCount++;
		t2->matchResults.push_back(std::tuple(t1->rating, t1->RD, 1));
		t2->matchLostCount++;
		break;
	case result::team2:
		t1->matchResults.push_back(std::tuple(t2->rating, t2->RD, 1));
		t1->matchLostCount++;
		t2->matchResults.push_back(std::tuple(t1->rating, t1->RD, 0));
		t2->matchWonCount++;
		break;
	case result::draw:
		t1->matchResults.push_back(std::tuple(t2->rating,t2->RD, 2));
		t1->matchDrawnCount++;
		t2->matchResults.push_back(std::tuple(t1->rating, t1->RD, 2));
		t2->matchDrawnCount++;
		break;
	default: {
#ifndef _DEBUG
			abort(); //abort if in debug config as invalid enum supplied
#endif
			break;
		}
	}
}
