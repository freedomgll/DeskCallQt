/********************************************************************************
** Form generated from reading UI file 'deskcallqt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKCALLQT_H
#define UI_DESKCALLQT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DeskCallQTClass
{
public:

    void setupUi(QDialog *DeskCallQTClass)
    {
        if (DeskCallQTClass->objectName().isEmpty())
            DeskCallQTClass->setObjectName(QStringLiteral("DeskCallQTClass"));
        DeskCallQTClass->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeskCallQTClass->sizePolicy().hasHeightForWidth());
        DeskCallQTClass->setSizePolicy(sizePolicy);
        DeskCallQTClass->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        retranslateUi(DeskCallQTClass);

        QMetaObject::connectSlotsByName(DeskCallQTClass);
    } // setupUi

    void retranslateUi(QDialog *DeskCallQTClass)
    {
        DeskCallQTClass->setWindowTitle(QApplication::translate("DeskCallQTClass", "DeskCallQT", 0));
    } // retranslateUi

};

namespace Ui {
    class DeskCallQTClass: public Ui_DeskCallQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKCALLQT_H
