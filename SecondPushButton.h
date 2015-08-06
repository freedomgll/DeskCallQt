#pragma once
#include "CoderPushButton.h"
#include "deskcallqt.h"

class SecondPushButton :
	public CoderPushButton
{
public:
	SecondPushButton(void);
	SecondPushButton(const QString & text,  QString businessId, const QRect & rect, DeskCallQT * parent = 0);
	~SecondPushButton(void);

public slots:
	void clickAction();

private:
	QString businessId;
};

