//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _TEAMLISTTABLE_H_
#define _TEAMLISTTABLE_H_

#include <QTableWidget>
#include <QPushButton>
#include <memory>
#include "glicko2TeamSet.h"

/*
* A class to handle the list of teams on the right hand side of the main window
* that stores information about all the teams in the teamset and their associated values
*/

class teamListTable : public QTableWidget
{
	Q_OBJECT
public:
	QPushButton addTeamButton;
	std::shared_ptr<glicko2TeamSet> teamList = nullptr;

	teamListTable(QWidget* parent = Q_NULLPTR);
	void init(std::shared_ptr<glicko2TeamSet> teamLi); /*init function due to not being able to use custom constructors for promoted classes with 
										qt designer make sure to call this ASAP*/
public slots:
	void teamAdded(size_t teamIndex); //a slot to run to add a team to the table
};

#endif

