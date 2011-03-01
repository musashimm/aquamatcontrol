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


/** @file codeUpdate.h
@brief Plik nagłówkowy - Klasa codeUpdate
*/

#ifndef CODEUPDATE_H
#define CODEUPDATE_H

#include <QByteArray>
#include <QList>
#include <QString>
#include <QFile>
#include <QDebug>

#define CODE_BYTE_ARRAY_LENGTH 128

class CodeUpdate {

	public:
		CodeUpdate();
		~CodeUpdate();
		void prepareFromIntelHex(QString);
		QByteArray* getArray(int);
		void clear();
		int blockSize();
		int byteSize();
		bool isEmpty();
		int getStatus();
		QString getStatusString();
		QString getAsString(int);
        enum CodeUpdateStatus { UNKNOWN, INTELHEX, UNSUPPORTED };

	private:
        CodeUpdateStatus status;
        QList<QByteArray*> codeArray;
};

#endif
