//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* a class to create a warning box to notify the user if they do anything which could possibly lead to negative or unintended consequences.
* the user can then choose to continue or go back from this dialog box
*/

#ifndef _WARNINGDIALOG_H_
#define _WARNINGDIALOG_H_

#include "werrorDialog.h"

class warningDialog : public werrorDialog
{
	Q_OBJECT

public:
	QPixmap image; //image to be used in werror dialogue
	warningDialog(QWidget *parent = Q_NULLPTR, std::string title = "unknown", std::string description = "no information was provided to the error dialog");
	~warningDialog();
signals:
	void cancelButtonPressed();	//a signal to be emitted when the cancel button is pressed
	void continueButtonPressed();	//a signal to be emitted when the continue button is pressed
};

#endif
