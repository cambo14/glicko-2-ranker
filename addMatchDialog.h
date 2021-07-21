//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _ADDMATCHDIALOGUE_H_
#define _ADDMATCHDIALOGUE_H_

/* A Class to provide a dialog box when the user tries
 to create a match*/


#include <QDialog>
#include <memory>
#include "ui_addMatchDialog.h"
#include "glicko2TeamSet.h"

class addMatchDialog : public QDialog
{
	Q_OBJECT

public:
	addMatchDialog(QWidget *parent = Q_NULLPTR);
	~addMatchDialog();

	void init(std::shared_ptr<glicko2TeamSet*> teamS); //init function because QT does not allow custom constructors with designer call ASAP

	std::shared_ptr<glicko2TeamSet*> teamSet;
private:
	Ui::addMatchDialog ui;

public slots:
	void addMatchButtonPressed();
	void cancelMatchButtonPressed();
signals:
	void matchSubmitted(int team1Ind, int team2Ind, uint8_t winner);
};

#endif