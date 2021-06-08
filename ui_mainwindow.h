/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"
#include "matchListTable.h"
#include "teamListTable.h"

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSystem_Constant;
    QAction *actionAbout;
    QAction *actionTeams;
    QAction *actionAdd_Team;
    QAction *actionMatches;
    QAction *actionAdd_Match;
    QAction *actionRank;
    QAction *actionNew;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    teamListTable *teamList;
    QVBoxLayout *infoLay;
    QHBoxLayout *sysInfoLay;
    QVBoxLayout *sysValLay;
    QHBoxLayout *numTeamsLay;
    QLabel *numTeamsLabel;
    QLabel *numTeamsView;
    QHBoxLayout *numMatchesLay;
    QLabel *numMatchesLabel;
    QLabel *numMatchesView;
    QHBoxLayout *sysConLay;
    QLabel *sysConLabel;
    QLineEdit *sysConView;
    QHBoxLayout *ratingRangeLay;
    QLabel *ratingRangeLabel;
    QLabel *ratingRangeView;
    QChartView *rankDistChart;
    QVBoxLayout *teamInfoLay;
    QLabel *teamNameLabel;
    QHBoxLayout *teamGraphInfoLay;
    QVBoxLayout *teamTextInfoLay;
    QHBoxLayout *ratingLay;
    QLabel *ratingLabel;
    QLabel *ratingView;
    QHBoxLayout *ratingDevLay;
    QLabel *ratingDevLabel;
    QLabel *ratingDevView;
    QHBoxLayout *volLay;
    QLabel *volLabel;
    QLabel *volView;
    QHBoxLayout *matWonLay;
    QLabel *matWonLabel;
    QLabel *matWonView;
    QHBoxLayout *matLostLay;
    QLabel *matLostLabel;
    QLabel *matLostView;
    QHBoxLayout *matDrawnLay;
    QLabel *matDrawnLabel;
    QLabel *matDrawnView;
    QChartView *rateHistoryView;
    QVBoxLayout *verticalLayout;
    QPushButton *calcRankButton;
    matchListTable *matchList;
    QVBoxLayout *verticalLayout_2;
    QLabel *matchNum;
    QHBoxLayout *horizontalLayout;
    QLabel *team1Label;
    QComboBox *team1Combo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *team2Label;
    QComboBox *team2Combo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *resultLabel;
    QComboBox *resultCombo;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuTeams;
    QMenu *menuMatches;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(974, 600);
        mainWindow->setAutoFillBackground(false);
        actionOpen = new QAction(mainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(mainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(mainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSystem_Constant = new QAction(mainWindow);
        actionSystem_Constant->setObjectName(QString::fromUtf8("actionSystem_Constant"));
        actionAbout = new QAction(mainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionTeams = new QAction(mainWindow);
        actionTeams->setObjectName(QString::fromUtf8("actionTeams"));
        actionAdd_Team = new QAction(mainWindow);
        actionAdd_Team->setObjectName(QString::fromUtf8("actionAdd_Team"));
        actionMatches = new QAction(mainWindow);
        actionMatches->setObjectName(QString::fromUtf8("actionMatches"));
        actionAdd_Match = new QAction(mainWindow);
        actionAdd_Match->setObjectName(QString::fromUtf8("actionAdd_Match"));
        actionRank = new QAction(mainWindow);
        actionRank->setObjectName(QString::fromUtf8("actionRank"));
        actionNew = new QAction(mainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        teamList = new teamListTable(centralwidget);
        if (teamList->columnCount() < 1)
            teamList->setColumnCount(1);
        if (teamList->rowCount() < 1)
            teamList->setRowCount(1);
        teamList->setObjectName(QString::fromUtf8("teamList"));
        teamList->setEnabled(true);
        teamList->setMaximumSize(QSize(200, 16777215));
        teamList->setSizeIncrement(QSize(1, 3));
        teamList->setBaseSize(QSize(1, 3));
        teamList->setShowGrid(false);
        teamList->setRowCount(1);
        teamList->setColumnCount(1);
        teamList->horizontalHeader()->setVisible(false);
        teamList->horizontalHeader()->setStretchLastSection(true);
        teamList->verticalHeader()->setVisible(false);
        teamList->verticalHeader()->setMinimumSectionSize(45);
        teamList->verticalHeader()->setDefaultSectionSize(45);

        horizontalLayout_5->addWidget(teamList);

        infoLay = new QVBoxLayout();
        infoLay->setObjectName(QString::fromUtf8("infoLay"));
        sysInfoLay = new QHBoxLayout();
        sysInfoLay->setObjectName(QString::fromUtf8("sysInfoLay"));
        sysValLay = new QVBoxLayout();
        sysValLay->setSpacing(0);
        sysValLay->setObjectName(QString::fromUtf8("sysValLay"));
        numTeamsLay = new QHBoxLayout();
        numTeamsLay->setObjectName(QString::fromUtf8("numTeamsLay"));
        numTeamsLay->setContentsMargins(-1, -1, -1, 0);
        numTeamsLabel = new QLabel(centralwidget);
        numTeamsLabel->setObjectName(QString::fromUtf8("numTeamsLabel"));
        numTeamsLabel->setMinimumSize(QSize(140, 20));
        numTeamsLabel->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(11);
        numTeamsLabel->setFont(font);

        numTeamsLay->addWidget(numTeamsLabel);

        numTeamsView = new QLabel(centralwidget);
        numTeamsView->setObjectName(QString::fromUtf8("numTeamsView"));
        numTeamsView->setMinimumSize(QSize(50, 20));
        numTeamsView->setMaximumSize(QSize(16777215, 20));
        numTeamsView->setFont(font);

        numTeamsLay->addWidget(numTeamsView);


        sysValLay->addLayout(numTeamsLay);

        numMatchesLay = new QHBoxLayout();
        numMatchesLay->setSpacing(5);
        numMatchesLay->setObjectName(QString::fromUtf8("numMatchesLay"));
        numMatchesLay->setContentsMargins(-1, 0, -1, -1);
        numMatchesLabel = new QLabel(centralwidget);
        numMatchesLabel->setObjectName(QString::fromUtf8("numMatchesLabel"));
        numMatchesLabel->setMinimumSize(QSize(140, 20));
        numMatchesLabel->setMaximumSize(QSize(16777215, 20));
        numMatchesLabel->setFont(font);

        numMatchesLay->addWidget(numMatchesLabel);

        numMatchesView = new QLabel(centralwidget);
        numMatchesView->setObjectName(QString::fromUtf8("numMatchesView"));
        numMatchesView->setMinimumSize(QSize(50, 20));
        numMatchesView->setMaximumSize(QSize(16777215, 20));
        numMatchesView->setFont(font);

        numMatchesLay->addWidget(numMatchesView);


        sysValLay->addLayout(numMatchesLay);

        sysConLay = new QHBoxLayout();
        sysConLay->setObjectName(QString::fromUtf8("sysConLay"));
        sysConLabel = new QLabel(centralwidget);
        sysConLabel->setObjectName(QString::fromUtf8("sysConLabel"));
        sysConLabel->setMinimumSize(QSize(140, 20));
        sysConLabel->setMaximumSize(QSize(16777215, 20));
        sysConLabel->setFont(font);

        sysConLay->addWidget(sysConLabel);

        sysConView = new QLineEdit(centralwidget);
        sysConView->setObjectName(QString::fromUtf8("sysConView"));

        sysConLay->addWidget(sysConView);


        sysValLay->addLayout(sysConLay);

        ratingRangeLay = new QHBoxLayout();
        ratingRangeLay->setObjectName(QString::fromUtf8("ratingRangeLay"));
        ratingRangeLabel = new QLabel(centralwidget);
        ratingRangeLabel->setObjectName(QString::fromUtf8("ratingRangeLabel"));
        ratingRangeLabel->setMinimumSize(QSize(140, 20));
        ratingRangeLabel->setMaximumSize(QSize(16777215, 20));
        ratingRangeLabel->setFont(font);

        ratingRangeLay->addWidget(ratingRangeLabel);

        ratingRangeView = new QLabel(centralwidget);
        ratingRangeView->setObjectName(QString::fromUtf8("ratingRangeView"));
        ratingRangeView->setMinimumSize(QSize(50, 20));
        ratingRangeView->setMaximumSize(QSize(16777215, 20));
        ratingRangeView->setFont(font);

        ratingRangeLay->addWidget(ratingRangeView);


        sysValLay->addLayout(ratingRangeLay);


        sysInfoLay->addLayout(sysValLay);

        rankDistChart = new QChartView(centralwidget);
        rankDistChart->setObjectName(QString::fromUtf8("rankDistChart"));

        sysInfoLay->addWidget(rankDistChart);


        infoLay->addLayout(sysInfoLay);

        teamInfoLay = new QVBoxLayout();
        teamInfoLay->setObjectName(QString::fromUtf8("teamInfoLay"));
        teamNameLabel = new QLabel(centralwidget);
        teamNameLabel->setObjectName(QString::fromUtf8("teamNameLabel"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        teamNameLabel->setFont(font1);

        teamInfoLay->addWidget(teamNameLabel);

        teamGraphInfoLay = new QHBoxLayout();
        teamGraphInfoLay->setObjectName(QString::fromUtf8("teamGraphInfoLay"));
        teamTextInfoLay = new QVBoxLayout();
        teamTextInfoLay->setObjectName(QString::fromUtf8("teamTextInfoLay"));
        ratingLay = new QHBoxLayout();
        ratingLay->setObjectName(QString::fromUtf8("ratingLay"));
        ratingLabel = new QLabel(centralwidget);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));
        ratingLabel->setMinimumSize(QSize(140, 20));
        ratingLabel->setMaximumSize(QSize(16777215, 20));
        ratingLabel->setFont(font);

        ratingLay->addWidget(ratingLabel);

        ratingView = new QLabel(centralwidget);
        ratingView->setObjectName(QString::fromUtf8("ratingView"));
        ratingView->setMinimumSize(QSize(140, 20));
        ratingView->setMaximumSize(QSize(16777215, 20));
        ratingView->setFont(font);

        ratingLay->addWidget(ratingView);


        teamTextInfoLay->addLayout(ratingLay);

        ratingDevLay = new QHBoxLayout();
        ratingDevLay->setObjectName(QString::fromUtf8("ratingDevLay"));
        ratingDevLabel = new QLabel(centralwidget);
        ratingDevLabel->setObjectName(QString::fromUtf8("ratingDevLabel"));
        ratingDevLabel->setMinimumSize(QSize(140, 20));
        ratingDevLabel->setMaximumSize(QSize(16777215, 20));
        ratingDevLabel->setFont(font);

        ratingDevLay->addWidget(ratingDevLabel);

        ratingDevView = new QLabel(centralwidget);
        ratingDevView->setObjectName(QString::fromUtf8("ratingDevView"));
        ratingDevView->setMinimumSize(QSize(140, 20));
        ratingDevView->setMaximumSize(QSize(16777215, 20));
        ratingDevView->setFont(font);

        ratingDevLay->addWidget(ratingDevView);


        teamTextInfoLay->addLayout(ratingDevLay);

        volLay = new QHBoxLayout();
        volLay->setObjectName(QString::fromUtf8("volLay"));
        volLabel = new QLabel(centralwidget);
        volLabel->setObjectName(QString::fromUtf8("volLabel"));
        volLabel->setMinimumSize(QSize(140, 20));
        volLabel->setMaximumSize(QSize(16777215, 20));
        volLabel->setFont(font);

        volLay->addWidget(volLabel);

        volView = new QLabel(centralwidget);
        volView->setObjectName(QString::fromUtf8("volView"));
        volView->setMinimumSize(QSize(140, 20));
        volView->setMaximumSize(QSize(16777215, 20));
        volView->setFont(font);

        volLay->addWidget(volView);


        teamTextInfoLay->addLayout(volLay);

        matWonLay = new QHBoxLayout();
        matWonLay->setObjectName(QString::fromUtf8("matWonLay"));
        matWonLabel = new QLabel(centralwidget);
        matWonLabel->setObjectName(QString::fromUtf8("matWonLabel"));
        matWonLabel->setMinimumSize(QSize(140, 20));
        matWonLabel->setMaximumSize(QSize(16777215, 20));
        matWonLabel->setFont(font);

        matWonLay->addWidget(matWonLabel);

        matWonView = new QLabel(centralwidget);
        matWonView->setObjectName(QString::fromUtf8("matWonView"));
        matWonView->setMinimumSize(QSize(140, 20));
        matWonView->setMaximumSize(QSize(16777215, 20));
        matWonView->setFont(font);

        matWonLay->addWidget(matWonView);


        teamTextInfoLay->addLayout(matWonLay);

        matLostLay = new QHBoxLayout();
        matLostLay->setObjectName(QString::fromUtf8("matLostLay"));
        matLostLabel = new QLabel(centralwidget);
        matLostLabel->setObjectName(QString::fromUtf8("matLostLabel"));
        matLostLabel->setMinimumSize(QSize(140, 20));
        matLostLabel->setMaximumSize(QSize(16777215, 20));
        matLostLabel->setFont(font);

        matLostLay->addWidget(matLostLabel);

        matLostView = new QLabel(centralwidget);
        matLostView->setObjectName(QString::fromUtf8("matLostView"));
        matLostView->setMinimumSize(QSize(140, 20));
        matLostView->setMaximumSize(QSize(16777215, 20));
        matLostView->setFont(font);

        matLostLay->addWidget(matLostView);


        teamTextInfoLay->addLayout(matLostLay);

        matDrawnLay = new QHBoxLayout();
        matDrawnLay->setObjectName(QString::fromUtf8("matDrawnLay"));
        matDrawnLabel = new QLabel(centralwidget);
        matDrawnLabel->setObjectName(QString::fromUtf8("matDrawnLabel"));
        matDrawnLabel->setMinimumSize(QSize(140, 20));
        matDrawnLabel->setMaximumSize(QSize(16777215, 20));
        matDrawnLabel->setFont(font);

        matDrawnLay->addWidget(matDrawnLabel);

        matDrawnView = new QLabel(centralwidget);
        matDrawnView->setObjectName(QString::fromUtf8("matDrawnView"));
        matDrawnView->setMinimumSize(QSize(140, 20));
        matDrawnView->setMaximumSize(QSize(16777215, 20));
        matDrawnView->setFont(font);

        matDrawnLay->addWidget(matDrawnView);


        teamTextInfoLay->addLayout(matDrawnLay);


        teamGraphInfoLay->addLayout(teamTextInfoLay);

        rateHistoryView = new QChartView(centralwidget);
        rateHistoryView->setObjectName(QString::fromUtf8("rateHistoryView"));

        teamGraphInfoLay->addWidget(rateHistoryView);


        teamInfoLay->addLayout(teamGraphInfoLay);


        infoLay->addLayout(teamInfoLay);

        infoLay->setStretch(0, 2);
        infoLay->setStretch(1, 3);

        horizontalLayout_5->addLayout(infoLay);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calcRankButton = new QPushButton(centralwidget);
        calcRankButton->setObjectName(QString::fromUtf8("calcRankButton"));
        calcRankButton->setMinimumSize(QSize(0, 70));
        QFont font2;
        font2.setPointSize(20);
        calcRankButton->setFont(font2);

        verticalLayout->addWidget(calcRankButton);

        matchList = new matchListTable(centralwidget);
        if (matchList->columnCount() < 1)
            matchList->setColumnCount(1);
        if (matchList->rowCount() < 1)
            matchList->setRowCount(1);
        matchList->setObjectName(QString::fromUtf8("matchList"));
        matchList->setMinimumSize(QSize(200, 0));
        matchList->setMaximumSize(QSize(200, 16777215));
        matchList->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        matchList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        matchList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        matchList->setShowGrid(false);
        matchList->setRowCount(1);
        matchList->setColumnCount(1);
        matchList->horizontalHeader()->setVisible(false);
        matchList->horizontalHeader()->setHighlightSections(true);
        matchList->horizontalHeader()->setStretchLastSection(true);
        matchList->verticalHeader()->setVisible(false);
        matchList->verticalHeader()->setCascadingSectionResizes(true);
        matchList->verticalHeader()->setMinimumSectionSize(45);
        matchList->verticalHeader()->setDefaultSectionSize(45);
        matchList->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(matchList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        matchNum = new QLabel(centralwidget);
        matchNum->setObjectName(QString::fromUtf8("matchNum"));
        QFont font3;
        font3.setPointSize(12);
        matchNum->setFont(font3);
        matchNum->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(matchNum);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        team1Label = new QLabel(centralwidget);
        team1Label->setObjectName(QString::fromUtf8("team1Label"));

        horizontalLayout->addWidget(team1Label);

        team1Combo = new QComboBox(centralwidget);
        team1Combo->setObjectName(QString::fromUtf8("team1Combo"));

        horizontalLayout->addWidget(team1Combo);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        team2Label = new QLabel(centralwidget);
        team2Label->setObjectName(QString::fromUtf8("team2Label"));

        horizontalLayout_3->addWidget(team2Label);

        team2Combo = new QComboBox(centralwidget);
        team2Combo->setObjectName(QString::fromUtf8("team2Combo"));

        horizontalLayout_3->addWidget(team2Combo);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));

        horizontalLayout_4->addWidget(resultLabel);

        resultCombo = new QComboBox(centralwidget);
        resultCombo->setObjectName(QString::fromUtf8("resultCombo"));

        horizontalLayout_4->addWidget(resultCombo);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(1, 4);
        mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 974, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTeams = new QMenu(menubar);
        menuTeams->setObjectName(QString::fromUtf8("menuTeams"));
        menuMatches = new QMenu(menubar);
        menuMatches->setObjectName(QString::fromUtf8("menuMatches"));
        mainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuTeams->menuAction());
        menubar->addAction(menuMatches->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuEdit->addAction(actionSystem_Constant);
        menuHelp->addAction(actionAbout);
        menuTeams->addAction(actionTeams);
        menuTeams->addAction(actionAdd_Team);
        menuMatches->addAction(actionMatches);
        menuMatches->addAction(actionAdd_Match);
        menuMatches->addAction(actionRank);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "Glicko-2 Ranker", nullptr));
        actionOpen->setText(QCoreApplication::translate("mainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("mainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("mainWindow", "Save As", nullptr));
        actionSystem_Constant->setText(QCoreApplication::translate("mainWindow", "System Constant", nullptr));
        actionAbout->setText(QCoreApplication::translate("mainWindow", "About", nullptr));
        actionTeams->setText(QCoreApplication::translate("mainWindow", "Teams", nullptr));
        actionAdd_Team->setText(QCoreApplication::translate("mainWindow", "Add Team", nullptr));
        actionMatches->setText(QCoreApplication::translate("mainWindow", "Matches", nullptr));
        actionAdd_Match->setText(QCoreApplication::translate("mainWindow", "Add Match", nullptr));
        actionRank->setText(QCoreApplication::translate("mainWindow", "Rank", nullptr));
        actionNew->setText(QCoreApplication::translate("mainWindow", "New", nullptr));
        numTeamsLabel->setText(QCoreApplication::translate("mainWindow", "Number of Teams:", nullptr));
        numTeamsView->setText(QCoreApplication::translate("mainWindow", "32", nullptr));
        numMatchesLabel->setText(QCoreApplication::translate("mainWindow", "Number of Matches Complete:", nullptr));
        numMatchesView->setText(QCoreApplication::translate("mainWindow", "32", nullptr));
        sysConLabel->setText(QCoreApplication::translate("mainWindow", "System Constant:", nullptr));
        sysConView->setText(QCoreApplication::translate("mainWindow", "0.8", nullptr));
        ratingRangeLabel->setText(QCoreApplication::translate("mainWindow", "Range of Ratings:", nullptr));
        ratingRangeView->setText(QCoreApplication::translate("mainWindow", "500-3500", nullptr));
        teamNameLabel->setText(QCoreApplication::translate("mainWindow", "Team Name Here", nullptr));
        ratingLabel->setText(QCoreApplication::translate("mainWindow", "Rating:", nullptr));
        ratingView->setText(QCoreApplication::translate("mainWindow", "2753", nullptr));
        ratingDevLabel->setText(QCoreApplication::translate("mainWindow", "Rating Deviation:", nullptr));
        ratingDevView->setText(QCoreApplication::translate("mainWindow", "351", nullptr));
        volLabel->setText(QCoreApplication::translate("mainWindow", "Volatility:", nullptr));
        volView->setText(QCoreApplication::translate("mainWindow", "0.08", nullptr));
        matWonLabel->setText(QCoreApplication::translate("mainWindow", "Matches Won:", nullptr));
        matWonView->setText(QCoreApplication::translate("mainWindow", "12", nullptr));
        matLostLabel->setText(QCoreApplication::translate("mainWindow", "Matches Lost:", nullptr));
        matLostView->setText(QCoreApplication::translate("mainWindow", "12", nullptr));
        matDrawnLabel->setText(QCoreApplication::translate("mainWindow", "Matches Drawn:", nullptr));
        matDrawnView->setText(QCoreApplication::translate("mainWindow", "1", nullptr));
        calcRankButton->setText(QCoreApplication::translate("mainWindow", "RANK", nullptr));
        matchNum->setText(QCoreApplication::translate("mainWindow", "Match NULL", nullptr));
        team1Label->setText(QCoreApplication::translate("mainWindow", "Team 1:", nullptr));
        team2Label->setText(QCoreApplication::translate("mainWindow", "Team 2:", nullptr));
        resultLabel->setText(QCoreApplication::translate("mainWindow", "Result:", nullptr));
        menuFile->setTitle(QCoreApplication::translate("mainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("mainWindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainWindow", "Help", nullptr));
        menuTeams->setTitle(QCoreApplication::translate("mainWindow", "Teams", nullptr));
        menuMatches->setTitle(QCoreApplication::translate("mainWindow", "Matches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
