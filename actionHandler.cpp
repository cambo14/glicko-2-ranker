#include "actionHandler.h"
#include "addTeamDialog.h"
#include "addMatchDialog.h"
#include "fatalErrorDialog.h"
#include "warningDialog.h"

actionHandler::actionHandler(QWidget* par) {
	parent = par;
}

void actionHandler::newTeam() {
	//addTeamDialog addTeam(parent);
	//addTeam.exec();
	fatalErrorDialog errorDialog(parent, "test", "is this showing up????");
	errorDialog.exec();
}

void actionHandler::newMatch()
{
	addMatchDialog addMatch(parent);
	addMatch.exec();
}
