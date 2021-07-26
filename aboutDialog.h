//Copyright(C) 2021 Campbell Rowland
//see license file for more information


/*
*A class that provides an about dialog for the software.
*/

#ifndef _ABOUTDIALOG_H_
#define _ABOUTDIALOG_H_

#include <QtWidgets/QDialog>
#include "ui_aboutDialog.h"

class aboutDialog : public QDialog
{
	Q_OBJECT

public:
	aboutDialog(QWidget *parent = Q_NULLPTR);
	~aboutDialog();

private:
	Ui::aboutDialog ui;	//ui elements of this dialog
};

#endif
