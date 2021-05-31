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
	addTeamDialog(QWidget *parent = Q_NULLPTR);
	~addTeamDialog();

private:
	Ui::addTeamDialog ui;
};

#endif
