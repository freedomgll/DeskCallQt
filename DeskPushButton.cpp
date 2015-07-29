#include "DeskPushButton.h"


DeskPushButton::DeskPushButton(const QString & text,  QString id, int layer, QWidget * parent):QPushButton(text, parent)
{
	this->id = id;
	this->layer = layer;
}
