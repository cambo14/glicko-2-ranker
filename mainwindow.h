#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "actionHandler.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::shared_ptr<glicko2TeamSet> teamSet;
    actionHandler handler;

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

public slots:
    void updateTeamInfo(size_t teamIndex);

private:
    Ui::mainWindow* ui;
};
#endif // MAINWINDOW_H
