#include "desksettings.h"

#include <QtDebug>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>

#include "deskchoice.h"
#include "FirstPushButton.h"

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
	
	connect(ui.pushButtonPostion, SIGNAL(clicked()), this, SLOT(clickPostion()));

	connect(ui.pushButtonBGP, SIGNAL(clicked()), this, SLOT(clickButtonBGP()));
	connect(ui.pushButtonFont, SIGNAL(clicked()), this, SLOT(clickButtonFont()));
	connect(ui.pushButtonColor, SIGNAL(clicked()), this, SLOT(clickButtonColor()));

	connect(ui.pushButtonSub, SIGNAL(clicked()), this, SLOT(clickButtonSub()));
	connect(ui.pushButtonRegion, SIGNAL(clicked()), this, SLOT(clickButtonRegion()));

	connect(ui.pushBackPic, SIGNAL(clicked()), this, SLOT(clickBackPic()));
	connect(ui.pushBackFont, SIGNAL(clicked()), this, SLOT(clickBackFont()));
	connect(ui.pushBackColor, SIGNAL(clicked()), this, SLOT(clickBackColor()));
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
	ConfigUtils::LoadConfigSettings(parent->settings, parent->configSettings);
	CoderPostion postion = parent->configSettings.postion;

	ui.lineEditTop->setText( QString::number(postion.top, 10));
	ui.lineEditBottom->setText( QString::number(postion.bottom, 10));
	ui.lineEditLeft->setText( QString::number(postion.left, 10));
	ui.lineEditRight->setText( QString::number(postion.right, 10));
	ui.lineEditMaxRow->setText( QString::number(postion.maxRows, 10));
	ui.lineEditSpace->setText( QString::number(postion.space, 10));

	ui.lineEditSub->setText(parent->configSettings.sub);
}

void DeskSettings::clickPostion()
{
	CoderPostion postion;
	postion.top = ui.lineEditTop->text().toInt();
	postion.bottom = ui.lineEditBottom->text().toInt();
	postion.left =  ui.lineEditLeft->text().toInt();
	postion.right = ui.lineEditRight->text().toInt();
	postion.maxRows = ui.lineEditMaxRow->text().toInt();
	postion.space =  ui.lineEditSpace->text().toInt();

	parent->configSettings.postion = postion;

	resetDeskDialog();
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
		
		resetDeskDialog();
	}
}

void DeskSettings::clickButtonFont()
{
	QFontDialog font(parent->configSettings.buttonFont, this);
	font.setWindowFlags(font.windowFlags() | Qt::WindowCloseButtonHint);

	if (font.exec()== QDialog::Accepted) {
		parent->configSettings.buttonFont = font.currentFont();
		resetDeskDialog();
	} 
}

void DeskSettings::clickButtonColor()
{
	QColor color = QColorDialog::getColor(parent->configSettings.buttonColor, this);

	if(color.isValid())
	{
		parent->configSettings.buttonColor = color;

		resetDeskDialog();
	}
}

void DeskSettings::clickButtonSub()
{
	parent->configSettings.sub = ui.lineEditSub->text();
	resetDeskDialog();
}

void DeskSettings::clickButtonRegion()
{
	DeskChoice choice(this->parent);
	if(choice.exec() == QDialog::Accepted)
	{
		QList<classT> classList = choice.confirmChoice();

		QList<CoderPushButton *> buttonList;

		for(int i = 0; i < classList.size(); ++i)
		 {
			 CoderPushButton *pushButton= new FirstPushButton(classList[i].classname, classList[i].classid, QRect(), this->parent);
			 buttonList.append(pushButton);
		 }

		this->parent->RecreateButtonList(buttonList);

		resetDeskDialog();
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
		
		resetDeskDialog();
	}
}

void DeskSettings::clickBackFont()
{
	QFontDialog font(parent->configSettings.backFont, this);
	font.setWindowFlags(font.windowFlags() | Qt::WindowCloseButtonHint);

	if (font.exec()== QDialog::Accepted) {
		parent->configSettings.backFont = font.currentFont();
		resetDeskDialog();
	} 
}

void DeskSettings::clickBackColor()
{
	QColor color = QColorDialog::getColor(parent->configSettings.buttonColor, this);

	if(color.isValid())
	{
		parent->configSettings.backColor = color;
		
		resetDeskDialog();
	}
}

void DeskSettings::resetDeskDialog()
{
	ConfigUtils::SaveConfigSettings(parent->settings, parent->configSettings);
	parent->drawDialog();
}