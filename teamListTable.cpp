//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "teamListTable.h"

teamListTable::teamListTable(QWidget* parent) : QTableWidget(1, 1, parent), addTeamButton(QString("+ ADD TEAM"), this) {
	setCellWidget(0, 0, &addTeamButton);
}

teamListTable::~teamListTable()
{
	for (size_t i = 0; i < infoWidgets.size(); i++) {
		delete infoWidgets[i];
	}
}

void teamListTable::init(std::shared_ptr<glicko2TeamSet*> teamLi)  /*init function due to not being able to use custom constructors for promoted classes with 
																	qt designer make sure to call this ASAP*/
{
	teamList = teamLi;
}

void teamListTable::refresh() //refresh items in the table after values have been changed
{
	for (size_t i = 0; i < infoWidgets.size(); i++) infoWidgets[i]->refresh();
}



void teamListTable::teamAdded(size_t teamIndex) { //a slot to run to add a team to the table
	setRowCount(rowCount()+1);												//create and add the team to the table
	infoWidgets.push_back(new teamListTableItem(teamList, teamIndex, this));
	infoWidgets[teamIndex]->show();
	setCellWidget(rowCount() - 1, 0, infoWidgets[teamIndex]);

	QObject::connect(infoWidgets.at(teamIndex), &QPushButton::released, this, [=]() {emit updateTeamInfo(teamIndex); });	//connect the team button to the function to update the values on the main windows
}
