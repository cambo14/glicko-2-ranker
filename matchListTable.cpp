//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "matchListTable.h"

void matchListTable::matchAdded(size_t matchIndex)
{
	setRowCount(rowCount() + 1);
	tableWidgets.push_back(new matchListTableItem(matchList, matchIndex, this));
	tableWidgets.at(matchIndex)->show();
	setCellWidget(rowCount() - 1, 0, tableWidgets.at(matchIndex));

	QObject::connect(this->tableWidgets.at(matchIndex), &QPushButton::released, this, [=]() {emit updateMatchInfo(matchIndex); });
}

void matchListTable::init(std::shared_ptr<glicko2TeamSet> matchLi)
{
	matchList = matchLi;
}

matchListTable::matchListTable(QWidget* parent)
	: QTableWidget(1, 1, parent), addMatchButton(QString("ADD MATCH +"), this)
{
	setCellWidget(0, 0, &addMatchButton);
	QObject::connect(&addMatchButton, &QPushButton::released, this, &matchListTable::addMatchButtonPressed);
}

matchListTable::~matchListTable()
{
	for (size_t i = 0; i < tableWidgets.size(); i++) {
		delete tableWidgets[i];
	}
}
