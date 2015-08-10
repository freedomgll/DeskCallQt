#pragma once
#ifndef CODERPUSHBUTTON_H
#define CODERPUSHBUTTON_H

#include "qpushbutton.h"

class DeskCallQT;

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

#endif // CODERPUSHBUTTON_H

