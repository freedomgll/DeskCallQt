#include "desksettings.h"

#include <QtDebug>

DeskSettings::DeskSettings(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

DeskSettings::DeskSettings(DeskCallQT *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->parent = parent;
	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

	
	SetIntValidate(ui.lineEditTop);
	SetIntValidate(ui.lineEditBottom);
	SetIntValidate(ui.lineEditLeft);
	SetIntValidate(ui.lineEditRight);
	SetIntValidate(ui.lineEditMaxRow);
	SetIntValidate(ui.lineEditSpace);

	loadConfig();
	
	connect(ui.pushButtonPostion, SIGNAL(clicked()), this, SLOT(saveConfig()));
}

DeskSettings::~DeskSettings()
{

}

void DeskSettings::SetIntValidate(QLineEdit *edit)
{
	edit->setValidator(new QIntValidator(0, 100, this));
}

void DeskSettings::loadConfig()
{
	qDebug() << "loadConfig";
	CoderPostion postion;
	ConfigUtils::GetCoderPostion(parent->settings, postion);

	ui.lineEditTop->setText( QString::number(postion.top, 10));
	ui.lineEditBottom->setText( QString::number(postion.bottom, 10));
	ui.lineEditLeft->setText( QString::number(postion.left, 10));
	ui.lineEditRight->setText( QString::number(postion.right, 10));
	ui.lineEditMaxRow->setText( QString::number(postion.maxRows, 10));
	ui.lineEditSpace->setText( QString::number(postion.space, 10));
}

void DeskSettings::saveConfig()
{
	qDebug() << "saveConfig";

	CoderPostion postion;
	postion.top = ui.lineEditTop->text().toInt();
	postion.bottom = ui.lineEditBottom->text().toInt();
	postion.left =  ui.lineEditLeft->text().toInt();
	postion.right = ui.lineEditRight->text().toInt();
	postion.maxRows = ui.lineEditMaxRow->text().toInt();
	postion.space =  ui.lineEditSpace->text().toInt();

	ConfigUtils::SetCoderPostion(parent->settings, postion);
}