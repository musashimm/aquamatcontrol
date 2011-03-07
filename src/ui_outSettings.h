/********************************************************************************
** Form generated from reading UI file 'outSettings.ui'
**
** Created: Mon Mar 7 19:21:44 2011
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutSettings
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *outSettingsLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_active;
    QCheckBox *checkBox_block;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_label;
    QHBoxLayout *buttonsLayout;
    QLabel *label_2;
    QPushButton *b_set;

    void setupUi(QWidget *OutSettings)
    {
        if (OutSettings->objectName().isEmpty())
            OutSettings->setObjectName(QString::fromUtf8("OutSettings"));
        OutSettings->resize(179, 105);
        groupBox = new QGroupBox(OutSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(2, 0, 173, 101));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(6, 14, 161, 86));
        outSettingsLayout = new QVBoxLayout(verticalLayoutWidget);
        outSettingsLayout->setObjectName(QString::fromUtf8("outSettingsLayout"));
        outSettingsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        outSettingsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_active = new QCheckBox(verticalLayoutWidget);
        checkBox_active->setObjectName(QString::fromUtf8("checkBox_active"));

        horizontalLayout->addWidget(checkBox_active);

        checkBox_block = new QCheckBox(verticalLayoutWidget);
        checkBox_block->setObjectName(QString::fromUtf8("checkBox_block"));

        horizontalLayout->addWidget(checkBox_block);


        outSettingsLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_label = new QLineEdit(verticalLayoutWidget);
        lineEdit_label->setObjectName(QString::fromUtf8("lineEdit_label"));
        lineEdit_label->setMaxLength(5);

        horizontalLayout_2->addWidget(lineEdit_label);


        outSettingsLayout->addLayout(horizontalLayout_2);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        buttonsLayout->addWidget(label_2);

        b_set = new QPushButton(verticalLayoutWidget);
        b_set->setObjectName(QString::fromUtf8("b_set"));
        b_set->setMaximumSize(QSize(100000, 21));

        buttonsLayout->addWidget(b_set);


        outSettingsLayout->addLayout(buttonsLayout);


        retranslateUi(OutSettings);

        QMetaObject::connectSlotsByName(OutSettings);
    } // setupUi

    void retranslateUi(QWidget *OutSettings)
    {
        OutSettings->setWindowTitle(QApplication::translate("OutSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OutSettings", "GroupBox", 0, QApplication::UnicodeUTF8));
        checkBox_active->setText(QApplication::translate("OutSettings", "Aktywne", 0, QApplication::UnicodeUTF8));
        checkBox_block->setText(QApplication::translate("OutSettings", "Blokada", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OutSettings", "Nazwa", 0, QApplication::UnicodeUTF8));
        lineEdit_label->setText(QApplication::translate("OutSettings", "ABCDE", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OutSettings", "QB", 0, QApplication::UnicodeUTF8));
        b_set->setText(QApplication::translate("OutSettings", "Ustaw", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OutSettings: public Ui_OutSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTSETTINGS_H
