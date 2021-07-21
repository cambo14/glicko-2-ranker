//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _ACTIONHANDLER_H_
#define _ACTIONHANDLER_H_

#include <QObject>
#include <memory>
#include "glicko2TeamSet.h"

class actionHandler:public QObject {  //a class designed to handle actions done by the user and to then perform the appropriate actions
	Q_OBJECT
public:
	actionHandler(QWidget* par, std::shared_ptr<glicko2TeamSet*> tS);
	QWidget* parent;	//the parent window of this handler
	std::shared_ptr<glicko2TeamSet*> teamSet;
	void nonFatalErrorEncountered(std::string name, std::string description); //a function to display an error message when an error is encountered
public slots:
	void newTeam();	//a slot to run when an action that results in a new team being created is performed
	void newMatch(); //a slot to run when an action that results in a new match being created is performed
	void onAbout(); //a slot to run when an action that results in an about dialog box showing up is performed
	void onNew(); //a slot to run when a new teamset is created
	void newTeamAdded(std::string teamName, float rating, float RD); //a slot to handle creating a team
	void newMatchAdded(int team1Ind, int team2Ind, uint8_t winner); //a slot to handle creating a match
signals:
	void teamCreated(size_t index); //a signal to let other classes know a team has been created
	void matchCreated(size_t index); //a sginal to let other classes know a match has been created
	void sysValsNeedUpdate();
};

#endif
