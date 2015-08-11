#include "deskcallqt.h"
#include "desksettings.h"
#include "deskchoice.h"

#include "ConfigSql.h"
#include "FirstPushButton.h"
#include "SecondPushButton.h"

#include <QtWidgets/QLayout>
#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <QPushButton>
#include <QFontDialog>
#include <QShortcut>
#include <QMessageBox>
#include <QSignalMapper>
#include <QLabel>
#include <QTimer>
#include <QTextCodec>
#include <QFileDialog>

static bool createConnection(QString host, QString database, QString user, QString password)
{
	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver, drivers)
		qDebug()<<driver;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );

	db.setHostName(host);
	db.setPort(3306);

	db.setDatabaseName(database);

	db.setUserName(user);
	db.setPassword(password);
    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
	return true;

}

DeskCallQT::DeskCallQT(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags=Qt::Dialog;

    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

	//showFullScreen();

	offIndex = this->width();
	
	QShortcut * shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(config()));

	initDialog();
}

DeskCallQT::~DeskCallQT()
{

}

void DeskCallQT::initDialog()
{
	this->settings = new QSettings("Resources/Coder.ini", QSettings::IniFormat);
	this->settings->setIniCodec(QTextCodec::codecForName("GBK"));

	ConfigUtils::LoadConfigSettings(settings, configSettings);

	createConnection(configSettings.host, configSettings.database, configSettings.user, configSettings.password);

	this->setObjectName("mainWindow");

	this->confSql = ConfigSql();
	QList<classT> classList;
	foreach(QString regionid, configSettings.RegionIDs)
	{
		classList.append(confSql.queryLClass(regionid));
	}
	
	if(classList.size() < 1)
	{
		DeskChoice(this).exec();
	}

	welcomeLabel = new QLabel(this);

	for(int i = 0; i < classList.size(); ++i)
	{
		CoderPushButton *pushButton= new FirstPushButton(classList[i].classname, classList[i].classid,QRect() , this);
		this->buttonList.append(pushButton);
	}

	drawDialog();

	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawWelcome()));
    timer->start(100);
}

void DeskCallQT::drawDialog()
{
	ConfigUtils::LoadConfigSettings(settings, configSettings);

	this->setStyleSheet(QString("#mainWindow { border-image: url(Resources/%1);}").arg(configSettings.backPic));


	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(this->buttonList.size(),this->width(),this->height(),configSettings.postion);

	 for(int i = 0; i < this->buttonList.size(); ++i)
	 {
		 CoderPushButton* pushButton = this->buttonList[i];
		 pushButton->setGeometry(lRects[i]);

		 pushButton->setButtonStyle();
	 }

	 welcomeLabel->setText(configSettings.sub);
	 welcomeLabel->setStyleSheet(QString("QLabel {color: %1;}").arg(configSettings.backColor.name()));
	QRect rect = welcomeLabel->geometry();
	rect.setX(offIndex);

	welcomeLabel->setFont(this->configSettings.backFont);
	offWidth = welcomeLabel->fontMetrics().width(welcomeLabel->text());
	int offHeight = welcomeLabel->fontMetrics().height();

	rect.setHeight(offHeight);

	welcomeLabel->setGeometry(rect);
}

void DeskCallQT::config()
{
	//bool ok;

	//QFont font = this->font("Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic");
	//font = QFontDialog::getFont(&ok, font, this);

	//if (ok) {
	//	// font is set to the font the user selected
	//	this->setFont(font, "Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic");
	//} 

	DeskSettings w(this);
	w.exec();
}

void DeskCallQT::print(int id)
{
	QMessageBox msgBox;
	msgBox.setText(QString::number(id, 10));
	msgBox.exec();
}

void DeskCallQT::deskClick(QWidget * b)
{
	/*DeskPushButton *desk = qobject_cast<DeskPushButton*>(b);
	if(desk->layer == 1)
	{
		QString id = desk->id;
		foreach ( QObject *c, buttonList)
		{
			delete c;
		}

		buttonList.clear();

		businessList.clear();
		businessList = confSql.queryLBusiness(id);
	}
*/
	/*QMessageBox msgBox;
	msgBox.setText(desk->id);
	msgBox.exec();
*/

}


void DeskCallQT::resizeEvent(QResizeEvent *)
{
	//ui.tableView->setGeometry(this->rect());
	qDebug() << this->width();
	qDebug() << this->height();
}

void DeskCallQT::drawWelcome()
{
	offIndex = offIndex - 5;
	
	if(offIndex < -offWidth )
		offIndex = this->width();

	QRect rect = welcomeLabel->geometry();
	rect.setX(offIndex);
	welcomeLabel->setGeometry(rect);
	
}

void DeskCallQT::RecreateButtonList(QList<CoderPushButton *> buttonList)
{
	foreach(QPushButton * b,this->buttonList)
	{
		delete b;
	}

	this->buttonList.clear();
	this->buttonList.append(buttonList);
}
