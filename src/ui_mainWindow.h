/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Sat Mar 19 14:08:22 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *m_loadSettings;
    QAction *m_saveSettings;
    QAction *m_quit;
    QAction *m_about;
    QAction *m_loadSettingsFromFile;
    QAction *m_saveSettingsToFile;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *status;
    QWidget *gridLayoutWidget_3;
    QGridLayout *outLayout;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *tempLayout;
    QGroupBox *groupBox_alarms;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *alarmLayout;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *l_dateTime;
    QLabel *l_dateTimeHour;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *adStatusLayout;
    QWidget *tab_5;
    QGroupBox *topOffGroupBox;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *topOffLayout;
    QLabel *label_17;
    QLabel *label_15;
    QSpinBox *topOff_max_run;
    QLabel *label_16;
    QCheckBox *topOff_block_min_ro;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *topOffButtons;
    QPushButton *b_getTopOff;
    QPushButton *b_setTopOff;
    QPushButton *b_clearTopOff;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *topOffIndicatorsLayout;
    QCheckBox *topOff_block;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *b_getAlarm;
    QPushButton *b_clearAlarm;
    QPushButton *b_blockAlarm;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QDateTimeEdit *e_dateTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QTimeEdit *e_timeDayFrom;
    QLabel *label_9;
    QTimeEdit *e_timeDayTo;
    QPushButton *b_getDateTime;
    QPushButton *b_getTimeDay;
    QPushButton *b_setDateTime;
    QPushButton *b_setTimeDay;
    QWidget *temperature;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *tempSettingsLayout;
    QGroupBox *groupBox_7;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_20;
    QLabel *label_12;
    QLabel *label_26;
    QLabel *label_30;
    QLabel *label_25;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_22;
    QLabel *label_21;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *b_tempGetSettings;
    QPushButton *b_tempSetSettings;
    QPushButton *b_discoverSensors;
    QWidget *tab_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_4;
    QWidget *gridLayoutWidget_4;
    QGridLayout *outSettingsLayout;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *b_getOutSettings;
    QPushButton *b_outAllActive;
    QPushButton *b_outAllInactive;
    QPushButton *b_outAllBlock;
    QPushButton *b_outAllUnblock;
    QWidget *tab_8;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *b_pwmGetConfig;
    QPushButton *b_pwmSendConfig;
    QSpacerItem *horizontalSpacer;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *pwmSettingsLayout;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *verticalSpacer;
    QWidget *tab_3;
    QWidget *gridLayoutWidget_5;
    QGridLayout *timersLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_6;
    QWidget *gridLayoutWidget_7;
    QGridLayout *timersSettingsLayout;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *b_timersGetSettings;
    QPushButton *b_timersSetSettings;
    QWidget *tab_9;
    QWidget *gridLayoutWidget_6;
    QGridLayout *timersvSettingsLayout;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *b_timersvGetSettings;
    QPushButton *b_timersvSetSettings;
    QWidget *tab_11;
    QWidget *horizontalLayoutWidget_13;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *b_timersSecGetSettings;
    QPushButton *b_timersSecSetSettings;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *timersSecSettingsLayout;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab;
    QListWidget *eventViewer;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *b_getEvents;
    QPushButton *b_clearEvents;
    QPushButton *b_saveEvents;
    QSpacerItem *horizontalSpacer_2;
    QWidget *settings;
    QListWidget *logViewer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QPushButton *b_chooseUpdateFile;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_updateFileName;
    QLabel *l_updateFileInfo;
    QPushButton *b_codeUpdate;
    QGroupBox *groupBox_6;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *l_serialStatus;
    QComboBox *cb_serial_port;
    QComboBox *cb_port_speed;
    QWidget *horizontalLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QCheckBox *check_periodicStatus;
    QSpinBox *spin_periodicStatusInterval;
    QLabel *label_10;
    QSpinBox *spin_periodicReadInterval;
    QLabel *label_11;
    QCheckBox *check_periodicRead;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *b_openPort;
    QPushButton *b_closePort;
    QPushButton *b_clearLog;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *b_refreshStatus;
    QProgressBar *progressStatus;
    QPushButton *b_getAllConfiguration;
    QPushButton *b_setAllConfiguration;
    QMenuBar *menubar;
    QMenu *menuPlik;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(900, 620);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(900, 620));
        MainWindow->setMaximumSize(QSize(900, 620));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/app_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        m_loadSettings = new QAction(MainWindow);
        m_loadSettings->setObjectName(QString::fromUtf8("m_loadSettings"));
        m_saveSettings = new QAction(MainWindow);
        m_saveSettings->setObjectName(QString::fromUtf8("m_saveSettings"));
        m_quit = new QAction(MainWindow);
        m_quit->setObjectName(QString::fromUtf8("m_quit"));
        m_about = new QAction(MainWindow);
        m_about->setObjectName(QString::fromUtf8("m_about"));
        m_loadSettingsFromFile = new QAction(MainWindow);
        m_loadSettingsFromFile->setObjectName(QString::fromUtf8("m_loadSettingsFromFile"));
        m_saveSettingsToFile = new QAction(MainWindow);
        m_saveSettingsToFile->setObjectName(QString::fromUtf8("m_saveSettingsToFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        status = new QWidget();
        status->setObjectName(QString::fromUtf8("status"));
        gridLayoutWidget_3 = new QWidget(status);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(240, 100, 631, 261));
        outLayout = new QGridLayout(gridLayoutWidget_3);
        outLayout->setObjectName(QString::fromUtf8("outLayout"));
        outLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_3 = new QWidget(status);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 370, 871, 121));
        tempLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        tempLayout->setObjectName(QString::fromUtf8("tempLayout"));
        tempLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_alarms = new QGroupBox(status);
        groupBox_alarms->setObjectName(QString::fromUtf8("groupBox_alarms"));
        groupBox_alarms->setGeometry(QRect(6, 6, 225, 245));
        verticalLayoutWidget_3 = new QWidget(groupBox_alarms);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(6, 12, 213, 225));
        alarmLayout = new QVBoxLayout(verticalLayoutWidget_3);
        alarmLayout->setObjectName(QString::fromUtf8("alarmLayout"));
        alarmLayout->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(status);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(504, 12, 365, 81));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/resources/logocontrol2.png")));
        groupBox_2 = new QGroupBox(status);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(242, 6, 255, 83));
        verticalLayoutWidget_7 = new QWidget(groupBox_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(10, 16, 235, 65));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        l_dateTime = new QLabel(verticalLayoutWidget_7);
        l_dateTime->setObjectName(QString::fromUtf8("l_dateTime"));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        l_dateTime->setFont(font);
        l_dateTime->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(l_dateTime);

        l_dateTimeHour = new QLabel(verticalLayoutWidget_7);
        l_dateTimeHour->setObjectName(QString::fromUtf8("l_dateTimeHour"));
        QFont font1;
        font1.setPointSize(16);
        l_dateTimeHour->setFont(font1);
        l_dateTimeHour->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(l_dateTimeHour);

        groupBox = new QGroupBox(status);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(6, 256, 225, 105));
        verticalLayoutWidget_6 = new QWidget(groupBox);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(6, 16, 213, 81));
        adStatusLayout = new QVBoxLayout(verticalLayoutWidget_6);
        adStatusLayout->setObjectName(QString::fromUtf8("adStatusLayout"));
        adStatusLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(status, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        topOffGroupBox = new QGroupBox(tab_5);
        topOffGroupBox->setObjectName(QString::fromUtf8("topOffGroupBox"));
        topOffGroupBox->setGeometry(QRect(8, 152, 863, 333));
        label_14 = new QLabel(topOffGroupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(186, 10, 421, 269));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/resources/top_off.png")));
        horizontalLayoutWidget_4 = new QWidget(topOffGroupBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(62, 284, 687, 37));
        topOffLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        topOffLayout->setObjectName(QString::fromUtf8("topOffLayout"));
        topOffLayout->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(horizontalLayoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        topOffLayout->addWidget(label_17);

        label_15 = new QLabel(horizontalLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        topOffLayout->addWidget(label_15);

        topOff_max_run = new QSpinBox(horizontalLayoutWidget_4);
        topOff_max_run->setObjectName(QString::fromUtf8("topOff_max_run"));
        topOff_max_run->setFrame(true);
        topOff_max_run->setMinimum(2);
        topOff_max_run->setMaximum(255);
        topOff_max_run->setSingleStep(1);

        topOffLayout->addWidget(topOff_max_run);

        label_16 = new QLabel(horizontalLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        topOffLayout->addWidget(label_16);

        topOff_block_min_ro = new QCheckBox(topOffGroupBox);
        topOff_block_min_ro->setObjectName(QString::fromUtf8("topOff_block_min_ro"));
        topOff_block_min_ro->setGeometry(QRect(616, 186, 129, 22));
        topOff_block_min_ro->setChecked(true);
        verticalLayoutWidget_2 = new QWidget(topOffGroupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(668, 16, 187, 119));
        topOffButtons = new QVBoxLayout(verticalLayoutWidget_2);
        topOffButtons->setObjectName(QString::fromUtf8("topOffButtons"));
        topOffButtons->setContentsMargins(0, 0, 0, 0);
        b_getTopOff = new QPushButton(verticalLayoutWidget_2);
        b_getTopOff->setObjectName(QString::fromUtf8("b_getTopOff"));

        topOffButtons->addWidget(b_getTopOff);

        b_setTopOff = new QPushButton(verticalLayoutWidget_2);
        b_setTopOff->setObjectName(QString::fromUtf8("b_setTopOff"));

        topOffButtons->addWidget(b_setTopOff);

        b_clearTopOff = new QPushButton(verticalLayoutWidget_2);
        b_clearTopOff->setObjectName(QString::fromUtf8("b_clearTopOff"));

        topOffButtons->addWidget(b_clearTopOff);

        horizontalLayoutWidget_10 = new QWidget(topOffGroupBox);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(14, 38, 307, 41));
        topOffIndicatorsLayout = new QHBoxLayout(horizontalLayoutWidget_10);
        topOffIndicatorsLayout->setObjectName(QString::fromUtf8("topOffIndicatorsLayout"));
        topOffIndicatorsLayout->setContentsMargins(0, 0, 0, 0);
        topOff_block = new QCheckBox(horizontalLayoutWidget_10);
        topOff_block->setObjectName(QString::fromUtf8("topOff_block"));
        topOff_block->setChecked(true);

        topOffIndicatorsLayout->addWidget(topOff_block);

        gridLayoutWidget_8 = new QWidget(topOffGroupBox);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(38, 130, 641, 109));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 8, 193, 139));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        b_getAlarm = new QPushButton(groupBox_4);
        b_getAlarm->setObjectName(QString::fromUtf8("b_getAlarm"));

        verticalLayout_7->addWidget(b_getAlarm);

        b_clearAlarm = new QPushButton(groupBox_4);
        b_clearAlarm->setObjectName(QString::fromUtf8("b_clearAlarm"));

        verticalLayout_7->addWidget(b_clearAlarm);

        b_blockAlarm = new QPushButton(groupBox_4);
        b_blockAlarm->setObjectName(QString::fromUtf8("b_blockAlarm"));

        verticalLayout_7->addWidget(b_blockAlarm);

        groupBox_5 = new QGroupBox(tab_5);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(214, 8, 657, 139));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        e_dateTime = new QDateTimeEdit(groupBox_5);
        e_dateTime->setObjectName(QString::fromUtf8("e_dateTime"));
        e_dateTime->setCurrentSection(QDateTimeEdit::YearSection);
        e_dateTime->setCalendarPopup(false);

        gridLayout_5->addWidget(e_dateTime, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        e_timeDayFrom = new QTimeEdit(groupBox_5);
        e_timeDayFrom->setObjectName(QString::fromUtf8("e_timeDayFrom"));

        horizontalLayout->addWidget(e_timeDayFrom);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        e_timeDayTo = new QTimeEdit(groupBox_5);
        e_timeDayTo->setObjectName(QString::fromUtf8("e_timeDayTo"));

        horizontalLayout->addWidget(e_timeDayTo);


        gridLayout_5->addLayout(horizontalLayout, 1, 0, 1, 1);

        b_getDateTime = new QPushButton(groupBox_5);
        b_getDateTime->setObjectName(QString::fromUtf8("b_getDateTime"));

        gridLayout_5->addWidget(b_getDateTime, 0, 1, 1, 1);

        b_getTimeDay = new QPushButton(groupBox_5);
        b_getTimeDay->setObjectName(QString::fromUtf8("b_getTimeDay"));

        gridLayout_5->addWidget(b_getTimeDay, 1, 1, 1, 1);

        b_setDateTime = new QPushButton(groupBox_5);
        b_setDateTime->setObjectName(QString::fromUtf8("b_setDateTime"));

        gridLayout_5->addWidget(b_setDateTime, 0, 2, 1, 1);

        b_setTimeDay = new QPushButton(groupBox_5);
        b_setTimeDay->setObjectName(QString::fromUtf8("b_setTimeDay"));

        gridLayout_5->addWidget(b_setTimeDay, 1, 2, 1, 1);

        tabWidget->addTab(tab_5, QString());
        temperature = new QWidget();
        temperature->setObjectName(QString::fromUtf8("temperature"));
        horizontalLayoutWidget_6 = new QWidget(temperature);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(2, 4, 869, 447));
        tempSettingsLayout = new QHBoxLayout(horizontalLayoutWidget_6);
        tempSettingsLayout->setObjectName(QString::fromUtf8("tempSettingsLayout"));
        tempSettingsLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(horizontalLayoutWidget_6);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy);
        groupBox_7->setFlat(true);
        verticalLayoutWidget_4 = new QWidget(groupBox_7);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(4, 22, 164, 361));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMaximumSize(QSize(16777215, 30));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_20);

        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_12);

        label_26 = new QLabel(verticalLayoutWidget_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMaximumSize(QSize(16777215, 30));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_26);

        label_30 = new QLabel(verticalLayoutWidget_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        label_30->setMaximumSize(QSize(16777215, 30));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_30);

        label_25 = new QLabel(verticalLayoutWidget_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMaximumSize(QSize(16777215, 30));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_25);

        label_23 = new QLabel(verticalLayoutWidget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setMaximumSize(QSize(16777215, 30));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_23);

        label_24 = new QLabel(verticalLayoutWidget_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setMaximumSize(QSize(16777215, 30));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_24);

        label_27 = new QLabel(verticalLayoutWidget_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMaximumSize(QSize(16777215, 30));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_27);

        label_28 = new QLabel(verticalLayoutWidget_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setMaximumSize(QSize(16777215, 30));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_28);

        label_29 = new QLabel(verticalLayoutWidget_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMaximumSize(QSize(16777215, 30));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_29);

        label_22 = new QLabel(verticalLayoutWidget_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setMaximumSize(QSize(16777215, 30));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_22);

        label_21 = new QLabel(verticalLayoutWidget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMaximumSize(QSize(16777215, 30));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_21);


        tempSettingsLayout->addWidget(groupBox_7);

        horizontalLayoutWidget_8 = new QWidget(temperature);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(4, 456, 389, 30));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        b_tempGetSettings = new QPushButton(horizontalLayoutWidget_8);
        b_tempGetSettings->setObjectName(QString::fromUtf8("b_tempGetSettings"));

        horizontalLayout_6->addWidget(b_tempGetSettings);

        b_tempSetSettings = new QPushButton(horizontalLayoutWidget_8);
        b_tempSetSettings->setObjectName(QString::fromUtf8("b_tempSetSettings"));

        horizontalLayout_6->addWidget(b_tempSetSettings);

        b_discoverSensors = new QPushButton(horizontalLayoutWidget_8);
        b_discoverSensors->setObjectName(QString::fromUtf8("b_discoverSensors"));

        horizontalLayout_6->addWidget(b_discoverSensors);

        tabWidget->addTab(temperature, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(4, 4, 869, 487));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayoutWidget_4 = new QWidget(tab_4);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(4, 2, 857, 423));
        outSettingsLayout = new QGridLayout(gridLayoutWidget_4);
        outSettingsLayout->setSpacing(3);
        outSettingsLayout->setObjectName(QString::fromUtf8("outSettingsLayout"));
        outSettingsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_11 = new QWidget(tab_4);
        horizontalLayoutWidget_11->setObjectName(QString::fromUtf8("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(2, 430, 767, 30));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        b_getOutSettings = new QPushButton(horizontalLayoutWidget_11);
        b_getOutSettings->setObjectName(QString::fromUtf8("b_getOutSettings"));

        horizontalLayout_8->addWidget(b_getOutSettings);

        b_outAllActive = new QPushButton(horizontalLayoutWidget_11);
        b_outAllActive->setObjectName(QString::fromUtf8("b_outAllActive"));

        horizontalLayout_8->addWidget(b_outAllActive);

        b_outAllInactive = new QPushButton(horizontalLayoutWidget_11);
        b_outAllInactive->setObjectName(QString::fromUtf8("b_outAllInactive"));

        horizontalLayout_8->addWidget(b_outAllInactive);

        b_outAllBlock = new QPushButton(horizontalLayoutWidget_11);
        b_outAllBlock->setObjectName(QString::fromUtf8("b_outAllBlock"));

        horizontalLayout_8->addWidget(b_outAllBlock);

        b_outAllUnblock = new QPushButton(horizontalLayoutWidget_11);
        b_outAllUnblock->setObjectName(QString::fromUtf8("b_outAllUnblock"));

        horizontalLayout_8->addWidget(b_outAllUnblock);

        tabWidget_3->addTab(tab_4, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayoutWidget_12 = new QWidget(tab_8);
        horizontalLayoutWidget_12->setObjectName(QString::fromUtf8("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(2, 430, 857, 30));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        b_pwmGetConfig = new QPushButton(horizontalLayoutWidget_12);
        b_pwmGetConfig->setObjectName(QString::fromUtf8("b_pwmGetConfig"));

        horizontalLayout_9->addWidget(b_pwmGetConfig);

        b_pwmSendConfig = new QPushButton(horizontalLayoutWidget_12);
        b_pwmSendConfig->setObjectName(QString::fromUtf8("b_pwmSendConfig"));

        horizontalLayout_9->addWidget(b_pwmSendConfig);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        verticalLayoutWidget_8 = new QWidget(tab_8);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(3, 1, 859, 425));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        pwmSettingsLayout = new QGridLayout();
        pwmSettingsLayout->setObjectName(QString::fromUtf8("pwmSettingsLayout"));
        pwmSettingsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_5->addLayout(pwmSettingsLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_11->addItem(verticalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_11);

        tabWidget_3->addTab(tab_8, QString());
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayoutWidget_5 = new QWidget(tab_3);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(4, 4, 777, 485));
        timersLayout = new QGridLayout(gridLayoutWidget_5);
        timersLayout->setObjectName(QString::fromUtf8("timersLayout"));
        timersLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(tab_3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(4, 4, 869, 487));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayoutWidget_7 = new QWidget(tab_6);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(2, 2, 861, 425));
        timersSettingsLayout = new QGridLayout(gridLayoutWidget_7);
        timersSettingsLayout->setObjectName(QString::fromUtf8("timersSettingsLayout"));
        timersSettingsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_7 = new QWidget(tab_6);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(2, 430, 271, 30));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        b_timersGetSettings = new QPushButton(horizontalLayoutWidget_7);
        b_timersGetSettings->setObjectName(QString::fromUtf8("b_timersGetSettings"));

        horizontalLayout_5->addWidget(b_timersGetSettings);

        b_timersSetSettings = new QPushButton(horizontalLayoutWidget_7);
        b_timersSetSettings->setObjectName(QString::fromUtf8("b_timersSetSettings"));

        horizontalLayout_5->addWidget(b_timersSetSettings);

        tabWidget_2->addTab(tab_6, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        gridLayoutWidget_6 = new QWidget(tab_9);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(2, 2, 861, 425));
        timersvSettingsLayout = new QGridLayout(gridLayoutWidget_6);
        timersvSettingsLayout->setObjectName(QString::fromUtf8("timersvSettingsLayout"));
        timersvSettingsLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_5 = new QWidget(tab_9);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(2, 430, 271, 30));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        b_timersvGetSettings = new QPushButton(horizontalLayoutWidget_5);
        b_timersvGetSettings->setObjectName(QString::fromUtf8("b_timersvGetSettings"));

        horizontalLayout_4->addWidget(b_timersvGetSettings);

        b_timersvSetSettings = new QPushButton(horizontalLayoutWidget_5);
        b_timersvSetSettings->setObjectName(QString::fromUtf8("b_timersvSetSettings"));

        horizontalLayout_4->addWidget(b_timersvSetSettings);

        tabWidget_2->addTab(tab_9, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        horizontalLayoutWidget_13 = new QWidget(tab_11);
        horizontalLayoutWidget_13->setObjectName(QString::fromUtf8("horizontalLayoutWidget_13"));
        horizontalLayoutWidget_13->setGeometry(QRect(2, 430, 271, 30));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_13);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        b_timersSecGetSettings = new QPushButton(horizontalLayoutWidget_13);
        b_timersSecGetSettings->setObjectName(QString::fromUtf8("b_timersSecGetSettings"));

        horizontalLayout_10->addWidget(b_timersSecGetSettings);

        b_timersSecSetSettings = new QPushButton(horizontalLayoutWidget_13);
        b_timersSecSetSettings->setObjectName(QString::fromUtf8("b_timersSecSetSettings"));

        horizontalLayout_10->addWidget(b_timersSecSetSettings);

        verticalLayoutWidget = new QWidget(tab_11);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(2, 2, 861, 425));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        timersSecSettingsLayout = new QGridLayout();
        timersSecSettingsLayout->setSpacing(3);
        timersSecSettingsLayout->setObjectName(QString::fromUtf8("timersSecSettingsLayout"));

        verticalLayout_4->addLayout(timersSecSettingsLayout);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_13->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_13);

        tabWidget_2->addTab(tab_11, QString());
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        eventViewer = new QListWidget(tab);
        eventViewer->setObjectName(QString::fromUtf8("eventViewer"));
        eventViewer->setGeometry(QRect(4, 4, 869, 451));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(eventViewer->sizePolicy().hasHeightForWidth());
        eventViewer->setSizePolicy(sizePolicy2);
        horizontalLayoutWidget_9 = new QWidget(tab);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(6, 460, 867, 30));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        b_getEvents = new QPushButton(horizontalLayoutWidget_9);
        b_getEvents->setObjectName(QString::fromUtf8("b_getEvents"));

        horizontalLayout_7->addWidget(b_getEvents);

        b_clearEvents = new QPushButton(horizontalLayoutWidget_9);
        b_clearEvents->setObjectName(QString::fromUtf8("b_clearEvents"));

        horizontalLayout_7->addWidget(b_clearEvents);

        b_saveEvents = new QPushButton(horizontalLayoutWidget_9);
        b_saveEvents->setObjectName(QString::fromUtf8("b_saveEvents"));

        horizontalLayout_7->addWidget(b_saveEvents);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        tabWidget->addTab(tab, QString());
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        logViewer = new QListWidget(settings);
        logViewer->setObjectName(QString::fromUtf8("logViewer"));
        logViewer->setGeometry(QRect(4, 206, 869, 283));
        logViewer->setWordWrap(true);
        logViewer->setSortingEnabled(false);
        groupBox_3 = new QGroupBox(settings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(4, 122, 869, 77));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        b_chooseUpdateFile = new QPushButton(groupBox_3);
        b_chooseUpdateFile->setObjectName(QString::fromUtf8("b_chooseUpdateFile"));
        b_chooseUpdateFile->setMinimumSize(QSize(100, 45));

        gridLayout_2->addWidget(b_chooseUpdateFile, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        l_updateFileName = new QLabel(groupBox_3);
        l_updateFileName->setObjectName(QString::fromUtf8("l_updateFileName"));

        verticalLayout_2->addWidget(l_updateFileName);

        l_updateFileInfo = new QLabel(groupBox_3);
        l_updateFileInfo->setObjectName(QString::fromUtf8("l_updateFileInfo"));

        verticalLayout_2->addWidget(l_updateFileInfo);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        b_codeUpdate = new QPushButton(groupBox_3);
        b_codeUpdate->setObjectName(QString::fromUtf8("b_codeUpdate"));
        b_codeUpdate->setEnabled(true);
        b_codeUpdate->setMinimumSize(QSize(200, 45));

        gridLayout_2->addWidget(b_codeUpdate, 0, 2, 1, 1);

        gridLayout_2->setColumnStretch(1, 2);
        groupBox_6 = new QGroupBox(settings);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(4, 2, 869, 115));
        formLayoutWidget = new QWidget(groupBox_6);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(8, 18, 273, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        l_serialStatus = new QLabel(formLayoutWidget);
        l_serialStatus->setObjectName(QString::fromUtf8("l_serialStatus"));

        formLayout->setWidget(2, QFormLayout::FieldRole, l_serialStatus);

        cb_serial_port = new QComboBox(formLayoutWidget);
        cb_serial_port->setObjectName(QString::fromUtf8("cb_serial_port"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cb_serial_port);

        cb_port_speed = new QComboBox(formLayoutWidget);
        cb_port_speed->setObjectName(QString::fromUtf8("cb_port_speed"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cb_port_speed);

        horizontalLayoutWidget_2 = new QWidget(groupBox_6);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(292, 18, 370, 62));
        gridLayout_4 = new QGridLayout(horizontalLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        check_periodicStatus = new QCheckBox(horizontalLayoutWidget_2);
        check_periodicStatus->setObjectName(QString::fromUtf8("check_periodicStatus"));

        gridLayout_4->addWidget(check_periodicStatus, 0, 0, 1, 1);

        spin_periodicStatusInterval = new QSpinBox(horizontalLayoutWidget_2);
        spin_periodicStatusInterval->setObjectName(QString::fromUtf8("spin_periodicStatusInterval"));
        spin_periodicStatusInterval->setMinimum(10);

        gridLayout_4->addWidget(spin_periodicStatusInterval, 0, 1, 1, 1);

        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 2, 1, 1);

        spin_periodicReadInterval = new QSpinBox(horizontalLayoutWidget_2);
        spin_periodicReadInterval->setObjectName(QString::fromUtf8("spin_periodicReadInterval"));
        spin_periodicReadInterval->setEnabled(false);
        spin_periodicReadInterval->setMinimum(1);

        gridLayout_4->addWidget(spin_periodicReadInterval, 1, 1, 1, 1);

        label_11 = new QLabel(horizontalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);

        gridLayout_4->addWidget(label_11, 1, 2, 1, 1);

        check_periodicRead = new QCheckBox(horizontalLayoutWidget_2);
        check_periodicRead->setObjectName(QString::fromUtf8("check_periodicRead"));
        check_periodicRead->setEnabled(false);
        check_periodicRead->setChecked(true);

        gridLayout_4->addWidget(check_periodicRead, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(groupBox_6);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(292, 80, 475, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        b_openPort = new QPushButton(horizontalLayoutWidget);
        b_openPort->setObjectName(QString::fromUtf8("b_openPort"));

        horizontalLayout_2->addWidget(b_openPort);

        b_closePort = new QPushButton(horizontalLayoutWidget);
        b_closePort->setObjectName(QString::fromUtf8("b_closePort"));

        horizontalLayout_2->addWidget(b_closePort);

        b_clearLog = new QPushButton(horizontalLayoutWidget);
        b_clearLog->setObjectName(QString::fromUtf8("b_clearLog"));

        horizontalLayout_2->addWidget(b_clearLog);

        tabWidget->addTab(settings, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        b_refreshStatus = new QPushButton(centralwidget);
        b_refreshStatus->setObjectName(QString::fromUtf8("b_refreshStatus"));

        horizontalLayout_3->addWidget(b_refreshStatus);

        progressStatus = new QProgressBar(centralwidget);
        progressStatus->setObjectName(QString::fromUtf8("progressStatus"));
        progressStatus->setValue(0);
        progressStatus->setTextVisible(true);

        horizontalLayout_3->addWidget(progressStatus);

        b_getAllConfiguration = new QPushButton(centralwidget);
        b_getAllConfiguration->setObjectName(QString::fromUtf8("b_getAllConfiguration"));

        horizontalLayout_3->addWidget(b_getAllConfiguration);

        b_setAllConfiguration = new QPushButton(centralwidget);
        b_setAllConfiguration->setObjectName(QString::fromUtf8("b_setAllConfiguration"));

        horizontalLayout_3->addWidget(b_setAllConfiguration);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 25));
        menuPlik = new QMenu(menubar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPlik->menuAction());
        menubar->addAction(menuInfo->menuAction());
        menuPlik->addAction(m_loadSettings);
        menuPlik->addAction(m_loadSettingsFromFile);
        menuPlik->addSeparator();
        menuPlik->addAction(m_saveSettings);
        menuPlik->addAction(m_saveSettingsToFile);
        menuPlik->addSeparator();
        menuPlik->addAction(m_quit);
        menuInfo->addAction(m_about);

        retranslateUi(MainWindow);
        QObject::connect(m_quit, SIGNAL(activated()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        m_loadSettings->setText(QApplication::translate("MainWindow", "\305\201aduj konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
        m_saveSettings->setText(QApplication::translate("MainWindow", "Zapisz konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
        m_quit->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
        m_about->setText(QApplication::translate("MainWindow", "O programie...", 0, QApplication::UnicodeUTF8));
        m_loadSettingsFromFile->setText(QApplication::translate("MainWindow", "\305\201aduj konfiguracj\304\231 z pliku", 0, QApplication::UnicodeUTF8));
        m_saveSettingsToFile->setText(QApplication::translate("MainWindow", "Zapisz konfiguracj\304\231 do pliku", 0, QApplication::UnicodeUTF8));
        groupBox_alarms->setTitle(QApplication::translate("MainWindow", "Alarmy", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Czas", 0, QApplication::UnicodeUTF8));
        l_dateTime->setText(QApplication::translate("MainWindow", "2009-01-01", 0, QApplication::UnicodeUTF8));
        l_dateTimeHour->setText(QApplication::translate("MainWindow", "10:10 Wt", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Automatyczna dolewka", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(status), QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        topOffGroupBox->setTitle(QApplication::translate("MainWindow", "Automatyczna dolewka", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", " Maks. czas pracy AD", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "sek.", 0, QApplication::UnicodeUTF8));
        topOff_block_min_ro->setText(QApplication::translate("MainWindow", "Blokada czujnika", 0, QApplication::UnicodeUTF8));
        b_getTopOff->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_setTopOff->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia", 0, QApplication::UnicodeUTF8));
        b_clearTopOff->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207 alarmy i blokady ", 0, QApplication::UnicodeUTF8));
        topOff_block->setText(QApplication::translate("MainWindow", "Blokada pracy", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Alarmy", 0, QApplication::UnicodeUTF8));
        b_getAlarm->setText(QApplication::translate("MainWindow", "Pobierz stan", 0, QApplication::UnicodeUTF8));
        b_clearAlarm->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207 alarmy", 0, QApplication::UnicodeUTF8));
        b_blockAlarm->setText(QApplication::translate("MainWindow", "Zablokuj powiadomienia", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Czas", 0, QApplication::UnicodeUTF8));
        e_dateTime->setDisplayFormat(QApplication::translate("MainWindow", "yy-MM-dd HH:mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Od", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Do", 0, QApplication::UnicodeUTF8));
        b_getDateTime->setText(QApplication::translate("MainWindow", "Pobierz", 0, QApplication::UnicodeUTF8));
        b_getTimeDay->setText(QApplication::translate("MainWindow", "Pobierz por\304\231 dnia", 0, QApplication::UnicodeUTF8));
        b_setDateTime->setText(QApplication::translate("MainWindow", "Ustaw", 0, QApplication::UnicodeUTF8));
        b_setTimeDay->setText(QApplication::translate("MainWindow", "Ustaw por\304\231 dnia", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Podstawowe / AD", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        label_20->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Numer seryjny", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Flagi / B\305\202\304\231dne odczyty", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Alarmy", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Temperatura aktualna", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Temp. docelowa", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Temp. docelowa nocna", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "Temp. minimalna", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Temp. maksymalna", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Histereza", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Wyj\305\233cie ch\305\202odz\304\205ce", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Wyj\305\233cie podgrzewaj\304\205ce", 0, QApplication::UnicodeUTF8));
        b_tempGetSettings->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_tempSetSettings->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia ", 0, QApplication::UnicodeUTF8));
        b_discoverSensors->setText(QApplication::translate("MainWindow", "Wykryj czujniki", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(temperature), QApplication::translate("MainWindow", "Temperatura", 0, QApplication::UnicodeUTF8));
        b_getOutSettings->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_outAllActive->setText(QApplication::translate("MainWindow", "Wszystkie w\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        b_outAllInactive->setText(QApplication::translate("MainWindow", "Wszystkie wy\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        b_outAllBlock->setText(QApplication::translate("MainWindow", "Wszystkie zablokuj", 0, QApplication::UnicodeUTF8));
        b_outAllUnblock->setText(QApplication::translate("MainWindow", "Wszystkie odblokuj", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_4), QApplication::translate("MainWindow", "Binarne", 0, QApplication::UnicodeUTF8));
        b_pwmGetConfig->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_pwmSendConfig->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "Pwm", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Wyj\305\233cia", 0, QApplication::UnicodeUTF8));
        b_timersGetSettings->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_timersSetSettings->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Godzinowe", 0, QApplication::UnicodeUTF8));
        b_timersvGetSettings->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_timersvSetSettings->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Interwa\305\202owe", 0, QApplication::UnicodeUTF8));
        b_timersSecGetSettings->setText(QApplication::translate("MainWindow", "Pobierz ustawienia", 0, QApplication::UnicodeUTF8));
        b_timersSecSetSettings->setText(QApplication::translate("MainWindow", "Wy\305\233lij ustawienia", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QApplication::translate("MainWindow", "Sekundowe", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Timery", 0, QApplication::UnicodeUTF8));
        b_getEvents->setText(QApplication::translate("MainWindow", "Pobierz histori\304\231 zdarze\305\204", 0, QApplication::UnicodeUTF8));
        b_clearEvents->setText(QApplication::translate("MainWindow", "Wyszczy\305\233\304\207 histori\304\231 zdarze\305\204", 0, QApplication::UnicodeUTF8));
        b_saveEvents->setText(QApplication::translate("MainWindow", "Zapisz histori\304\231 do pliku", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Historia zdarze\305\204", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Aktualizacja oprogramowania", 0, QApplication::UnicodeUTF8));
        b_chooseUpdateFile->setText(QApplication::translate("MainWindow", "Wybierz plik", 0, QApplication::UnicodeUTF8));
        l_updateFileName->setText(QApplication::translate("MainWindow", "Nie wybranu \305\274adnego pliku", 0, QApplication::UnicodeUTF8));
        l_updateFileInfo->setText(QApplication::translate("MainWindow", "Brak informacji o pliku \305\272r\303\263d\305\202owym", 0, QApplication::UnicodeUTF8));
        b_codeUpdate->setText(QApplication::translate("MainWindow", "Programuj", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Komunikacja", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Port szeregowy", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Szybko\305\233\304\207 transmisji", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Status portu", 0, QApplication::UnicodeUTF8));
        l_serialStatus->setText(QApplication::translate("MainWindow", "Zamkni\304\231ty", 0, QApplication::UnicodeUTF8));
        check_periodicStatus->setText(QApplication::translate("MainWindow", "Wysy\305\202anie zapytania o status co", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "sekund", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "sekund", 0, QApplication::UnicodeUTF8));
        check_periodicRead->setText(QApplication::translate("MainWindow", "Odczyt z portu szeregowego co", 0, QApplication::UnicodeUTF8));
        b_openPort->setText(QApplication::translate("MainWindow", "Otw\303\263rz port", 0, QApplication::UnicodeUTF8));
        b_closePort->setText(QApplication::translate("MainWindow", "Zamknij port", 0, QApplication::UnicodeUTF8));
        b_clearLog->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207 log", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(settings), QApplication::translate("MainWindow", "Komunikacja i aktualizacja", 0, QApplication::UnicodeUTF8));
        b_refreshStatus->setText(QApplication::translate("MainWindow", "Zauktualizuj status", 0, QApplication::UnicodeUTF8));
        b_getAllConfiguration->setText(QApplication::translate("MainWindow", "Pobierz konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
        b_setAllConfiguration->setText(QApplication::translate("MainWindow", "Wy\305\233lij konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0, QApplication::UnicodeUTF8));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
