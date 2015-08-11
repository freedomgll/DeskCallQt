/********************************************************************************
** Form generated from reading UI file 'deskchoice.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKCHOICE_H
#define UI_DESKCHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeskChoice
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxArea;

    void setupUi(QDialog *DeskChoice)
    {
        if (DeskChoice->objectName().isEmpty())
            DeskChoice->setObjectName(QStringLiteral("DeskChoice"));
        DeskChoice->resize(343, 243);
        QFont font;
        font.setPointSize(8);
        DeskChoice->setFont(font);
        label = new QLabel(DeskChoice);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 60, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(9);
        label->setFont(font1);
        label_2 = new QLabel(DeskChoice);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 80, 48, 16));
        label_2->setFont(font1);
        comboBoxArea = new QComboBox(DeskChoice);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(160, 30, 111, 20));
        comboBoxArea->setFont(font1);

        retranslateUi(DeskChoice);

        QMetaObject::connectSlotsByName(DeskChoice);
    } // setupUi

    void retranslateUi(QDialog *DeskChoice)
    {
        DeskChoice->setWindowTitle(QApplication::translate("DeskChoice", "\351\200\211\346\213\251\350\220\245\344\270\232\345\216\205\345\214\272\345\237\237", 0));
        label->setText(QApplication::translate("DeskChoice", "\351\200\211\346\213\251\350\220\245\344\270\232\345\216\205", 0));
        label_2->setText(QApplication::translate("DeskChoice", "\351\200\211\346\213\251\345\214\272\345\237\237", 0));
    } // retranslateUi

};

namespace Ui {
    class DeskChoice: public Ui_DeskChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKCHOICE_H
