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


void actionHandler::newMatch()
{
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

void actionHandler::newMatchAdded(int team1Ind, int team2Ind, uint8_t winner)
{
	teamSet->matchSet.push_back(match(&teamSet->teamSet.at(team1Ind), &teamSet->teamSet.at(team2Ind), winner));
	emit matchCreated(teamSet->matchSet.size() - 1);
}
