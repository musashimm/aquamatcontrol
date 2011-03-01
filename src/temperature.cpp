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

/** @file temperature.cpp
@brief Implementacja klasy Temperature
*/

#include "temperature.h"

Temperature::Temperature() {
	this->tens=0;
	this->units=0;
	this->flags=0;
}

Temperature::Temperature(uchar t,uchar u,uchar f) {
	this->tens = t;
	this->units = u;
	this->flags = f;
}

Temperature::Temperature(double temp) {
	double intpart,fractpart;
	this->flags = 0;
	fractpart = modf (temp , &intpart);
	this->tens=((uchar)intpart) >> 4;
	this->units=(uchar)(fractpart*10000/625)|((uchar)intpart) << 4;
}

uchar Temperature::getTens() {
	return tens;
}

uchar Temperature::getUnits() {
	return units;
}

double Temperature::getDouble() {
	return ((tens << 4|units >> 4)+(units & 0x0F)*0.0625);
}

bool Temperature::isActive() {
	if ((flags & TEMP_SENSOR_ROLE_MASK) == TEMP_SENSOR_ROLE_INACTIVE) {
		return false;
	} else {
		return true;
	}
}

QString Temperature::getAlarmString() {
	QString alarms;
	if (flags & _BV(TEMP_SENSOR_STATUS_OK)) {
			if (flags & _BV(TEMP_ALARM_MIN)) {
				alarms.append("Temp. MIN");
			} else if (flags & _BV(TEMP_ALARM_MAX)) {
				alarms.append("Temp. MAX");
			} else {
				alarms.append("Brak");
			}
		} else {
			alarms.append("Uszkodzony");
		}	
	return alarms;
}

bool Temperature::isMin() {
	if (flags & _BV(TEMP_ALARM_MIN)) {
		return true;
	} else {
		return false;
	}
}

bool Temperature::isMax() {
	if (flags & _BV(TEMP_ALARM_MAX)) {
		return true;
	} else {
		return false;
	}
}

bool Temperature::isOk() {
	if (flags & _BV(TEMP_SENSOR_STATUS_OK)) {
		return true;
	} else {
		return false;
	}
}

bool Temperature::isCooling() {
	if (flags & _BV(TEMP_SENSOR_COOLING)) {
		return true;
	} else {
		return false;
	}
}

bool Temperature::isHeating() {
	if (flags & _BV(TEMP_SENSOR_HEATING)) {
		return true;
	} else {
		return false;
	}
}

QString Temperature::toString() {
	return QString("%1").arg(((tens << 4)|(units >> 4))+((units & 0x0F)*0.0625),0,'f',1);
}

