/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *infoTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *infoImg;
    QLabel *infoText;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(375, 230);
        aboutDialog->setMinimumSize(QSize(375, 230));
        aboutDialog->setMaximumSize(QSize(375, 230));
        widget = new QWidget(aboutDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 359, 176));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoTitle = new QLabel(widget);
        infoTitle->setObjectName(QString::fromUtf8("infoTitle"));
        QFont font;
        font.setPointSize(21);
        infoTitle->setFont(font);

        verticalLayout->addWidget(infoTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        infoImg = new QLabel(widget);
        infoImg->setObjectName(QString::fromUtf8("infoImg"));
        infoImg->setMinimumSize(QSize(100, 100));
        infoImg->setMaximumSize(QSize(100, 100));
        infoImg->setPixmap(QPixmap(QString::fromUtf8(":/resources/about.png")));
        infoImg->setScaledContents(true);

        horizontalLayout->addWidget(infoImg);

        infoText = new QLabel(widget);
        infoText->setObjectName(QString::fromUtf8("infoText"));
        infoText->setTextFormat(Qt::RichText);
        infoText->setWordWrap(true);
        infoText->setTextInteractionFlags(Qt::TextBrowserInteraction);

        horizontalLayout->addWidget(infoText);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QCoreApplication::translate("aboutDialog", "About", nullptr));
        infoTitle->setText(QCoreApplication::translate("aboutDialog", "About", nullptr));
        infoImg->setText(QString());
        infoText->setText(QCoreApplication::translate("aboutDialog", "<html><head/><body><p>This is a program that will rank sets of teams based of the Glicko-2 ranking system. More information can be found about this system <a href=\"http://www.glicko.net/glicko/glicko2.pdf\"><span style=\" text-decoration: underline; color:#0000ff;\">here</span></a>. As a quick overview however rating refers to how well a team performs and RD refers to how consistent a team is in how it performs. If in doubt about what a teams value should be use the pre entered value.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
