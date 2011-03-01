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

/** @file temperature.h
@brief Plik nagłówkowy - Klasa temperatury.
*/

#ifndef CLASSTEMPERATURE_H
#define CLASSTEMPERATURE_H

typedef unsigned char uchar;
#include <math.h>
#include <QString>
#include "commonDefs.h"

class Temperature {
	
	public:
		Temperature();
		Temperature(uchar,uchar,uchar f = 0);
		Temperature(double);
		uchar getTens();
		uchar getUnits();
		double getDouble();
		QString toString();
		bool isActive();
		QString getAlarmString();
		bool isMin();
		bool isMax();
		bool isOk();
		bool isCooling();
		bool isHeating();

	private:
		uchar tens;
		uchar units;
		uchar flags;
};

#endif
