#include "desksettings.h"

DeskSettings::DeskSettings(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

	ui.lineEdit->setValidator(new QIntValidator(0, 100, this));
}

DeskSettings::~DeskSettings()
{

}
