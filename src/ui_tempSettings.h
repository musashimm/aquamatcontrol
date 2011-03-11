/********************************************************************************
** Form generated from reading UI file 'tempSettings.ui'
**
** Created: Fri Mar 11 20:42:37 2011
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
        TempSettings->resize(173, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TempSettings->sizePolicy().hasHeightForWidth());
        TempSettings->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(TempSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(2, 4, 165, 385));
        groupBox->setTitle(QString::fromUtf8("title"));
        groupBox->setFlat(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 18, 146, 359));
        layout = new QVBoxLayout(layoutWidget);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setSizeConstraint(QLayout::SetFixedSize);
        layout->setContentsMargins(0, 0, 0, 0);
        check_tempActive = new QCheckBox(layoutWidget);
        check_tempActive->setObjectName(QString::fromUtf8("check_tempActive"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(check_tempActive->sizePolicy().hasHeightForWidth());
        check_tempActive->setSizePolicy(sizePolicy1);
        check_tempActive->setMaximumSize(QSize(16777215, 30));
        check_tempActive->setCheckable(true);
        check_tempActive->setChecked(false);

        layout->addWidget(check_tempActive);

        l_romSerial = new QLabel(layoutWidget);
        l_romSerial->setObjectName(QString::fromUtf8("l_romSerial"));
        sizePolicy.setHeightForWidth(l_romSerial->sizePolicy().hasHeightForWidth());
        l_romSerial->setSizePolicy(sizePolicy);
        l_romSerial->setMaximumSize(QSize(16777215, 30));
        l_romSerial->setAlignment(Qt::AlignCenter);

        layout->addWidget(l_romSerial);

        l_flags = new QLabel(layoutWidget);
        l_flags->setObjectName(QString::fromUtf8("l_flags"));
        sizePolicy.setHeightForWidth(l_flags->sizePolicy().hasHeightForWidth());
        l_flags->setSizePolicy(sizePolicy);
        l_flags->setMaximumSize(QSize(16777215, 30));

        layout->addWidget(l_flags);

        l_tempAlarms = new QLabel(layoutWidget);
        l_tempAlarms->setObjectName(QString::fromUtf8("l_tempAlarms"));
        sizePolicy.setHeightForWidth(l_tempAlarms->sizePolicy().hasHeightForWidth());
        l_tempAlarms->setSizePolicy(sizePolicy);
        l_tempAlarms->setMaximumSize(QSize(16777215, 30));

        layout->addWidget(l_tempAlarms);

        l_currentTemp = new QLabel(layoutWidget);
        l_currentTemp->setObjectName(QString::fromUtf8("l_currentTemp"));
        sizePolicy.setHeightForWidth(l_currentTemp->sizePolicy().hasHeightForWidth());
        l_currentTemp->setSizePolicy(sizePolicy);
        l_currentTemp->setMaximumSize(QSize(16777215, 30));

        layout->addWidget(l_currentTemp);

        spin_targetTemp = new QDoubleSpinBox(layoutWidget);
        spin_targetTemp->setObjectName(QString::fromUtf8("spin_targetTemp"));
        sizePolicy1.setHeightForWidth(spin_targetTemp->sizePolicy().hasHeightForWidth());
        spin_targetTemp->setSizePolicy(sizePolicy1);
        spin_targetTemp->setMaximumSize(QSize(16777215, 30));
        spin_targetTemp->setDecimals(1);
        spin_targetTemp->setSingleStep(0.1);
        spin_targetTemp->setValue(20);

        layout->addWidget(spin_targetTemp);

        spin_targetNightTemp = new QDoubleSpinBox(layoutWidget);
        spin_targetNightTemp->setObjectName(QString::fromUtf8("spin_targetNightTemp"));
        sizePolicy1.setHeightForWidth(spin_targetNightTemp->sizePolicy().hasHeightForWidth());
        spin_targetNightTemp->setSizePolicy(sizePolicy1);
        spin_targetNightTemp->setMaximumSize(QSize(16777215, 30));
        spin_targetNightTemp->setDecimals(1);
        spin_targetNightTemp->setSingleStep(0.1);
        spin_targetNightTemp->setValue(20);

        layout->addWidget(spin_targetNightTemp);

        spin_minTemp = new QDoubleSpinBox(layoutWidget);
        spin_minTemp->setObjectName(QString::fromUtf8("spin_minTemp"));
        sizePolicy1.setHeightForWidth(spin_minTemp->sizePolicy().hasHeightForWidth());
        spin_minTemp->setSizePolicy(sizePolicy1);
        spin_minTemp->setMaximumSize(QSize(16777215, 30));
        spin_minTemp->setDecimals(1);
        spin_minTemp->setMaximum(100);
        spin_minTemp->setSingleStep(0.1);
        spin_minTemp->setValue(10);

        layout->addWidget(spin_minTemp);

        spin_maxTemp = new QDoubleSpinBox(layoutWidget);
        spin_maxTemp->setObjectName(QString::fromUtf8("spin_maxTemp"));
        sizePolicy1.setHeightForWidth(spin_maxTemp->sizePolicy().hasHeightForWidth());
        spin_maxTemp->setSizePolicy(sizePolicy1);
        spin_maxTemp->setMaximumSize(QSize(16777215, 30));
        spin_maxTemp->setDecimals(1);
        spin_maxTemp->setSingleStep(0.1);
        spin_maxTemp->setValue(30);

        layout->addWidget(spin_maxTemp);

        spin_histeresis = new QDoubleSpinBox(layoutWidget);
        spin_histeresis->setObjectName(QString::fromUtf8("spin_histeresis"));
        sizePolicy1.setHeightForWidth(spin_histeresis->sizePolicy().hasHeightForWidth());
        spin_histeresis->setSizePolicy(sizePolicy1);
        spin_histeresis->setMaximumSize(QSize(16777215, 30));
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
