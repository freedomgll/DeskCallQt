#ifndef DESKLOGIN_H
#define DESKLOGIN_H

#include <QWidget>
#include "ui_desklogin.h"

class DeskLogin : public QWidget
{
	Q_OBJECT

public:
	DeskLogin(QWidget *parent = 0);
	~DeskLogin();

private:
	Ui::DeskLogin ui;
};

#endif // DESKLOGIN_H
