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

/** @file outDisplay.cpp
@brief Implementacja wyświetlania wyjść
*/

#include "outDisplay.h"
#include "main.h"

OutDisplay::OutDisplay(int id,QGroupBox *parent)
     : QGroupBox(parent)
{
	this->id=id;
	label = new QLabel("abcde");
	setTitle(QString(tr("Wyj. %1 [%2]")).arg(id+1).arg(label->text()));
	QHBoxLayout *layout = new QHBoxLayout;
	state = new Indicator(parent,"S:");
	layout->addWidget(state);
	blockage = new Indicator(parent,"B:");
	layout->addWidget(blockage);
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);
	setLayout(layout);
}

void OutDisplay::active() {
	state->active();
}

void OutDisplay::inactive() {
	state->inactive();
}

void OutDisplay::block() {
	blockage->block();
}

QString OutDisplay::getName() {
	return label->text();
}

void OutDisplay::setLabel(QString name) {
	label->setText(name);
	setTitle(QString(tr("Wyj. %1 [%2]")).arg(id+1).arg(label->text()));
}

void OutDisplay::unblock() {
	blockage->inactive();
}

// void OutDisplay::setState(uchar b) {
// 	if (b & _BV(OUTPUT_ACTIVE_FLAG)) {
// 			active();
// 		} else {
// 			inactive();
// 		}	
// 	if (b & _BV(OUTPUT_BLOCK_FLAG)) {
// 			block();
// 		} else {
// 			unblock();
// 		}	
// }
