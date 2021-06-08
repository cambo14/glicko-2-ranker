#ifndef _ACTIONHANDLER_H_
#define _ACTIONHANDLER_H_

#include <QObject>
#include <memory>
#include "glicko2TeamSet.h"

class actionHandler:public QObject {  //a class designed to handle actions done by the user and to then perform the appropriate actions
	Q_OBJECT
public:
	actionHandler(QWidget* par, std::shared_ptr<glicko2TeamSet> tS);
	QWidget* parent;	//the parent window of this handler
	std::shared_ptr<glicko2TeamSet> teamSet;
public slots:
	void newTeam();	//a slot to run when an action that results in a new team being created is performed
	void newMatch(); //a slot to run when an action that results in a new match being created is performed
	void onAbout(); //a slot to run when an action that results in an about dialog box showing up is performed
	void onNew(); //a slot to run when a new teamset is created
	void newTeamAdded(std::string teamName, float rating, float RD); //a slot to handle creating a team
signals:
	void teamCreated(size_t index); //a signal to let other classes know a team has been created
};

#endif
