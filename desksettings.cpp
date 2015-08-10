#include "desksettings.h"

#include <QtDebug>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>

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

	connect(ui.pushButtonBGP, SIGNAL(clicked()), this, SLOT(clickButtonBGP()));
	connect(ui.pushButtonFont, SIGNAL(clicked()), this, SLOT(clickButtonFont()));
	connect(ui.pushButtonColor, SIGNAL(clicked()), this, SLOT(clickButtonColor()));

	connect(ui.pushBackPic, SIGNAL(clicked()), this, SLOT(clickBackPic()));
	connect(ui.pushBackFont, SIGNAL(clicked()), this, SLOT(clickBackFont()));
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

void DeskSettings::clickButtonBGP()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("打开文件"),
                                                "./Resources",
                                                QStringLiteral("图片文件 (*_up.jpg)"));
	if(!fileName.isEmpty())
	{
		fileName = QFileInfo(fileName).fileName();
		fileName.replace("_up.jpg", "");
		qDebug() << fileName;
		parent->configSettings.buttonPic=fileName;
		parent->settings->setValue("Settings/ButtonFace", parent->configSettings.buttonPic);

		parent->drawDialog();
	}
}

void DeskSettings::clickButtonFont()
{
	bool ok;

	QFont font = QFontDialog::getFont(&ok, parent->configSettings.buttonFont, this);

	if (ok) {
		// font is set to the font the user selected
		parent->configSettings.buttonFont = font;
		ConfigUtils::setFont(parent->settings,parent->configSettings.buttonFont,"Settings/FontName", "Settings/FontSize", "Settings/FontBold", "Settings/FontItalic","Settings/FontUnderline");
	} 
}

void DeskSettings::clickButtonColor()
{
	QColor color = QColorDialog::getColor(parent->configSettings.buttonColor, this);

	if(color.isValid())
	{
		parent->configSettings.buttonColor = color;
		parent->settings->setValue("Settings/FontColor", color.name());
	}
}


void DeskSettings::clickBackPic()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("打开文件"),
                                                "./Resources",
                                                QStringLiteral("图片文件 (*.jpg)"));
	if(!fileName.isEmpty())
	{
		fileName = QFileInfo(fileName).fileName();
		qDebug() << fileName;
		parent->configSettings.backPic=fileName;
		parent->settings->setValue("Settings/BackPic", parent->configSettings.backPic);

		parent->drawDialog();
	}
}

void DeskSettings::clickBackFont()
{
	bool ok;

	QFont font = QFontDialog::getFont(&ok, parent->configSettings.noticeFont, this);

	if (ok) {
		// font is set to the font the user selected
		parent->configSettings.noticeFont = font;
		ConfigUtils::setFont(parent->settings,parent->configSettings.noticeFont,"Settings/FontName2", "Settings/FontSize2", "Settings/FontBold2", "Settings/FontItalic2","Settings/FontUnderline2");
	} 
}

void DeskSettings::clickBackColor()
{
	QColor color = QColorDialog::getColor(parent->configSettings.buttonColor, this);

	if(color.isValid())
	{
		parent->configSettings.buttonColor = color;
		parent->settings->setValue("Settings/FontColor", color.name());
	}
}