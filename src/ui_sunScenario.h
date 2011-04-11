/********************************************************************************
** Form generated from reading UI file 'sunScenario.ui'
**
** Created: Tue Apr 12 00:18:31 2011
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
#include <QtGui/QHBoxLayout>
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
    QTimeEdit *sunriseTime;
    QTimeEdit *sunsetTime;
    QCheckBox *keepPower;
    QWidget *layoutWidget;
    QHBoxLayout *sunScenarioBottomLayout;
    QLabel *label_2;
    QSpinBox *numberOfSteps;
    QLabel *label_3;
    QSpinBox *stepDuration;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpinBox *maxPower;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *minPower;
    QLabel *label_4;

    void setupUi(QWidget *SunScenario)
    {
        if (SunScenario->objectName().isEmpty())
            SunScenario->setObjectName(QString::fromUtf8("SunScenario"));
        SunScenario->resize(660, 360);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SunScenario->sizePolicy().hasHeightForWidth());
        SunScenario->setSizePolicy(sizePolicy);
        SunScenario->setMaximumSize(QSize(660, 360));
        label = new QLabel(SunScenario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, -36, 557, 417));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/sunScenario.png")));
        label->setAlignment(Qt::AlignCenter);
        sunriseTime = new QTimeEdit(SunScenario);
        sunriseTime->setObjectName(QString::fromUtf8("sunriseTime"));
        sunriseTime->setGeometry(QRect(226, 18, 71, 25));
        sunriseTime->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(7, 30, 0)));
        sunsetTime = new QTimeEdit(SunScenario);
        sunsetTime->setObjectName(QString::fromUtf8("sunsetTime"));
        sunsetTime->setGeometry(QRect(464, 18, 67, 25));
        sunsetTime->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(20, 0, 0)));
        keepPower = new QCheckBox(SunScenario);
        keepPower->setObjectName(QString::fromUtf8("keepPower"));
        keepPower->setGeometry(QRect(332, 120, 147, 21));
        keepPower->setChecked(true);
        keepPower->setTristate(false);
        layoutWidget = new QWidget(SunScenario);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 302, 337, 29));
        sunScenarioBottomLayout = new QHBoxLayout(layoutWidget);
        sunScenarioBottomLayout->setObjectName(QString::fromUtf8("sunScenarioBottomLayout"));
        sunScenarioBottomLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        sunScenarioBottomLayout->addWidget(label_2);

        numberOfSteps = new QSpinBox(layoutWidget);
        numberOfSteps->setObjectName(QString::fromUtf8("numberOfSteps"));
        numberOfSteps->setMinimum(1);
        numberOfSteps->setValue(10);

        sunScenarioBottomLayout->addWidget(numberOfSteps);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        sunScenarioBottomLayout->addWidget(label_3);

        stepDuration = new QSpinBox(layoutWidget);
        stepDuration->setObjectName(QString::fromUtf8("stepDuration"));
        stepDuration->setMinimum(1);
        stepDuration->setMaximum(30);
        stepDuration->setValue(5);

        sunScenarioBottomLayout->addWidget(stepDuration);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        sunScenarioBottomLayout->addWidget(label_8);

        horizontalLayoutWidget = new QWidget(SunScenario);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(12, 102, 141, 33));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        maxPower = new QSpinBox(horizontalLayoutWidget);
        maxPower->setObjectName(QString::fromUtf8("maxPower"));
        maxPower->setMinimum(50);
        maxPower->setMaximum(100);
        maxPower->setValue(100);

        horizontalLayout->addWidget(maxPower);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        horizontalLayoutWidget_2 = new QWidget(SunScenario);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(18, 210, 137, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        minPower = new QSpinBox(horizontalLayoutWidget_2);
        minPower->setObjectName(QString::fromUtf8("minPower"));
        minPower->setMinimum(0);
        minPower->setMaximum(49);

        horizontalLayout_2->addWidget(minPower);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        retranslateUi(SunScenario);

        QMetaObject::connectSlotsByName(SunScenario);
    } // setupUi

    void retranslateUi(QWidget *SunScenario)
    {
        SunScenario->setWindowTitle(QApplication::translate("SunScenario", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        keepPower->setText(QApplication::translate("SunScenario", "W\305\202\304\205czone w maksie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SunScenario", "Liczba krok\303\263w", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SunScenario", "Czas kroku", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SunScenario", "min.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SunScenario", "Max. moc", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SunScenario", "%", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SunScenario", "Min. moc", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SunScenario", "%", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SunScenario: public Ui_SunScenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUNSCENARIO_H
