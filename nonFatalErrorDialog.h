//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* a class to create a dialog box in response to a non fatal error being encountered
* from this dialog box the user can either decide to continue or to save the current system to file and quit
*/

#ifndef _NONFATALERRORDIALOG_H_
#define _NONFATALERRORDIALOG_H_

#include "werrorDialog.h"

class nonFatalErrorDialog : public werrorDialog
{
	Q_OBJECT

public:
	QPixmap image;	//image to be used in werror dialogue
	nonFatalErrorDialog(QWidget *parent = Q_NULLPTR, std::string title = "unknown", std::string description = "no information was provided to the error dialog");
	~nonFatalErrorDialog();
signals:
	void saveAndQuit();	//a signal to be emitted when the user wants to save and quit
	void continueUnsafe();	//a signal to be emitted when the user wants to continue

};

#endif
