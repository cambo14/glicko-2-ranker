#include "nonFatalErrorDialog.h"

nonFatalErrorDialog::nonFatalErrorDialog(QWidget *parent, std::string title, std::string description)
	: werrorDialog(parent), image(QString::fromUtf8(":/resources/error.png"))
{
	ui.werrorTitle->setText(QString::fromUtf8("Non Fatal Error")); //initialise design of dialogue
	ui.werrorCap->setText(QString::fromUtf8(title));
	ui.werrorInfo->setText(QString::fromUtf8(description));
	ui.werrorImg->setPixmap(image);
	ui.button1->setText(QString::fromUtf8("Save and Exit"));
	ui.button2->setText(QString::fromUtf8("Continue (unsafe)"));
}

nonFatalErrorDialog::~nonFatalErrorDialog()
{
}
