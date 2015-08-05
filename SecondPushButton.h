#pragma once
#include "qpushbutton.h"
class SecondPushButton :
	public QPushButton
{
public:
	SecondPushButton(void);
	SecondPushButton(const QString & text,  QString businessId, QWidget * parent = 0);
	~SecondPushButton(void);

public slots:
	void clickAction();

private:
	QWidget * parent;
	QString businessId;
};

