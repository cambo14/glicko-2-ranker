//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "actionHandler.h"
#include "addTeamDialog.h"
#include "addMatchDialog.h"
#include "fatalErrorDialog.h"
#include "warningDialog.h"
#include "nonFatalErrorDialog.h"
#include "aboutDialog.h"

actionHandler::actionHandler(QWidget* par, std::shared_ptr<glicko2TeamSet> tS) {
	parent = par;
	teamSet = tS;
}

void actionHandler::newTeam() {
	addTeamDialog addTeam(parent);
	QObject::connect(&addTeam, &addTeamDialog::teamSubmitted, this, &actionHandler::newTeamAdded); //connect the new team dialog to the handler
	addTeam.exec();
	addTeam.deleteLater();
}


void actionHandler::nonFatalErrorEncountered(std::string name, std::string description)
{
	nonFatalErrorDialog errorDialog(parent, name, description);
	errorDialog.exec();
	return;
}

void actionHandler::newMatch()
{
	if (teamSet->teamSet.size() < 2) { //check that there are enough teams to create a match
		nonFatalErrorDialog errorDialog(parent, "not enough teams", "you need at least two teams in the teamset to create a match.");
		errorDialog.exec();
		return;
	}
	addMatchDialog addMatch(parent);
	addMatch.init(teamSet);
	QObject::connect(&addMatch, &addMatchDialog::matchSubmitted, this, &actionHandler::newMatchAdded);
	addMatch.exec();
	addMatch.deleteLater();
}

void actionHandler::onAbout()
{
	aboutDialog about(parent);
	about.exec();
}

void actionHandler::onNew()
{
	teamSet = std::make_shared<glicko2TeamSet>("actionHandler");
}

void actionHandler::newTeamAdded(std::string teamName, float rating, float RD)
{
	teamSet->teamSet.push_back(team(teamName, rating, RD));
	emit teamCreated(teamSet->teamSet.size() - 1);
}

void actionHandler::newMatchAdded(int team1Ind, int team2Ind, uint8_t winner)	//slot to run when a new match is added to the system
{
	teamSet->matchSet.push_back(match(&teamSet->teamSet.at(team1Ind), &teamSet->teamSet.at(team2Ind), static_cast<result>(winner)));
	emit matchCreated(teamSet->matchSet.size() - 1);
}
