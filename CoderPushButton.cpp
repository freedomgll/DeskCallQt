#include "CoderPushButton.h"
#include "deskcallqt.h"

CoderPushButton::CoderPushButton(void)
{
}

CoderPushButton::CoderPushButton(const QString & text, const QRect & rect, DeskCallQT * parent):QPushButton(text, parent)
{
	this->parent = parent;
	setButtonStyle();
	this->setGeometry(rect);
	this->show();
}

CoderPushButton::~CoderPushButton(void)
{
}

//void CoderPushButton::RecreateButtonList(QList<CoderPushButton *> buttonList)
//{
//	foreach(CoderPushButton * b,this->parent->buttonList)
//	{
//		delete b;
//	}
//
//	this->parent->buttonList.clear();
//	this->parent->buttonList.append(buttonList);
//}

void CoderPushButton::setButtonStyle()
{
	QString str=QStringLiteral("QPushButton {border-image: url(Resources/%1_up.jpg); color:  %2;} QPushButton:pressed {border-image: url(Resources/%1_down.jpg);} ").arg(parent->configSettings.buttonPic,"#008000");
	this->setStyleSheet(str);
	this->setFont(parent->configSettings.buttonFont);
}