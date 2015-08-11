#include "deskchoice.h"
#include <QtDebug>
#include <QFont>

DeskChoice::DeskChoice(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

DeskChoice::DeskChoice(DeskCallQT *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->parent = parent;
	setFixedSize(size());

	Qt::WindowFlags flags=Qt::Dialog;

    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

	ConfigSql configSql = ConfigSql();
	areaList = configSql.queryLArea();

	QStringList list;

	foreach(areaT area,areaList)
	{
		list.append(area.areaname);
	}

	ui.comboBoxArea->addItems(list);

	areaRegionT data = configSql.queryAreaRegion(this->parent->configSettings.RegionID);

	if(!data.areaname.isEmpty())
	{
		ui.comboBoxArea->setCurrentText(data.areaname);
		areaChanged(ui.comboBoxArea->currentIndex());
	}

	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(areaChanged(int)));
}

DeskChoice::~DeskChoice()
{

}

void DeskChoice::areaChanged(int index)
{
	qDebug() << index;

	foreach(QCheckBox * b,this->checkBoxList)
	{
		delete b;
	}
	checkBoxList.clear();

	ConfigSql configSql = ConfigSql();

	regionList = configSql.queryLRegion(areaList[index].id);

	QFont font(QStringLiteral("ÐÂËÎÌå"), 9);
	for(int i=0; i < regionList.size(); i++)
	{
		QCheckBox *b = new QCheckBox(regionList[i].regionname, this);
		
		b->setFont(font);
		b->setGeometry(140,50+20*i,150,20);
		b->show();

		if(this->parent->configSettings.RegionIDs.contains(regionList[i].regionid))
		{
			b->setChecked(true);
		}

		checkBoxList.append(b);
	}
}

QList<classT> DeskChoice::confirmChoice()
{
	this->parent->configSettings.RegionID = "";

	QStringList list;
	
	for(int i=0; i < checkBoxList.size(); i++)
	{
		QCheckBox *b = checkBoxList[i];
		if(b->checkState() == Qt::Checked)
		{
			list << regionList[i].regionid;
			this->parent->configSettings.RegionID = regionList[i].regionid;
		}
	}

	this->parent->configSettings.RegionIDs = list;

	ConfigSql configSql = ConfigSql();
	QList<classT> classList;

	foreach(QString regionid, list)
	{
		classList.append(configSql.queryLClass(regionid));
	}

	return classList;
}