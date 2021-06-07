#ifndef _MATCHLISTTABLE_H_
#define _MATCHLISTTABLE_H_

#include <QTableWidget>
#include <QPushButton>
#include <memory>
#include "glicko2TeamSet.h"

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

	void init(std::shared_ptr<glicko2TeamSet> matchLi); /*init function due to not being able to use custom constructors for promoted classes with 
										qt designer make sure to call this ASAP*/

	matchListTable(QWidget *parent = Q_NULLPTR);
	~matchListTable();

private:

};

#endif