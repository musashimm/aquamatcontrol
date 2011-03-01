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

/** @file comboBoxQButtons.cpp
@brief Implementacja klasy okna ComboBoxQButtons
*/

#include "comboBoxQButtons.h"

ComboBoxQButtons::ComboBoxQButtons(QWidget *parent) {
	this->parent=parent;
	this->addItem(QString("Brak"),QVariant(7));
	for (int i=0;i < OUTPUTS_QBUTTONS_NUM;i++) {
		this->addItem(QString("%1").arg(i+1),QVariant(i));
	}
	this->setCurrentIndex(0);
}

int ComboBoxQButtons::get() {
	return itemData(currentIndex()).toInt();
}
		
void ComboBoxQButtons::set(int atId) {
	if (atId < OUTPUTS_QBUTTONS_NUM) {
		setCurrentIndex(findData(atId));
	} else {
		setCurrentIndex(findData(OUTPUTS_QBUTTONS_MASK));
	}
}

