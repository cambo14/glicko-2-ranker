//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QValueAxis>
#include <QLineSeries>
#include "actionHandler.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::shared_ptr<glicko2TeamSet*> teamSet;
    actionHandler handler;

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();


    QVector<double> rateDistribx, rateDistriby; //QVectors holding the values for the rating distribution chart

public slots:
    
    void updateTeamInfo(size_t teamIndex); //slots to run to update certain elements of the ui that do not have their own custom class
    void updateMatchInfo(size_t matchIndex);
    void comboEdited(matchMemType field, size_t matchIndex);
    void rateTeams();
    void saveAs();
    void openFile();
    void updateSysVals();
    void updateSysCon();
signals:
    void matchComboUpdated(size_t matchIndex); //a signal to inform the matchListTable when the combo Boxes are edited
private:
    Ui::mainWindow* ui;
    void addRatingDistribSeries(size_t teamIndex); //a function containing code that needs to be run when rateDistribData is changed
    void newTeamSelected(size_t teamIndex); // a function to run to update the rating history chart when a team is selected
    void initRatingData();
};


#endif // MAINWINDOW_H
