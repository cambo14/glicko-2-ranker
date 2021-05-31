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


};

#endif
