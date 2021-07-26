//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _MATCHLISTTABLEITEM_H_
#define _MATCHLISTTABLEITEM_H_

#include <QtWidgets/QPushButton>
#include <memory>
#include "glicko2TeamSet.h"

/*
* A class to handle the individual items in the matchListTable class
*/

class matchListTableItem : public QPushButton
{
	Q_OBJECT
public:
	std::shared_ptr<glicko2TeamSet*> teamSet; //points to the class that handles all the actual calculations and team/match values for the system
	size_t index;	//the index of the match in the vector holding all of the matches that is in the system being pointed to by the teamSet pointer

	matchListTableItem(std::shared_ptr<glicko2TeamSet*> teamS, size_t ind, QWidget* parent);
	~matchListTableItem();
};

#endif

