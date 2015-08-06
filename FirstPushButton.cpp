#include "FirstPushButton.h"
#include "SecondPushButton.h"
#include "ConfigUtils.h"
#include "ConfigSql.h"

#include <QMessageBox>
#include <QtDebug>

FirstPushButton::FirstPushButton(void)
{
}

FirstPushButton::FirstPushButton(const QString & text,  QString classid, int layer,DeskCallQT * parent):QPushButton(text, parent)
{
	this->parent = parent;
	this->classid = classid;
	connect(this, SIGNAL(clicked()),this,SLOT(print()));

	QString str=QStringLiteral("QPushButton {border-image: url(Resources/%1_up.jpg); color:  %2;} QPushButton:pressed {border-image: url(Resources/%1_down.jpg);} ").arg(QStringLiteral("×ÏË®¾§"),"#008000");
	this->setStyleSheet(str);
	this->setFont(this->parent->buttonFont);
}


FirstPushButton::~FirstPushButton(void)
{
}

void FirstPushButton::print()
{
	/*QMessageBox msgBox;
	msgBox.setText(QString::number(1000, 10));
	msgBox.exec();*/

	/*FirstPushButton * bu = new FirstPushButton("test111","c7ab1fe1-b583-40bc-a837-b2d3d060c4d1",100,this->parent);
	bu->setGeometry(100,200,50,20);
	bu->show();*/

	ConfigSql confSql = ConfigSql();
	QList<businessT> businessList =	confSql.queryLBusiness(this->classid);

	businessT business;
	business.businessid ="";
	business.businessname = QStringLiteral("·µ»Ø/Return");
	business.businesscode = "";

	businessList.append(business);

	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(businessList.size(),this->parent->width(),this->parent->height(),this->parent->postion);
	qDebug() << lRects;

	QList<QPushButton *> buttonList;

	for(int i = 0; i < businessList.size(); ++i)
	 {
		 QPushButton *pushButton= new SecondPushButton(businessList[i].businessname, businessList[i].businessid, lRects[i], this->parent);
		 buttonList.append(pushButton);
	 }


	foreach(QPushButton * b,this->parent->buttonList)
	{
		delete b;
	}

	this->parent->buttonList.clear();
	this->parent->buttonList.append(buttonList);

	//delete this;
}
