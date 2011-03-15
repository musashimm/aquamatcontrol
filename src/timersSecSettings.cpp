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
*/

#include <QTime>
#include "timersSecSettings.h"

TimersSecSettings::TimersSecSettings(int id,OutSettings* pouts[],QWidget *parent)
     : QWidget(parent)
{
	ui.setupUi(this);
	this->id=id;
	ui.groupBox->setTitle(QString(tr("Timer sek. %1")).arg(id+1));
	wday = new ComboBoxWeekDay(this);
	ui.gridLayout->addWidget(wday,3,1);
	out = new ComboBoxOuts(pouts,this);
	ui.gridLayout->addWidget(out,4,1);
//	connect(ui.c_active, SIGNAL(stateChanged(int)), this, SLOT(changeState(int)));
//	disable();
}

//void TimersSettings::changeOutLabel(int id,QString label)  {
//	out->changeLabel(id,label);
//}
//
//bool TimersSettings::isActive() {
//    return ui.c_active->isChecked();
//}
//
//void TimersSettings::changeState(int state) {
//	if (state) {
//		enable();
//		emit enabled();
//	} else {
//		disable();
//		emit disabled();
//	}
//}
//
//void TimersSettings::disable() {
//    ui.c_active->setChecked(false);
//	ui.e_from->setEnabled(false);
//	ui.e_to->setEnabled(false);
//	wday->setEnabled(false);
//	out->setEnabled(false);
//}
//
//void TimersSettings::enable() {
//    ui.c_active->setChecked(true);
//	ui.e_from->setEnabled(true);
//	ui.e_to->setEnabled(true);
//	wday->setEnabled(true);
//	out->setEnabled(true);
//}
//
//QTime TimersSettings::getTimeFrom() {
//	return ui.e_from->time();
//}
//
//QTime TimersSettings::getTimeTo() {
//	return ui.e_to->time();
//}
//
//void TimersSettings::setTimeFrom(QTime t) {
//	ui.e_from->setTime(t);
//}
//
//void TimersSettings::setTimeTo(QTime t) {
//	ui.e_to->setTime(t);
//}
//
//void TimersSettings::setTimeFrom(int hours,int minutes) {
//	QTime time(hours,minutes);
//	setTimeFrom(time);
//}
//
//void TimersSettings::setTimeTo(int hours, int minutes) {
//	QTime time(hours,minutes);
//	setTimeTo(time);
//}
//
//int TimersSettings::getOut() {
//	return out->get();
//}
//
//void TimersSettings::setOut(int id) {
//	out->set(id);
//}
//
//int TimersSettings::getWday() {
//	return wday->get();
//}
//
//void TimersSettings::setWday(int id) {
//	wday->set(id);
//}
//
//void TimersSettings::setActive() {
//	ui.c_active->setChecked(true);
//}
//
//void TimersSettings::setInActive() {
//	ui.c_active->setChecked(false);
//}
//
//void TimersSettings::setFlags(int flags) {
//	if (!(flags & _BV(TIMERS_FLAG_BLOCKED))) {
//		ui.c_active->setCheckState(Qt::Checked);
//	}
//	setWday((flags & TIMERS_FLAG_WDAY_MASK) >> 1);
//}
//
//int TimersSettings::getFlags() {
//	int wday = getWday();
//
//	if (ui.c_active->isChecked()) {
//		return wday << 1;
//	} else {
//		return wday << 1 | _BV(TIMERS_FLAG_BLOCKED);
//	}
//}
//
//void TimersSettings::set(int fromh, int fromm, int toh, int tom,int out, int flags) {
//	setTimeFrom(QTime(fromh,fromm));
//	setTimeTo(QTime(toh,tom));
//	setOut(out);
//	setFlags(flags);
//}
//
