#pragma once
#include "qpushbutton.h"
#include "deskcallqt.h"

class SecondPushButton :
	public QPushButton
{
public:
	SecondPushButton(void);
	SecondPushButton(const QString & text,  QString businessId, const QRect & rect, DeskCallQT * parent = 0);
	~SecondPushButton(void);

public slots:
	void clickAction();

private:
	DeskCallQT * parent;
	QString businessId;
};

