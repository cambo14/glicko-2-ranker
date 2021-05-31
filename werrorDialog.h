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
