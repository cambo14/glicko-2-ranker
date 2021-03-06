//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _ADDTEAMDIALOGUE_H_
#define _ADDTEAMDIALOGUE_H_

/* 
* A Class to provide a dialog box when the user tries
* to create a team
*/

#include <QtWidgets/QDialog>
#include "ui_addTeamDialog.h"

class addTeamDialog : public QDialog
{
	Q_OBJECT

public:
	addTeamDialog(QWidget *par = Q_NULLPTR);
	~addTeamDialog();

	Ui::addTeamDialog ui;
public slots:
	void addButtonPressed();		// a slot to run when the add team button is pressed
	void cancelButtonPressed();		// a slot to run when the cancel button is pressed. Should only close and delete the dialog
signals:
	void saveQuit(); //a signal to be emitted if there was an error with the dialog box and the application needs to quit
	void teamSubmitted(std::string teamname, float rating, float RD);	//a signal to emit with the values of the newly created team
};

#endif
