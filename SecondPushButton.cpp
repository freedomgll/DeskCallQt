#include "SecondPushButton.h"
#include "FirstPushButton.h"

#include <QMessageBox>
#include <QtDebug>

SecondPushButton::SecondPushButton(void)
{
}

SecondPushButton::SecondPushButton(const QString & text,  QString businessId, const QRect & rect, DeskCallQT  * parent):CoderPushButton(text, rect, parent)
{
	this->businessId = businessId;
	connect(this, SIGNAL(clicked()),this,SLOT(clickAction()));
}

SecondPushButton::~SecondPushButton(void)
{
}

void SecondPushButton::clickAction()
{
	if(this->text() == QStringLiteral("·µ»Ø/Return"))
	{
		ConfigSql confSql = ConfigSql();
		QList<classT> classList;
		foreach(QString regionid, this->parent->configSettings.RegionIDs)
		{
			classList.append(confSql.queryLClass(regionid));
		}

		QList<QRect> lRects =ConfigUtils::CaculateButtonRects(classList.size(),this->parent->width(),this->parent->height(),this->parent->configSettings.postion);
		qDebug() << lRects;

		QList<CoderPushButton *> buttonList;

		for(int i = 0; i < classList.size(); ++i)
		 {
			 CoderPushButton *pushButton= new FirstPushButton(classList[i].classname, classList[i].classid, lRects[i], this->parent);
			 buttonList.append(pushButton);
		 }

		this->parent->RecreateButtonList(buttonList);
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(this->businessId);
		msgBox.exec();
	}
}
