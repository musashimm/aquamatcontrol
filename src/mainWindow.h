/*
AquamatControl - Interfejs graficzny do sterownika akwariowego Aquamat
Copyright (C) 2009 Wojciech Todryk (wojciech@todryk.pl)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

$Id$
*/

/** @file mainWindow.h
@brief Plik nagłówkowy - Główne okno
*/

#include <QMessageBox>
#include <QMainWindow>
#include <QSettings>
#include <QStringList>
#include <QDateTime>
#include <QTextCodec>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QHash>
#include <QFileDialog>
#include <QFile>
#include <QCloseEvent>
#include <QColor>

#include "ui_mainWindow.h"
#include "aboutDialog.h"
#include "commandProcessor.h"
#include "tempDisplay.h"
#include "outDisplay.h"
#include "outSettings.h"
#include "tempSettings.h"
#include "timersSettings.h"
#include "timersvSettings.h"
#include "comboBoxWeekDay.h"
#include "comboBoxOuts.h"
#include "main.h"
#include "command.h"
#include "temperature.h"
#include "indicatorl.h"
#include "codeUpdate.h"
#include "codeUpdateDialog.h"
#include "codeUpdateThread.h"

#include <qextserialenumerator.h>
#include <qextserialport.h>

#define WAITING 1
#define DONE 2

class CommandProcessor;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
	Ui::MainWindow ui;

public slots:
	void about();

	//void runCodeUpdate();
	void showUpdateDialog();
	//void showUpdateDialog();

	void loadSettingsFromFile();
	void chooseUpdateFile();
	void loadSettingsDefault();
	void saveSettingsToFile();
	void saveSettingsDefault();
	void insertLogEntry(const QString,const QString color = "black");
    void insertEventEntry(QString);
    void openSerialPort();
	void closeSerialPort();
	//void receiveDataManual();
	//void sendDataManual();
	void refreshStatus(void);
    void getAllConfiguration(void);
    void setAllConfiguration(void);
    QextSerialPort* getSerialPort(void);
	void logStatus(const char* title,int status);
	void updateStatusBar(const char* text);
	void updateStatusBar(QString);
	void updateProgressBar(int value);
	void refreshThreadFinished();
	void refreshThreadStarted();
	void log(QByteArray *c,const char* title,int);
	void togglePeriodicStatus(int state);
    void closeEvent(QCloseEvent*);

	void setUiDateTime(Command* c);
	void setUiTimeDay(Command* c);
	void setTimeDay();
	void getTimeDay();
	void setDateTime();
	void getDateTime();

	void alarmInit();
	void getAlarm();
	void setUiAlarms(uchar flags);
	void clearAlarm();
	void blockAlarm();
	void changeAlarmTitle(int);

	void getTemp();
	void getTempSettings();
	void setTempSettings();
	void tempInit();
	TempSettings* getPTemp(int);
	void discoverTemp();

	void outInit();
	void getOut();
	void getOutSettings();
    void setOutSettings();
 	void setUiOutState(int,uchar);
 	void setUiOutLabel(int,QString);
	void setOutState(int,int,int);
	void setOutBlock(int,int,int);
	void setOutLabel(int,QString);
	void sendOutSettings(int,QString,int);
	void setOutAllActive();
	void setOutAllInactive();
	void setOutAllBlock();
	void setOutAllUnblock();
	OutSettings* getPOut(int id);

	void topOffInit();
	void getTopOff();
	void setUiTopOff(Command* c);
	void setTopOff();
	void clearTopOff();

	void timersInit();
	void getTimers();
	void setTimers();
	TimersSettings* getPTimers(int id);

	void timersvInit();
	void getTimersv();
	void setTimersv();
	TimersvSettings* getPTimersv(int id);

	void eventsInit();
	void getEvents();
	void addEvent(int year, int monthtype, int day,int hours, int minutes, int value1, int value2, int value3);
	QString eventsOffOn(int value);
	void clearEvents();
	QString eventsTempSensor(int);
	QString eventsOut(int);
	QString eventsState(int);
	void enableGetEvents();
	void enableClearEvents();
    void saveEventsToFile();

private slots:
	void makeActions();
	void loadSettings(QSettings*);
	void saveSettings(QSettings*);

private:
    CodeUpdateThread *cut;
    CodeUpdate codeUpdate;
    QextSerialPort* port;
	CommandProcessor cp;
	QTimer periodicStatusTimer;
	TempDisplay* pTempDisplays[TEMP_SENSORS_NUM];
	OutDisplay* pOutDisplays[OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE];
	OutSettings* pOutSettings[OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE];
	TempSettings* pTempSettings[TEMP_SENSORS_NUM];
	TimersSettings* pTimersSettings[TIMERS_NUM];
	TimersvSettings* pTimersvSettings[TIMERSV_NUM];
	Indicator* pIndicators[ALARMS_TYPES_NUM];
	ComboBoxOuts *topOffOut;

	Indicator *alarmTempMax;
	Indicator *alarmTempMin;
	Indicator *alarmTempFailure;
	Indicator *alarmMinRo;
	Indicator *alarmAdMax;

	Indicator *topOff_min_sump_status;
	Indicator *topOff_max_sump_status;

	Indicator *topOff_max_sump;
    IndicatorL *topOff_block_by_pin;
	Indicator *topOff_min_sump;
	Indicator *topOff_running;
	IndicatorL *topOff_min_ro;
	IndicatorL *topOff_max_run_indicator;
};
