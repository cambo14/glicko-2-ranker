//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "actionHandler.h"
#include "addTeamDialog.h"
#include "addMatchDialog.h"
#include "fatalErrorDialog.h"
#include "warningDialog.h"
#include "nonFatalErrorDialog.h"
#include "aboutDialog.h"

actionHandler::actionHandler(QWidget* par, std::shared_ptr<glicko2TeamSet*> tS) {
	parent = par;
	teamSet = tS;
}

void actionHandler::newTeam() { //a slot to run when an action that results in a new team being created is performed
	emit sysValsNeedUpdate();
	addTeamDialog addTeam(parent);
	QObject::connect(&addTeam, &addTeamDialog::teamSubmitted, this, &actionHandler::newTeamAdded); //connect the new team dialog to the handler
	QObject::connect(&addTeam, &addTeamDialog::saveQuit, this, &actionHandler::saveAndQuit);
	addTeam.exec();
	addTeam.deleteLater();
}


bool actionHandler::nonFatalErrorEncountered(std::string name, std::string description) //a function to display an error message when an error is encountered. Will return true if the user decides to continue and false if the user saves and quits
{
	nonFatalErrorDialog* errorDialog = new nonFatalErrorDialog(parent, name, description);
	errorDialog->exec();
	QObject::connect(errorDialog, &nonFatalErrorDialog::continueUnsafe, this, [&]() {errorDialog->deleteLater(); return true; });
	QObject::connect(errorDialog, &nonFatalErrorDialog::saveAndQuit, this, [&]() {errorDialog->deleteLater(); return true; });
	return true;
}

bool actionHandler::warningDialogEncountered(std::string name, std::string description) //a function to display a warning. Will return true if the user decides to continue and false if the user wants cancel their action
{
	warningDialog* warnDialog = new warningDialog(parent, name, description);
	QObject::connect(warnDialog, &warningDialog::cancelButtonPressed, this, [&]() {warnDialog->deleteLater(); return false; });
	QObject::connect(warnDialog, &warningDialog::continueButtonPressed, this, [&]() {warnDialog->deleteLater(); return true; });
	warnDialog->exec();
	return true;
}

void actionHandler::newMatch() //a slot to run when an action that results in a new match being created is performed
{
	emit sysValsNeedUpdate();
	if ((*teamSet)->teamSet.size() < 2) { //check that there are enough teams to create a match
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

void actionHandler::onAbout() //a slot to run when an action that results in an about dialog box showing up is performed
{
	aboutDialog about(parent);
	about.exec();
}

void actionHandler::onNew() //a slot to run when a new teamset is created
{
	teamSet = std::make_shared<glicko2TeamSet*>();
}

void actionHandler::newTeamAdded(std::string teamName, float rating, float RD) //a slot to handle creating a team
{
	(*teamSet)->teamSet.push_back(team(teamName, rating, RD));
	emit teamCreated((*teamSet)->teamSet.size() - 1);
}

void actionHandler::newMatchAdded(int team1Ind, int team2Ind, uint8_t winner)	//slot to run when a new match is added to the system
{
	(*teamSet)->matchSet.push_back(match(&(*teamSet)->teamSet.at(team1Ind), &(*teamSet)->teamSet.at(team2Ind), static_cast<result>(winner)));
	emit matchCreated((*teamSet)->matchSet.size() - 1);
}

void actionHandler::saveAndQuit() //a slot to save the current teamSet and then quit
{
	emit onSaveAndQuit();
}
