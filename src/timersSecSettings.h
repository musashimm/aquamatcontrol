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
    Foundation, Inc., 59 Timersle Place, Suite 330, Boston, MA  02111-1307  USA

	$Id$
*/

/** @file timersSecSettings.h
@brief Plik nagłówkowy - Konfiguracja timerów sekundowych.
*/

#ifndef CLASSTIMERSSECSETTINGS_H
#define CLASSTIMERSSECSETTINGS_H

#include "ui_timersSecSettings.h"
#include "comboBoxWeekDay.h"
#include "comboBoxOuts.h"
#include "outSettings.h"

class TimersSecSettings : public QWidget {

	Q_OBJECT

	public:
		TimersSecSettings(int id,OutSettings* pouts[],QWidget *parent = 0);
//		void changeOutLabel(int,QString);
//		void disable();
//		void enable();
//		QTime getTimeFrom();
//		QTime getTimeTo();
//		void setTimeFrom(QTime);
//		void setTimeFrom(int,int);
//		void setTimeTo(QTime);
//		void setTimeTo(int,int);
//		int getOut();
//		void setOut(int);
//		int getWday();
//		void setWday(int);
//		void setActive();
//		void setInActive();
//		int getFlags();
//		void setFlags(int);
//		void set(int,int,int,int,int,int);
//		bool isActive();
//
//	signals:
//		void enabled();
//		void disabled();
//
//	private slots:
//		void changeState(int);

	private:
		int id;
		Ui::TimersSecSettings ui;
		ComboBoxWeekDay *wday;
		ComboBoxOuts *out;
};

#endif
