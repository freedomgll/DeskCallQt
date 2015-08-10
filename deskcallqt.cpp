#include "deskcallqt.h"
#include "desksettings.h"
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

	Qt::WindowFlags flags=Qt::Dialog;

    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

	//showFullScreen();


	offIndex = this->width();

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

	//connect(signalMapper, SIGNAL(mapped(QWidget *)), this, SLOT(deskClick(QWidget *)));


	//bool ok;
	//QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
	//if (ok) {
	//	// font is set to the font the user selected
	//} else {
	//	// the user canceled the dialog; font is set to the initial
	//	// value, in this case Times, 12.
	//}

	
	QShortcut * shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(config()));

	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawWelcome()));
    timer->start(100);

	/*DeskSettings w(this);
	w.exec();*/

	/*QStringList filters;
	filters << QStringLiteral("图片文件 (*_up.jpg)");

	QFileDialog dialog(this);
	dialog.setDirectory(".\\Resources");
	dialog.setNameFilters(filters);
	dialog.exec();*/
	initDialog();
}

DeskCallQT::~DeskCallQT()
{

}

void DeskCallQT::initDialog()
{
	this->settings = new QSettings("Resources/Coder.ini", QSettings::IniFormat);
	this->settings->setIniCodec(QTextCodec::codecForName("GBK"));

	createConnection();

	this->setObjectName("mainWindow");
	this->setStyleSheet("#mainWindow { border-image: url(Resources/default2.jpg);}");

	
	this->confSql = ConfigSql();
	classList =	confSql.queryLClass();

	ConfigUtils::GetCoderPostion(settings, postion);
	ConfigUtils::GetCoderPostion(settings, this->configSettings.postion);
	this->configSettings.buttonFont = ConfigUtils::GetButtonFont(settings);
	this->configSettings.noticeFont = ConfigUtils::GetNoticeFont(settings);

	this->configSettings.buttonPic = this->settings->value("Settings/ButtonFace").toString();
	this->configSettings.buttonColor = ConfigUtils::GetButtonColor(settings);

	welcomeLabel = new QLabel(this);
	//label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	welcomeLabel->setText(QStringLiteral("欢迎使用排队系统"));
	//welcomeLabel->setAlignment(Qt::AlignJustify);
	//welcomeLabel->setStyleSheet("QLabel {font-family:宋体; font-weight: bold; font-size: 18pt; color: red;}");
	welcomeLabel->setStyleSheet("QLabel {color: #008000;}");
	//welcomeLabel->setGeometry(offIndex,100,300,welcomeLabel->height());
	QRect rect = welcomeLabel->geometry();
	rect.setX(offIndex);

	welcomeLabel->setFont(this->configSettings.noticeFont);
	offWidth = welcomeLabel->fontMetrics().width(welcomeLabel->text());
	int offHeight = welcomeLabel->fontMetrics().height();

	rect.setHeight(offHeight);

	welcomeLabel->setGeometry(rect);


	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(classList.size(),this->width(),this->height(),postion);
	qDebug() << lRects;

	 QSignalMapper *signalMapper = new QSignalMapper(this);

	 for(int i = 0; i < classList.size(); ++i)
	 {
		 CoderPushButton *pushButton= new FirstPushButton(classList[i].classname, classList[i].classid, lRects[i], this);


		/*connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(pushButton,pushButton);
		

		pushButton->show();*/

		this->buttonList.append(pushButton);
	 }


}

void DeskCallQT::drawDialog()
{
	ConfigUtils::LoadConfigSettings(settings, configSettings);


	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(classList.size(),this->width(),this->height(),configSettings.postion);

	 for(int i = 0; i < this->buttonList.size(); ++i)
	 {
		 QPushButton* pushButton = this->buttonList[i];
		 pushButton->setGeometry(lRects[i]);

		 //pushButton->setButtonStyle();
	 }
}

void DeskCallQT::open()
{
	this->setStyleSheet("#mainWindow { border-image: url(Resources/default.jpg);}");
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

void DeskCallQT::RecreateButtonList(QList<QPushButton *> buttonList)
{
	foreach(QPushButton * b,this->buttonList)
	{
		delete b;
	}

	this->buttonList.clear();
	this->buttonList.append(buttonList);
}
