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

/** @file comboBoxWeekDay.cpp
@brief Implementacja klasy ComboBoxWeekDay
*/

#include "comboBoxWeekDay.h"

ComboBoxWeekDay::ComboBoxWeekDay(QWidget *parent) {
	this->parent=parent;
	this->addItem(QString("Codziennie"),QVariant(7));
	this->addItem(QString(tr("Poniedziałek")),QVariant(1));
	this->addItem(QString("Wtorek"),QVariant(2));
	this->addItem(QString(tr("Środa")),QVariant(3));
	this->addItem(QString("Czwartek"),QVariant(4));
	this->addItem(QString(tr("Piątek")),QVariant(5));
	this->addItem(QString("Sobota"),QVariant(6));
	this->addItem(QString("Niedziela"),QVariant(0));
	this->setCurrentIndex(0);
}

int ComboBoxWeekDay::get() {
	return itemData(currentIndex()).toInt();
}
		
void ComboBoxWeekDay::set(int atId) {
	setCurrentIndex(findData(atId));
}

