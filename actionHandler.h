#ifndef _ACTIONHANDLER_H_
#define _ACTIONHANDLER_H_

#include <QObject>

class actionHandler:public QObject {  //a class designed to handle actions done by the user and to then perform the appropriate actions
	Q_OBJECT
public:
	actionHandler(QWidget* par);
	QWidget* parent;	//the parent window of this handler
public slots:
	void newTeam();	//a slot to run when an action that results in a new team being created is performed
	void newMatch(); //a slot to run when an action that results in a new match being created is performed
	void onAbout(); //a slot to run when an action that results in an about dialog box showing up is performed
};

#endif
