/********************************************************************************
** Form generated from reading UI file 'addMatchDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMATCHDIALOG_H
#define UI_ADDMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addMatchDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *finalLayout;
    QHBoxLayout *team1Layout;
    QLabel *team1Label;
    QComboBox *team1Input;
    QHBoxLayout *team2Layout;
    QLabel *team2Label;
    QComboBox *team2Input;
    QHBoxLayout *winnerLayout;
    QLabel *winnerLabel;
    QComboBox *winnerInput;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *addMatchDialog)
    {
        if (addMatchDialog->objectName().isEmpty())
            addMatchDialog->setObjectName(QString::fromUtf8("addMatchDialog"));
        addMatchDialog->resize(210, 200);
        addMatchDialog->setMinimumSize(QSize(210, 200));
        addMatchDialog->setMaximumSize(QSize(210, 200));
        horizontalLayout_2 = new QHBoxLayout(addMatchDialog);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        finalLayout = new QVBoxLayout();
        finalLayout->setSpacing(6);
        finalLayout->setObjectName(QString::fromUtf8("finalLayout"));
        team1Layout = new QHBoxLayout();
        team1Layout->setSpacing(6);
        team1Layout->setObjectName(QString::fromUtf8("team1Layout"));
        team1Label = new QLabel(addMatchDialog);
        team1Label->setObjectName(QString::fromUtf8("team1Label"));

        team1Layout->addWidget(team1Label);

        team1Input = new QComboBox(addMatchDialog);
        team1Input->setObjectName(QString::fromUtf8("team1Input"));

        team1Layout->addWidget(team1Input);


        finalLayout->addLayout(team1Layout);

        team2Layout = new QHBoxLayout();
        team2Layout->setSpacing(6);
        team2Layout->setObjectName(QString::fromUtf8("team2Layout"));
        team2Label = new QLabel(addMatchDialog);
        team2Label->setObjectName(QString::fromUtf8("team2Label"));

        team2Layout->addWidget(team2Label);

        team2Input = new QComboBox(addMatchDialog);
        team2Input->setObjectName(QString::fromUtf8("team2Input"));

        team2Layout->addWidget(team2Input);


        finalLayout->addLayout(team2Layout);

        winnerLayout = new QHBoxLayout();
        winnerLayout->setSpacing(6);
        winnerLayout->setObjectName(QString::fromUtf8("winnerLayout"));
        winnerLabel = new QLabel(addMatchDialog);
        winnerLabel->setObjectName(QString::fromUtf8("winnerLabel"));

        winnerLayout->addWidget(winnerLabel);

        winnerInput = new QComboBox(addMatchDialog);
        winnerInput->setObjectName(QString::fromUtf8("winnerInput"));

        winnerLayout->addWidget(winnerInput);


        finalLayout->addLayout(winnerLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(addMatchDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addButton = new QPushButton(addMatchDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);


        finalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(finalLayout);


        retranslateUi(addMatchDialog);

        QMetaObject::connectSlotsByName(addMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *addMatchDialog)
    {
        addMatchDialog->setWindowTitle(QCoreApplication::translate("addMatchDialog", "addMatchDialog", nullptr));
        team1Label->setText(QCoreApplication::translate("addMatchDialog", "Team 1:", nullptr));
        team2Label->setText(QCoreApplication::translate("addMatchDialog", "Team 2:", nullptr));
        winnerLabel->setText(QCoreApplication::translate("addMatchDialog", "Winner:", nullptr));
        cancelButton->setText(QCoreApplication::translate("addMatchDialog", "Cancel", nullptr));
        addButton->setText(QCoreApplication::translate("addMatchDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addMatchDialog: public Ui_addMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMATCHDIALOG_H
