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
	QObject::connect(&addTeam, &addTeamDialog::teamSubmitted, this, &actionHandler::newMatchAdded); //connect the new team dialog to the handler
	addTeam.exec();
}


void actionHandler::newMatch()
{
	addMatchDialog addMatch(parent);
	addMatch.exec();
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

void actionHandler::newMatchAdded(std::string teamname, float rating, float RD)
{
}
