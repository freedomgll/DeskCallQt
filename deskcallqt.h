#ifndef DESKCALLQT_H
#define DESKCALLQT_H

#include <QtWidgets/QDialog>
#include "ui_deskcallqt.h"
#include <QLabel>
#include <QSettings>
#include <QPushButton>

#include "ConfigSql.h"
#include "DeskPushButton.h"

//class MyPushButton : public QPushButton
//{
//
//public:
//	QString id;
//	int layer;
//
//    MyPushButton(const QString & text,  QString id, int layer,QWidget * parent = 0):QPushButton(text, parent)
//	{
//		this->id = id;
//		this->layer = layer;
//	}
//};

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

	QFont font(const QString & qfamily, const QString & qpointSize, const QString & qweight, const QString & qitalic)
	{
		QString family = settings->value(qfamily).toString();
		int pointSize = settings->value(qpointSize).toInt();
		int weight = settings->value(qweight).toBool() ? 75 : 50;
		bool italic = settings->value(qitalic).toBool();

		QFont font(family, pointSize, weight, italic);
		return font;
	}

	void  setFont(QFont font, const QString & qfamily, const QString & qpointSize, const QString & qweight, const QString & qitalic)
	{
		settings->setValue(qfamily, font.family());
		settings->setValue(qpointSize, font.pointSize());
		settings->setValue(qweight, font.weight());
		settings->setValue(qitalic, font.italic());	
	}

		
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
	QList<QPushButton *> buttonList;

	QSettings * settings;

	int offIndex;
	int offWidth;

	ConfigSql confSql;
	QList<classT> classList;
	QList<businessT> businessList;
};

#endif // DESKCALLQT_H
