#include "SecondPushButton.h"


SecondPushButton::SecondPushButton(void)
{
}

SecondPushButton::SecondPushButton(const QString & text,  QString businessId, QWidget * parent):QPushButton(text, parent)
{
	this->parent = parent;
	this->businessId = businessId;
}

SecondPushButton::~SecondPushButton(void)
{
}
