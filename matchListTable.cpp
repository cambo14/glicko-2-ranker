//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "matchListTable.h"

//TODO create function to update table when value is changed from comboboxes in mainWindo.cpp

void matchListTable::matchAdded(size_t matchIndex)
{
	setRowCount(rowCount() + 1);
	tableWidgets.push_back(new matchListTableItem(matchList, matchIndex, this));
	tableWidgets.at(matchIndex)->show();
	setCellWidget(rowCount() - 1, 0, tableWidgets.at(matchIndex));

	QObject::connect(this->tableWidgets.at(matchIndex), &QPushButton::released, this, [=]() {emit updateMatchInfo(matchIndex); });
}

void matchListTable::updateMatch(size_t matchIndex)
{
	this->tableWidgets.at(matchIndex)->setText(QString::fromUtf8(matchList->matchSet.at(matchIndex).team1->name) + " V " + QString::fromUtf8(matchList->matchSet.at(matchIndex).team2->name));
}

void matchListTable::init(std::shared_ptr<glicko2TeamSet> matchLi)
{
	matchList = matchLi;
}

void matchListTable::clear()
{
	for (size_t i = 0; i < tableWidgets.size(); i++) delete tableWidgets[i];
	tableWidgets.shrink_to_fit();
}

matchListTable::matchListTable(QWidget* parent)
	: QTableWidget(1, 1, parent), addMatchButton(QString("ADD MATCH +"), this)
{
	setCellWidget(0, 0, &addMatchButton);
	QObject::connect(&addMatchButton, &QPushButton::released, this, &matchListTable::addMatchButtonPressed);
}

matchListTable::~matchListTable()
{
	if (tableWidgets.size() > 0) {
		for (size_t i = 0; i < tableWidgets.size(); i++) {
			delete tableWidgets[i];
		}
	}
}
