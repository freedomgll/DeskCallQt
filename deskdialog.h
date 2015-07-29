#ifndef DESKDIALOG_H
#define DESKDIALOG_H

#include <QDialog>
#include "ui_deskdialog.h"

class DeskDialog : public QDialog
{
	Q_OBJECT

public:
	DeskDialog(QWidget *parent = 0);
	~DeskDialog();

private:
	Ui::DeskDialog ui;
};

#endif // DESKDIALOG_H
