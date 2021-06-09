//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "teamListTable.h"

teamListTable::teamListTable(QWidget* parent) : QTableWidget(1, 1, parent), addTeamButton(QString("+ ADD TEAM"), this) {
	setCellWidget(0, 0, &addTeamButton);
	QObject::connect(&addTeamButton, &QPushButton::released, this, &teamListTable::addTeamButtonPressed);
}

teamListTable::~teamListTable()
{
	for (size_t i = 0; i < infoWidgets.size(); i++) {
		delete infoWidgets[i];
	}
}

void teamListTable::init(std::shared_ptr<glicko2TeamSet> teamLi)
{
	teamList = teamLi;
}


void teamListTable::teamAdded(size_t teamIndex) {
	setRowCount(rowCount()+1);
	infoWidgets.push_back(new teamListTableItem(teamList, teamIndex, this));
	infoWidgets[teamIndex]->show();
	setCellWidget(rowCount() - 1, 0, infoWidgets[teamIndex]);
}
