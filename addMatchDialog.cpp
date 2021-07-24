//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "addMatchDialog.h"

addMatchDialog::addMatchDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.addButton, &QPushButton::released, this, &addMatchDialog::addMatchButtonPressed);
	QObject::connect(ui.cancelButton, &QPushButton::released, this, &addMatchDialog::cancelMatchButtonPressed);
}

addMatchDialog::~addMatchDialog()
{
}

void addMatchDialog::init(std::shared_ptr<glicko2TeamSet*> teamS) //init function because QT does not allow custom constructors with designer call ASAP
{
	teamSet = teamS;
	for (size_t i = 0; i < (*teamSet)->teamSet.size(); i++) {
		ui.team1Input->addItem(QString::fromUtf8((*teamSet)->teamSet.at(i).name));
		ui.team2Input->addItem(QString::fromUtf8((*teamSet)->teamSet.at(i).name));
	}
	ui.winnerInput->addItem("Team 1");
	ui.winnerInput->addItem("Team 2");
	ui.winnerInput->addItem("Draw");
}

void addMatchDialog::cancelMatchButtonPressed() //a slot to run when the cancel button on the dialog is pressed
{
	close();
}

void addMatchDialog::addMatchButtonPressed() { //a slot to run when the add match button on the dialog is pressed
	emit matchSubmitted(ui.team1Input->currentIndex(), ui.team2Input->currentIndex(), ui.winnerInput->currentIndex());
	close();
}
