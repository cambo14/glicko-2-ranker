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

    ui->rateHistoryView->setChart(currentChart); //initialise individual teams rating history chart
    rateData->append(0, 10);
    currentChart->addSeries(rateData);
    currentChart->setAxisX(xAxis);
    currentChart->setAxisY(yAxis);
    yAxis->setTitleText("Rating");
    xAxis->setTitleText("Match");
    rateData->setVisible(false);

    ui->rankDistChart->setChart(currentSysInfoChart); //initialise ranking distribution chart
    currentSysInfoChart->addSeries(rateDistribData);
    currentSysInfoChart->setAxisX(xAxisSys);
    currentSysInfoChart->setAxisY(yAxisSys);
    xAxisSys->setTitleText("Rating");
    yAxisSys->setTitleText("Number Of Teams");
    rateDistribData->setVisible(false);
    currentSysInfoChart->setTitle("Rating Distribution in System");
    rateDistribData->setName("Rating Distribution throughout system");


    QObject::connect(ui->actionAdd_Team, &QAction::triggered, &handler, &actionHandler::newTeam); //connecting various signals to their
    QObject::connect(ui->actionAdd_Match, &QAction::triggered, &handler, &actionHandler::newMatch);//appropriate slots
    QObject::connect(ui->actionAbout, &QAction::triggered, &handler, &actionHandler::onAbout);
    QObject::connect(ui->actionNew, &QAction::triggered, &handler, &actionHandler::onNew);
    QObject::connect(&handler, &actionHandler::teamCreated, ui->teamList, &teamListTable::teamAdded);
    QObject::connect(&handler, &actionHandler::matchCreated, ui->matchList, &matchListTable::matchAdded);
    QObject::connect(&ui->teamList->addTeamButton, &QPushButton::released, &handler, &actionHandler::newTeam);
    QObject::connect(&ui->matchList->addMatchButton, &QPushButton::released, &handler, &actionHandler::newMatch);
    QObject::connect(ui->teamList, &teamListTable::updateTeamInfo, this, &mainWindow::updateTeamInfo);
    QObject::connect(ui->matchList, &matchListTable::updateMatchInfo, this, &mainWindow::updateMatchInfo);
    QObject::connect(this, &mainWindow::matchComboUpdated, ui->matchList, &matchListTable::updateMatch);
}

void mainWindow::updateMatchInfo(size_t matchIndex)
{
    ui->matchNum->setText("Match " + QString::number(matchIndex + 1));
    for (size_t i = 0; i < teamSet->teamSet.size(); i++) {
        ui->team1Combo->addItem(QString::fromUtf8(teamSet->teamSet[i].name));
        ui->team2Combo->addItem(QString::fromUtf8(teamSet->teamSet[i].name));
        ui->team1Combo->setCurrentIndex(std::distance(teamSet->teamSet.begin(),std::find(teamSet->teamSet.begin(), teamSet->teamSet.end(),*teamSet->matchSet[matchIndex].team1)));
        ui->team2Combo->setCurrentIndex(std::distance(teamSet->teamSet.begin(),std::find(teamSet->teamSet.begin(), teamSet->teamSet.end(),*teamSet->matchSet[matchIndex].team2)));
    }
    ui->resultCombo->addItem("Team 1 Won");
    ui->resultCombo->addItem("Team 2 Won");
    ui->resultCombo->addItem("Draw");
    ui->resultCombo->setCurrentIndex(static_cast<unsigned short>(teamSet->matchSet[matchIndex].winner));
    
    ui->team1Combo->disconnect();
    ui->team2Combo->disconnect();
    ui->resultCombo->disconnect();

    QObject::connect(ui->team1Combo, &QComboBox::currentIndexChanged, this, [=]() {
        this->comboEdited(matchMemType::team1, matchIndex); });
    QObject::connect(ui->team2Combo, &QComboBox::currentIndexChanged, this, [=]() {
        this->comboEdited(matchMemType::team2, matchIndex); });
    QObject::connect(ui->resultCombo, &QComboBox::currentIndexChanged, this, [=]() {
        this->comboEdited(matchMemType::result, matchIndex); });
}

void mainWindow::comboEdited(matchMemType field, size_t matchIndex) {
    switch (field) {
    case matchMemType::team1:
        this->teamSet->matchSet[matchIndex].team1 = &teamSet->teamSet.at(ui->team1Combo->currentIndex());
        break;
    case matchMemType::team2:
        this->teamSet->matchSet[matchIndex].team2 = &teamSet->teamSet.at(ui->team2Combo->currentIndex());
        break;
    case matchMemType::result:
        this->teamSet->matchSet[matchIndex].winner = static_cast<result>(ui->resultCombo->currentIndex());
        break;
    }
    emit matchComboUpdated(matchIndex);
}

void mainWindow::updateSysInfo()
{
    ui->numTeamsView->setText(QString::number(teamSet->teamSet.size()));
    ui->numMatchesView->setText(QString::number(teamSet->numMatchesComplete));
    ui->sysConView->setText(QString::number(teamSet->sysCon));      //TODO set callback for this entry
    ui->ratingRangeView->setText(QString::number(teamSet->teamSet.at(teamSet->getLowestRating()).rating) + " - " + QString::number(teamSet->teamSet.at(teamSet->getHighestRating()).rating));
}

void mainWindow::addRatingRateHistory(size_t teamIndex) //TODO optimise for sorting when sorting is implemented
                                                        //This will also involve sorting points for easy searching
{
    for (int i = 0; i < rateDistribData->count(); i++) {
        if (rateDistribData->at(i).x() == teamSet->teamSet.at(teamIndex).rating) {
            rateDistribData->replace(i, rateDistribData->at(i).x(), rateDistribData->at(i).y() + 1);
            return;
        }
    }
    rateDistribData->append(teamSet->teamSet.at(teamIndex).rating, 1);
}

void mainWindow::changeRatingRateHistory(size_t teamIndex, float oldRating)//TODO optimise for sorting when sorting is implemented
                                                                           //This will also involve sorting points for easy searching
{
    for (size_t i = 0; i < rateDistribData->count(); i++) {
        if (rateDistribData->at(i).x() == oldRating) {
            rateDistribData->replace(i, rateDistribData->at(i).x(), rateDistribData->at(i).y() - 1);
            break;
        }
    }
    addRatingRateHistory(teamIndex);
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
    delete currentSysInfoChart;
}



