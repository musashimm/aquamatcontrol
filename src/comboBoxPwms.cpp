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

/** @file comboBoxPwms.cpp
@brief Implementacja klasy ComboBoxPwms
*/

#include "comboBoxPwms.h"

ComboBoxPwms::ComboBoxPwms(PwmSettings* ppwms[], QWidget *parent) {
	this->parent=parent;
	addItem(QString("Brak"),QVariant(UINT8_T_DISABLED));
	for (int i=0;i<PWM_NUM;i++) {
		addItem(QString("%1: %2").arg(i+1).arg(ppwms[i]->getName()),QVariant(i));
	}
	setCurrentIndex(0);
}

void ComboBoxPwms::changeName(int atId,QString newName) {
	int current = currentIndex();
	int index = findData(atId);
	removeItem(index);
	insertItem(index,QString("%1: %2").arg(atId+1).arg(newName),QVariant(atId));
	setCurrentIndex(current);
}

int ComboBoxPwms::get() {
	return itemData(currentIndex()).toInt();
}

void ComboBoxPwms::set(int atId) {
	if (atId >= PWM_NUM) {
		atId = UINT8_T_DISABLED;
	}
	setCurrentIndex(findData(atId));
}

