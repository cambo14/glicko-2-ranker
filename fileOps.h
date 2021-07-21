//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef _FILEOPS_H_
#define _FILEOPS_H_
#include <iostream>
#include <memory>
#include <QFile>
#include "actionHandler.h"

void createAndSaveCurrentToFile(QFile* file, actionHandler* handler); //a function to take the curren teamset and store all of its information to file
void readFromFile(QFile* file, actionHandler* handler);	//a function to read all the data on the ranking system from a provided XML file

#endif