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

/** @file controlComponent.h
@brief Plik nagłówkowy - Control Component.
*/

#ifndef CLASSCONTROLCOMPONENT_H
#define CLASSCONTROLCOMPONENT_H

#include <QWidget>
#include <QString>
//#include <QByteArray>
//#include <QTimer>
//#include "ui_sunScenario.h"

class ControlComponent :public QWidget {

    Q_OBJECT

	public:
		ControlComponent(int id,QString name, QWidget *parent = 0);
//		QByteArray getSettingsArray();
//		QString getName();
//		int getPwm();
//		bool isBlocked();
//		void setName(QString);
//		void setPwm(int);
//		void setFlags(int);
//		bool isNameChanged();
        int getId();
        QString getName();
        bool wasNameModified();
        bool wasModified();
        virtual bool isActive() = 0;
        virtual bool isBlocked() = 0;
        virtual void setFlags(int) = 0;
        virtual int getFlags() = 0;
        virtual QByteArray getAsArray() = 0;
        virtual void setAsArray(QByteArray) = 0;

//	public slots:
//		void newSettings(int,int,QString);
//
//    signals:
//		void stateChanged(int,int,int);
//
//	private slots:
//		void stateChanged();
//		void pwmChanged(int);
//		void checkPwmChange();
//		void nameChanged();

	private:
		//Ui::SunScenario ui;
		int id;
		QString name;
		bool wasNameModifiedFlag;
		bool wasModifiedFlag;
//		QTimer *timer;
//		int oldpwm;
//		bool nameChangedFlag;
};

#endif