//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "teamListTableItem.h"

void teamListTableItem::refresh()
{
	setText(QString::fromUtf8((*teamSet.get())->teamSet[index].name) + " Rating: " + QString::number((*teamSet.get())->teamSet[index].rating));
}

teamListTableItem::teamListTableItem(std::shared_ptr<glicko2TeamSet*> teamS, size_t ind, QWidget* parent) : teamSet(teamS),
QPushButton(QString::fromUtf8((*teamS.get())->teamSet.at(ind).name) + "  Rating: " + QString::number((*teamS.get())->teamSet.at(ind).rating),parent)
{
	index = ind;
	teamSet = teamS;
}

teamListTableItem::teamListTableItem(const teamListTableItem& tableItem)
{
	teamSet = tableItem.teamSet;
}

teamListTableItem::~teamListTableItem()
{
}
