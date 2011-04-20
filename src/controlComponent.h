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
#include <QSettings>
#include <QList>

class ControlComponent :public QWidget {

    Q_OBJECT

	public:
		ControlComponent(int id, QString name, QWidget *parent = 0);
        int getId();
        bool wasNameModified();
        bool wasModified();
        virtual void setName(QString);
        virtual QString getName();
        virtual bool isActive() = 0;
        virtual bool isBlocked() = 0;
        virtual void setFlags(int) = 0;
        virtual int getFlags() = 0;
        virtual QByteArray getAsArray() = 0;
        virtual void setAsArray(QByteArray) = 0;
        virtual void save(QSettings*) = 0;
        virtual void load(QSettings*) = 0;

	protected:
		static QList<ControlComponent*> controls;
		int id;
		QString name;
		bool wasNameModifiedFlag;
		bool wasModifiedFlag;

};

#endif
