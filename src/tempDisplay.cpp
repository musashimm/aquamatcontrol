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

/** @file tempDisplay.cpp
@brief Implementacja wyświetlania temperatury
*/

#include "tempDisplay.h"

#include "main.h"

TempDisplay::TempDisplay(int id,QWidget *parent)
     : QWidget(parent)
{
	this->id=id;
	QGroupBox *groupBox = new QGroupBox(QString("Czujnik temp. %1").arg(id+1));
	lcd = new QLCDNumber(3);
	lcd->setSegmentStyle(QLCDNumber::Filled);
	lcd->setFrameStyle(QFrame::NoFrame);
	lcd->setSmallDecimalPoint(true);
	QHBoxLayout *layout2 = new QHBoxLayout;	
	QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(lcd);
	groupBox->setLayout(layout);
	layout2->addWidget(groupBox);
	setContentsMargins(0,0,0,0);
	layout->setContentsMargins(0,0,0,0);
	setLayout(layout2);
 }

void TempDisplay::display(const QString & s) {
	lcd->display(s);
}

void TempDisplay::display(uchar b1,uchar b2,uchar flags) {	
	lcd->display(QString("%1.%2").arg((b1 << 4)|(b2 >> 4)).arg(b2 & 0x0F));
	if (flags & TEMP_SENSOR_ROLE_MASK) {
		if (flags & _BV(TEMP_SENSOR_STATUS_OK)) {
			if (flags & _BV(TEMP_ALARM_MIN)) {
				tooLow();
			} else if (flags & _BV(TEMP_ALARM_MAX)) {
				tooHigh();	
			} else {
                                activate();
			}
		} else {
			failure();
		}
	} else {
                deactivate();
	}
}

void TempDisplay::display(Temperature t) {
	lcd->display(t.toString());
	if (t.isActive()) {
		if (t.isOk()) {
			if (t.isMin()) {
				tooLow();
			} else if (t.isMax()) {
				tooHigh();	
			} else {
                                activate();
			}
		} else {
			failure();
		}
	} else {
                deactivate();
	}
}

void TempDisplay::deactivate() {
	lcd->setPalette(QPalette(QColor(0xEEEEEE)));
	lcd->display("--.-");
	lcd->setEnabled(false);
}

void TempDisplay::failure() {
	lcd->setPalette(QPalette(QColor("red")));
	lcd->setEnabled(false);
}

void TempDisplay::activate() {
	lcd->setPalette(QPalette(QColor("black")));
	lcd->setEnabled(true);
}

void TempDisplay::tooLow() {
	lcd->setPalette(QPalette(QColor("blue")));
	lcd->setEnabled(true);
}

void TempDisplay::tooHigh() {
	lcd->setPalette(QPalette(QColor("red")));
	lcd->setEnabled(true);
}


