#ifndef DESKCALLQT_H
#define DESKCALLQT_H

#include <QtWidgets/QDialog>
#include "ui_deskcallqt.h"
#include <QLabel>
#include <QSettings>
#include <QPushButton>

#include "ConfigSql.h"
#include "ConfigUtils.h"

class DeskCallQT : public QDialog
{
	Q_OBJECT

public:
	DeskCallQT(QWidget *parent = 0);
	~DeskCallQT();

protected:
    void  resizeEvent(QResizeEvent* event);
	void  open();

public:
	void drawButtons();
	void drawPage();
	void RecreateButtonList(QList<QPushButton *> buttonList);
	
	QFont buttonFont;
	QFont noticeFont;

	QList<QPushButton *> buttonList;
	CoderPostion postion;
	QSettings * settings;

	ConfigSettings configSettings;

	void initDialog();
	void drawDialog();
		
public slots:
	void  config();
	void  print(int id);
	void  drawWelcome();
	void  deskClick(QWidget *);

private:
	Ui::DeskCallQTClass ui;	
	QLabel * label;

	QLabel * noticeLabel;
	QLabel * welcomeLabel;

	int offIndex;
	int offWidth;

	ConfigSql confSql;
	QList<classT> classList;
	QList<businessT> businessList;
};

#endif // DESKCALLQT_H
