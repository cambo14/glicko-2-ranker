//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "matchListTableItem.h"

matchListTableItem::matchListTableItem(std::shared_ptr<glicko2TeamSet*> teamS, size_t ind, QWidget* parent) : 
	QPushButton(QString::fromUtf8((*(teamS.get()))->matchSet.at(ind).team1->name) + " V " + QString::fromUtf8((*(teamS.get()))->matchSet.at(ind).team2->name), parent)
{
	index = ind;
	teamSet = teamS;
}

matchListTableItem::~matchListTableItem()
{
}
