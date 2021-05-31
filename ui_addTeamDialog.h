/********************************************************************************
** Form generated from reading UI file 'addTeamDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEAMDIALOG_H
#define UI_ADDTEAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addTeamDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *valueLay;
    QHBoxLayout *teamNameLay;
    QLabel *teamNameLabel;
    QLineEdit *teamNameInput;
    QHBoxLayout *ratingLay;
    QLabel *ratingLabel;
    QLineEdit *ratingInput;
    QHBoxLayout *ratDevLay;
    QLabel *ratDevLabel;
    QLineEdit *ratDevInp;
    QHBoxLayout *volLay;
    QLabel *volLabel;
    QLineEdit *volInput;
    QHBoxLayout *finalButtonLay;
    QPushButton *cancelTeamAddButton;
    QSpacerItem *buttonSpacer;
    QPushButton *addTeamButton;

    void setupUi(QDialog *addTeamDialog)
    {
        if (addTeamDialog->objectName().isEmpty())
            addTeamDialog->setObjectName(QString::fromUtf8("addTeamDialog"));
        addTeamDialog->resize(350, 200);
        addTeamDialog->setMinimumSize(QSize(350, 200));
        addTeamDialog->setMaximumSize(QSize(350, 200));
        verticalLayout = new QVBoxLayout(addTeamDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        valueLay = new QVBoxLayout();
        valueLay->setSpacing(6);
        valueLay->setObjectName(QString::fromUtf8("valueLay"));
        teamNameLay = new QHBoxLayout();
        teamNameLay->setSpacing(6);
        teamNameLay->setObjectName(QString::fromUtf8("teamNameLay"));
        teamNameLabel = new QLabel(addTeamDialog);
        teamNameLabel->setObjectName(QString::fromUtf8("teamNameLabel"));
        teamNameLabel->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(11);
        teamNameLabel->setFont(font);

        teamNameLay->addWidget(teamNameLabel);

        teamNameInput = new QLineEdit(addTeamDialog);
        teamNameInput->setObjectName(QString::fromUtf8("teamNameInput"));

        teamNameLay->addWidget(teamNameInput);


        valueLay->addLayout(teamNameLay);

        ratingLay = new QHBoxLayout();
        ratingLay->setSpacing(6);
        ratingLay->setObjectName(QString::fromUtf8("ratingLay"));
        ratingLabel = new QLabel(addTeamDialog);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));
        ratingLabel->setMinimumSize(QSize(0, 0));
        ratingLabel->setFont(font);

        ratingLay->addWidget(ratingLabel);

        ratingInput = new QLineEdit(addTeamDialog);
        ratingInput->setObjectName(QString::fromUtf8("ratingInput"));

        ratingLay->addWidget(ratingInput);


        valueLay->addLayout(ratingLay);

        ratDevLay = new QHBoxLayout();
        ratDevLay->setSpacing(6);
        ratDevLay->setObjectName(QString::fromUtf8("ratDevLay"));
        ratDevLabel = new QLabel(addTeamDialog);
        ratDevLabel->setObjectName(QString::fromUtf8("ratDevLabel"));
        ratDevLabel->setMinimumSize(QSize(0, 0));
        ratDevLabel->setFont(font);

        ratDevLay->addWidget(ratDevLabel);

        ratDevInp = new QLineEdit(addTeamDialog);
        ratDevInp->setObjectName(QString::fromUtf8("ratDevInp"));

        ratDevLay->addWidget(ratDevInp);


        valueLay->addLayout(ratDevLay);

        volLay = new QHBoxLayout();
        volLay->setSpacing(6);
        volLay->setObjectName(QString::fromUtf8("volLay"));
        volLabel = new QLabel(addTeamDialog);
        volLabel->setObjectName(QString::fromUtf8("volLabel"));
        volLabel->setMinimumSize(QSize(0, 0));
        volLabel->setFont(font);

        volLay->addWidget(volLabel);

        volInput = new QLineEdit(addTeamDialog);
        volInput->setObjectName(QString::fromUtf8("volInput"));

        volLay->addWidget(volInput);


        valueLay->addLayout(volLay);


        verticalLayout->addLayout(valueLay);

        finalButtonLay = new QHBoxLayout();
        finalButtonLay->setSpacing(6);
        finalButtonLay->setObjectName(QString::fromUtf8("finalButtonLay"));
        cancelTeamAddButton = new QPushButton(addTeamDialog);
        cancelTeamAddButton->setObjectName(QString::fromUtf8("cancelTeamAddButton"));

        finalButtonLay->addWidget(cancelTeamAddButton);

        buttonSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        finalButtonLay->addItem(buttonSpacer);

        addTeamButton = new QPushButton(addTeamDialog);
        addTeamButton->setObjectName(QString::fromUtf8("addTeamButton"));

        finalButtonLay->addWidget(addTeamButton);


        verticalLayout->addLayout(finalButtonLay);


        retranslateUi(addTeamDialog);

        QMetaObject::connectSlotsByName(addTeamDialog);
    } // setupUi

    void retranslateUi(QDialog *addTeamDialog)
    {
        addTeamDialog->setWindowTitle(QCoreApplication::translate("addTeamDialog", "Add Team", nullptr));
        teamNameLabel->setText(QCoreApplication::translate("addTeamDialog", "Team Name:", nullptr));
        teamNameInput->setText(QString());
        ratingLabel->setText(QCoreApplication::translate("addTeamDialog", "Rating:", nullptr));
        ratingInput->setText(QCoreApplication::translate("addTeamDialog", "1500", nullptr));
        ratDevLabel->setText(QCoreApplication::translate("addTeamDialog", "Rating Deviation:", nullptr));
        ratDevInp->setText(QCoreApplication::translate("addTeamDialog", "350", nullptr));
        volLabel->setText(QCoreApplication::translate("addTeamDialog", "Volatility:", nullptr));
        volInput->setText(QCoreApplication::translate("addTeamDialog", "0.06", nullptr));
        cancelTeamAddButton->setText(QCoreApplication::translate("addTeamDialog", "Cancel", nullptr));
        addTeamButton->setText(QCoreApplication::translate("addTeamDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTeamDialog: public Ui_addTeamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEAMDIALOG_H
