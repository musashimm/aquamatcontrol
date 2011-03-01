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

/** @file tempDisplay.h
@brief Plik nagłówkowy - Wyświetlanie temperatury.
*/

#ifndef CLASSTEMPDISPLAY_H
#define CLASSTEMPDISPLAY_H

#include <QWidget>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QSizePolicy>
#include "indicator.h"
#include "temperature.h"

class TempDisplay : public QWidget
{
		Q_OBJECT

public:
		TempDisplay(int id,QWidget *parent = 0);

public slots:
		void display(const QString & s);
		void display(uchar,uchar,uchar);
		void display(Temperature);
                void deactivate();
		void failure();
                void activate();
		void tooLow();
		void tooHigh();

signals:

private:
	int id;
	QLCDNumber *lcd;

};

#endif
