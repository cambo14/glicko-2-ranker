#include "addTeamDialog.h"
#include "ui_addTeamDialog.h"
#include <QAction>

addTeamDialog::addTeamDialog(QWidget *par)
	: QDialog(par)
{
	ui.setupUi(this);
	QAction::connect(this->ui.addTeamButton, &QPushButton::released, this, &addTeamDialog::addButtonPressed);
}

addTeamDialog::~addTeamDialog()
{
}

void addTeamDialog::addButtonPressed() {
	emit teamSubmitted(ui.teamNameInput->text().toUtf8().constData(), ui.ratingInput->text().toFloat(), ui.ratDevInp->text().toFloat());
	//TODO check that entered values are OK
}
