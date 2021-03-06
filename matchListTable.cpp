//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "matchListTable.h"

void matchListTable::matchAdded(size_t matchIndex) //a slot to run when a new match is added to the table
{
	setRowCount(rowCount() + 1);
	tableWidgets.push_back(new matchListTableItem(matchList, matchIndex, this));
	tableWidgets.at(matchIndex)->show();
	setCellWidget(rowCount() - 1, 0, tableWidgets.at(matchIndex));

	QObject::connect(this->tableWidgets.at(matchIndex), &QPushButton::released, this, [=]() {emit updateMatchInfo(matchIndex); });
}

void matchListTable::updateMatch(size_t matchIndex) //a slot to update the values on the table when a match is edited outside of the table
{
	this->tableWidgets.at(matchIndex)->setText(QString::fromUtf8((*matchList)->matchSet.at(matchIndex).team1->name) + " V " + QString::fromUtf8((*matchList)->matchSet.at(matchIndex).team2->name));
}

void matchListTable::init(std::shared_ptr<glicko2TeamSet*> matchLi) /*init function due to not being able to use custom constructors for promoted classes with 
																	qt designer make sure to call this ASAP*/
{
	matchList = matchLi;
}

void matchListTable::clear() //clear all buttons in the table. Used when a set of matches are ranked
{
	for (int i = 1; i < rowCount(); i++)removeCellWidget(i, 0);
	setRowCount(1);
	tableWidgets.clear();
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
