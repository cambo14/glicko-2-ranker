//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* A header file that contains the functions that
* do all the actions on files that need to be done
* by this software
*/

#ifndef _FILEOPS_H_
#define _FILEOPS_H_
#include <iostream>
#include <memory>
#include <QFile>
#include "actionHandler.h"

void createAndSaveCurrentToFile(QFile* file, actionHandler* handler); //a function to take the curren teamset and store all of its information to file
void readFromFile(QFile* file, actionHandler* handler);	//a function to read all the data on the ranking system from a provided XML file

#endif