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
    std::shared_ptr<glicko2TeamSet> teamSet;
    actionHandler handler;

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

    QChart* currentChart = new QChart;
    QValueAxis* yAxis = new QValueAxis;
    QValueAxis* xAxis = new QValueAxis;
    QLineSeries* rateData = new QLineSeries;

public slots:
    void updateTeamInfo(size_t teamIndex);

private:
    Ui::mainWindow* ui;
};
#endif // MAINWINDOW_H
