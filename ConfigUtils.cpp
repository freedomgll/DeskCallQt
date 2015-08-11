#include "ConfigUtils.h"

#include <QtDebug>

ConfigUtils::ConfigUtils(void)
{
}


ConfigUtils::~ConfigUtils(void)
{
}

QList<QRect> ConfigUtils::CaculateButtonRects(int size, int cx, int cy, CoderPostion postion)
{
	QList<QRect> lRects;

	int maxRows = postion.maxRows;
	int space = postion.space;

	int col = (size + maxRows -1)/maxRows;
	int row = (size + col -1)/col;

	int width = cx*(postion.right - postion.left)/100;
	int height = cy*(postion.bottom - postion.top)/100;

	int xOffset = width/col;
	int yOffset = height/row;

	int xOffw = xOffset*(100-space)/200;
	int yOffh = yOffset*(100-space)/200;
	
	int xStart = (cx*postion.left/100) + xOffset/2;
	int yStart = (cy*postion.top)/100 + yOffset/2;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int px = xStart + xOffset*j;
			int py = yStart + yOffset*i;

			lRects.push_back(QRect(px - xOffw,py - yOffh,2*xOffw,2*yOffh));
		}
	}


	return lRects;
}

void ConfigUtils::GetCoderPostion(QSettings * settings, CoderPostion& postion)
{
	postion.left = settings->value("Settings/Left").toInt();
	postion.right = settings->value("Settings/Right").toInt();
	postion.top = settings->value("Settings/Top").toInt();
	postion.bottom = settings->value("Settings/Bottom").toInt();
	postion.maxRows = settings->value("Settings/MaxRows").toInt();
	postion.space = settings->value("Settings/ButtonSpace").toInt();
}

void ConfigUtils::SetCoderPostion(QSettings * settings, CoderPostion& postion)
{
	settings->setValue("Settings/Left", postion.left);
	settings->setValue("Settings/Right",postion.right);
	settings->setValue("Settings/Top",postion.top);
	settings->setValue("Settings/Bottom",postion.bottom);
	settings->setValue("Settings/MaxRows",postion.maxRows);
	settings->setValue("Settings/ButtonSpace",postion.space);
}

QFont ConfigUtils::GetButtonFont(QSettings * settings)
{
	return font(settings,"Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic", "Settings/FontUnderline");
}

QFont ConfigUtils::GetBackFont(QSettings * settings)
{
	return font(settings,"Settings/FontName2", "Settings/FontSize2", "Settings/FontBold2", "Settings/FontItalic2", "Settings/FontUnderline2");
}

QFont ConfigUtils::GetNoticeFont(QSettings * settings)
{
	return font(settings,"Settings/FontName2", "Settings/FontSize2", "Settings/FontBold2", "Settings/FontItalic2", "Settings/FontUnderline2");
}

void ConfigUtils::LoadConfigSettings(QSettings * settings, ConfigSettings & configSettings)
{
	configSettings.host = settings->value("Database/ServerAddress").toString();
	configSettings.database = settings->value("Database/DBase").toString();
	configSettings.user = settings->value("Database/DBuser").toString();
	configSettings.password = settings->value("Database/DBpass").toString();
	
	configSettings.RegionID = settings->value("Database/Region").toString();
	configSettings.RegionIDs = settings->value("Database/RegionIDs").toString().split("|");

	ConfigUtils::GetCoderPostion(settings, configSettings.postion);

	configSettings.buttonFont = ConfigUtils::GetButtonFont(settings);
	configSettings.backFont = ConfigUtils::GetBackFont(settings);

	configSettings.buttonPic = settings->value("Settings/ButtonFace").toString();
	configSettings.buttonColor = QColor(settings->value("Settings/FontColor").toString());

	configSettings.sub = settings->value("Settings/Sub").toString();
	configSettings.backPic = settings->value("Settings/BackPic").toString();
	configSettings.backColor = QColor(settings->value("Settings/FontColor2").toString());
}

void ConfigUtils::SaveConfigSettings(QSettings * settings, ConfigSettings & configSettings)
{
	settings->setValue("Database/Region", configSettings.RegionID);
	settings->setValue("Database/RegionIDs", configSettings.RegionIDs.join("|"));

	SetCoderPostion(settings, configSettings.postion);

	setFont(settings,configSettings.buttonFont,"Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic","Settings/FontUnderline");	
	setFont(settings,configSettings.backFont,"Settings/FontName2", "Settings/FontSize2", "Settings/FontBold2", "Settings/FontItalic2","Settings/FontUnderline2");

	settings->setValue("Settings/ButtonFace", configSettings.buttonPic);
	settings->setValue("Settings/FontColor", configSettings.buttonColor.name());

	settings->setValue("Settings/Sub", configSettings.sub);
	settings->setValue("Settings/BackPic", configSettings.backPic);
	settings->setValue("Settings/FontColor2", configSettings.backColor.name());

}