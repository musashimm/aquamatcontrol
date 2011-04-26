/********************************************************************************
** Form generated from reading UI file 'timersSecSettings.ui'
**
** Created: Tue Apr 26 23:00:53 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERSSECSETTINGS_H
#define UI_TIMERSSECSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimersSecSettings
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QCheckBox *c_active;
    QLabel *label;
    QTimeEdit *e_from;
    QLabel *label_2;
    QSpinBox *s_duration;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *TimersSecSettings)
    {
        if (TimersSecSettings->objectName().isEmpty())
            TimersSecSettings->setObjectName(QString::fromUtf8("TimersSecSettings"));
        TimersSecSettings->resize(234, 191);
        gridLayout_2 = new QGridLayout(TimersSecSettings);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(TimersSecSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        c_active = new QCheckBox(groupBox);
        c_active->setObjectName(QString::fromUtf8("c_active"));
        c_active->setTristate(false);

        gridLayout->addWidget(c_active, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        e_from = new QTimeEdit(groupBox);
        e_from->setObjectName(QString::fromUtf8("e_from"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(e_from->sizePolicy().hasHeightForWidth());
        e_from->setSizePolicy(sizePolicy2);
        e_from->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(e_from, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(84, 16777215));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        s_duration = new QSpinBox(groupBox);
        s_duration->setObjectName(QString::fromUtf8("s_duration"));
        sizePolicy2.setHeightForWidth(s_duration->sizePolicy().hasHeightForWidth());
        s_duration->setSizePolicy(sizePolicy2);
        s_duration->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(s_duration, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(TimersSecSettings);

        QMetaObject::connectSlotsByName(TimersSecSettings);
    } // setupUi

    void retranslateUi(QWidget *TimersSecSettings)
    {
        TimersSecSettings->setWindowTitle(QApplication::translate("TimersSecSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TimersSecSettings", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TimersSecSettings", "Aktywny", 0, QApplication::UnicodeUTF8));
        c_active->setText(QString());
        label->setText(QApplication::translate("TimersSecSettings", "Od", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TimersSecSettings", "Przez (sek.)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TimersSecSettings", "Dzie\305\204", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TimersSecSettings", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimersSecSettings: public Ui_TimersSecSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSSECSETTINGS_H
