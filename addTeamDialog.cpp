//Copyright(C) 2021 Campbell Rowland
//see license file for more information 

#include "addTeamDialog.h"
#include "ui_addTeamDialog.h"
#include "nonFatalErrorDialog.h"
#include <QAction>

addTeamDialog::addTeamDialog(QWidget *par)
	: QDialog(par)
{
	ui.setupUi(this);
	QAction::connect(this->ui.addTeamButton, &QPushButton::released, this, &addTeamDialog::addButtonPressed);
	QAction::connect(this->ui.cancelTeamAddButton, &QPushButton::released, this, &addTeamDialog::cancelButtonPressed);
}

addTeamDialog::~addTeamDialog()
{
}

void addTeamDialog::cancelButtonPressed() // a slot to run when the cancel button is pressed. Should only close and delete the dialog
{
	close();
}


void addTeamDialog::addButtonPressed() { // a slot to run when the add team button is pressed
	bool* isNum = new bool;
	float checkVal = ui.ratingInput->text().toFloat(isNum);
	if (!(*isNum)) {	//check that the RD is a number
		nonFatalErrorDialog* errorDialog = new nonFatalErrorDialog(parentWidget(), "Invalid rating input", "The teams rating must be a number");
		QObject::connect(errorDialog, &nonFatalErrorDialog::saveAndQuit, this, [&]() {emit saveQuit(); errorDialog->deleteLater(); return; });
		QObject::connect(errorDialog, &nonFatalErrorDialog::continueUnsafe, this, [&]() {errorDialog->deleteLater(); return; });
		errorDialog->exec();
	}

	checkVal = ui.ratDevInp->text().toFloat(isNum);
	if(!(*isNum)){	//check that the RD is a number
		nonFatalErrorDialog* errorDialog = new nonFatalErrorDialog(parentWidget(), "Invalid RD input", "The teams RD must be a number");
		QObject::connect(errorDialog, &nonFatalErrorDialog::saveAndQuit, this, [&]() {emit saveQuit(); errorDialog->deleteLater(); return; });
		QObject::connect(errorDialog, &nonFatalErrorDialog::continueUnsafe, this, [&]() {errorDialog->deleteLater(); return; });
		errorDialog->exec();
	}

	checkVal = ui.volInput->text().toFloat(isNum);
	if (!(*isNum)) {	//check that the volatility is a number
		nonFatalErrorDialog* errorDialog = new nonFatalErrorDialog(parentWidget(), "Invalid volatility input", "The teams volatility must be a number");
		QObject::connect(errorDialog, &nonFatalErrorDialog::saveAndQuit, this, [&]() {emit saveQuit(); errorDialog->deleteLater(); return; });
		QObject::connect(errorDialog, &nonFatalErrorDialog::continueUnsafe, this, [&]() {errorDialog->deleteLater(); return; });
		errorDialog->exec();
	}
	emit teamSubmitted(ui.teamNameInput->text().toUtf8().constData(), ui.ratingInput->text().toFloat(), ui.ratDevInp->text().toFloat());
	close();
}
