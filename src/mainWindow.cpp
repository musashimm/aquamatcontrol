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

/** @file mainWindow.cpp
@brief Implementacja głównego okna
*/

#include "mainWindow.h"
#include "processingTemp.cpp"
#include "processingTime.cpp"
#include "processingPwm.cpp"
#include "processingAlarm.cpp"
#include "processingOut.cpp"
#include "processingTopOff.cpp"
#include "processingTimers.cpp"
#include "processingTimersv.cpp"
#include "processingTimersSec.cpp"
#include "processingEvents.cpp"

//#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    statusBar()->setSizeGripEnabled(false);
    ui.tabWidget->setCurrentIndex(0);
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));

    cut = new CodeUpdateThread(&codeUpdate);

    ui.b_codeUpdate->setEnabled(false);

    makeActions();

    cp.setParent(this);

	outInit();
	pwmInit();
	tempInit();
	timersInit();
	timersvInit();
	timersSecInit();
	topOffInit();
	alarmInit();
	eventsInit();

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    for (int i=0;i<ports.size();i++) {
        if (ports.at(i).physName.contains("/dev/")) {
            ui.cb_serial_port->addItem(ports.at(i).physName,QVariant(i));
        } else {
            ui.cb_serial_port->addItem(ports.at(i).portName,QVariant(i));
        }
    }

    ui.cb_port_speed->addItem("9600",QVariant(BAUD9600));
    ui.cb_port_speed->addItem("19200",QVariant(BAUD19200));
    ui.cb_port_speed->addItem("38400",QVariant(BAUD38400));
    ui.cb_port_speed->addItem("57600",QVariant(BAUD57600));
    ui.cb_port_speed->addItem("115200",QVariant(BAUD115200));

    loadSettingsDefault();

    if (ports.size()) {
        openSerialPort();
    } else {
        insertLogEntry(tr("Problem z konfiguracją portu szeregowego"));
    }
}

void MainWindow::openSerialPort() {

    PortSettings ps;
    ps.BaudRate = (BaudRateType)ui.cb_port_speed->itemData(ui.cb_port_speed->currentIndex()).toInt();
    ps.DataBits=DATA_8;
    ps.FlowControl=FLOW_OFF;
    ps.Parity=PAR_NONE;
    ps.StopBits=STOP_1;
    ps.Timeout_Millisec = 10;

    port = new QextSerialPort();

    if (!(ui.cb_serial_port->currentText().size())) {
        insertLogEntry(QString("Nie wybrano portu"));
        ui.l_serialStatus->setText("<font color='red'>Nie wybrano portu</font>");
        ui.tabWidget->setCurrentIndex(6);
        return;
    }

    port = new QextSerialPort(ui.cb_serial_port->currentText(), ps);
    bool ret = port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    if (ret) {
        insertLogEntry(QString("Otwarty port: %1").arg(ui.cb_serial_port->currentText()));
        insertLogEntry(QString("Szybkość transmisji %1 bodów").arg(ui.cb_port_speed->currentText()));
        ui.b_chooseUpdateFile->setEnabled(true);
        ui.l_serialStatus->setText("<font color='green'>Otwarty</font>");
    } else {
        ui.b_chooseUpdateFile->setEnabled(false);
        ui.b_codeUpdate->setEnabled(false);
        insertLogEntry(QString("Problem z otwarciem portu: %1").arg(ui.cb_serial_port->currentText()));
    }

    cut->setPort(port);
}

void MainWindow::closeSerialPort() {
    insertLogEntry(QString("Zamykam port %1").arg(ui.cb_serial_port->currentText()));
    port->close();
    ui.b_chooseUpdateFile->setEnabled(false);
    ui.b_codeUpdate->setEnabled(false);
    ui.l_serialStatus->setText("<font color='black'>Zamknięty</font>");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    closeSerialPort();
    event->accept();
}

void MainWindow::insertLogEntry(QString string,QString color) {
    QListWidgetItem *listItem;
	if (ui.logViewer->count() > 100) {
		delete ui.logViewer->takeItem(0);
	}
	QDateTime now = QDateTime::currentDateTime();
	listItem = new QListWidgetItem(now.toString("hh:mm:ss.zzz").append("  ").append(string));
	listItem->setTextColor(QColor(color));
	ui.logViewer->addItem(listItem);
	//ui.logViewer->addItem(now.toString("<font color='red'>hh:mm:ss.zzz</font>").append("  ").append(string));
	ui.logViewer->scrollToBottom();
}

void MainWindow::insertEventEntry(QString string) {
    //QDateTime now = QDateTime::currentDateTime();
    //ui.eventViewer->addItem(now.toString("yyyy/MM/dd hh:mm").append("  ").append(string));
    ui.eventViewer->addItem(string);
    ui.eventViewer->scrollToBottom();
}

QextSerialPort* MainWindow::getSerialPort(void) {
    return port;
}

void MainWindow::makeActions() {

	connect(ui.m_about, SIGNAL(triggered()), this, SLOT(about()));
	connect(ui.m_loadSettings, SIGNAL(triggered()), this, SLOT(loadSettingsDefault()));
	connect(ui.m_saveSettings, SIGNAL(triggered()), this, SLOT(saveSettingsDefault()));
	connect(ui.m_loadSettingsFromFile, SIGNAL(triggered()), this, SLOT(loadSettingsFromFile()));
	connect(ui.m_saveSettingsToFile, SIGNAL(triggered()), this, SLOT(saveSettingsToFile()));
	connect(ui.b_openPort, SIGNAL(clicked()), this, SLOT(openSerialPort()));
	connect(ui.b_closePort, SIGNAL(clicked()), this, SLOT(closeSerialPort()));
//	connect(ui.b_receiveData, SIGNAL(clicked()), this, SLOT(receiveDataManual()));
//	connect(ui.b_sendData, SIGNAL(clicked()), this, SLOT(sendDataManual()));

	connect(ui.b_refreshStatus, SIGNAL(clicked()), this, SLOT(refreshStatus()));
    connect(ui.b_getAllConfiguration, SIGNAL(clicked()), this, SLOT(getAllConfiguration()));
    connect(ui.b_setAllConfiguration, SIGNAL(clicked()), this, SLOT(setAllConfiguration()));

	connect(ui.b_getDateTime, SIGNAL(clicked()), this, SLOT(getDateTime()));
	connect(ui.b_getTimeDay, SIGNAL(clicked()), this, SLOT(getTimeDay()));
	connect(ui.b_setDateTime, SIGNAL(clicked()), this, SLOT(setDateTime()));
	connect(ui.b_setTimeDay, SIGNAL(clicked()), this, SLOT(setTimeDay()));

	connect(ui.b_clearLog, SIGNAL(clicked()), ui.logViewer, SLOT(clear()));

	connect(&periodicStatusTimer, SIGNAL(timeout()), this, SLOT(refreshStatus()));
	connect(ui.check_periodicStatus, SIGNAL(stateChanged(int)), this, SLOT(togglePeriodicStatus(int)));

    connect(ui.b_chooseUpdateFile, SIGNAL(clicked()), this, SLOT(chooseUpdateFile()));
    connect(ui.b_codeUpdate, SIGNAL(clicked()), cut, SLOT(start()));
	connect(cut, SIGNAL(progress(QString)), this, SLOT(insertLogEntry(QString)));
	connect(cut, SIGNAL(progress(QString,QString)), this, SLOT(insertLogEntry(QString,QString)));
	connect(cut, SIGNAL(startCodeUpdate()), this, SLOT(showUpdateDialog()));

	connect(cut, SIGNAL(started()), &cp, SLOT(stopProcessing()));
	connect(cut, SIGNAL(finished()), &cp, SLOT(startProcessing()));
}

void MainWindow::togglePeriodicStatus(int state) {
	if (state == Qt::Checked) {
	  periodicStatusTimer.start(ui.spin_periodicStatusInterval->value()*1000);
	} else {
	  periodicStatusTimer.stop();
	}
}

//void MainWindow::togglePeriodicRead(int state) {
//	if (state == Qt::Checked) {
//	  periodicReadTimer.start(ui.spin_periodicReadInterval->value()*1000);
//	} else {
//	  periodicReadTimer.stop();
//	}
//}

void MainWindow::refreshStatus(void) {
    cp.sessionStart();
    //ui.b_refreshStatus->setEnabled(false);
	getDateTime();
	getTemp();
	getOut();
	getAlarm();
	getTopOff();
    cp.sessionFillingStop();
}

void MainWindow::getAllConfiguration(void) {
    cp.sessionStart();
    getOutSettings();
    getTempSettings();
    getTimeDay();
    getTimers();
    getTimersv();
    getTopOff();
    cp.sessionFillingStop();
}

void MainWindow::setAllConfiguration(void) {
    cp.sessionStart();
    setOutSettings();
    setTempSettings();
    setTimeDay();
    setTimers();
    setTimersv();
    setTopOff();
    cp.sessionFillingStop();
}


void MainWindow::updateStatusBar(const char* text) {
	statusBar()->showMessage(tr(text));
}

void MainWindow::updateStatusBar(QString text) {
	updateStatusBar(text.toAscii().data());
}

void MainWindow::updateProgressBar(int value) {
	ui.progressStatus->setValue(value);
}

void MainWindow::refreshThreadStarted() {
	updateProgressBar(0);
	ui.b_refreshStatus->setEnabled(false);
}

void MainWindow::refreshThreadFinished() {
	updateProgressBar(100);
	ui.b_refreshStatus->setEnabled(true);
}

void MainWindow::log(QByteArray *c,const char* title,int count) {
	QString s = QString(tr(title));

	for (int i=0;i<c->count();i++) {
		s.append(QString("%1").arg((uchar)c->at(i)));
		s.append((QString("(%1)-").arg((uchar)c->at(i),2,16,QLatin1Char('0'))).toUpper());
	}
	s.append("END ");
    s.append(QString(tr(" %1/%2 bajt(y/ów)")).arg(count).arg(c->count()));
	insertLogEntry(s);
}

void MainWindow::logStatus(const char* title,int status) {
	QString s;
	QTextStream out(&s);
	out << tr(title) << tr(" status: ") << status;
	insertLogEntry(s);
}

//void MainWindow::receiveDataManual() {
//    if (cp.receiveCommandQueueCount()) {
//        Command c = cp.fromQueue();
//    } else {
//        insertLogEntry(tr("Brak komend do odebrania"));
//        insertLogEntry((QString("Pozostała ilość danych w buforze - %1 bajtów").arg(cp.receivedBufferCount())));
//    }
//}

//void MainWindow::sendDataManual() {
//	if (ui.e_dataToSend->text().size() > 0) {
//                cp.toQueue(Command(ui.e_dataToSend->text()));
//                if (ui.c_clearAfterSent->isChecked()) {
//                        ui.e_dataToSend->clear();
//                }
//	} else {
//            insertLogEntry(tr("brak danych do wysłania"));
//	}
//}

void MainWindow::loadSettings(QSettings* settings)
{
    if(settings->contains("version")) {

    ui.e_timeDayFrom->setTime(QTime::fromString(settings->value("dayFrom").toString(),"hh:mm"));
    ui.e_timeDayTo->setTime(QTime::fromString(settings->value("dayTo").toString(),"hh:mm"));

	settings->beginGroup("Comunication");
	ui.cb_serial_port->setCurrentIndex(ui.cb_serial_port->findText(settings->value("serialPort").toString()));
	ui.check_periodicStatus->setChecked(settings->value("pperiodicStatusReadEnable").toBool());
	ui.spin_periodicReadInterval->setValue(settings->value("periodicReadInterval").toInt());
	ui.spin_periodicStatusInterval->setValue(settings->value("periodicStatusReadInterval").toInt());
	ui.cb_port_speed->setCurrentIndex(ui.cb_port_speed->findText(settings->value("portSpeed").toString()));
	settings->endGroup();

    settings->beginGroup("TopOff");
    ui.topOff_block->setChecked(settings->value("topOffBlock").toBool());
    ui.topOff_block_min_ro->setChecked(settings->value("topOffBlockMinRo").toBool());
    topOffOut->set(settings->value("topOffOut").toInt());
    ui.topOff_max_run->setValue(settings->value("topOffMaxRun").toInt());
    settings->endGroup();

    settings->beginReadArray("TemperatureSensors");
    for (int i = 0; i < TEMP_SENSORS_NUM; i++) {
     	settings->setArrayIndex(i);
     	pTempSettings[i]->setActive(settings->value("active").toBool());
     	pTempSettings[i]->setRomSerial(settings->value("romSerial").toString());
     	pTempSettings[i]->setTargetTemp(Temperature(settings->value("targetTemp").toDouble()));
     	pTempSettings[i]->setTargetNightTemp(Temperature(settings->value("targetNightTemp").toDouble()));
        pTempSettings[i]->setMinTemp(Temperature(settings->value("minTemp").toDouble()));
        pTempSettings[i]->setMaxTemp(Temperature(settings->value("maxTemp").toDouble()));
        pTempSettings[i]->setHisteresis(Temperature(settings->value("histeresis").toDouble()));
        pTempSettings[i]->setOutCooling(settings->value("outCooling").toInt());
        pTempSettings[i]->setOutHeating(settings->value("outHeating").toInt());
    }
    settings->endArray();

	settings->beginReadArray("Outputs");
	for (int i = 0; i < OUTPUTS_NUM; i++) {
     	settings->setArrayIndex(i);
     	pOutSettings[i]->setLabel(settings->value("name","?????").toString());
     	pOutSettings[i]->setQButton(settings->value("qb").toInt());
     	if (settings->value("block").toBool()) {
     	    pOutSettings[i]->block();
     	}
 	}
 	settings->endArray();

 	pwmLoadSettings(settings);

 	settings->beginReadArray("Timers");
	for (int i = 0; i < TIMERS_NUM; i++) {
     	settings->setArrayIndex(i);
     	if (settings->value("active").toBool()) {
     	    pTimersSettings[i]->enable();
     	}
     	pTimersSettings[i]->setWday(settings->value("wday").toInt());
     	pTimersSettings[i]->setOut(settings->value("out").toInt());
        pTimersSettings[i]->setTimeFrom(QTime::fromString(settings->value("from").toString(),"hh:mm"));
        pTimersSettings[i]->setTimeTo(QTime::fromString(settings->value("to").toString(),"hh:mm"));
 	}
 	settings->endArray();

 	settings->beginReadArray("TimersV");
	for (int i = 0; i < TIMERSV_NUM; i++) {
     	settings->setArrayIndex(i);
     	if (settings->value("active").toBool()) {
     	    pTimersvSettings[i]->enable();
     	}
     	pTimersvSettings[i]->setTimeOff(settings->value("off").toInt());
     	pTimersvSettings[i]->setTimeOn(settings->value("on").toInt());
     	pTimersvSettings[i]->setOut(settings->value("out").toInt());
 	}
 	settings->endArray();

    insertLogEntry(tr("Konfiguracja załadowana z pliku: ")+settings->fileName());
    statusBar()->showMessage(tr("Konfiguracja załadowana z pliku: ")+settings->fileName());
    } else {
        insertLogEntry(tr("Plik z konfiguracją nie istnieje lub błędny format pliku"));
        statusBar()->showMessage(tr("Plik z konfiguracją nie istnieje lub błędny format pliku"));
    }
 }

void MainWindow::saveSettings(QSettings* settings)
{
    settings->setValue("version",PROJECT_VERSION);
    settings->setValue("dayFrom",ui.e_timeDayFrom->time().toString("hh:mm"));
    settings->setValue("dayTo",ui.e_timeDayTo->time().toString("hh:mm"));

    settings->beginGroup("TopOff");
    settings->setValue("topOffBlock", ui.topOff_block->isChecked());
    settings->setValue("topOffBlockMinRo", ui.topOff_block_min_ro->isChecked());
    settings->setValue("topOffOut", topOffOut->get());
    settings->setValue("topOffMaxRun", ui.topOff_max_run->value());
    settings->endGroup();

    settings->beginWriteArray("TemperatureSensors");
    for (int i = 0; i < TEMP_SENSORS_NUM; i++) {
     	settings->setArrayIndex(i);
        settings->setValue("active", pTempSettings[i]->isActive());
     	settings->setValue("romSerial", pTempSettings[i]->getRomSerial());
     	settings->setValue("targetTemp",pTempSettings[i]->getTargetTemp().toString());
     	settings->setValue("targetNightTemp",pTempSettings[i]->getTargetNightTemp().toString());
     	settings->setValue("minTemp",pTempSettings[i]->getMinTemp().toString());
     	settings->setValue("maxTemp",pTempSettings[i]->getMaxTemp().toString());
     	settings->setValue("histeresis",pTempSettings[i]->getHisteresis().toString());
     	settings->setValue("outCooling", pTempSettings[i]->getOutCooling());
     	settings->setValue("outHeating", pTempSettings[i]->getOutHeating());
    }
    settings->endArray();

	settings->beginGroup("Comunication");
	settings->setValue("serialPort", ui.cb_serial_port->currentText());
	settings->setValue("portSpeed", ui.cb_port_speed->currentText());
	settings->setValue("periodicReadInterval",ui.spin_periodicReadInterval->value());
	settings->setValue("periodicStatusReadInterval",ui.spin_periodicStatusInterval->value());
	settings->setValue("periodicStatusReadEnable",ui.check_periodicStatus->checkState());
	settings->endGroup();

    settings->beginWriteArray("Outputs");
	for (int i = 0; i < OUTPUTS_NUM; i++) {
     	settings->setArrayIndex(i);
     	settings->setValue("name", pOutSettings[i]->getLabel());
     	settings->setValue("qb", pOutSettings[i]->getQButton());
     	settings->setValue("block", pOutSettings[i]->isBlocked());
 	}
 	settings->endArray();

 	pwmSaveSettings(settings);

 	settings->beginWriteArray("Timers");
	for (int i = 0; i < TIMERS_NUM; i++) {
     	settings->setArrayIndex(i);
     	settings->setValue("from", (pTimersSettings[i]->getTimeFrom().toString("hh:mm")));
     	settings->setValue("to", (pTimersSettings[i]->getTimeTo().toString("hh:mm")));
     	settings->setValue("wday", pTimersSettings[i]->getWday());
        settings->setValue("out", pTimersSettings[i]->getOut());
     	settings->setValue("active", pTimersSettings[i]->isActive());
 	}
 	settings->endArray();

    settings->beginWriteArray("TimersV");
	for (int i = 0; i < TIMERSV_NUM; i++) {
     	settings->setArrayIndex(i);
     	settings->setValue("off", (pTimersvSettings[i]->getTimeOff()));
     	settings->setValue("on", (pTimersvSettings[i]->getTimeOn()));
        settings->setValue("out", pTimersvSettings[i]->getOut());
     	settings->setValue("active", pTimersvSettings[i]->isActive());
 	}
 	settings->endArray();

 	statusBar()->showMessage(tr("Konfiguracja zapisana do pliku: ")+settings->fileName());
	insertLogEntry(tr("Konfiguracja zapisana do pliku: ")+settings->fileName());
}

void MainWindow::loadSettingsDefault() {
    QSettings settings(PROJECT_NAME,PROJECT_NAME);
    loadSettings(&settings);
}

void MainWindow::saveSettingsDefault() {
    QSettings settings(PROJECT_NAME,PROJECT_NAME);
    saveSettings(&settings);
}

void MainWindow::loadSettingsFromFile() {
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Załaduj konfigurację"), ".", tr("Pliki konfiguracyjne (*.ini)"));
    if (!fileName.isEmpty()) {
        QSettings settings(fileName,QSettings::IniFormat);
        loadSettings(&settings);
    }
}

void MainWindow::saveSettingsToFile() {
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,tr("Zapisz konfigurację"), ".", tr("Pliki konfiguracyjne (*.ini)"));
    if (!fileName.isEmpty()) {
        QSettings settings(fileName,QSettings::IniFormat);
        saveSettings(&settings);
    }
}

/** @file mainWindow.cpp
@brief Implementacja głównego okna.

@todo
- tipy dla elementów menu
- klawisz zdalnego resetu
*/
