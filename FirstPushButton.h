#pragma once
#include "qpushbutton.h"
#include "deskcallqt.h"

#include <QtWidgets/QWidget>
#include <QList>

class FirstPushButton :
	public QPushButton
{
	Q_OBJECT

public:
	FirstPushButton(void);
	FirstPushButton(const QString & text,  QString id, int layer,DeskCallQT * parent = 0);
	~FirstPushButton(void);

	void DrawButtons(QList<int> list);

public slots:
	void print();

private:
	DeskCallQT * parent;
	QString classid;
};

