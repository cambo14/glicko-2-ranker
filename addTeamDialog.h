#ifndef _ADDTEAMDIALOGUE_H_
#define _ADDTEAMDIALOGUE_H_

/* A Class to provide a dialog box when the user tries
 to create a team*/

#include <QDialog>
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
signals:
	void teamSubmitted(std::string teamname, float rating, float RD);	//a signal to emit with the values of the newly created team
};

#endif
