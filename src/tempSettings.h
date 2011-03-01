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

/** @file tempSettings.h
@brief Plik nagłówkowy - Konfiguracja kontroli temperatury.
*/

#include "temperature.h"
#include "ui_tempSettings.h"
#include "comboBoxOuts.h"
#include "main.h"

class TempSettings : public QWidget {

	Q_OBJECT

	public:
		TempSettings(int id,OutSettings* pouts[],QWidget *parent = 0);

	public slots:
		void changeOutLabel(int,QString);
		void setCurrentTemp(Temperature);
		void deactivate();
		void activate();
		bool isActive();
		void setTargetTemp(Temperature);
		Temperature getTargetTemp();
		void setTargetNightTemp(Temperature);
		Temperature getTargetNightTemp();
		void setMinTemp(Temperature);
		Temperature getMinTemp();
		void setMaxTemp(Temperature);
		Temperature getMaxTemp();
		void setHisteresis(Temperature);
		Temperature getHisteresis();
		void setFlagsBr(uchar,uchar);
		void setStatus(int,int,int,int);
		int getOutCooling();
		void setOutCooling(int);
		int getOutHeating();
		void setOutHeating(int);
		void setRomSerial(QByteArray);
		void setRomSerial(QString);
		int getFlags();
		QString getRomSerial();
		void setActive(bool);


	signals:
		void activated();
		void deactivated();
		void currentTempChanged(Temperature);

	private:
		int id;
		Ui::TempSettings ui;
		ComboBoxOuts *outCooling;
		ComboBoxOuts *outHeating;
};
