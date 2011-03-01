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

/** @file tempSettings.cpp
@brief Implementacja konfiguracji temperatury
*/

#include "tempSettings.h"
#include <QTextStream>

TempSettings::TempSettings(int id,OutSettings* pouts[],QWidget *parent)
     : QWidget(parent)
{
  ui.setupUi(this);
	this->id=id;
	ui.groupBox->setTitle(QString(tr("Czujnik temp. %1")).arg(id+1));
	outCooling = new ComboBoxOuts(pouts,this);
	ui.layout->insertWidget(10,outCooling);
	outHeating = new ComboBoxOuts(pouts,this);
	ui.layout->insertWidget(11,outHeating);
	connect(ui.check_tempActive, SIGNAL(clicked(bool)), this, SLOT(setActive(bool)));
	deactivate();
}

void TempSettings::changeOutLabel(int id,QString label)  {
	outCooling->changeLabel(id,label);
	outHeating->changeLabel(id,label);
}

bool TempSettings::isActive() {
    return ui.check_tempActive->isChecked();
}

void TempSettings::setCurrentTemp(Temperature t) {
	QString alarms;
	QString tempString = t.toString();
	if (t.isHeating()) {
		tempString.append(" (Grzanie)");
	}
	if (t.isCooling()) {
		tempString.append(tr(" (Chłodzenie)"));
	}
	ui.l_currentTemp->setText(tempString);
	if (t.isActive()) {
		ui.check_tempActive->setChecked(true);
		activate();
		ui.l_tempAlarms->setText(t.getAlarmString());
	} else {
		ui.check_tempActive->setChecked(false);
		deactivate();
	}
	emit currentTempChanged(t);
}

void TempSettings::deactivate() {
        ui.check_tempActive->setChecked(false);
	ui.l_romSerial->setEnabled(false);
	ui.l_flags->setEnabled(false);
	ui.l_tempAlarms->setEnabled(false);
	ui.l_currentTemp->setEnabled(false);
	ui.spin_targetTemp->setEnabled(false);
	ui.spin_targetNightTemp->setEnabled(false);
	ui.spin_maxTemp->setEnabled(false);
	ui.spin_histeresis->setEnabled(false);
	ui.spin_minTemp->setEnabled(false);
	outCooling->setEnabled(false);
	outHeating->setEnabled(false);
}

void TempSettings::activate() {
        ui.check_tempActive->setChecked(true);
	ui.l_romSerial->setEnabled(true);
	ui.l_flags->setEnabled(true);
	ui.l_tempAlarms->setEnabled(true);
	ui.l_currentTemp->setEnabled(true);
	ui.spin_targetTemp->setEnabled(true);
	ui.spin_targetNightTemp->setEnabled(true);
	ui.spin_maxTemp->setEnabled(true);
	ui.spin_histeresis->setEnabled(true);
	ui.spin_minTemp->setEnabled(true);
	outCooling->setEnabled(true);
	outHeating->setEnabled(true);
}

void TempSettings::setActive(bool state) {
	if (state) {
		activate();
		emit activated();
	} else {
		deactivate();
		emit deactivated();
	}
}

void TempSettings::setTargetTemp(Temperature t) {
	if (t.getTens() == UINT8_T_DISABLED || t.getUnits() == UINT8_T_DISABLED ) {
		return;
	}
	ui.spin_targetTemp->setValue(t.getDouble());
}

Temperature TempSettings::getTargetTemp() {
	return Temperature(ui.spin_targetTemp->value());
}

void TempSettings::setTargetNightTemp(Temperature t) {
	if (t.getTens() == UINT8_T_DISABLED || t.getUnits() == UINT8_T_DISABLED ) {
		return;
	}
	ui.spin_targetNightTemp->setValue(t.getDouble());
}

Temperature TempSettings::getTargetNightTemp() {
	return Temperature(ui.spin_targetNightTemp->value());
}

void TempSettings::setMinTemp(Temperature t) {
	if (t.getTens() == UINT8_T_DISABLED || t.getUnits() == UINT8_T_DISABLED ) {
		return;
	}
	ui.spin_minTemp->setValue(t.getDouble());
}

Temperature TempSettings::getMinTemp() {
	return Temperature(ui.spin_minTemp->value());
}

void TempSettings::setMaxTemp(Temperature t) {
	if (t.getTens() == UINT8_T_DISABLED || t.getUnits() == UINT8_T_DISABLED ) {
		return;
	}
	ui.spin_maxTemp->setValue(t.getDouble());
}

Temperature TempSettings::getMaxTemp() {
	return Temperature(ui.spin_maxTemp->value());
}

void TempSettings::setHisteresis(Temperature t) {
	if (t.getTens() == UINT8_T_DISABLED || t.getUnits() == UINT8_T_DISABLED ) {
		return;
	}
	ui.spin_histeresis->setValue(t.getDouble());
}

Temperature TempSettings::getHisteresis() {
	return Temperature(ui.spin_histeresis->value());
}

void TempSettings::setFlagsBr(uchar flags,uchar badreads) {
	QString s = QString("%1").arg(flags,2,16,QLatin1Char('0')).toUpper();
	ui.l_flags->setText(QString("%1h / %2").arg(s).arg(badreads));
}

int TempSettings::getFlags() {
	uchar flags=0;
	if (ui.check_tempActive->isChecked()) {
		flags &= ~_BV(TEMP_SENSOR_ROLE_0);
		flags &= ~_BV(TEMP_SENSOR_ROLE_1);
	} else {
		flags |= _BV(TEMP_SENSOR_ROLE_0);
		flags |= _BV(TEMP_SENSOR_ROLE_1);
	}
	return flags;
}

void TempSettings::setStatus(int tens,int units,int flags,int br) {
	setCurrentTemp(Temperature(tens,units,flags));
	setFlagsBr(flags,br);
}

int TempSettings::getOutCooling() {
	return outCooling->get();
}

void TempSettings::setOutCooling(int id) {
	outCooling->set(id);
}

int TempSettings::getOutHeating() {
	return outHeating->get();
}

void TempSettings::setOutHeating(int id) {
	outHeating->set(id);
}

void TempSettings::setRomSerial(QByteArray rom) {
	QString s="";
	for (int i=0;i<8;i++) {
		s.append(QString("%1").arg((uchar)rom[i],2,16,QLatin1Char('0')));
	}
	ui.l_romSerial->setText(s.toUpper());
}

void TempSettings::setRomSerial(QString rom) {
    ui.l_romSerial->setText(rom.toUpper());
}

QString TempSettings::getRomSerial() {
	return ui.l_romSerial->text();
}
