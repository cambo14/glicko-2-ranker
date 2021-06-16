//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow), handler(this, teamSet)
{
    teamSet = std::make_shared<glicko2TeamSet>("mainWInd");
    handler.teamSet = teamSet;

    ui->setupUi(this);              //initialise various ui components
    ui->matchList->init(teamSet);
    ui->teamList->init(teamSet);
    ui->rateHistoryView->setChart(currentChart);
    rateData->append(0, 10);
    currentChart->addSeries(rateData);
    currentChart->setAxisX(xAxis);
    currentChart->setAxisY(yAxis);
    yAxis->setTitleText("Rating");
    xAxis->setTitleText("Match");
    rateData->setVisible(false);


    QObject::connect(ui->actionAdd_Team, &QAction::triggered, &handler, &actionHandler::newTeam); //connecting various signals to their
    QObject::connect(ui->actionAdd_Match, &QAction::triggered, &handler, &actionHandler::newMatch);//appropriate slot on actionHandler
    QObject::connect(ui->actionAbout, &QAction::triggered, &handler, &actionHandler::onAbout);
    QObject::connect(ui->actionNew, &QAction::triggered, &handler, &actionHandler::onNew);
    QObject::connect(&handler, &actionHandler::teamCreated, ui->teamList, &teamListTable::teamAdded);
    QObject::connect(&handler, &actionHandler::matchCreated, ui->matchList, &matchListTable::matchAdded);
    QObject::connect(&ui->teamList->addTeamButton, &QPushButton::released, &handler, &actionHandler::newTeam);
    QObject::connect(&ui->matchList->addMatchButton, &QPushButton::released, &handler, &actionHandler::newMatch);
    QObject::connect(ui->teamList, &teamListTable::updateTeamInfo, this, &mainWindow::updateTeamInfo);
    
}

void mainWindow::updateTeamInfo(size_t teamIndex) {
    ui->teamNameLabel->setText(QString::fromUtf8(teamSet->teamSet[teamIndex].name)); //update values on team info label
    ui->ratingView->setText(QString::number(teamSet->teamSet[teamIndex].rating));
    ui->ratingDevView->setText(QString::number(teamSet->teamSet[teamIndex].RD));
    ui->volView->setText(QString::number(teamSet->teamSet[teamIndex].volatility));
    ui->matWonView->setText(QString::number(teamSet->teamSet[teamIndex].matchWonCount));
    ui->matDrawnView->setText(QString::number(teamSet->teamSet[teamIndex].matchDrawnCount));
    ui->matLostView->setText(QString::number(teamSet->teamSet[teamIndex].matchLostCount));

    currentChart->setTitle(QString::fromUtf8(teamSet->teamSet[teamIndex].name));    //update graph with new values
    delete rateData;
    rateData = new QLineSeries;
    rateData->setName(QString::fromUtf8(teamSet->teamSet[teamIndex].name));
    for (int i = 0; i < teamSet->teamSet[teamIndex].rateHist.size(); i++) {
        rateData->append(i, teamSet->teamSet[teamIndex].rateHist.at(i));
    }
    currentChart->addSeries(rateData);
    rateData->attachAxis(xAxis);
    rateData->attachAxis(yAxis);
    yAxis->setRange(0, floor((teamSet->teamSet[teamIndex].rating * 1.5) / 40) * 40);    //set range forcing all ticks to be rounded to the nearest 10
    xAxis->setRange(0, teamSet->teamSet[teamIndex].rateHist.size());
    if (teamSet->teamSet[teamIndex].rateHist.size() < 4) xAxis->setTickCount(teamSet->teamSet[teamIndex].rateHist.size() + 1);
}

mainWindow::~mainWindow()
{
    delete ui;
    delete currentChart;
}

