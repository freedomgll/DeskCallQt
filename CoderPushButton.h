#pragma once
#include "qpushbutton.h"
#include "deskcallqt.h"

class CoderPushButton :
	public QPushButton
{
public:
	CoderPushButton(void);
	CoderPushButton(const QString & text, const QRect & rect, DeskCallQT * parent);
	~CoderPushButton(void);

	void setButtonStyle();

protected:
	DeskCallQT * parent;

	//void RecreateButtonList(QList<CoderPushButton *> buttonList);
};

