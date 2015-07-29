/********************************************************************************
** Form generated from reading UI file 'desklogin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKLOGIN_H
#define UI_DESKLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeskLogin
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *DeskLogin)
    {
        if (DeskLogin->objectName().isEmpty())
            DeskLogin->setObjectName(QStringLiteral("DeskLogin"));
        DeskLogin->resize(400, 300);
        pushButton = new QPushButton(DeskLogin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 70, 75, 23));
        lineEdit = new QLineEdit(DeskLogin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 70, 113, 20));

        retranslateUi(DeskLogin);

        QMetaObject::connectSlotsByName(DeskLogin);
    } // setupUi

    void retranslateUi(QWidget *DeskLogin)
    {
        DeskLogin->setWindowTitle(QApplication::translate("DeskLogin", "DeskLogin", 0));
        pushButton->setText(QApplication::translate("DeskLogin", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class DeskLogin: public Ui_DeskLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKLOGIN_H
