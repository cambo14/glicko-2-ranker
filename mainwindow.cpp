//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow), handler(this, teamSet)
    , rateDistribx(0), rateDistriby(0)
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

    ui->rankDistChart->setMinimumWidth(250);

    ui->rankDistChart->addGraph();
    ui->rankDistChart->graph(0)->setData(rateDistribx, rateDistriby);

    ui->rankDistChart->xAxis->setLabel("Rating");
    ui->rankDistChart->yAxis->setLabel("Number of Teams with rating");
    ui->rankDistChart->xAxis->setRange(0, 2000);
    ui->rankDistChart->yAxis->setRange(0, 5);
    ui->rankDistChart->replot();


    QObject::connect(ui->actionAdd_Team, &QAction::triggered, &handler, &actionHandler::newTeam); //connecting various signals to their
    QObject::connect(ui->actionAdd_Match, &QAction::triggered, &handler, &actionHandler::newMatch);//appropriate slots
    QObject::connect(ui->actionAbout, &QAction::triggered, &handler, &actionHandler::onAbout);
    QObject::connect(ui->actionNew, &QAction::triggered, &handler, &actionHandler::onNew);
    QObject::connect(&handler, &actionHandler::teamCreated, ui->teamList, &teamListTable::teamAdded);
    QObject::connect(&handler, &actionHandler::teamCreated, this, &mainWindow::addRatingDistribSeries);
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








void mainWindow::addRatingDistribSeries(size_t teamIndex)    //TODO optimise later //function to add a rating to the series holding the different teams ratings and to then sort it
{
    ptrdiff_t lowerRange = 0;
    ptrdiff_t upperRange = rateDistribx.size();
    if (rateDistribx.size() == 0) { //just add the rating to the series if it is empty so there is no issue with searching an empty vector
        rateDistribx.append(teamSet->teamSet[teamIndex].rating);
        rateDistriby.append(1);
        ui->rankDistChart->replot();
        return;
    }
    while(true){
        ptrdiff_t middle = floor((upperRange - lowerRange) / 2) + lowerRange;
        if (teamSet->teamSet[teamIndex].rating > rateDistribx.at(middle)) {     
            lowerRange = middle + 1;
        }
        else if (teamSet->teamSet[teamIndex].rating < rateDistribx.at(middle)) {
            upperRange = (middle > 0) ? middle - 1 : middle;
        }
        else {
            rateDistriby[middle]++;
            break;
        }
        if (upperRange - lowerRange == 0) {
            if (lowerRange >= rateDistribx.size()) {
                rateDistribx.push_back(teamSet->teamSet[teamIndex].rating);
                rateDistriby.push_back(1);
            } else {
                if (rateDistribx[lowerRange] == teamSet->teamSet[teamIndex].rating) {
                    rateDistriby[lowerRange]++;
                    break;
                }
                rateDistribx.insert(rateDistribx.begin() + lowerRange, teamSet->teamSet[teamIndex].rating);
                rateDistriby.insert(rateDistriby.begin() + lowerRange, 1);
            }
            break;
        }
    }
    ui->rankDistChart->xAxis->setRange(rateDistribx[0], rateDistribx[rateDistribx.size() - 1]);
    ui->rankDistChart->yAxis->setRange(0, (teamSet->teamSet.size() > 5) ? teamSet->teamSet.size() / 2 : 5);
    ui->rankDistChart->graph(0)->setData(rateDistribx, rateDistriby);
    ui->rankDistChart->replot();
}

void mainWindow::initRatingData()
{
    rateDistribx.clear();
    rateDistriby.clear();

    for (size_t i = 0; i < teamSet->teamSet.size(); i++) {
        bool found = false;
        size_t lowerRange = 0;
        size_t upperRange = rateDistribx.size() - 1;
        while (found == false) {
            size_t middle = floor((upperRange - lowerRange) / 2) + lowerRange;
            if (teamSet->teamSet[i].rating > rateDistribx.at(middle)) {
                lowerRange = middle + 1;
            }
            else if (teamSet->teamSet[i].rating < rateDistribx.at(middle)) {
                upperRange = middle - 1;
            }
            else {
                found = true;
                rateDistriby[middle]++;
            }
            if (upperRange - lowerRange == 0) {
                rateDistribx.insert(rateDistribx.begin() + (lowerRange + 1), teamSet->teamSet[i].rating);
                rateDistriby.insert(rateDistriby.begin() + (lowerRange + 1), 1);
                break;
            }
        }
    }
    ui->rankDistChart->replot();
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
