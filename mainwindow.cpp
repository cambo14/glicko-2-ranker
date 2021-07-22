//Copyright(C) 2021 Campbell Rowland
//see license file for more information

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileOps.h"

mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow), handler(this, teamSet)
    , rateDistribx(0), rateDistriby(0)
{
    teamSet = std::make_shared<glicko2TeamSet*>(new glicko2TeamSet);
    handler.teamSet = teamSet;

    ui->setupUi(this);              //initialise various ui components
    ui->matchList->init(teamSet);
    ui->teamList->init(teamSet);

    ui->rateHistoryView->setMinimumWidth(250);  //initialise the rating history chart
    ui->rateHistoryView->addGraph();
    ui->rateHistoryView->yAxis->setLabel("Rating");

    ui->rankDistChart->setMinimumWidth(250);        //initialise the ranking distribution chart on the main screen
    ui->rankDistChart->addGraph();
    ui->rankDistChart->graph(0)->setData(rateDistribx, rateDistriby);
    ui->rankDistChart->xAxis->setLabel("Rating");
    ui->rankDistChart->yAxis->setLabel("Number of Teams with rating");
    ui->rankDistChart->xAxis->setRange(0, 2000);
    ui->rankDistChart->yAxis->setRange(0, 5);
    ui->rankDistChart->replot();

    QObject::connect(ui->actionAdd_Team, &QAction::triggered, &handler, &actionHandler::newTeam); //connecting various signals to their
    QObject::connect(ui->actionAdd_Match, &QAction::triggered, &handler, &actionHandler::newMatch);//appropriate slots
    QObject::connect(ui->actionSave_As, &QAction::triggered, this, &mainWindow::saveAs);
    QObject::connect(ui->actionOpen, &QAction::triggered, this, &mainWindow::openFile);
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
    QObject::connect(ui->calcRankButton, &QPushButton::released, this, &mainWindow::rateTeams);
    QObject::connect(ui->actionRank, &QAction::triggered, this, &mainWindow::rateTeams);
    QObject::connect(&handler, &actionHandler::sysValsNeedUpdate, this, &mainWindow::updateSysVals);
    QObject::connect(ui->sysConView, &QLineEdit::editingFinished, this, &mainWindow::updateSysCon);


    //TODO remove this once debugging is done
    handler.newTeamAdded("main", 1500, 200);
    handler.newTeamAdded("one", 1400, 30);
    handler.newTeamAdded("two", 1550, 100);
    handler.newTeamAdded("three", 1700, 300);

    handler.newMatchAdded(0, 1, 0);
    handler.newMatchAdded(0, 2, 1);
    handler.newMatchAdded(0, 3, 1);

    updateSysVals(); //update the sysVals panel
}



void mainWindow::saveAs()
{
    QFile saveFile(QFileDialog::getSaveFileName(this, "Save As","", "Xml Files(*.xml)", nullptr, QFileDialog::ShowDirsOnly));
    createAndSaveCurrentToFile(&saveFile, &handler);
}

void mainWindow::updateMatchInfo(size_t matchIndex)
{
    ui->matchNum->setText("Match " + QString::number(matchIndex + 1));
    for (size_t i = 0; i < (*teamSet.get())->teamSet.size(); i++) {
        ui->team1Combo->addItem(QString::fromUtf8((*teamSet.get())->teamSet[i].name));
        ui->team2Combo->addItem(QString::fromUtf8((*teamSet.get())->teamSet[i].name));
        ui->team1Combo->setCurrentIndex(std::distance((*teamSet.get())->teamSet.begin(),std::find((*teamSet.get())->teamSet.begin(), (*teamSet.get())->teamSet.end(),*(*teamSet.get())->matchSet[matchIndex].team1)));
        ui->team2Combo->setCurrentIndex(std::distance((*teamSet.get())->teamSet.begin(),std::find((*teamSet.get())->teamSet.begin(), (*teamSet.get())->teamSet.end(),*(*teamSet.get())->matchSet[matchIndex].team2)));
    }
    ui->resultCombo->addItem("Team 1 Won");
    ui->resultCombo->addItem("Team 2 Won");
    ui->resultCombo->addItem("Draw");
    ui->resultCombo->setCurrentIndex(static_cast<unsigned short>((*(teamSet.get()))->matchSet[matchIndex].winner));
    
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

void mainWindow::openFile()
{
    QFile openFile(QFileDialog::getOpenFileName(this, "Open", "", "Xml Files(*.xml)"));
    readFromFile(&openFile, &handler);
    ui->teamList->refresh();
    emit handler.sysValsNeedUpdate();
}

void mainWindow::comboEdited(matchMemType field, size_t matchIndex) {
    switch (field) {
    case matchMemType::team1:
        (*(this->teamSet.get()))->matchSet[matchIndex].team1 = &(*teamSet.get())->teamSet.at(ui->team1Combo->currentIndex());
        break;
    case matchMemType::team2:
        (*(this->teamSet.get()))->matchSet[matchIndex].team2 = &(*teamSet.get())->teamSet.at(ui->team2Combo->currentIndex());
        break;
    case matchMemType::result:
        (*(this->teamSet.get()))->matchSet[matchIndex].winner = static_cast<result>(ui->resultCombo->currentIndex());
        break;
    }
    emit matchComboUpdated(matchIndex);
}

void mainWindow::updateSysVals()
{
    ui->numTeamsView->setText(QString::number((*teamSet)->teamSet.size()));
    ui->numMatchesView->setText(QString::number((*teamSet)->numMatchesComplete));
    if ((*teamSet)->teamSet.size() > 0) ui->ratingRangeView->setText(QString::number((*teamSet)->teamSet[(*teamSet)->getLowestRating()].rating) + " - " + QString::number((*teamSet)->teamSet[(*teamSet)->getHighestRating()].rating));
}

void mainWindow::rateTeams()
{
    emit handler.sysValsNeedUpdate();
    (*(teamSet.get()))->rateTeams();
    ui->teamList->refresh();
    ui->matchList->clear();
}

void mainWindow::updateSysCon()
{
    bool* isNum = new bool;
    float newSysCon = ui->sysConView->text().toFloat(isNum);
    if (!isNum) {
        if (!handler.nonFatalErrorEncountered("Invalid input", "A Number was not inputted into the system constant box. Please input a positive number above 0 into the system constant box to change the system constant")) {
            saveAs();   //save the file and close the program if the user decides to save and quit
            delete this;
        }
        ui->sysConView->setText(QString::number((*teamSet)->sysCon));
    }
    else {
        if (newSysCon > 0) {
            if (!((0.3 <= newSysCon) & (newSysCon<= 1.2))) {
                if (!handler.warningDialogEncountered("Atypical value entered", "The typical value of this variable is between 0.3 and 1.2 however you entered a number outside of this range. Do you want to continue?")) {
                    ui->sysConView->setText(QString::number((*teamSet)->sysCon));
                    return;
                }
            }
            (*teamSet)->sysCon = newSysCon;
            return;
        }
        else {
            if (!handler.nonFatalErrorEncountered("Invalid input", "An invalid number was inputted into the system constant box. Please input a positive number above 0 into the system constant box")) {
                saveAs();   //save the file and close the program if the user decides to save and quit
                delete this;
            }
            ui->sysConView->setText(QString::number((*teamSet)->sysCon));
        }
    }
    delete isNum;
}

void mainWindow::addRatingDistribSeries(size_t teamIndex)    //function to add a rating to the series holding the different teams ratings and to then sort it
{
    ptrdiff_t lowerRange = 0;
    ptrdiff_t upperRange = rateDistribx.size();
    if (rateDistribx.size() == 0) { //just add the rating to the series if it is empty so there is no issue with searching an empty vector
        rateDistribx.append((*(teamSet.get()))->teamSet[teamIndex].rating);
        rateDistriby.append(1);
        ui->rankDistChart->replot();
        return;
    }
    while(true){
        ptrdiff_t middle = floor((upperRange - lowerRange) / 2) + lowerRange;
        if ((*(teamSet.get()))->teamSet[teamIndex].rating > rateDistribx.at(middle)) {     
            lowerRange = middle + 1;
        }
        else if ((*(teamSet.get()))->teamSet[teamIndex].rating < rateDistribx.at(middle)) {
            upperRange = (middle > 0) ? middle - 1 : middle;
        }
        else {
            rateDistriby[middle]++;
            break;
        }
        if (upperRange - lowerRange == 0) {
            if (lowerRange >= rateDistribx.size()) {
                rateDistribx.push_back((*(teamSet.get()))->teamSet[teamIndex].rating);
                rateDistriby.push_back(1);
            } else {
                if (rateDistribx[lowerRange] == (*(teamSet.get()))->teamSet[teamIndex].rating) {
                    rateDistriby[lowerRange]++;
                    break;
                }
                rateDistribx.insert(rateDistribx.begin() + lowerRange, (*(teamSet.get()))->teamSet[teamIndex].rating);
                rateDistriby.insert(rateDistriby.begin() + lowerRange, 1);
            }
            break;
        }
    }
    ui->rankDistChart->xAxis->setRange(rateDistribx[0], rateDistribx[rateDistribx.size() - 1]);
    ui->rankDistChart->yAxis->setRange(0, ((*(teamSet.get()))->teamSet.size() > 5) ? (*(teamSet.get()))->teamSet.size() / 2 : 5);
    ui->rankDistChart->graph(0)->setData(rateDistribx, rateDistriby);
    ui->rankDistChart->replot();
}

void mainWindow::initRatingData()
{
    rateDistribx.clear();
    rateDistriby.clear();

    for (size_t i = 0; i < (*teamSet.get())->teamSet.size(); i++) {
        bool found = false;
        size_t lowerRange = 0;
        size_t upperRange = rateDistribx.size() - 1;
        while (found == false) {
            size_t middle = floor((upperRange - lowerRange) / 2) + lowerRange;
            if ((*teamSet.get())->teamSet[i].rating > rateDistribx.at(middle)) {
                lowerRange = middle + 1;
            }
            else if ((*teamSet.get())->teamSet[i].rating < rateDistribx.at(middle)) {
                upperRange = middle - 1;
            }
            else {
                found = true;
                rateDistriby[middle]++;
            }
            if (upperRange - lowerRange == 0) {
                rateDistribx.insert(rateDistribx.begin() + (lowerRange + 1), (*teamSet.get())->teamSet[i].rating);
                rateDistriby.insert(rateDistriby.begin() + (lowerRange + 1), 1);
                break;
            }
        }
    }
    ui->rankDistChart->replot();
}


void mainWindow::updateTeamInfo(size_t teamIndex) {
    ui->teamNameLabel->setText(QString::fromUtf8((*teamSet.get())->teamSet[teamIndex].name)); //update values on team info label
    ui->ratingView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].rating));
    ui->ratingDevView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].RD));
    ui->volView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].volatility));
    ui->matWonView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].matchWonCount));
    ui->matDrawnView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].matchDrawnCount));
    ui->matLostView->setText(QString::number((*teamSet.get())->teamSet[teamIndex].matchLostCount));
    newTeamSelected(teamIndex);
}

void mainWindow::newTeamSelected(size_t teamIndex) {
    ui->rateHistoryView->xAxis->setRange(0, (*teamSet.get())->teamSet[teamIndex].rateHistx.size());
    ui->rateHistoryView->yAxis->setRange(0,(*teamSet.get())->teamSet[teamIndex].getHighestRateHist() * 1.3);
    ui->rateHistoryView->xAxis->setLabel(QString::fromUtf8((*teamSet.get())->teamSet[teamIndex].name));
    ui->rateHistoryView->graph(0)->setData((*teamSet.get())->teamSet[teamIndex].rateHistx, (*teamSet.get())->teamSet[teamIndex].rateHisty);
    ui->rateHistoryView->replot();
}

mainWindow::~mainWindow()
{
    delete ui;
}
