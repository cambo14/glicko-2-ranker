//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
*  A class that handles the interactions between the actual ranking system and the windows as well as handling certain actions
*  done by the user
*/

#ifndef _ACTIONHANDLER_H_
#define _ACTIONHANDLER_H_

#include <QObject>
#include <memory>
#include "glicko2TeamSet.h"

class actionHandler:public QObject { 
	Q_OBJECT
public:
	actionHandler(QWidget* par, std::shared_ptr<glicko2TeamSet*> tS);
	QWidget* parent;	//the parent window of this handler
	std::shared_ptr<glicko2TeamSet*> teamSet; //a pointer to the teamSet pointer
	
	bool warningDialogEncountered(std::string name, std::string description); //a function to display a warning. Will return true if the user decides to continue and false if the user wants cancel their action
public slots:
	bool nonFatalErrorEncountered(std::string name, std::string description); //a function to display an error message when an error is encountered. Will return true if the user decides to continue and false if the user saves and quits
	void newTeam();	//a slot to run when an action that results in a new team being created is performed
	void newMatch(); //a slot to run when an action that results in a new match being created is performed
	void onAbout(); //a slot to run when an action that results in an about dialog box showing up is performed
	void onNew(); //a slot to run when a new teamset is created
	void newTeamAdded(std::string teamName, float rating, float RD); //a slot to handle creating a team
	void newMatchAdded(int team1Ind, int team2Ind, uint8_t winner); //a slot to handle creating a match
	void saveAndQuit(); //a slot to save the current teamSet and then quit
signals:
	void teamCreated(size_t index); //a signal to let other classes know a team has been created
	void matchCreated(size_t index); //a sginal to let other classes know a match has been created
	void sysValsNeedUpdate();		//a signal to let other classes know that the system values need to be updated on the UI
	void onSaveAndQuit(); //a signal to let the main window window know the the program needs to save and quit
};

#endif
