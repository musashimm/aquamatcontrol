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

/** @file commandProcessor.cpp
@brief Implementacja klasy procesora komend
*/

#include "commandProcessor.h"
#include "mainWindow.h"

/** @todo
- odbieranie w oddzielnym wątku
- poprawić statusy na status barze
*/

CommandProcessor::CommandProcessor() {
    transmitTimer.start(TRANSMIT_INTERVAL);
    receiveTimer.start(RECEIVE_INTERVAL);
    connect(&transmitTimer, SIGNAL(timeout()), this, SLOT(transmit()));
    connect(&receiveTimer, SIGNAL(timeout()), this, SLOT(receive()));
}

CommandProcessor::CommandProcessor(int transmitInterval,int receiveInterval) {
    transmitTimer.start(transmitInterval);
    receiveTimer.start(receiveInterval);
    connect(&transmitTimer, SIGNAL(timeout()), this, SLOT(transmit()));
    connect(&receiveTimer, SIGNAL(timeout()), this, SLOT(receive()));
}

void CommandProcessor::stopProcessing() {
    transmitTimer.stop();
    receiveTimer.stop();
    parent->getSerialPort()->readAll();
    parent->insertLogEntry(QString("+++++ ").append("Zatrzymanie procesowania statusu"),"blue");
}

void CommandProcessor::startProcessing() {
    transmitTimer.start(TRANSMIT_INTERVAL);
    receiveTimer.start(RECEIVE_INTERVAL);
    parent->insertLogEntry(QString("+++++ ").append("Wznowienie procesowania statusu"),"blue");
}

void CommandProcessor::setParent(MainWindow* parent) {
	this->parent = parent;
}

void CommandProcessor::changeIntervals(int transmitInterval,int receiveInterval) {
    transmitTimer.start(transmitInterval);
    receiveTimer.start(receiveInterval);
}

void CommandProcessor::transmit() {
	Command c;
    qint64 bytesTransmitted = 0;
    if(!transmitCommandQueue.isEmpty()) {
        c = transmitCommandQueue.dequeue();
        bytesTransmitted = parent->getSerialPort()->write(c);
        parent->log(&c,"<<<<< ",bytesTransmitted);
	}
}

void CommandProcessor::toQueue(Command command) {
    transmitCommandQueue.enqueue(command);
	parent->insertLogEntry(QString("<<<<< ").append(command.toString()),"blue");
    parent->insertLogEntry(QString("Kolejka: %1 komend").arg(transmitCommandQueue.count()));
    putToSession(&command);
}

Command CommandProcessor::fromQueue() {
    Command c = receiveCommandQueue.dequeue();
    if (c.isValid()) {
        parent->insertLogEntry(QString("***** ").append(c.toString()),"blue");
    } else {
        parent->insertLogEntry(QString("***** ").append(c.toString()),"red");
    }
    parent->insertLogEntry(QString("Kolejka: %1 komend").arg(receiveCommandQueue.count()));
    return c;
}

int CommandProcessor::receiveCommandQueueCount() {
    return receiveCommandQueue.size();
}

int CommandProcessor::receivedBufferCount() {
    return received.size();
}


void CommandProcessor::receive(void) {
	int kon=0;
	Command command;
	QByteArray receivedData;
    receivedData = parent->getSerialPort()->readAll();

	while (receivedData.count() > 0) {

        if (received.count() > MAX_SIZE_RECEIVED_BUFFER) {
            parent->insertLogEntry(tr("Czyszczenie received"));
            received.clear();
        }

		received.append(receivedData);
		parent->log(&received,">>>>>  ",receivedData.count());

		while (received.indexOf(GUI_END_OF_COMMAND) != -1) {
			kon=received.indexOf(GUI_END_OF_COMMAND);
			command = received.left(kon+1);
			received.remove(0,kon+1);
			//parent->log(&command,"Komenda: ",kon+1);
            //receiveCommandQueue.enqueue(command);
            if (receiveCommandQueue.size() > MAX_SIZE_RECEIVE_COMMAND_QUEUE) {
                parent->insertLogEntry(tr("Czyszczenie receiveCommandQueue"));
                receiveCommandQueue.clear();
            }
            if (command.isValid()) {
                parent->insertLogEntry(QString(">>>>> ").append(command.toString()),"green");
            } else {
                parent->insertLogEntry(QString(">>>>> ").append(command.toString()),"red");
            }
			processCommand(&command);
			//parent->log(&received,"Bufor: ",received.size());
		}
        receivedData = parent->getSerialPort()->readAll();
    }
}

void CommandProcessor::processCommand (Command* c) {
	if (!c->isValid()) {
		return;
	}
    putToReceivedSession(c);
	switch(c->getCommand()) {
		//=======================================================================================
		case GUI_LOG_COMMAND: analyzeEventResponse(c);
			break;
		//=======================================================================================
		case GUI_TIMERSV_COMMAND: analyzeTimersvResponse(c);
			break;
		//=======================================================================================
		case GUI_TIMERS_COMMAND: analyzeTimersResponse(c);
			break;
		//=======================================================================================
		case GUI_STATUS_COMMAND: analyzeStatusResponse(c);
			break;
		//=======================================================================================
		case GUI_ALARM_COMMAND: analyzeAlarmStatusResponse(c);
			break;
    //=======================================================================================
		case GUI_DATETIME_COMMAND: parent->setUiDateTime(c);
			break;
		//=======================================================================================
		case GUI_DAYTIME_COMMAND: parent->setUiTimeDay(c);
			break;
		//=======================================================================================
		case GUI_TEMP_COMMAND:
			switch(c->getSubCommand()) {
				case GUI_SUBCOMMAND_GET_STATUS_RESPONSE: analyzeTempStatusResponse(c);
													break;
				case GUI_SUBCOMMAND_GET_SETTINGS_RESPONSE: analyzeTempSettingsResponse(c);
													break;
				case GUI_SUBCOMMAND_DISCOVER_RESPONSE: analyzeTempDiscoverResponse(c);
													break;
			}
			break;
		//=======================================================================================
		case GUI_OUT_COMMAND:
			switch(c->getSubCommand()) {
				case GUI_SUBCOMMAND_GET_STATUS_RESPONSE:
					c->resetIndex();
					for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
						parent->setUiOutState(i,c->next());
					}
					break;
				case GUI_SUBCOMMAND_GET_SETTINGS_RESPONSE:
					c->resetIndex();
					for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
						parent->setUiOutState(i,c->next());
						parent->setUiOutLabel(i,c->next(5));
					}
					break;
			}
			break;
        	//=======================================================================================
            case GUI_PWM:
			switch(c->getSub()) {
				case GUI_GET:
					c->resetIndex();
					for (int i=0;i<PWM_NUM;i++) {
						parent->getPwmSetting(i)->setPwm(c->next());
						parent->getPwmSetting(i)->setFlags(c->next());
						if (c->hasExtra()) {
							parent->getPwmSetting(i)->setName(c->next(5));
						}
					}
					break;
			}
			break;
		//========================================================================================
		case GUI_TOP_OFF_COMMAND:
			parent->setUiTopOff(c);
			break;
		//========================================================================================
		default: parent->insertLogEntry(QString(QObject::tr("Odebrano nierozpoznaną komendę (%1) (%2)")).arg(c->getCommand(),2,16,QLatin1Char('0')).arg(c->getSubCommand(),2,16,QLatin1Char('0')));
			break;
	}
}

void CommandProcessor::analyzeAlarmStatusResponse(Command *c) {
	parent->setUiAlarms(c->first());
	parent->changeAlarmTitle(c->next());
}

void CommandProcessor::analyzeStatusResponse(Command *c) {
	int main,major,minor,cres,sres;
	QString text;
	int sub = c->getSubCommand();
	switch(sub) {
		case GUI_CLIENT_PRESENT:
				main=c->first();
				major=c->next();
				minor=c->next();
				text = QString("Sterownik aktywny (wersja: %1.%2.%3)").arg(main).arg(major).arg(minor);
				text.append(QDateTime::currentDateTime().toString(" - yyyy/MM/dd hh:mm"));
				parent->statusBar()->showMessage(text);
			break;
 		case GUI_UNKONWN_COMMAND:
		case GUI_BUFFER_FULL:
		case GUI_COMMAND_CKSUM_ERROR:
		case GUI_COMMAND_PARAMS_ERROR:
			break;
		case GUI_COMMAND_OK:
			cres=c->first();
			sres=c->next();
			if (cres == GUI_LOG_COMMAND) {
				if (sres == GUI_SUBCOMMAND_GET_STATUS) {
					parent->insertEventEntry(tr("Koniec historii zdarzeń"));
					parent->enableGetEvents();
				} else if (sres == GUI_SUBCOMMAND_CLEAR) {
					parent->enableClearEvents();
				}

			}
			if (sres == GUI_SUBCOMMAND_SET) {
				parent->statusBar()->showMessage(tr("Ustawienia wysłane"));
			}
			if (sres == GUI_SUBCOMMAND_GET_SETTINGS) {
				parent->statusBar()->showMessage(tr("Ustawienia pobrane"));
			}
			if (sres == GUI_SUBCOMMAND_GET_STATUS) {
				parent->statusBar()->showMessage(tr("Status pobrany"));
			}
			break;
		case GUI_EMPTY_RES:
			parent->insertEventEntry(tr("Brak zdarzeń w historii"));
			parent->enableGetEvents();
			break;
		default: parent->insertLogEntry(QString("Nierozpoznany status ").append(paramsReceived(c)));
	}
}

QString CommandProcessor::paramsReceived(Command *c) {
	int rcomm,rsubcomm;
	rcomm = c->first();
	rsubcomm = c->next();
	return QString("(%1) (%2)").arg(rcomm,2,16,QLatin1Char('0')).arg(rsubcomm,2,16,QLatin1Char('0'));
}

void CommandProcessor::analyzeTempDiscoverResponse(Command *c) {
	int id = c->first();
    parent->getPTemp(id)->setRomSerial(c->next(8));
}

void CommandProcessor::analyzeTempStatusResponse(Command *c) {
	int id = c->first();
	int tens = c->next();
	int units = c->next();
	int flags = c->next();
	int br = c->next();
	parent->getPTemp(id)->setStatus(tens,units,flags,br);
}

void CommandProcessor::analyzeTempSettingsResponse(Command *c) {
	int id = c->first();
	int tens = c->next();
	int units = c->next();
	int tens_target = c->next();
	int units_target = c->next();
	int tens_target_night = c->next();
	int units_target_night = c->next();
	int tens_max = c->next();
	int units_max = c->next();
	int tens_min = c->next();
	int units_min = c->next();
	int histeresis = c->next();
	int flags = c->next();
	int br = c->next();
	int out_cooling = c->next();
	int out_heating = c->next();
	parent->getPTemp(id)->setTargetTemp(Temperature(tens_target,units_target));
	parent->getPTemp(id)->setTargetNightTemp(Temperature(tens_target_night,units_target_night));
	parent->getPTemp(id)->setMinTemp(Temperature(tens_min,units_min));
	parent->getPTemp(id)->setMaxTemp(Temperature(tens_max,units_max));
	parent->getPTemp(id)->setHisteresis(Temperature(0,histeresis));
	parent->getPTemp(id)->setStatus(tens,units,flags,br);
	parent->getPTemp(id)->setOutCooling(out_cooling);
	parent->getPTemp(id)->setOutHeating(out_heating);
}

void CommandProcessor::analyzeEventResponse(Command *c) {
	int year = c->first();
	int monthtype = c->next();
	int day = c->next();
	int hours = c->next();
	int minutes = c->next();
	int value1 = c->next();
	int value2 = c->next();
	int value3 = c->next();
	parent->addEvent(year,monthtype,day,hours,minutes,value1,value2,value3);
}

void CommandProcessor::analyzeTimersvResponse(Command *c) {
	int id = c->first();
	int off = c->next();
	int on = c->next();
	int out = c->next();
	int flags = c->next();
	parent->getPTimersv(id)->set(on,off,out,flags);
}

void CommandProcessor::analyzeTimersResponse(Command *c) {
	int id = c->first();
	int fromh = c->next();
	int fromm = c->next();
	int toh = c->next();
	int tom = c->next();
	int out = c->next();
	int flags = c->next();
	parent->getPTimers(id)->set(fromh,fromm,toh,tom,out,flags);
}


int CommandProcessor::getSessionSize() {
    return commandsSession.size();
}

void CommandProcessor::putToSession(Command* pc) {
    if (commandsSessionFilling) {
        if (commandsSession.contains(pc->getCommand())) {
            commandsSession[pc->getCommand()]++;
        } else {
            commandsSession.insert(pc->getCommand(),1);
            commandsReceivedSession.insert(pc->getCommand(),0);
        }
    }
}

void CommandProcessor::putToReceivedSession(Command* pc) {
    if (commandsSessionInProgress) {
        if (commandsReceivedSession.contains(pc->getCommand())) {
            commandsReceivedSession[pc->getCommand()]++;
        }
        parent->updateProgressBar(getSessionProgress());
    }
}

int CommandProcessor::getSessionProgress() {
    double csent=0;
    double creceived=0;
    double progress=0;
    QHashIterator<int, int> i(commandsSession);


    if (commandsSession.isEmpty()) {
        return 0;
    } else {
        while (i.hasNext()) {
            i.next();
            csent+=i.value();

            if (commandsReceivedSession[i.key()] > i.value()) {
                creceived+=i.value();
            } else {
                creceived+=commandsReceivedSession[i.key()];
            }
        }
        if (creceived) {
            progress = (creceived/csent*100);
        }
        return (int)progress;
    }
}

void CommandProcessor::sessionStart() {
    commandsSession.clear();
    commandsReceivedSession.clear();
    commandsSessionFilling=true;
    commandsSessionInProgress=false;
}

void CommandProcessor::sessionFillingStop() {
    commandsSessionFilling=false;
    commandsSessionInProgress=true;
}

