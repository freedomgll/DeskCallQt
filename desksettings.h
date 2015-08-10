#ifndef DESKSETTINGS_H
#define DESKSETTINGS_H

#include <QDialog>
#include "ui_desksettings.h"

#include "deskcallqt.h"

class DeskSettings : public QDialog
{
	Q_OBJECT

public:
	DeskSettings(QWidget *parent = 0);
	DeskSettings(DeskCallQT *parent);
	~DeskSettings();

public slots:
	void loadConfig();
	void saveConfig();
	void clickButtonBGP();
	void clickButtonFont();
	void clickButtonColor();

private:
	Ui::DeskSettings ui;

	DeskCallQT *parent;
	
	void SetIntValidate(QLineEdit *edit);
};

#endif // DESKSETTINGS_H
