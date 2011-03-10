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

/** @file pwmSettings.cpp
@brief Implementacja konfiguracji wyjść PWM.
*/

#include "pwmSettings.h"
#include "main.h"

PwmSettings::PwmSettings(int id,QString name, QWidget *parent)
     : QWidget(parent)
{
  	ui.setupUi(this);
  	this->id=id;
	ui.edit_name->setText(name);
	ui.groupBox->setTitle(QString(tr("Wyjście PWM %1")).arg(id+1));
	dialChanged(ui.dial->value());
	connect(ui.checkBox_blocked, SIGNAL(clicked()), this, SLOT(stateChanged()));
	connect(ui.dial,SIGNAL(sliderReleased()), this, SLOT(stateChanged()));
	connect(ui.dial,SIGNAL(sliderMoved(int)), this, SLOT(dialChanged(int)));
}

void PwmSettings::dialChanged(int value) {
	ui.dial_label->setText(QString(tr("%1%").arg(value)));
}

void PwmSettings::stateChanged() {
	int flags = 0;
	if(ui.checkBox_blocked->isChecked()) {
		flags = 1;
	}
	emit stateChanged(this->id,ui.dial->value(),flags);
}

void PwmSettings::newSettings(int pwm,int flags,QString name) {
    if (name != NULL) {
		ui.edit_name->setText(name);
	}
	ui.dial->setValue(pwm);
	dialChanged(pwm);
	if (flags & _BV(PWM_FLAG_BLOCKED)) {
		ui.checkBox_blocked->setChecked(true);
	} else {
		ui.checkBox_blocked->setChecked(false);
	}
}

QByteArray PwmSettings::getSettingsArray() {
	QByteArray a;
	int flags = 0;
	QString s(NAME_LENGTH,' ');

	if(ui.checkBox_blocked->isChecked()) {
		flags = 1;
	}

	s.replace(0,ui.edit_name->text().size(),ui.edit_name->text());

	a.append(uchar(id));
	a.append(uchar(ui.dial->value()));
	a.append(uchar(flags));
	a.append(s);

	return a;
}

QString PwmSettings::getName() {
 	return ui.edit_name->text();
}

bool PwmSettings::isBlocked() {
    if(ui.checkBox_blocked->isChecked()) {
		return true;
	} else {
        return false;
	}
}

int PwmSettings::getPwm() {
    return ui.dial->value();
}
