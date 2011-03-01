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

/** @file command.cpp
@brief Implementacja klasy codeUpdate - klasa pomocna jest przy aktualizacji oprogramowania
*/

#include "codeUpdate.h"
//#include "commonDefs.h"

CodeUpdate::CodeUpdate() {
    status = UNKNOWN;
}

CodeUpdate::~CodeUpdate() {
    clear();
}

void CodeUpdate::prepareFromIntelHex(QString fileName) {
    QFile file(fileName);
    int recNum = 0;
    int toFill  = 0;
    int left = 0;

    codeArray.clear();

    QByteArray* byteArray = new QByteArray();


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         return;
    }
    while (!file.atEnd()) {
         QByteArray line = file.readLine();
         //qDebug() << line.constData();
         if (line[0] == ':') {
            line.remove(0, 1);
            QByteArray hexArray = QByteArray::fromHex(line);
            recNum = hexArray[0];

            if (recNum) {
                //if if (hexArray[0]) {
                //qDebug() << "record size:" << (int)hexArray[0];
                if ((uint)hexArray[3] == 0x00) {

                    if (byteArray->size() + recNum <= CODE_BYTE_ARRAY_LENGTH) {
                            //qDebug() << "Czytam:" << recNum;
                            byteArray->append(hexArray.mid(4,recNum));
                            //qDebug() << "aktualny index:" << byteArray->size();
                    } else {
                            toFill = CODE_BYTE_ARRAY_LENGTH - byteArray->size();
                            //qDebug() << "Czytam to fill:" << toFill;
                            //qDebug() << "zakladam nowy:";
                            codeArray.append(byteArray);
                            byteArray = new QByteArray();
                            left = recNum - toFill;
                            if (left) {
                                //qDebug() << "Czytam left:" << left;
                                byteArray->append(hexArray.mid(4+toFill,left));
                            }
                    }
                } else {
                    status = UNSUPPORTED;
                    break;
                }

            } else {
                if ((uint)hexArray[3] == 0x01) {
                     toFill = CODE_BYTE_ARRAY_LENGTH - byteArray->size();
                     if (toFill) {
                        byteArray->append(QByteArray(toFill,255));
                        //qDebug() << "Generacja bajtow:" << toFill;
                        codeArray.append(byteArray);
                     }

                    status = INTELHEX;
                    break;
                }
            }
        } else {
            break;
        }
    }
}

void CodeUpdate::clear() {
    for (int i=0; i<codeArray.size();i++) {
        if (codeArray[i] != NULL) {
            delete codeArray[i];
        }
    }
    codeArray.clear();
}

int CodeUpdate::getStatus() {
    return status;
}

QString CodeUpdate::getStatusString() {
    switch (status) {
        case INTELHEX:
            return QString("IntelHex");
            break;
        case UNSUPPORTED:
            return QString("Niezaimplementowany");
            break;
        default:
            return QString("Nierozpoznany");
    }
}

QString CodeUpdate::getAsString(int count) {
    QString s;
    for (int i=0; i< codeArray.size();i++) {
         if (codeArray[i] != NULL) {
             for (int j=0;j<codeArray[i]->size();j+=count ) {
                s.append(codeArray[i]->mid(j,count).toHex().constData());
                s.append("\n");
             }
        }
        s.append("\n");

    }
    return s;
}

int CodeUpdate::byteSize() {
    return (codeArray.size() * CODE_BYTE_ARRAY_LENGTH);
}

int CodeUpdate::blockSize() {
    return (codeArray.size());
}

bool CodeUpdate::isEmpty() {
    if (blockSize()) {
        return true;
    } else {
        return false;
    }
}

QByteArray* CodeUpdate::getArray(int num) {
    return codeArray[num];
}
