//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* the base class that nonFatalErrorDialog, fatalErrorDialog and warningDialog are all based off of
*/

#ifndef _WERRORDIALOG_H_
#define _WERRORDIALOG_H_

#include <QDialog>
#include "ui_werrorDialog.h"

class werrorDialog : public QDialog
{
	Q_OBJECT

public:
	werrorDialog(QWidget *parent = Q_NULLPTR);
	~werrorDialog();

protected:
	Ui::werrorDialog ui;
};

#endif
