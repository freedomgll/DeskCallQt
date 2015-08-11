#ifndef DESKCHOICE_H
#define DESKCHOICE_H

#include <QDialog>
#include "ui_deskchoice.h"
#include "ConfigSql.h"
#include <QCheckBox>

class DeskChoice : public QDialog
{
	Q_OBJECT

public:
	DeskChoice(QWidget *parent = 0);
	~DeskChoice();

public slots:
	void areaChanged(int);

private:
	Ui::DeskChoice ui;

	QList<areaT> areaList;
	QList<QCheckBox *> checkBoxList;
};

#endif // DESKCHOICE_H
