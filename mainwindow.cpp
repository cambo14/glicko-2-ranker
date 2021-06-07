#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow), handler(this, teamSet)
{
    teamSet = std::make_shared<glicko2TeamSet>("mainWInd");

    ui->setupUi(this);              //initialise various ui components
    ui->matchList->init(teamSet);
    ui->teamList->init(teamSet);

    
    QObject::connect(ui->actionAdd_Team, &QAction::triggered, &handler, &actionHandler::newTeam); //connecting various signals to their
    QObject::connect(ui->actionAdd_Match, &QAction::triggered, &handler, &actionHandler::newMatch);//appropriate slot on actionHandler
    QObject::connect(ui->actionAbout, &QAction::triggered, &handler, &actionHandler::onAbout);
    QObject::connect(ui->actionNew, &QAction::triggered, &handler, &actionHandler::onNew);

    
}

mainWindow::~mainWindow()
{
    delete ui;
}

