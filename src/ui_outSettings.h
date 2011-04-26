/********************************************************************************
** Form generated from reading UI file 'outSettings.ui'
**
** Created: Mon Apr 18 13:37:29 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTSETTINGS_H
#define UI_OUTSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutSettings
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_label;
    QCheckBox *checkBox_active;
    QHBoxLayout *nameLayout;
    QLabel *label_2;
    QCheckBox *checkBox_block;

    void setupUi(QWidget *OutSettings)
    {
        if (OutSettings->objectName().isEmpty())
            OutSettings->setObjectName(QString::fromUtf8("OutSettings"));
        OutSettings->resize(221, 90);
        gridLayout = new QGridLayout(OutSettings);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(OutSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_label = new QLineEdit(groupBox);
        lineEdit_label->setObjectName(QString::fromUtf8("lineEdit_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_label->sizePolicy().hasHeightForWidth());
        lineEdit_label->setSizePolicy(sizePolicy);
        lineEdit_label->setMaximumSize(QSize(70, 16777215));
        lineEdit_label->setMaxLength(5);

        horizontalLayout->addWidget(lineEdit_label);

        checkBox_active = new QCheckBox(groupBox);
        checkBox_active->setObjectName(QString::fromUtf8("checkBox_active"));

        horizontalLayout->addWidget(checkBox_active);


        verticalLayout->addLayout(horizontalLayout);

        nameLayout = new QHBoxLayout();
        nameLayout->setSpacing(3);
        nameLayout->setObjectName(QString::fromUtf8("nameLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        nameLayout->addWidget(label_2);

        checkBox_block = new QCheckBox(groupBox);
        checkBox_block->setObjectName(QString::fromUtf8("checkBox_block"));

        nameLayout->addWidget(checkBox_block);


        verticalLayout->addLayout(nameLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(OutSettings);

        QMetaObject::connectSlotsByName(OutSettings);
    } // setupUi

    void retranslateUi(QWidget *OutSettings)
    {
        OutSettings->setWindowTitle(QApplication::translate("OutSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OutSettings", "GroupBox", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OutSettings", "Nazwa", 0, QApplication::UnicodeUTF8));
        lineEdit_label->setText(QApplication::translate("OutSettings", "ABCDE", 0, QApplication::UnicodeUTF8));
        checkBox_active->setText(QApplication::translate("OutSettings", "Aktywne", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OutSettings", "QB", 0, QApplication::UnicodeUTF8));
        checkBox_block->setText(QApplication::translate("OutSettings", "Blokada", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OutSettings: public Ui_OutSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTSETTINGS_H
