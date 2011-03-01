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

/** @file comboBoxWeekDay.h
@brief Plik nagłówkowy - ComboBox dla dni tygodnia
*/

#ifndef CLASSCOMBOBOXWEEKDAY_H
#define CLASSCOMBOBOXWEEKDAY_H

#include <QComboBox>

class ComboBoxWeekDay : public QComboBox
{
	Q_OBJECT

	public:
		ComboBoxWeekDay(QWidget *parent = 0);
		int get();
		void set(int);

	private:
		QWidget *parent;
};

#endif
