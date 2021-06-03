#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "actionHandler.h"
#include "glicko2TeamSet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    glicko2TeamSet *teamSet;
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();


private:
    Ui::mainWindow* ui;
    actionHandler handler;
};
#endif // MAINWINDOW_H
