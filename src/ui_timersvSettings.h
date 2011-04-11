/********************************************************************************
** Form generated from reading UI file 'timersvSettings.ui'
**
** Created: Tue Apr 12 00:18:31 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERSVSETTINGS_H
#define UI_TIMERSVSETTINGS_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimersvSettings
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QCheckBox *c_active;
    QLabel *label;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpinBox *e_off;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *e_on;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *TimersvSettings)
    {
        if (TimersvSettings->objectName().isEmpty())
            TimersvSettings->setObjectName(QString::fromUtf8("TimersvSettings"));
        TimersvSettings->resize(199, 167);
        gridLayout_2 = new QGridLayout(TimersvSettings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(TimersvSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 3, 3, 3);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        c_active = new QCheckBox(groupBox);
        c_active->setObjectName(QString::fromUtf8("c_active"));

        gridLayout->addWidget(c_active, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        e_off = new QSpinBox(groupBox);
        e_off->setObjectName(QString::fromUtf8("e_off"));
        e_off->setMinimum(1);

        horizontalLayout->addWidget(e_off);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        e_on = new QSpinBox(groupBox);
        e_on->setObjectName(QString::fromUtf8("e_on"));
        e_on->setMinimum(1);
        e_on->setValue(3);

        horizontalLayout_2->addWidget(e_on);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(TimersvSettings);

        QMetaObject::connectSlotsByName(TimersvSettings);
    } // setupUi

    void retranslateUi(QWidget *TimersvSettings)
    {
        TimersvSettings->setWindowTitle(QApplication::translate("TimersvSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TimersvSettings", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TimersvSettings", "Aktywny", 0, QApplication::UnicodeUTF8));
        c_active->setText(QString());
        label->setText(QApplication::translate("TimersvSettings", "Wy\305\202.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TimersvSettings", "W\305\202.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TimersvSettings", "min.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TimersvSettings", "min.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TimersvSettings", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimersvSettings: public Ui_TimersvSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSVSETTINGS_H
