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

/** @file outSettings.h
@brief Plik nagłówkowy - Konfiguracja wyjść
*/

#ifndef CLASSOUTSETTINGS_H
#define CLASSOUTSETTINGS_H


#include <QLabel>
#include <QString>
#include "ui_outSettings.h"
#include "comboBoxQButtons.h"

class OutSettings : public QWidget {

	Q_OBJECT

	public:
		OutSettings(int,QString,QWidget *parent = 0);
		void active();
		void inactive();
		void block();
		void unblock();
		void setLabel(QString);
		void setState(uchar);
		QString getLabel();
		bool isBlocked();
		int getQButton();
        void setQButton(int number);

    signals:
		void activeChanged(int,int,int);
		void blockChanged(int,int,int);
		void labelChanged(int,QString);
		void newSettings(int,QString,int);

	private slots:
		void setSlot();
		void activatedSlot(bool);
		void blockedSlot(bool);
		void activatedSlot(int);
		void blockedSlot(int);

	private:
		int id;
		bool override;
		bool cancel;
		QString label;
		Ui::OutSettings ui;
		ComboBoxQButtons* qbutton;

};


#endif
