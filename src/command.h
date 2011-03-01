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

/** @file command.h
@brief Plik nagłówkowy - Klasa Command
*/

#ifndef CLASSCOMMAND_H
#define CLASSCOMMAND_H

#include <QByteArray>
#include <QString>
#include <QHash>

class Command : public QByteArray {
	
	public:
		Command();
        Command(QString);
		Command(uchar c,uchar subc);
		Command& operator= (QByteArray ba);
		QByteRef operator[] (int index);
		uchar next();
        QByteArray next(int);
		void add(uchar);
		uchar first();
		void resetIndex();
		uchar getCommand();
		uchar getSubCommand();
		QString toString();
		int getIindex();
		void end();
		int isNext();
		uchar getReceivedCrc();	
		uchar getCalculatedCrc();
        void calculateCrc();
		bool isValid();
		QString getCDesc(uchar);
		QString getSDesc(uchar);
		QString getStatusDesc(uchar);
		void prepareCommon(void);

	private:
		int iindex;
		uchar crc;
		QHash<int,QString> commandsDesc;
		QHash<int,QString> subcommandsDesc;
		QHash<int,QString> statusDesc;
};

#endif

