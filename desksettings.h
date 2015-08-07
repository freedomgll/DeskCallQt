#ifndef DESKSETTINGS_H
#define DESKSETTINGS_H

#include <QDialog>
#include "ui_desksettings.h"

class DeskSettings : public QDialog
{
	Q_OBJECT

public:
	DeskSettings(QWidget *parent = 0);
	~DeskSettings();

private:
	Ui::DeskSettings ui;
};

#endif // DESKSETTINGS_H
