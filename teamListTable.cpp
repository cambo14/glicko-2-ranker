#include "teamListTable.h"

teamListTable::teamListTable(QWidget* parent) : QTableWidget(1, 1, parent), addTeamButton(QString("+ ADD TEAM"), this) {
	setCellWidget(0, 0, &addTeamButton);
}

void teamListTable::init(glicko2TeamSet* teamLi)
{
	teamList = teamLi;
}
