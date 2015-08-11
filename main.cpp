#include "deskcallqt.h"
#include "desklogin.h"
#include "deskdialog.h"
#include <QtWidgets/QApplication>
#include <QSettings>
#include <QtDebug>
#include <QTextCodec>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTranslator translator;
	translator.load("qtbase_zh_CN.qm","Resources/");
	a.installTranslator(&translator);

	DeskCallQT w;
	DeskLogin l;

	w.show();

	QSettings settings("Resources/Coder.ini", QSettings::IniFormat);
	settings.setIniCodec(QTextCodec::codecForName("GBK"));
	settings.allKeys();
	QStringList childKeys = settings.allKeys();
	foreach (const QString &childKey, childKeys)
	{
		QString var = settings.value(childKey).toString();
		//qDebug() << var;
	}

	int i = settings.value("Settings/Left").toInt();


	/*DeskDialog d;
	if(d.exec()== QDialog::Accepted)
	{	
		w.show();
		
	}
	else
	{	
		l.show();
	}*/

	

	return a.exec();
}
