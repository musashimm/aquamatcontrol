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

/** @file sunScenario.cpp
@brief Implementacja scenariusza "Słońce".

Opis funkcjonalności znajduje się w pliku \ref sunScenario.h.

*/

#include "sunScenario.h"
#include "main.h"

SunScenario::SunScenario(int id,QString name,PwmSettings* ppwms[], QWidget *parent):ControlComponent(id,name,parent) {
  	ui.setupUi(this);
  	pwm = new ComboBoxPwms(ppwms,this);
  	ui.outLayout->addWidget(pwm);
}

int SunScenario::getComponentId() {
    return SUN_COMPONENT_ID;
}

QString SunScenario::getComponentDesc() {
    return QString(SUN_COMPONENT_DESC);
}

void SunScenario::changeOutputName(int id, QString newName) {
	pwm->changeName(id,newName);
}

bool SunScenario::isActive() {
    return true;
}

bool SunScenario::isBlocked() {
    return !(isActive());
}

int SunScenario::getFlags() {
    int flags = 0;
    if(ui.keepPower->isChecked()) {
		flags = 1;
	}
	return flags;
}

void SunScenario::setFlags(int flags) {
    if (flags & _BV(KEEP_POWER_FLAG)) {
		ui.keepPower->setChecked(true);
	} else {
		ui.keepPower->setChecked(false);
	}
}

QByteArray SunScenario::getAsArray() {
    QByteArray a;
    a.append(uchar(id));
    a.append(uchar(ui.sunriseTime->time().hour()));
    a.append(uchar(ui.sunriseTime->time().minute()));
    a.append(uchar(ui.sunsetTime->time().hour()));
    a.append(uchar(ui.sunsetTime->time().minute()));
    a.append(uchar(ui.minPower->value()));
    a.append(uchar(ui.maxPower->value()));
    a.append(uchar(ui.numberOfSteps->value()));
    a.append(uchar(ui.stepDuration->value()));
    a.append(uchar(getFlags()));
    return a;
}

void SunScenario::setAsArray(QByteArray params) {
    ui.sunriseTime->setTime(QTime(params[1],params[2],0));
    ui.sunsetTime->setTime(QTime(params[3],params[4],0));
    ui.minPower->setValue(params[5]);
    ui.maxPower->setValue(params[6]);
    ui.numberOfSteps->setValue(params[7]);
    ui.stepDuration->setValue(params[8]);
    setFlags(params[9]);
}

void SunScenario::save(QSettings* s) {
   	s->setArrayIndex(id);
    s->setValue("sunriseTime",ui.sunriseTime->time().toString("hh:mm"));
    s->setValue("sunsetTime",ui.sunsetTime->time().toString("hh:mm"));
    s->setValue("minPower", ui.minPower->value());
    s->setValue("maxPower", ui.maxPower->value());
    s->setValue("numberOfSteps", ui.numberOfSteps->value());
    s->setValue("stepDuration", ui.stepDuration->value());
    s->setValue("keepPower", ui.keepPower->isChecked());
    s->setValue("pwmOutput", pwm->get());
}

void SunScenario::load(QSettings* s) {
    s->setArrayIndex(id);
    ui.sunriseTime->setTime(QTime::fromString(s->value("sunriseTime").toString(),"hh:mm"));
    ui.sunsetTime->setTime(QTime::fromString(s->value("sunsetTime").toString(),"hh:mm"));
    ui.minPower->setValue(s->value("minPower").toInt());
    ui.maxPower->setValue(s->value("maxPower").toInt());
    ui.numberOfSteps->setValue(s->value("numberOfSteps").toInt());
    ui.stepDuration->setValue(s->value("stepDuration").toInt());
    ui.keepPower->setChecked(s->value("keepPower").toBool());
    pwm->set(s->value("pwmOutput").toInt());
}
