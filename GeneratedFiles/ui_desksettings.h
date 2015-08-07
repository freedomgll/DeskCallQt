/********************************************************************************
** Form generated from reading UI file 'desksettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKSETTINGS_H
#define UI_DESKSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeskSettings
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditTop;
    QLabel *label_2;
    QLineEdit *lineEditBottom;
    QLabel *label_5;
    QLineEdit *lineEditMaxRow;
    QPushButton *pushButtonPostion;
    QLabel *label_4;
    QLineEdit *lineEditLeft;
    QLabel *label_3;
    QLineEdit *lineEditRight;
    QLabel *label_6;
    QLineEdit *lineEditSpace;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_7;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_8;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QPushButton *pushButton_9;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_11;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox;
    QLabel *label_14;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_12;
    QLabel *label_15;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_13;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_14;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_15;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;

    void setupUi(QDialog *DeskSettings)
    {
        if (DeskSettings->objectName().isEmpty())
            DeskSettings->setObjectName(QStringLiteral("DeskSettings"));
        DeskSettings->resize(500, 515);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        DeskSettings->setFont(font);
        layoutWidget = new QWidget(DeskSettings);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 481, 503));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditTop = new QLineEdit(groupBox);
        lineEditTop->setObjectName(QStringLiteral("lineEditTop"));
        lineEditTop->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(lineEditTop, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEditBottom = new QLineEdit(groupBox);
        lineEditBottom->setObjectName(QStringLiteral("lineEditBottom"));

        gridLayout->addWidget(lineEditBottom, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        lineEditMaxRow = new QLineEdit(groupBox);
        lineEditMaxRow->setObjectName(QStringLiteral("lineEditMaxRow"));

        gridLayout->addWidget(lineEditMaxRow, 0, 5, 1, 1);

        pushButtonPostion = new QPushButton(groupBox);
        pushButtonPostion->setObjectName(QStringLiteral("pushButtonPostion"));

        gridLayout->addWidget(pushButtonPostion, 0, 6, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEditLeft = new QLineEdit(groupBox);
        lineEditLeft->setObjectName(QStringLiteral("lineEditLeft"));

        gridLayout->addWidget(lineEditLeft, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        lineEditRight = new QLineEdit(groupBox);
        lineEditRight->setObjectName(QStringLiteral("lineEditRight"));

        gridLayout->addWidget(lineEditRight, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 4, 1, 1);

        lineEditSpace = new QLineEdit(groupBox);
        lineEditSpace->setObjectName(QStringLiteral("lineEditSpace"));

        gridLayout->addWidget(lineEditSpace, 1, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, 9, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_2->addWidget(lineEdit_7, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox_3);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_3->addWidget(lineEdit_8, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 0, 2, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout_3->addWidget(lineEdit_11, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 0, 4, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_3->addWidget(lineEdit_9, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 1, 2, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox_3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout_3->addWidget(lineEdit_12, 1, 3, 1, 1);

        pushButton_8 = new QPushButton(groupBox_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 1, 4, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_3->addWidget(lineEdit_10, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 2, 2, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox_3);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout_3->addWidget(lineEdit_13, 2, 3, 1, 1);

        pushButton_9 = new QPushButton(groupBox_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_3->addWidget(pushButton_9, 2, 4, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 0, -1, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_14 = new QLineEdit(groupBox_4);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        verticalLayout_5->addWidget(lineEdit_14);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_3->addWidget(pushButton_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_3->addWidget(pushButton_11);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_4->addWidget(checkBox, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_4->addWidget(label_14, 0, 1, 1, 1);

        lineEdit_15 = new QLineEdit(groupBox_5);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout_4->addWidget(lineEdit_15, 0, 2, 1, 1);

        pushButton_12 = new QPushButton(groupBox_5);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout_4->addWidget(pushButton_12, 1, 0, 1, 1);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 1, 1, 1, 1);

        lineEdit_16 = new QLineEdit(groupBox_5);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        gridLayout_4->addWidget(lineEdit_16, 1, 2, 1, 1);

        pushButton_13 = new QPushButton(groupBox_5);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_4->addWidget(pushButton_13, 1, 3, 1, 1);


        verticalLayout_7->addLayout(gridLayout_4);


        verticalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_14 = new QPushButton(groupBox_6);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        horizontalLayout_4->addWidget(pushButton_14);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, -1, 9, -1);
        pushButton_15 = new QPushButton(layoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        horizontalLayout_5->addWidget(pushButton_15);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        pushButton_16 = new QPushButton(layoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        horizontalLayout_5->addWidget(pushButton_16);

        pushButton_17 = new QPushButton(layoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        horizontalLayout_5->addWidget(pushButton_17);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(DeskSettings);

        QMetaObject::connectSlotsByName(DeskSettings);
    } // setupUi

    void retranslateUi(QDialog *DeskSettings)
    {
        DeskSettings->setWindowTitle(QApplication::translate("DeskSettings", "\351\200\211\351\241\271", 0));
        groupBox->setTitle(QApplication::translate("DeskSettings", "\346\214\211\351\222\256\350\260\203\346\225\264", 0));
        label->setText(QApplication::translate("DeskSettings", "\344\270\212", 0));
        lineEditTop->setInputMask(QString());
        label_2->setText(QApplication::translate("DeskSettings", "\344\270\213", 0));
        label_5->setText(QApplication::translate("DeskSettings", "\346\234\200\345\244\247\350\241\214\346\225\260", 0));
        pushButtonPostion->setText(QApplication::translate("DeskSettings", "\350\260\203\346\225\264", 0));
        label_4->setText(QApplication::translate("DeskSettings", "\345\267\246", 0));
        label_3->setText(QApplication::translate("DeskSettings", "\345\217\263", 0));
        label_6->setText(QApplication::translate("DeskSettings", "\351\227\264\350\267\235", 0));
        pushButton_2->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\346\214\211\351\222\256\350\203\214\346\231\257>>", 0));
        pushButton_3->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\346\214\211\351\222\256\345\255\227\344\275\223>>", 0));
        pushButton_4->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\346\214\211\351\222\256\351\242\234\350\211\262>>", 0));
        groupBox_2->setTitle(QApplication::translate("DeskSettings", "\347\245\250\345\217\267\350\256\276\347\275\256", 0));
        label_7->setText(QApplication::translate("DeskSettings", "\346\240\207\351\242\230", 0));
        pushButton_5->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        pushButton_6->setText(QApplication::translate("DeskSettings", "\345\276\275\346\240\207\350\256\276\347\275\256>>", 0));
        groupBox_3->setTitle(QApplication::translate("DeskSettings", "\344\274\221\346\201\257\346\227\266\351\227\264", 0));
        label_8->setText(QApplication::translate("DeskSettings", "\346\227\266\351\227\264\346\256\2651", 0));
        label_11->setText(QApplication::translate("DeskSettings", "\345\210\260", 0));
        pushButton_7->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        label_9->setText(QApplication::translate("DeskSettings", "\346\227\266\351\227\264\346\256\2652", 0));
        label_12->setText(QApplication::translate("DeskSettings", "\345\210\260", 0));
        pushButton_8->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        label_10->setText(QApplication::translate("DeskSettings", "\346\227\266\351\227\264\346\256\2653", 0));
        label_13->setText(QApplication::translate("DeskSettings", "\345\210\260", 0));
        pushButton_9->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        groupBox_4->setTitle(QApplication::translate("DeskSettings", "\346\273\232\345\212\250\345\255\227\345\271\225", 0));
        pushButton_10->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\345\255\227\345\271\225\345\255\227\344\275\223>>", 0));
        pushButton_11->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        groupBox_5->setTitle(QApplication::translate("DeskSettings", "\345\217\213\346\203\205\346\217\220\347\244\272", 0));
        checkBox->setText(QApplication::translate("DeskSettings", "\346\230\257\345\220\246\346\217\220\347\244\272", 0));
        label_14->setText(QApplication::translate("DeskSettings", "\351\253\230\345\263\260\346\227\245", 0));
        pushButton_12->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\346\217\220\347\244\272\345\255\227\344\275\223>>", 0));
        label_15->setText(QApplication::translate("DeskSettings", "\351\253\230\345\263\260\346\227\266\346\256\265", 0));
        pushButton_13->setText(QApplication::translate("DeskSettings", "\346\233\264\346\224\271", 0));
        groupBox_6->setTitle(QApplication::translate("DeskSettings", "\351\200\211\346\213\251\350\220\245\344\270\232\345\216\205\345\214\272\345\237\237", 0));
        pushButton_14->setText(QApplication::translate("DeskSettings", "\345\214\272\345\237\237\350\256\276\347\275\256>>", 0));
        pushButton_15->setText(QApplication::translate("DeskSettings", "\350\256\276\347\275\256\350\203\214\346\231\257\345\233\276\347\211\207>>", 0));
        pushButton_16->setText(QApplication::translate("DeskSettings", "\347\241\256\345\256\232", 0));
        pushButton_17->setText(QApplication::translate("DeskSettings", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class DeskSettings: public Ui_DeskSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKSETTINGS_H
