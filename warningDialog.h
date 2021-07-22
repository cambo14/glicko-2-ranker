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
	void cancelButtonPressed();
	void continueButtonPressed();
};

#endif
