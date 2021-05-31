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