/********************************************************************************
** Form generated from reading UI file 'sunScenario.ui'
**
** Created: Thu Apr 7 21:45:25 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUNSCENARIO_H
#define UI_SUNSCENARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SunScenario
{
public:
    QLabel *label;
    QTimeEdit *timeEdit;
    QTimeEdit *timeEdit_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QCheckBox *checkBox;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;

    void setupUi(QWidget *SunScenario)
    {
        if (SunScenario->objectName().isEmpty())
            SunScenario->setObjectName(QString::fromUtf8("SunScenario"));
        SunScenario->resize(610, 444);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SunScenario->sizePolicy().hasHeightForWidth());
        SunScenario->setSizePolicy(sizePolicy);
        SunScenario->setMaximumSize(QSize(762, 542));
        label = new QLabel(SunScenario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(54, 24, 524, 372));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/sunScenario.png")));
        label->setAlignment(Qt::AlignCenter);
        timeEdit = new QTimeEdit(SunScenario);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(158, 290, 71, 25));
        timeEdit_2 = new QTimeEdit(SunScenario);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(390, 294, 67, 25));
        spinBox = new QSpinBox(SunScenario);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(14, 120, 55, 25));
        spinBox_2 = new QSpinBox(SunScenario);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(14, 212, 55, 25));
        checkBox = new QCheckBox(SunScenario);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(282, 80, 84, 21));
        spinBox_3 = new QSpinBox(SunScenario);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(250, 350, 55, 25));
        spinBox_4 = new QSpinBox(SunScenario);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(312, 350, 55, 25));

        retranslateUi(SunScenario);

        QMetaObject::connectSlotsByName(SunScenario);
    } // setupUi

    void retranslateUi(QWidget *SunScenario)
    {
        SunScenario->setWindowTitle(QApplication::translate("SunScenario", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        checkBox->setText(QApplication::translate("SunScenario", "CheckBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SunScenario: public Ui_SunScenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUNSCENARIO_H
