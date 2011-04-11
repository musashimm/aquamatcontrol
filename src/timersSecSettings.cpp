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
    Foundation, Inc., 59 Timersle Place, Suite 330, Boston, MA  02111-1307  USA

	$Id$
*/

/** @file timersSecSettings.cpp
@brief Implementacja konfiguracji timerów sekundowych.

Komponenty obiektu timersSecSettings:

- c_active    - checkbox
- e_from      - edit time
- s_duration  - czas trwania
- wday        - dzień tygodnia
- out         - przyspisane wyjście
*/

#include <QTime>
#include "timersSecSettings.h"

TimersSecSettings::TimersSecSettings(int id,OutSettings* pouts[],QWidget *parent)
     : QWidget(parent)
{
	ui.setupUi(this);
	this->id=id;
	ui.groupBox->setTitle(QString(tr("Timer sekundowy %1")).arg(id+1));
	wday = new ComboBoxWeekDay(this);
	ui.gridLayout->addWidget(wday,3,1);
	out = new ComboBoxOuts(pouts,this);
	ui.gridLayout->addWidget(out,4,1);
	connect(ui.c_active, SIGNAL(stateChanged(int)), this, SLOT(changeState(int)));
	disable();
}

void TimersSecSettings::changeOutLabel(int id,QString label)  {
	out->changeLabel(id,label);
}

bool TimersSecSettings::isActive() {
    return ui.c_active->isChecked();
}

void TimersSecSettings::changeState(int state) {
	if (state) {
		enable();
		emit enabled();
	} else {
		disable();
		emit disabled();
	}
}

void TimersSecSettings::disable() {
    ui.c_active->setChecked(false);
	ui.e_from->setEnabled(false);
	ui.s_duration->setEnabled(false);
	wday->setEnabled(false);
	out->setEnabled(false);
}

void TimersSecSettings::enable() {
    ui.c_active->setChecked(true);
	ui.e_from->setEnabled(true);
	ui.s_duration->setEnabled(true);
	wday->setEnabled(true);
	out->setEnabled(true);
}


QTime TimersSecSettings::getTimeFrom() {
	return ui.e_from->time();
}

int TimersSecSettings::getDuration() {
	return ui.s_duration->value();
}

void TimersSecSettings::setTimeFrom(QTime t) {
	ui.e_from->setTime(t);
}

void TimersSecSettings::setTimeFrom(int hours,int minutes) {
	QTime time(hours,minutes);
	setTimeFrom(time);
}

void TimersSecSettings::setDuration(int value) {
	ui.s_duration->setValue(value);
}

int TimersSecSettings::getOut() {
	return out->get();
}

void TimersSecSettings::setOut(int id) {
	out->set(id);
}

int TimersSecSettings::getWday() {
	return wday->get();
}

void TimersSecSettings::setWday(int id) {
	wday->set(id);
}

void TimersSecSettings::setActive() {
	ui.c_active->setChecked(true);
}

void TimersSecSettings::setInActive() {
	ui.c_active->setChecked(false);
}

void TimersSecSettings::setFlags(int flags) {
	if (!(flags & _BV(TIMERS_FLAG_BLOCKED))) {
		ui.c_active->setChecked(true);
	}
	setWday((flags & TIMERSSEC_FLAG_WDAY_MASK) >> 1);
}

int TimersSecSettings::getFlags() {
	int wday = getWday();

	if (ui.c_active->isChecked()) {
		return wday << 1;
	} else {
		return wday << 1 | _BV(TIMERS_FLAG_BLOCKED);
	}
}

void TimersSecSettings::newSettings(int fromh, int fromm, int duration, int out, int flags) {
	setTimeFrom(QTime(fromh,fromm));
	setDuration(duration);
	setOut(out);
	setFlags(flags);
}

QByteArray TimersSecSettings::getSettingsArray() {
    QByteArray a;
	int flags = 0;
	if(!(ui.c_active->isChecked())) {
		flags = 1;
	}
	flags |= getWday() << 1;
	a.append(uchar(id));
	a.append(uchar(getTimeFrom().hour()));
	a.append(uchar(getTimeFrom().minute()));
	a.append(uchar(getDuration()));
	a.append(uchar(getOut()));
	a.append(uchar(flags));
	return a;
}
