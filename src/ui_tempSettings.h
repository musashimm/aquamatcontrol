/********************************************************************************
** Form generated from reading UI file 'tempSettings.ui'
**
** Created: Thu Apr 7 21:34:13 2011
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TempSettings
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
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
        TempSettings->resize(184, 391);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TempSettings->sizePolicy().hasHeightForWidth());
        TempSettings->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(TempSettings);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(TempSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setTitle(QString::fromUtf8("title"));
        groupBox->setFlat(false);
        layout = new QVBoxLayout(groupBox);
        layout->setSpacing(3);
        layout->setContentsMargins(3, 3, 3, 3);
        layout->setObjectName(QString::fromUtf8("layout"));
        check_tempActive = new QCheckBox(groupBox);
        check_tempActive->setObjectName(QString::fromUtf8("check_tempActive"));
        sizePolicy.setHeightForWidth(check_tempActive->sizePolicy().hasHeightForWidth());
        check_tempActive->setSizePolicy(sizePolicy);
        check_tempActive->setMinimumSize(QSize(0, 28));
        check_tempActive->setMaximumSize(QSize(16777215, 28));
        check_tempActive->setCheckable(true);
        check_tempActive->setChecked(false);

        layout->addWidget(check_tempActive);

        l_romSerial = new QLabel(groupBox);
        l_romSerial->setObjectName(QString::fromUtf8("l_romSerial"));
        sizePolicy.setHeightForWidth(l_romSerial->sizePolicy().hasHeightForWidth());
        l_romSerial->setSizePolicy(sizePolicy);
        l_romSerial->setMinimumSize(QSize(0, 28));
        l_romSerial->setMaximumSize(QSize(16777215, 28));
        l_romSerial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        l_romSerial->setMargin(0);

        layout->addWidget(l_romSerial);

        l_flags = new QLabel(groupBox);
        l_flags->setObjectName(QString::fromUtf8("l_flags"));
        sizePolicy.setHeightForWidth(l_flags->sizePolicy().hasHeightForWidth());
        l_flags->setSizePolicy(sizePolicy);
        l_flags->setMinimumSize(QSize(0, 28));
        l_flags->setMaximumSize(QSize(16777215, 28));

        layout->addWidget(l_flags);

        l_tempAlarms = new QLabel(groupBox);
        l_tempAlarms->setObjectName(QString::fromUtf8("l_tempAlarms"));
        sizePolicy.setHeightForWidth(l_tempAlarms->sizePolicy().hasHeightForWidth());
        l_tempAlarms->setSizePolicy(sizePolicy);
        l_tempAlarms->setMinimumSize(QSize(0, 28));
        l_tempAlarms->setMaximumSize(QSize(16777215, 28));

        layout->addWidget(l_tempAlarms);

        l_currentTemp = new QLabel(groupBox);
        l_currentTemp->setObjectName(QString::fromUtf8("l_currentTemp"));
        sizePolicy.setHeightForWidth(l_currentTemp->sizePolicy().hasHeightForWidth());
        l_currentTemp->setSizePolicy(sizePolicy);
        l_currentTemp->setMinimumSize(QSize(0, 28));
        l_currentTemp->setMaximumSize(QSize(16777215, 28));

        layout->addWidget(l_currentTemp);

        spin_targetTemp = new QDoubleSpinBox(groupBox);
        spin_targetTemp->setObjectName(QString::fromUtf8("spin_targetTemp"));
        sizePolicy.setHeightForWidth(spin_targetTemp->sizePolicy().hasHeightForWidth());
        spin_targetTemp->setSizePolicy(sizePolicy);
        spin_targetTemp->setMinimumSize(QSize(0, 28));
        spin_targetTemp->setMaximumSize(QSize(16777215, 28));
        spin_targetTemp->setDecimals(1);
        spin_targetTemp->setSingleStep(0.1);
        spin_targetTemp->setValue(20);

        layout->addWidget(spin_targetTemp);

        spin_targetNightTemp = new QDoubleSpinBox(groupBox);
        spin_targetNightTemp->setObjectName(QString::fromUtf8("spin_targetNightTemp"));
        sizePolicy.setHeightForWidth(spin_targetNightTemp->sizePolicy().hasHeightForWidth());
        spin_targetNightTemp->setSizePolicy(sizePolicy);
        spin_targetNightTemp->setMinimumSize(QSize(0, 28));
        spin_targetNightTemp->setMaximumSize(QSize(16777215, 28));
        spin_targetNightTemp->setDecimals(1);
        spin_targetNightTemp->setSingleStep(0.1);
        spin_targetNightTemp->setValue(20);

        layout->addWidget(spin_targetNightTemp);

        spin_minTemp = new QDoubleSpinBox(groupBox);
        spin_minTemp->setObjectName(QString::fromUtf8("spin_minTemp"));
        sizePolicy.setHeightForWidth(spin_minTemp->sizePolicy().hasHeightForWidth());
        spin_minTemp->setSizePolicy(sizePolicy);
        spin_minTemp->setMinimumSize(QSize(0, 28));
        spin_minTemp->setMaximumSize(QSize(16777215, 28));
        spin_minTemp->setDecimals(1);
        spin_minTemp->setMaximum(100);
        spin_minTemp->setSingleStep(0.1);
        spin_minTemp->setValue(10);

        layout->addWidget(spin_minTemp);

        spin_maxTemp = new QDoubleSpinBox(groupBox);
        spin_maxTemp->setObjectName(QString::fromUtf8("spin_maxTemp"));
        sizePolicy.setHeightForWidth(spin_maxTemp->sizePolicy().hasHeightForWidth());
        spin_maxTemp->setSizePolicy(sizePolicy);
        spin_maxTemp->setMinimumSize(QSize(0, 28));
        spin_maxTemp->setMaximumSize(QSize(16777215, 28));
        spin_maxTemp->setDecimals(1);
        spin_maxTemp->setSingleStep(0.1);
        spin_maxTemp->setValue(30);

        layout->addWidget(spin_maxTemp);

        spin_histeresis = new QDoubleSpinBox(groupBox);
        spin_histeresis->setObjectName(QString::fromUtf8("spin_histeresis"));
        sizePolicy.setHeightForWidth(spin_histeresis->sizePolicy().hasHeightForWidth());
        spin_histeresis->setSizePolicy(sizePolicy);
        spin_histeresis->setMinimumSize(QSize(0, 28));
        spin_histeresis->setMaximumSize(QSize(16777215, 28));
        spin_histeresis->setDecimals(1);
        spin_histeresis->setMinimum(0.1);
        spin_histeresis->setMaximum(1);
        spin_histeresis->setSingleStep(0.1);
        spin_histeresis->setValue(0.5);

        layout->addWidget(spin_histeresis);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(TempSettings);

        QMetaObject::connectSlotsByName(TempSettings);
    } // setupUi

    void retranslateUi(QWidget *TempSettings)
    {
        TempSettings->setWindowTitle(QApplication::translate("TempSettings", "Form", 0, QApplication::UnicodeUTF8));
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
