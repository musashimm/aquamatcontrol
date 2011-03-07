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

/** @file command.cpp
@brief Implementacja klasy komend
*/

#include "command.h"
#include "commandsDefs.h"
#include "commonDefs.h"

Command::Command() {
	prepareCommon();
}

Command::Command(uchar c,uchar subc) {
	QByteArray::clear();
	QByteArray::append(c);
	QByteArray::append(subc);
	prepareCommon();
}

Command::Command(QString raw) {
    QByteArray::append(raw);
    prepareCommon();
}

QString Command::getCDesc(uchar id) {
	if (commandsDesc.contains(id)) {
		return commandsDesc[id];
	} else {
		return QString("Brak/%1").arg(id, 0, 16);

	}
}

QString Command::getSDesc(uchar id) {
	if (subcommandsDesc.contains(id)) {
		return subcommandsDesc[id];
	} else {
		return QString("Brak/%1").arg(id, 0, 16);
	}
}

QString Command::getStatusDesc(uchar id) {
	if (statusDesc.contains(id)) {
		return statusDesc[id];
	} else {
		return QString("Brak/%1").arg(id, 0, 16);
	}
}

void Command::prepareCommon() {
	iindex=2;
	crc=0;
	commandsDesc[GUI_STATUS_COMMAND]="Status";
	commandsDesc[GUI_DATETIME_COMMAND]="DateTime";
	commandsDesc[GUI_DAYTIME_COMMAND]="DayTime";
	commandsDesc[GUI_TEMP_COMMAND]="Temp";
	commandsDesc[GUI_ALARM_COMMAND]="Alarm";
	commandsDesc[GUI_OUT_COMMAND]="Out";
	commandsDesc[GUI_TIMERS_COMMAND]="Timers";
	commandsDesc[GUI_TIMERSV_COMMAND]="TimersV";
	commandsDesc[GUI_TOP_OFF_COMMAND]="TopOff";
	commandsDesc[GUI_LOG_COMMAND]="Log";
	commandsDesc[GUI_PWM_COMMAND]="Pwm";

	subcommandsDesc[GUI_SUBCOMMAND_GET_STATUS]="GetStatus";
	subcommandsDesc[GUI_SUBCOMMAND_GET_STATUS_RESPONSE]="GetStatusRes";
	subcommandsDesc[GUI_SUBCOMMAND_SET]="Set";
	subcommandsDesc[GUI_SUBCOMMAND_CLEAR]="Clear";
	subcommandsDesc[GUI_SUBCOMMAND_GET_SETTINGS]="GetSettings";
	subcommandsDesc[GUI_SUBCOMMAND_GET_SETTINGS_RESPONSE]="GetSettingsRes";
	//subcommandsDesc[GUI_SUBCOMMAND_SET_NAME]="SetName";
	subcommandsDesc[GUI_SUBCOMMAND_SET_STATE]="SetState";
	subcommandsDesc[GUI_SUBCOMMAND_SET_BLOCK]="SetBlock";
	subcommandsDesc[GUI_SUBCOMMAND_SET_STATE_ALL]="SetStateAll";
	subcommandsDesc[GUI_SUBCOMMAND_SET_BLOCK_ALL]="SetBlockAll";
	subcommandsDesc[GUI_SUBCOMMAND_DISCOVER]="Discover";
	subcommandsDesc[GUI_SUBCOMMAND_DISCOVER_RESPONSE]="DiscoverRes";

	statusDesc[GUI_BUFFER_FULL]="BufferFull";
	statusDesc[GUI_UNKONWN_COMMAND]="UnknownCommand";
	statusDesc[GUI_CLIENT_PRESENT]="ClientPresent";
	statusDesc[GUI_COMMAND_OK]="CommandOk";
	statusDesc[GUI_COMMAND_CKSUM_ERROR]="CrcError";
	statusDesc[GUI_COMMAND_PARAMS_ERROR]="ParamsError";
	statusDesc[GUI_EMPTY_RES]="NoData";
}

Command& Command::operator= (QByteArray ba) {
	this->QByteArray::operator=(ba);
	return *this;
}

QByteRef Command::operator[] (int index) {
	return QByteArray::operator[](index);
}


void Command::resetIndex(void) {
	iindex=2;
}

int Command::isNext() {
	if (iindex > size()) {
		return false;
	} else {
		return true;
	}
}

uchar Command::first() {
	resetIndex();
	return next();
}

uchar Command::next() {
	uchar first;
	if (!(isNext())) {
		return UINT8_T_DISABLED;
	}
	first = this->at(iindex);
	iindex++;
	if (first == GUI_EXTEND_BYTE) {
		first = this->at(iindex);
		iindex++;
		return (first | GUI_EXTEND_BYTE);
	} else {
		return first;
	}
}

void Command::add(uchar byte) {
	if (byte >= GUI_EXTEND_BYTE) {
		this->append(GUI_EXTEND_BYTE);
		this->append(byte & 0x7F);
	} else {
		this->append(byte);
	}
}

QByteArray Command::next(int count) {
    QByteArray a;
	for (int i=0;i<count;i++) {
        a.append(this->next());
	}
    return a;
}

uchar Command::getCommand() {
	return QByteArray::operator[](0);
}

uchar Command::getSubCommand() {
	return QByteArray::operator[](1);
}

uchar Command::getReceivedCrc() {
    if ( size() >= 4 ) {
        return at(size()-2);
    } else {
        return UINT8_T_DISABLED;
    }
}

uchar Command::getCalculatedCrc() {
	return crc;
}

void Command::calculateCrc() {
	crc = 0;
	if ((uchar)this->at(size()-1) == GUI_END_OF_COMMAND) {
		for (int i=0;i<size()-2;i++) {
			crc = crc xor (uchar)this->at(i);
		}
	} else {
		for (int i=0;i<size();i++) {
			crc = crc xor (uchar)this->at(i);
		}
	}
}

bool Command::isValid() {
        calculateCrc();
        if (crc == getReceivedCrc()) {
            return true;
        } else {
            return false;
        }
}

QString Command::toString() {
	QString s = "Komenda: ";
	s.append(QString("(%1) ").arg(getCDesc(at(0))));
	if ((uchar)at(0) == GUI_STATUS_COMMAND) {
		s.append(QString("(%1) ").arg(getStatusDesc(at(1))));
	} else {
		s.append(QString("(%1) ").arg(getSDesc(at(1))));
	}
	for (int i=2;i<count()-2;i++) {
		s.append(QString("%1").arg((uchar)at(i)));
		s.append((QString("(%1)-").arg((uchar)at(i),2,16,QLatin1Char('0'))).toUpper());
	}
	s.append((QString("CRC(%1)-").arg((uchar)at(count()-2),2,16,QLatin1Char('0'))).toUpper());
	s.append("END ");
	s.append(QString(QObject::tr("%1 bajt(y/ów) ")).arg(count()));
	if (isValid()) {
		s.append("CRC: Ok ");
	} else {
		s.append("CRC: NotOk ");
        s.append((QString(" (%1/%2)").arg(getReceivedCrc(),2,16,QLatin1Char('0')).arg(getCalculatedCrc(),2,16,QLatin1Char('0'))).toUpper());
	}
	return s;
}

int Command::getIindex() {
	return iindex;
}

void Command::end(void) {
	calculateCrc();
	this->append(crc);
	this->append(GUI_END_OF_COMMAND);
}
