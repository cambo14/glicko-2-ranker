//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* a dialog to notify users if a fatal error is encountered and then
* take the appropriate steps to safely close the software and save to file if the user
* wants and it is possible
*/

#ifndef _FATALERRORDIALOG_H_
#define _FATALERRORDIALOG_H_

#include "werrorDialog.h"

class fatalErrorDialog : public werrorDialog
{
	Q_OBJECT

public:
	QPixmap image; //image to be used in werror dialogue
	fatalErrorDialog(QWidget *parent = Q_NULLPTR, std::string title = "unknown", std::string description = "no information was provided to the error dialog");
	~fatalErrorDialog();
};

#endif