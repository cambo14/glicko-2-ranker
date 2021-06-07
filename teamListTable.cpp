#include "teamListTable.h"

teamListTable::teamListTable(QWidget* parent) : QTableWidget(1, 1, parent), addTeamButton(QString("+ ADD TEAM"), this) {
	setCellWidget(0, 0, &addTeamButton);
}

void teamListTable::init(std::shared_ptr<glicko2TeamSet> teamLi)
{
	teamList = teamLi;
}


void teamListTable::teamAdded(size_t teamIndex) {

}
