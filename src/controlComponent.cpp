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

/** @file controlComponent.cpp
@brief Implementacja klasy bazowej dla wszystkich komponentów.
*/

#include <QWidget>
#include "controlComponent.h"

ControlComponent::ControlComponent(int id, QString name, QWidget *parent):QWidget(parent) {
  	//ui.setupUi(this);
  	this->id=id;
  	this->name=name;
//	ui.edit_name->setText(name);
//	nameChangedFlag = false;
//	ui.groupBox->setTitle(QString(tr("Wyjście PWM %1")).arg(id+1));
//	pwmChanged(ui.dial->value());
//	connect(ui.checkBox_blocked, SIGNAL(clicked()), this, SLOT(stateChanged()));
//	connect(ui.edit_name,SIGNAL(editingFinished()), this, SLOT(nameChanged()));
//	connect(ui.dial,SIGNAL(valueChanged(int)), this, SLOT(pwmChanged(int)));
//
//	timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(checkPwmChange()));
//	timer->start(1000);
}

int ControlComponent::getId() {
    return id;
}

bool ControlComponent::wasNameModified() {
    return wasNameModifiedFlag;
}

bool ControlComponent::wasModified() {
    return wasModifiedFlag;
}

QString ControlComponent::getName() {
    wasNameModifiedFlag = false;
    return name;
}

void ControlComponent::setName(QString name) {
    this->name = name;
    wasNameModifiedFlag = true;
}
//

//
//void PwmSettings::pwmChanged(int value) {
//	ui.dial_label->setText(QString(tr("%1%").arg(value)));
//}
//
//void PwmSettings::nameChanged() {
//    nameChangedFlag = true;
//}
//
//bool PwmSettings::isNameChanged() {
//    return nameChangedFlag;
//}
//
//void PwmSettings::checkPwmChange() {
//	if (oldpwm != ui.dial->value()) {
//		oldpwm = ui.dial->value();
//		stateChanged();
//	}
//}
//
//void PwmSettings::stateChanged() {
//	int flags = 0;
//	if(ui.checkBox_blocked->isChecked()) {
//		flags = 1;
//	}
//	emit stateChanged(this->id,ui.dial->value(),flags);
//}
//
//void PwmSettings::newSettings(int pwm,int flags,QString name) {
//    if (name != NULL) {
//		setName(name);
//	}
//	setPwm(pwm);
//	setFlags(flags);
//}
//
//QByteArray PwmSettings::getSettingsArray() {
//	QByteArray a;
//	int flags = 0;
//	QString s(NAME_LENGTH,' ');
//
//	if(ui.checkBox_blocked->isChecked()) {
//		flags = 1;
//	}
//
//	s.replace(0,ui.edit_name->text().size(),ui.edit_name->text());
//	nameChangedFlag = false;
//
//	a.append(uchar(id));
//	a.append(uchar(ui.dial->value()));
//	a.append(uchar(flags));
//	a.append(s);
//
//	return a;
//}
//
//QString PwmSettings::getName() {
// 	return ui.edit_name->text();
//}
//
//void PwmSettings::setName(QString name) {
//	ui.edit_name->setText(name);
//}
//
//bool PwmSettings::isBlocked() {
//    if(ui.checkBox_blocked->isChecked()) {
//		return true;
//	} else {
//        return false;
//	}
//}
//
//void PwmSettings::setFlags(int flags) {
//	if (flags & _BV(PWM_FLAG_BLOCKED)) {
//		ui.checkBox_blocked->setChecked(true);
//	} else {
//		ui.checkBox_blocked->setChecked(false);
//	}
//}
//
//int PwmSettings::getPwm() {
//    return ui.dial->value();
//}
//
//void PwmSettings::setPwm(int pwm) {
//	oldpwm=pwm;
//	ui.dial->setValue(pwm);
//	pwmChanged(pwm);
//}
