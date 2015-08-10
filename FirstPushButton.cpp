#include "FirstPushButton.h"
#include "SecondPushButton.h"
#include "ConfigUtils.h"
#include "ConfigSql.h"

#include <QMessageBox>
#include <QtDebug>

FirstPushButton::FirstPushButton(void)
{
}

FirstPushButton::FirstPushButton(const QString & text,  QString classid, const QRect & rect,DeskCallQT * parent):CoderPushButton(text, rect, parent)
{
	this->classid = classid;
	connect(this, SIGNAL(clicked()),this,SLOT(print()));
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

	QList<QRect> lRects =ConfigUtils::CaculateButtonRects(businessList.size(),this->parent->width(),this->parent->height(),this->parent->configSettings.postion);
	qDebug() << lRects;

	QList<CoderPushButton *> buttonList;

	for(int i = 0; i < businessList.size(); ++i)
	 {
		 CoderPushButton *pushButton= new SecondPushButton(businessList[i].businessname, businessList[i].businessid, lRects[i], this->parent);
		 buttonList.append(pushButton);
	 }

	this->parent->RecreateButtonList(buttonList);

	//delete this;
}
