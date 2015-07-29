/********************************************************************************
** Form generated from reading UI file 'deskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKDIALOG_H
#define UI_DESKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *DeskDialog)
    {
        if (DeskDialog->objectName().isEmpty())
            DeskDialog->setObjectName(QStringLiteral("DeskDialog"));
        DeskDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DeskDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(190, 240, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DeskDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 130, 141, 61));

        retranslateUi(DeskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeskDialog);
    } // setupUi

    void retranslateUi(QDialog *DeskDialog)
    {
        DeskDialog->setWindowTitle(QApplication::translate("DeskDialog", "DeskDialog", 0));
        label->setText(QApplication::translate("DeskDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class DeskDialog: public Ui_DeskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKDIALOG_H
