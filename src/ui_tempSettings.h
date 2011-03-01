/********************************************************************************
** Form generated from reading UI file 'tempSettings.ui'
**
** Created: Tue Mar 1 18:55:25 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPSETTINGS_H
#define UI_TEMPSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TempSettings
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *layout;
    QCheckBox *check_tempActive;
    QLabel *l_romSerial;
    QLabel *l_flags;
    QLabel *l_tempAlarms;
    QLabel *l_currentTemp;
    QDoubleSpinBox *spin_targetTemp;
    QDoubleSpinBox *spin_targetNightTemp;
    QDoubleSpinBox *spin_minTemp;
    QDoubleSpinBox *spin_maxTemp;
    QDoubleSpinBox *spin_histeresis;

    void setupUi(QWidget *TempSettings)
    {
        if (TempSettings->objectName().isEmpty())
            TempSettings->setObjectName(QString::fromUtf8("TempSettings"));
        TempSettings->resize(150, 397);
        groupBox = new QGroupBox(TempSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(2, 4, 144, 389));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(4, 21, 135, 359));
        layout = new QVBoxLayout(layoutWidget);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        check_tempActive = new QCheckBox(layoutWidget);
        check_tempActive->setObjectName(QString::fromUtf8("check_tempActive"));
        check_tempActive->setCheckable(true);
        check_tempActive->setChecked(false);

        layout->addWidget(check_tempActive);

        l_romSerial = new QLabel(layoutWidget);
        l_romSerial->setObjectName(QString::fromUtf8("l_romSerial"));
        l_romSerial->setAlignment(Qt::AlignCenter);

        layout->addWidget(l_romSerial);

        l_flags = new QLabel(layoutWidget);
        l_flags->setObjectName(QString::fromUtf8("l_flags"));

        layout->addWidget(l_flags);

        l_tempAlarms = new QLabel(layoutWidget);
        l_tempAlarms->setObjectName(QString::fromUtf8("l_tempAlarms"));

        layout->addWidget(l_tempAlarms);

        l_currentTemp = new QLabel(layoutWidget);
        l_currentTemp->setObjectName(QString::fromUtf8("l_currentTemp"));

        layout->addWidget(l_currentTemp);

        spin_targetTemp = new QDoubleSpinBox(layoutWidget);
        spin_targetTemp->setObjectName(QString::fromUtf8("spin_targetTemp"));
        spin_targetTemp->setDecimals(1);
        spin_targetTemp->setSingleStep(0.1);
        spin_targetTemp->setValue(20);

        layout->addWidget(spin_targetTemp);

        spin_targetNightTemp = new QDoubleSpinBox(layoutWidget);
        spin_targetNightTemp->setObjectName(QString::fromUtf8("spin_targetNightTemp"));
        spin_targetNightTemp->setDecimals(1);
        spin_targetNightTemp->setSingleStep(0.1);
        spin_targetNightTemp->setValue(20);

        layout->addWidget(spin_targetNightTemp);

        spin_minTemp = new QDoubleSpinBox(layoutWidget);
        spin_minTemp->setObjectName(QString::fromUtf8("spin_minTemp"));
        spin_minTemp->setDecimals(1);
        spin_minTemp->setMaximum(100);
        spin_minTemp->setSingleStep(0.1);
        spin_minTemp->setValue(10);

        layout->addWidget(spin_minTemp);

        spin_maxTemp = new QDoubleSpinBox(layoutWidget);
        spin_maxTemp->setObjectName(QString::fromUtf8("spin_maxTemp"));
        spin_maxTemp->setDecimals(1);
        spin_maxTemp->setSingleStep(0.1);
        spin_maxTemp->setValue(30);

        layout->addWidget(spin_maxTemp);

        spin_histeresis = new QDoubleSpinBox(layoutWidget);
        spin_histeresis->setObjectName(QString::fromUtf8("spin_histeresis"));
        spin_histeresis->setDecimals(1);
        spin_histeresis->setMinimum(0.1);
        spin_histeresis->setMaximum(1);
        spin_histeresis->setSingleStep(0.1);
        spin_histeresis->setValue(0.5);

        layout->addWidget(spin_histeresis);


        retranslateUi(TempSettings);

        QMetaObject::connectSlotsByName(TempSettings);
    } // setupUi

    void retranslateUi(QWidget *TempSettings)
    {
        TempSettings->setWindowTitle(QApplication::translate("TempSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TempSettings", "GroupBox", 0, QApplication::UnicodeUTF8));
        check_tempActive->setText(QApplication::translate("TempSettings", "Aktywny", 0, QApplication::UnicodeUTF8));
        l_romSerial->setText(QApplication::translate("TempSettings", "0011223344556677", 0, QApplication::UnicodeUTF8));
        l_flags->setText(QApplication::translate("TempSettings", "00H / 0", 0, QApplication::UnicodeUTF8));
        l_tempAlarms->setText(QApplication::translate("TempSettings", "Brak", 0, QApplication::UnicodeUTF8));
        l_currentTemp->setText(QApplication::translate("TempSettings", "20.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TempSettings: public Ui_TempSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPSETTINGS_H
