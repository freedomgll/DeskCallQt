#include "deskchoice.h"
#include <QtDebug>


DeskChoice::DeskChoice(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
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

	QList<regionT> regionList = configSql.queryLRegion(areaList[index].id);

	for(int i=0; i < regionList.size(); i++)
	{
		QCheckBox *b = new QCheckBox(regionList[i].regionname, this);
		b->setGeometry(100,100+20*i,50,20);
		b->show();
		checkBoxList.append(b);
	}
}
