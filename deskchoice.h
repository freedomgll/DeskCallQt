#ifndef DESKCHOICE_H
#define DESKCHOICE_H

#include <QDialog>
#include "ui_deskchoice.h"
#include "ConfigSql.h"
#include <QCheckBox>

#include "deskcallqt.h"

class DeskChoice : public QDialog
{
	Q_OBJECT

public:
	DeskChoice(QWidget *parent = 0);
	DeskChoice(DeskCallQT *parent);
	~DeskChoice();

	QList<classT> confirmChoice();

public slots:
	void areaChanged(int);

private:
	Ui::DeskChoice ui;

	DeskCallQT *parent;

	QList<areaT> areaList;
	QList<regionT> regionList;
	QList<QCheckBox *> checkBoxList;
};

#endif // DESKCHOICE_H
