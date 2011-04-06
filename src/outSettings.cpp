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

/** @file outSettings.cpp
@brief Implementacja konfiguracji wyjść
*/

#include "outSettings.h"
#include "main.h"

OutSettings::OutSettings(int id,QString label, QWidget *parent)
     : QWidget(parent)
{
  	ui.setupUi(this);
	connect(ui.checkBox_active, SIGNAL(clicked(bool)), this, SLOT(activatedSlot(bool)));
	connect(ui.checkBox_block, SIGNAL(clicked(bool)), this, SLOT(blockedSlot(bool)));
	connect(ui.checkBox_active, SIGNAL(stateChanged(int)), this, SLOT(activatedSlot(int)));
	connect(ui.checkBox_block, SIGNAL(stateChanged(int)), this, SLOT(blockedSlot(int)));
	//connect(ui.b_set, SIGNAL(clicked()), this, SLOT(setSlot()));
	this->id=id;
	this->override=false;
	this->cancel=false;
	this->label=label;
	ui.groupBox->setTitle(QString(tr("Wyj. %1 [%2]")).arg(id+1).arg(label));
	ui.lineEdit_label->setText(label);
	qbutton = new ComboBoxQButtons();
	ui.nameLayout->insertWidget(1,qbutton);
}

void OutSettings::active() {
	ui.checkBox_active->setCheckState(Qt::Checked);
}

void OutSettings::inactive() {
	ui.checkBox_active->setCheckState(Qt::Unchecked);
}

void OutSettings::block()  {
	ui.checkBox_block->setCheckState(Qt::Checked);
}

void OutSettings::unblock() {
	ui.checkBox_block->setCheckState(Qt::Unchecked);
}

bool OutSettings::isBlocked() {
	if (ui.checkBox_block->isChecked()) {
		return true;
	} else {
		return false;
	}
}

int OutSettings::getQButton() {
	return qbutton->get();
}

void OutSettings::setQButton(int number) {
	qbutton->set(number);
}

void OutSettings::setLabel(QString newLabel) {
	this->label=newLabel;
	ui.groupBox->setTitle(QString(tr("Wyj. %1 [%2]")).arg(id+1).arg(newLabel));
	ui.lineEdit_label->setText(newLabel);
	emit labelChanged(id,ui.lineEdit_label->text());
}

QString OutSettings::getLabel() {
 	return label;
}

void OutSettings::setState(uchar b) {
	if (!(b & _BV(OUTPUT_ACTIVE_FLAG))) {
			active();
		} else {
			inactive();
		}
	if (b & _BV(OUTPUT_BLOCK_FLAG)) {
			block();
		} else {
			unblock();
		}
	qbutton->set(b & OUTPUTS_QBUTTONS_MASK);
}

void OutSettings::activatedSlot(bool checked) {

	if (cancel) {
		if (override) {
			override=false;
			unblock();
			blockedSlot(0);
		}
		cancel=false;
	} else {
		if (!(isBlocked())) {
			override=true;
			block();
			blockedSlot(1);
		}
		cancel=true;
	}

	emit activeChanged(id,checked,true);
}

void OutSettings::activatedSlot(int state) {
	emit activeChanged(id,state,false);
}

void OutSettings::blockedSlot(bool checked) {
	emit blockChanged(id,checked,true);
}

void OutSettings::blockedSlot(int state) {
	emit blockChanged(id,state,false);
}

void OutSettings::setSlot() {
	setLabel(ui.lineEdit_label->text());
	emit newSettings(id,ui.lineEdit_label->text(),qbutton->get());
}

