#ifndef _ABOUTDIALOG_H_
#define _ABOUTDIALOG_H_

#include <QDialog>
#include "ui_aboutDialog.h"

class aboutDialog : public QDialog
{
	Q_OBJECT

public:
	aboutDialog(QWidget *parent = Q_NULLPTR);
	~aboutDialog();

private:
	Ui::aboutDialog ui;
};

#endif
