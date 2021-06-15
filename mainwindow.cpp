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

}

mainWindow::~mainWindow()
{
    delete ui;
}

