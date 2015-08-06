#include "SecondPushButton.h"


SecondPushButton::SecondPushButton(void)
{
}

SecondPushButton::SecondPushButton(const QString & text,  QString businessId, const QRect & rect, DeskCallQT  * parent):QPushButton(text, parent)
{
	this->parent = parent;
	this->businessId = businessId;

	QString str=QStringLiteral("QPushButton {border-image: url(Resources/%1_up.jpg); color:  %2;} QPushButton:pressed {border-image: url(Resources/%1_down.jpg);} ").arg(QStringLiteral("×ÏË®¾§"),"#008000");
	this->setStyleSheet(str);
	this->setFont(this->parent->buttonFont);
	this->setGeometry(rect);
	this->show();
}

SecondPushButton::~SecondPushButton(void)
{
}
