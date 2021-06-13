#ifndef _MATCHLISTTABLE_H_
#define _MATCHLISTTABLE_H_

//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include <QTableWidget>
#include <vector>
#include "matchListTableItem.h"

/*
 A class to handle the table on the right hand side of the main
 window that stores information about the various matches and lets
 users add new matches
*/

class matchListTable : public QTableWidget
{
	Q_OBJECT

public:
	std::shared_ptr<glicko2TeamSet> matchList = nullptr;
	QPushButton addMatchButton;

	std::vector<matchListTableItem*> tableWidgets;

	void init(std::shared_ptr<glicko2TeamSet> matchLi); /*init function due to not being able to use custom constructors for promoted classes with 
														qt designer make sure to call this ASAP*/

	matchListTable(QWidget *parent = Q_NULLPTR);
	~matchListTable();

public slots:
	void matchAdded(size_t matchIndex); //a slot to run when a new match is added to the table
signals:
	void addMatchButtonPressed();
};

#endif