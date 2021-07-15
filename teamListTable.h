//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _TEAMLISTTABLE_H_
#define _TEAMLISTTABLE_H_

#include <QTableWidget>
#include <QPushButton>
#include "teamListTableItem.h"

/*
* A class to handle the list of teams on the right hand side of the main window
* that stores information about all the teams in the teamset and their associated values
*/

class teamListTable : public QTableWidget
{
	Q_OBJECT
public:
	QPushButton addTeamButton;
	std::vector<teamListTableItem*> infoWidgets;

	std::shared_ptr<glicko2TeamSet> teamList = nullptr;

	teamListTable(QWidget* parent = Q_NULLPTR);
	~teamListTable();

	void init(std::shared_ptr<glicko2TeamSet> teamLi); /*init function due to not being able to use custom constructors for promoted classes with 
										qt designer make sure to call this ASAP*/
	void refresh(); //refresh items in the table after values have been changed
public slots:
	void teamAdded(size_t teamIndex); //a slot to run to add a team to the table
signals:
	void addTeamButtonPressed();	//a signal for when the button to add a team is pressed
	void updateTeamInfo(size_t teamIndex);	//a signal for when the user clicks on a team in the table
};

#endif

