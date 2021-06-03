#include "matchListTable.h"
#include <QString>

void matchListTable::init(glicko2TeamSet* matchLi)
{
	matchList = matchLi;
	setRowCount(20);	//TODO replace with number of matches from vector in the teamset
}

matchListTable::matchListTable(QWidget* parent)
	: QTableWidget(1, 1, parent), addMatchButton(QString("ADD TEAM +"), this)
{
	setCellWidget(0, 0, &addMatchButton);
	matchList = nullptr;
}

matchListTable::~matchListTable()
{
}
