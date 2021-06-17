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

void addMatchDialog::init(std::shared_ptr<glicko2TeamSet> teamS)
{//TODO handle if teamSet size is 0
	teamSet = teamS;
	for (size_t i = 0; i < teamSet->teamSet.size(); i++) {
		ui.team1Input->addItem(QString::fromUtf8(teamSet->teamSet.at(i).name));
		ui.team2Input->addItem(QString::fromUtf8(teamSet->teamSet.at(i).name));
	}
	ui.winnerInput->addItem("Team 1");
	ui.winnerInput->addItem("Team 2");
	ui.winnerInput->addItem("Draw");
}

void addMatchDialog::cancelMatchButtonPressed()
{
	close();
}

void addMatchDialog::addMatchButtonPressed() {
	emit matchSubmitted(ui.team1Input->currentIndex(), ui.team2Input->currentIndex(), ui.winnerInput->currentIndex());
	close();
	//TODO check selected items are valid
}
