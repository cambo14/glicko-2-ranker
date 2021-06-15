/********************************************************************************
** Form generated from reading UI file 'werrorDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WERRORDIALOG_H
#define UI_WERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_werrorDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *werrorTitle;
    QHBoxLayout *infoImgLay;
    QLabel *werrorImg;
    QVBoxLayout *infoLay;
    QLabel *werrorCap;
    QLabel *werrorInfo;
    QHBoxLayout *horizontalLayout;
    QPushButton *button2;
    QSpacerItem *horizontalSpacer;
    QPushButton *button1;

    void setupUi(QDialog *werrorDialog)
    {
        if (werrorDialog->objectName().isEmpty())
            werrorDialog->setObjectName(QString::fromUtf8("werrorDialog"));
        werrorDialog->resize(350, 175);
        werrorDialog->setMinimumSize(QSize(350, 175));
        werrorDialog->setMaximumSize(QSize(350, 175));
        layoutWidget = new QWidget(werrorDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 345, 169));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        werrorTitle = new QLabel(layoutWidget);
        werrorTitle->setObjectName(QString::fromUtf8("werrorTitle"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        werrorTitle->setFont(font);
        werrorTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(werrorTitle);

        infoImgLay = new QHBoxLayout();
        infoImgLay->setSpacing(6);
        infoImgLay->setObjectName(QString::fromUtf8("infoImgLay"));
        werrorImg = new QLabel(layoutWidget);
        werrorImg->setObjectName(QString::fromUtf8("werrorImg"));
        werrorImg->setMaximumSize(QSize(100, 100));
        werrorImg->setPixmap(QPixmap(QString::fromUtf8(":/warning")));
        werrorImg->setScaledContents(true);

        infoImgLay->addWidget(werrorImg);

        infoLay = new QVBoxLayout();
        infoLay->setSpacing(6);
        infoLay->setObjectName(QString::fromUtf8("infoLay"));
        werrorCap = new QLabel(layoutWidget);
        werrorCap->setObjectName(QString::fromUtf8("werrorCap"));
        QFont font1;
        font1.setPointSize(12);
        werrorCap->setFont(font1);

        infoLay->addWidget(werrorCap);

        werrorInfo = new QLabel(layoutWidget);
        werrorInfo->setObjectName(QString::fromUtf8("werrorInfo"));
        werrorInfo->setWordWrap(true);

        infoLay->addWidget(werrorInfo);

        infoLay->setStretch(0, 1);
        infoLay->setStretch(1, 5);

        infoImgLay->addLayout(infoLay);

        infoImgLay->setStretch(0, 1);
        infoImgLay->setStretch(1, 3);

        verticalLayout->addLayout(infoImgLay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button2 = new QPushButton(layoutWidget);
        button2->setObjectName(QString::fromUtf8("button2"));

        horizontalLayout->addWidget(button2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button1 = new QPushButton(layoutWidget);
        button1->setObjectName(QString::fromUtf8("button1"));

        horizontalLayout->addWidget(button1);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(werrorDialog);

        QMetaObject::connectSlotsByName(werrorDialog);
    } // setupUi

    void retranslateUi(QDialog *werrorDialog)
    {
        werrorDialog->setWindowTitle(QCoreApplication::translate("werrorDialog", "Warning", nullptr));
        werrorTitle->setText(QCoreApplication::translate("werrorDialog", "WERROR TITLE", nullptr));
        werrorImg->setText(QString());
        werrorCap->setText(QCoreApplication::translate("werrorDialog", "WERROR TYPE GOES HERE", nullptr));
        werrorInfo->setText(QCoreApplication::translate("werrorDialog", "FURTHER INFORMATION ABOUT THE WERROR GOES HERE E.G. WHAT CAUSED IT", nullptr));
        button2->setText(QCoreApplication::translate("werrorDialog", "BUTTON2", nullptr));
        button1->setText(QCoreApplication::translate("werrorDialog", "BUTTON1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class werrorDialog: public Ui_werrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WERRORDIALOG_H
