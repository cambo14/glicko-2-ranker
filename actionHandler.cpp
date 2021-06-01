#include "actionHandler.h"
#include "addTeamDialog.h"
#include "addMatchDialog.h"
#include "fatalErrorDialog.h"
#include "warningDialog.h"
#include "nonFatalErrorDialog.h"
#include "aboutDialog.h"

actionHandler::actionHandler(QWidget* par) {
	parent = par;
}

void actionHandler::newTeam() {
	addTeamDialog addTeam(parent);
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
