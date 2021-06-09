//Copyright(C) 2021 Campbell Rowland
//see license file for more information 

#include "addTeamDialog.h"
#include "ui_addTeamDialog.h"
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

void addTeamDialog::cancelButtonPressed()
{
	close();
}

void addTeamDialog::addButtonPressed() {
	emit teamSubmitted(ui.teamNameInput->text().toUtf8().constData(), ui.ratingInput->text().toFloat(), ui.ratDevInp->text().toFloat());
	close();
	//TODO check that entered values are OK
}
