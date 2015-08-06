#pragma once
#include "CoderPushButton.h"
#include "deskcallqt.h"

#include <QtWidgets/QWidget>
#include <QList>

class FirstPushButton :
	public CoderPushButton
{
	Q_OBJECT

public:
	FirstPushButton(void);
	FirstPushButton(const QString & text,  QString id, const QRect & rect, DeskCallQT * parent = 0);
	~FirstPushButton(void);

	void DrawButtons(QList<int> list);

public slots:
	void print();

private:
	QString classid;
};

