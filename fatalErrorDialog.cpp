#include "fatalErrorDialog.h"

fatalErrorDialog::fatalErrorDialog(QWidget *parent, std::string title, std::string description)
	: werrorDialog(parent), image(QString::fromUtf8(":/resources/error.png"))
{
	ui.werrorTitle->setText(QString::fromUtf8("Fatal Error")); //give dialog error information
	ui.werrorCap->setText(QString::fromUtf8(title));
	ui.werrorInfo->setText(QString::fromUtf8(description));
	ui.werrorImg->setPixmap(image);
	ui.button1->setText(QString::fromUtf8("Quit Without Saving"));
	ui.button2->setText(QString::fromUtf8("Save and Quit"));
}

fatalErrorDialog::~fatalErrorDialog()
{
}
