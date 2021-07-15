//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _TEAMLISTTABLEITEM_H_
#define _TEAMLISTTABLEITEM_H_
#include <QTableWidgetItem>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
//Copyright(C) 2021 Campbell Rowland
//see license file for more information

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

	void refresh(); //function to refresh values shown on the table when edited from an external source

	teamListTableItem(std::shared_ptr<glicko2TeamSet> teamS, size_t ind, QWidget* parent);
	teamListTableItem(const teamListTableItem& tableItem);
	~teamListTableItem();
};

#endif
