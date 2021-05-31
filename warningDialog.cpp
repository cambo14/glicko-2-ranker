#include "warningDialog.h"

warningDialog::warningDialog(QWidget *parent, std::string title, std::string description)
	: werrorDialog(parent), image(QString::fromUtf8(":/resources/warning.png"))
{
	ui.werrorTitle->setText(QString::fromUtf8("Warning"));	//initialise design of warning box
	ui.werrorCap->setText(QString::fromUtf8(title));
	ui.werrorInfo->setText(QString::fromUtf8(description));
	ui.werrorImg->setPixmap(image);
	ui.button1->setText(QString::fromUtf8("Continue"));
	ui.button2->setText(QString::fromUtf8("Cancel"));
}

warningDialog::~warningDialog()
{
}
