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

/** @file timersvSettings.cpp
@brief Implementacja konfiguracji timerów interwałowych.
*/

#include "timersvSettings.h"
#include "comboBoxOuts.h"

TimersvSettings::TimersvSettings(int id,OutSettings* pouts[],QWidget *parent)
     : QWidget(parent)
{
  ui.setupUi(this);
	this->id=id;
	ui.groupBox->setTitle(QString(tr("Timer interwałowy %1")).arg(id+1));
	out = new ComboBoxOuts(pouts,this);
	ui.gridLayout->addWidget(out,3,1);
	connect(ui.c_active, SIGNAL(stateChanged(int)), this, SLOT(changeState(int)));
	disable();
}

void TimersvSettings::changeState(int state) {
	if (state) {
		enable();
		emit enabled();
	} else {
		disable();
		emit disabled();
	}
}

bool TimersvSettings::isActive() {
    return ui.c_active->isChecked();
}

void TimersvSettings::disable() {
    ui.c_active->setChecked(false);
	ui.e_off->setEnabled(false);
	ui.e_on->setEnabled(false);
	out->setEnabled(false);
}

void TimersvSettings::enable() {
    ui.c_active->setChecked(true);
	ui.e_off->setEnabled(true);
	ui.e_on->setEnabled(true);
	out->setEnabled(true);
}

int TimersvSettings::getTimeOff() {
	return ui.e_off->value();
}

int TimersvSettings::getTimeOn() {
	return ui.e_on->value();
}

void TimersvSettings::setTimeOff(int value) {
	ui.e_off->setValue(value);
}

void TimersvSettings::setTimeOn(int value) {
	ui.e_on->setValue(value);
}

void TimersvSettings::changeOutLabel(int id,QString label)  {
	out->changeLabel(id,label);
}

int TimersvSettings::getOut() {
	return out->get();
}

void TimersvSettings::setOut(int id) {
	out->set(id);
}

void TimersvSettings::setActive() {
	ui.c_active->setChecked(true);
}

void TimersvSettings::setInActive() {
	ui.c_active->setChecked(false);
}

int TimersvSettings::getFlags() {
	if (ui.c_active->isChecked()) {
		return 0;
	} else {
		return _BV(TIMERSV_FLAG_BLOCKED);
	}
}

void TimersvSettings::setFlags(int flags) {
	if (!(flags & _BV(TIMERSV_FLAG_BLOCKED))) {
		ui.c_active->setCheckState(Qt::Checked);
	}
}

void TimersvSettings::set(int on,int off, int out, int flags) {
	setTimeOn(on);
	setTimeOff(off);
	setOut(out);
	setFlags(flags);
}
