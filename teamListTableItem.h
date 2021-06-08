//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _TEAMLISTTABLEITEM_H_
#define _TEAMLISTTABLEITEM_H_
#include <QTableWidgetItem>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <iostream>
#include <memory>
#include "glicko2TeamSet.h"

/*
* a class to handle individual items in the table of teams
*/

class teamListTableItem : public QPushButton
{
	Q_OBJECT
public:

	std::shared_ptr<glicko2TeamSet> teamSet;
	size_t index;

	teamListTableItem(std::shared_ptr<glicko2TeamSet> teamS, size_t ind, QWidget* parent);
	teamListTableItem(const teamListTableItem& tableItem);
	~teamListTableItem();
};

#endif
