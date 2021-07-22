#include "nonFatalErrorDialog.h"

nonFatalErrorDialog::nonFatalErrorDialog(QWidget *parent, std::string title, std::string description)
	: werrorDialog(parent), image(QString::fromUtf8("://error"))
{
	ui.werrorTitle->setText(QString::fromUtf8("Non Fatal Error")); //initialise design of dialogue
	ui.werrorCap->setText(QString::fromUtf8(title));
	ui.werrorInfo->setText(QString::fromUtf8(description));
	ui.werrorImg->setPixmap(image);
	ui.button1->setText(QString::fromUtf8("Save and Exit"));
	ui.button2->setText(QString::fromUtf8("Continue (unsafe)"));
	QObject::connect(ui.button1, QPushButton::released, this, nonFatalErrorDialog::saveAndQuit);
	QObject::connect(ui.button2, QPushButton::released, this, nonFatalErrorDialog::continueUnsafe);
}

nonFatalErrorDialog::~nonFatalErrorDialog()
{
}
