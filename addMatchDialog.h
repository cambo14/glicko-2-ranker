#ifndef _ADDMATCHDIALOGUE_H_
#define _ADDMATCHDIALOGUE_H_

/* A Class to provide a dialog box when the user tries
 to create a match*/


#include <QDialog>
#include "ui_addMatchDialog.h"

class addMatchDialog : public QDialog
{
	Q_OBJECT

public:
	addMatchDialog(QWidget *parent = Q_NULLPTR);
	~addMatchDialog();

private:
	Ui::addMatchDialog ui;
};

#endif