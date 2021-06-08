//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "teamListTableItem.h"

teamListTableItem::teamListTableItem(std::shared_ptr<glicko2TeamSet> teamS, size_t ind, QWidget* parent) : teamSet(teamS), 
QPushButton(QString::fromUtf8(teamS->teamSet.at(ind).name) + "  Rating: " + QString::number(teamS->teamSet.at(ind).rating),parent)
{
	index = ind;
}

teamListTableItem::teamListTableItem(const teamListTableItem& tableItem)
{
	teamSet = tableItem.teamSet;
}

teamListTableItem::~teamListTableItem()
{
}
