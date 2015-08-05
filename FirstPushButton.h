#pragma once
#include "qpushbutton.h"
#include "deskcallqt.h"

#include <QtWidgets/QWidget>
class FirstPushButton :
	public QPushButton
{
	Q_OBJECT

public:
	FirstPushButton(void);
	FirstPushButton(const QString & text,  QString id, int layer,DeskCallQT * parent = 0);
	~FirstPushButton(void);

public slots:
	void print();

private:
	DeskCallQT * parent;
	QString classid;
};

