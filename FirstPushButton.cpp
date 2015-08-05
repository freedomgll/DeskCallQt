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
}


FirstPushButton::~FirstPushButton(void)
{
}

void FirstPushButton::print()
{
	QMessageBox msgBox;
	msgBox.setText(QString::number(1000, 10));
	msgBox.exec();

	/*FirstPushButton * bu = new FirstPushButton("test111","c7ab1fe1-b583-40bc-a837-b2d3d060c4d1",100,this->parent);
	bu->setGeometry(100,200,50,20);
	bu->show();*/

	CoderPostion postion;
	postion.left = 35;
	postion.right =95;
	postion.top = 5;
	postion.bottom =70;
	postion.maxRows = 4;
	postion.space = 15;

	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(10,this->parent->width(),this->parent->height(),postion);
	qDebug() << lRects;

	ConfigSql confSql = ConfigSql();
	QList<businessT> businessList =	confSql.queryLBusiness(this->classid);

	businessT business;
	business.businessid ="";
	business.businessname = QStringLiteral("����/Return");
	business.businesscode = "";

	businessList.append(business);

	QList<QPushButton *> buttonList;

	for(int i = 0; i < businessList.size(); ++i)
	 {
		 SecondPushButton *pushButton= new SecondPushButton(businessList[i].businessname, businessList[i].businessid, this->parent);  
  
		pushButton->setGeometry(lRects[i]); //��ť��λ�ü���С  

		QString s = QStringLiteral("QPushButton{ background-image: url(Resources/��ˮ��_down.jpg); }");

		 /*QString str=QStringLiteral("QPushButton#btn_name{background-image: url(Resources/��ˮ��_up.jpg)}" 
                    "QPushButton#btn_name:hover{background-image: url(:/images/call_hov.bmp);}" 
                    "QPushButton#btn_name:pressed{background-image: url(Resources/��ˮ��_down.jpg);}");*/
		 QString str=QStringLiteral("QPushButton {background-image: url(Resources/��ˮ��_up.jpg); border: none; font-family:����; font-weight: bold; font-size: 18pt; color: red;} QPushButton:pressed {background-image: url(Resources/��ˮ��_down.jpg); border: none;} ");
		pushButton->setStyleSheet(str);

		pushButton->show();
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
