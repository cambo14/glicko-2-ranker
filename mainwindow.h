//Copyright(C) 2021 Campbell Rowland
//see license file for more information

/*
* A class that handles the main window of the program and all
* other things that need to be managed by it
* this is the base class of the software
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "actionHandler.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::shared_ptr<glicko2TeamSet*> teamSet;   //a shared pointer to the pointer containing the system
    actionHandler handler;                      // an instance of the actionHandler class to do all the actions that are done by that class

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();


    QVector<double> rateDistribx, rateDistriby; //QVectors holding the values for the rating distribution chart

public slots:
    
    void updateTeamInfo(size_t teamIndex); //a slot that updates teams info on the UI when it is edited 
    void updateMatchInfo(size_t matchIndex);    // a slot that updates match info on the UI when it is edited
    void comboEdited(matchMemType field, size_t matchIndex); //a slot that is run when on of the matches are edited using the combo boxes in the bottom right of the main window
    void rateTeams(); //a slot to be run when the user wants to rate all the teams based on the submitted matches
    void saveAs();  //a slot to be run when the user wants to save the current system to a file
    void openFile();   //a slot to be run when the user wants to open a system that is saved on a file
    void updateSysVals();   //a slot to be run when the system values need to be edited in the UI
    void updateSysCon();    // a slot to be run when the system constant needs to be edited in the UI
signals:
    void matchComboUpdated(size_t matchIndex); //a signal to inform the matchListTable when the combo Boxes are edited
private:
    Ui::mainWindow* ui;
    void addRatingDistribSeries(size_t teamIndex); //a function containing code that needs to be run when rateDistribData is changed
    void newTeamSelected(size_t teamIndex); // a function to run to update the rating history chart when a team is selected
    void initRatingData();  // a dunction to run when the rating chart needs to be intialised
};


#endif // MAINWINDOW_H
