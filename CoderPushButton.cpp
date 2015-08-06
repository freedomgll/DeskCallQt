#include "CoderPushButton.h"


CoderPushButton::CoderPushButton(void)
{
}

CoderPushButton::CoderPushButton(const QString & text, const QRect & rect, DeskCallQT * parent):QPushButton(text, parent)
{
	QString str=QStringLiteral("QPushButton {border-image: url(Resources/%1_up.jpg); color:  %2;} QPushButton:pressed {border-image: url(Resources/%1_down.jpg);} ").arg(QStringLiteral("×ÏË®¾§"),"#008000");
	this->setStyleSheet(str);
	this->setFont(parent->buttonFont);
	this->setGeometry(rect);
	this->show();

	this->parent = parent;
}

CoderPushButton::~CoderPushButton(void)
{
}

void CoderPushButton::RecreateButtonList(QList<QPushButton *> buttonList)
{
	foreach(QPushButton * b,this->parent->buttonList)
	{
		delete b;
	}

	this->parent->buttonList.clear();
	this->parent->buttonList.append(buttonList);
}