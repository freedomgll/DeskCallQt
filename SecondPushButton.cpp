#include "SecondPushButton.h"


SecondPushButton::SecondPushButton(void)
{
}

SecondPushButton::SecondPushButton(const QString & text,  QString businessId, const QRect & rect, DeskCallQT  * parent):CoderPushButton(text, rect, parent)
{
	this->businessId = businessId;
}

SecondPushButton::~SecondPushButton(void)
{
}
