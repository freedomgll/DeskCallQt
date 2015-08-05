#include "deskcallqt.h"
#include "ConfigUtils.h"
#include "ConfigSql.h"
#include "FirstPushButton.h"

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

static bool createConnection()
{
	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver, drivers)
		qDebug()<<driver;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );

	db.setHostName( "localhost" );
	db.setPort(3306);

	db.setDatabaseName( "trading" );

	db.setUserName( "root" );
	db.setPassword( "root" );
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

	settings = new QSettings("Resources/Coder.ini", QSettings::IniFormat);
	settings->setIniCodec(QTextCodec::codecForName("GBK"));

	bool b =settings->value("Settings/PrintMode").toBool();

	createConnection();

	this->confSql = ConfigSql();
	classList =	confSql.queryLClass();

	offIndex = this->width();

	Qt::WindowFlags flags=Qt::Dialog;

    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

	//showFullScreen();

	qDebug() << this->width();
	qDebug() << this->height();

//	Left=35
//Right=95
//Top=5
//Bottom=70
//MaxRows=4

	FirstPushButton * bu = new FirstPushButton("test","c7ab1fe1-b583-40bc-a837-b2d3d060c4d1",100,this);
	bu->setGeometry(100,100,50,20);

	CoderPostion postion;
	postion.left = 35;
	postion.right =95;
	postion.top = 5;
	postion.bottom =70;
	postion.maxRows = 4;
	postion.space = 15;

	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(10,this->width(),this->height(),postion);
	qDebug() << lRects;

	 QSignalMapper *signalMapper = new QSignalMapper(this);

	 for(int i = 0; i < classList.size(); ++i)
	 {
		 DeskPushButton *pushButton= new DeskPushButton(classList[i].classname, classList[i].classid, classList[i].layer, this);  
  
		pushButton->setGeometry(lRects[i]); //按钮的位置及大小  

		QString s = QStringLiteral("QPushButton{ background-image: url(Resources/紫水晶_down.jpg); }");

		 /*QString str=QStringLiteral("QPushButton#btn_name{background-image: url(Resources/紫水晶_up.jpg)}" 
                    "QPushButton#btn_name:hover{background-image: url(:/images/call_hov.bmp);}" 
                    "QPushButton#btn_name:pressed{background-image: url(Resources/紫水晶_down.jpg);}");*/
		 QString str=QStringLiteral("QPushButton {background-image: url(Resources/紫水晶_up.jpg); border: none; font-family:宋体; font-weight: bold; font-size: 18pt; color: red;} QPushButton:pressed {background-image: url(Resources/紫水晶_down.jpg); border: none;} ");
		pushButton->setStyleSheet(str);

		//connect(pushButton, SIGNAL(clicked()),this,SLOT(print(i)));

		connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(pushButton,pushButton);
		

		pushButton->show();

		buttonList.append(pushButton);
	 }

	//for (int i = 0; i < lRects.size(); ++i) {
 //   
	//	QString s = QStringLiteral("你好");
	//	QPushButton *pushButton= new QPushButton(s,this);  
 // 
	//	pushButton->setGeometry(lRects[i]); //按钮的位置及大小  

	//	 s = QStringLiteral("QPushButton{ background-image: url(Resources/紫水晶_down.jpg); }");

	//	 /*QString str=QStringLiteral("QPushButton#btn_name{background-image: url(Resources/紫水晶_up.jpg)}" 
 //                   "QPushButton#btn_name:hover{background-image: url(:/images/call_hov.bmp);}" 
 //                   "QPushButton#btn_name:pressed{background-image: url(Resources/紫水晶_down.jpg);}");*/
	//	 QString str=QStringLiteral("QPushButton {background-image: url(Resources/紫水晶_up.jpg); border: none; font-family:宋体; font-weight: bold; font-size: 18pt; color: red;} QPushButton:pressed {background-image: url(Resources/紫水晶_down.jpg); border: none;} ");
	//	pushButton->setStyleSheet(str);

	//	//connect(pushButton, SIGNAL(clicked()),this,SLOT(print(i)));

	//	
	//	signalMapper->setMapping(pushButton,i);
	//	connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));

	//	pushButton->show();
	//}

	connect(signalMapper, SIGNAL(mapped(QWidget *)), this, SLOT(deskClick(QWidget *)));

	this->setObjectName("mainWindow");
	this->setStyleSheet("#mainWindow { border-image: url(Resources/default2.jpg);}");

	QObjectList  l = this->children();

	foreach ( QObject *b, l)
	{
		//delete b;
	}

	//bool ok;
	//QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
	//if (ok) {
	//	// font is set to the font the user selected
	//} else {
	//	// the user canceled the dialog; font is set to the initial
	//	// value, in this case Times, 12.
	//}

	welcomeLabel = new QLabel(this);
	//label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	welcomeLabel->setText(QStringLiteral("欢迎使用排队系统"));
	//welcomeLabel->setAlignment(Qt::AlignJustify);
	//welcomeLabel->setStyleSheet("QLabel {font-family:宋体; font-weight: bold; font-size: 18pt; color: red;}");
	welcomeLabel->setStyleSheet("QLabel {color: #008000;}");
	//welcomeLabel->setGeometry(offIndex,100,300,welcomeLabel->height());
	QRect rect = welcomeLabel->geometry();
	rect.setX(offIndex);

	QFont font = this->font("Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic");

	welcomeLabel->setFont(font);
	offWidth = welcomeLabel->fontMetrics().width(welcomeLabel->text());
	int offHeight = welcomeLabel->fontMetrics().height();

	rect.setHeight(offHeight);

	welcomeLabel->setGeometry(rect);


	settings->value("Settings/PrintMode").toBool();


	
	QShortcut * shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(config()));

	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawWelcome()));
    timer->start(100);
}

DeskCallQT::~DeskCallQT()
{

}

void DeskCallQT::open()
{
	this->setStyleSheet("#mainWindow { border-image: url(Resources/default.jpg);}");
}

void DeskCallQT::config()
{
	bool ok;

	QFont font = this->font("Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic");
	font = QFontDialog::getFont(&ok, font, this);

	if (ok) {
		// font is set to the font the user selected
		this->setFont(font, "Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic");
	} 
}

void DeskCallQT::print(int id)
{
	QMessageBox msgBox;
	msgBox.setText(QString::number(id, 10));
	msgBox.exec();
}

void DeskCallQT::deskClick(QWidget * b)
{
	DeskPushButton *desk = qobject_cast<DeskPushButton*>(b);
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
