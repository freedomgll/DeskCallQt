#pragma once
#include <QPushButton>

class DeskPushButton : public QPushButton
{
	Q_OBJECT

public:
	QString id;
	int layer;
	DeskPushButton(const QString & text,  QString id, int layer,QWidget * parent = 0);
};

