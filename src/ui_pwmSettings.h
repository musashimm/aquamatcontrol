/********************************************************************************
** Form generated from reading UI file 'pwmSettings.ui'
**
** Created: Sat Mar 5 22:41:00 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWMSETTINGS_H
#define UI_PWMSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDial>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PwmSettings
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_blocked;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_2;
    QDial *dial_pwm;

    void setupUi(QWidget *PwmSettings)
    {
        if (PwmSettings->objectName().isEmpty())
            PwmSettings->setObjectName(QString::fromUtf8("PwmSettings"));
        PwmSettings->resize(179, 244);
        groupBox = new QGroupBox(PwmSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(4, 0, 169, 241));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(8, 16, 153, 219));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_blocked = new QCheckBox(verticalLayoutWidget);
        checkBox_blocked->setObjectName(QString::fromUtf8("checkBox_blocked"));

        verticalLayout->addWidget(checkBox_blocked);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMaxLength(5);
        lineEdit_name->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        dial_pwm = new QDial(verticalLayoutWidget);
        dial_pwm->setObjectName(QString::fromUtf8("dial_pwm"));
        dial_pwm->setMaximum(100);
        dial_pwm->setValue(0);
        dial_pwm->setInvertedAppearance(false);
        dial_pwm->setInvertedControls(false);
        dial_pwm->setWrapping(false);
        dial_pwm->setNotchTarget(10);
        dial_pwm->setNotchesVisible(true);

        verticalLayout->addWidget(dial_pwm);


        retranslateUi(PwmSettings);

        QMetaObject::connectSlotsByName(PwmSettings);
    } // setupUi

    void retranslateUi(QWidget *PwmSettings)
    {
        PwmSettings->setWindowTitle(QApplication::translate("PwmSettings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PwmSettings", "Pwm1", 0, QApplication::UnicodeUTF8));
        checkBox_blocked->setText(QApplication::translate("PwmSettings", "Zablokowane", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PwmSettings", "Nazwa", 0, QApplication::UnicodeUTF8));
        lineEdit_name->setText(QApplication::translate("PwmSettings", "ABCDE", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PwmSettings", "Ustaw nazw\304\231", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PwmSettings", "100%", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PwmSettings: public Ui_PwmSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWMSETTINGS_H
