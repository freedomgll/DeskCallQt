#pragma once

#include <QList>
#include <QRect>
#include <QString>
#include <QSettings>
#include <QFont>
#include <QColor>

class CoderPostion
{
public:
	int left;
	int right;
	int top;
	int bottom;
	int maxRows;
	int space;
};

class ConfigSettings
{
public:
	QFont buttonFont;
	QFont noticeFont;
	CoderPostion postion;
	QString buttonPic;
	QColor buttonColor;
};

class ConfigUtils
{
public:
	ConfigUtils(void);
	~ConfigUtils(void);

	static	QFont font(QSettings * settings, const QString & qfamily, const QString & qpointSize, const QString & qweight, const QString & qitalic, const QString & qunderline = "")
	{
		QString family = settings->value(qfamily).toString();
		int pointSize = settings->value(qpointSize).toInt();
		int weight = settings->value(qweight).toBool() ? 75 : 50;
		bool italic = settings->value(qitalic).toBool();

		QFont font(family, pointSize, weight, italic);
		if (qunderline != "")
		{
			bool underline = settings->value(qunderline).toBool();
			font.setUnderline(underline);
		}

		return font;
	}

	static void  setFont(QSettings * settings, QFont font, const QString & qfamily, const QString & qpointSize, const QString & qweight, const QString & qitalic, const QString & qunderline = "")
	{
		settings->setValue(qfamily, font.family());
		settings->setValue(qpointSize, font.pointSize());
		settings->setValue(qweight, font.weight());
		settings->setValue(qitalic, font.italic());	
		settings->setValue(qunderline, font.underline());	
	}

	static QList<QRect> CaculateButtonRects(int size, int width, int height, CoderPostion postion);
	static void GetCoderPostion(QSettings * settings, CoderPostion& postion);
	static void SetCoderPostion(QSettings * settings, CoderPostion& postion);
	static QFont GetButtonFont(QSettings * settings);
	static QFont GetNoticeFont(QSettings * settings);

	static QColor GetButtonColor(QSettings * settings);

	static void LoadConfigSettings(QSettings * settings, ConfigSettings & configSettings);
};

