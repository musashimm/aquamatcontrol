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

/** @file outDisplay.h
@brief Plik nagłówkowy - Wyświetlanie wyjść
*/

#ifndef CLASSOUTDISPLAY_H
#define CLASSOUTDISPLAY_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include "indicator.h"

class OutDisplay : public QGroupBox
{
		Q_OBJECT

public:
		OutDisplay(int id,QGroupBox *parent = 0);
		QString getName();

public slots:
		void active();
		void inactive();
		void block();
		void unblock();
		//void setState(uchar b);
		void setLabel(QString);

private:
	int id;
	QLabel *label;
	Indicator *state;
	Indicator *blockage;
};

#endif
