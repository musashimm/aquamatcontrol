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

/** @file codeUpdateThread.cpp

    @brief Implementacja wątku aktualizującego oprogramowanie.
*/

#include "codeUpdateThread.h"

/** @brief Domyślny konstruktor klasy.
*/
CodeUpdateThread::CodeUpdateThread(){
    cu = NULL;
    timeoutTimerActive=0;
    connect(&timeoutTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(this, SIGNAL(startTimeoutTimerSig(int)), &timeoutTimer, SLOT(start(int)));
    connect(this, SIGNAL(stopTimeoutTimerSig()), &timeoutTimer, SLOT(stop()));
}

/** @brief Konstruktor klasy.

    @param cu wskaźnik do obiektu \ref CodeUpdate.
*/
CodeUpdateThread::CodeUpdateThread(CodeUpdate *cu){
    this->cu = cu;
    timeoutTimerActive=0;
    connect(&timeoutTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(this, SIGNAL(startTimeoutTimerSig(int)), &timeoutTimer, SLOT(start(int)));
    connect(this, SIGNAL(stopTimeoutTimerSig()), &timeoutTimer, SLOT(stop()));
}

/** @brief Główna metoda po uruchomieniu wątku.
*/
void CodeUpdateThread::run() {

    int length = 0;
    processFlag = CONTINUE;
    state = START;
    xBlockNum = 1;
    subArrayNum = 0;

    QTime progTime;
    progTime.start();

    if (cu == NULL) {
        emit progress(QString("PROG: Niezdefiniowane źródło kodu"),QString("red"));
        processFlag = CONFIG_ERROR;
    }

    if (processFlag == CONTINUE) {
        if (!cu->isEmpty()) {
            emit progress(QString("PROG: Źródło kodu puste"),QString("red"));
            processFlag = CONFIG_ERROR;
        }
    }

    if (processFlag == CONTINUE) {
        emit progress(QString("PROG: Liczba bloków (%1 b.): %2").arg(CODE_BYTE_ARRAY_LENGTH).arg(cu->blockSize()));
        emit startCodeUpdate();
    }

    while (processFlag == CONTINUE) {
        switch (state) {
            case START:
                waitForSymbol(ASCIIC,TIME_TO_WAIT_IN_START,SEND_DATA,"Start - Oczekiwanie na ASCIIC","Otrzymano ASCIIC");
                break;
            case SEND_DATA:
                length = 0;
                //emit progress(QString("PROG: Wysyłanie xBloku:%1/subArray:%2/all:%3").arg(xBlockNum).arg(subArrayNum).arg(cu->blockSize()));

                if (subArrayNum < cu->blockSize()) {
                    QByteArray a(cu->getArray(subArrayNum)->constData(),CODE_BYTE_ARRAY_LENGTH);
                    if (a.size() == CODE_BYTE_ARRAY_LENGTH) {

                        int crc = calculateCRC(a.data(),CODE_BYTE_ARRAY_LENGTH);
                        a.prepend(~xBlockNum);
                        a.prepend(xBlockNum);
                        a.prepend(SOH);
                        a.append((crc & 0xFF00) >> 8);
                        a.append(crc & 0xFF);

                        length = port->write(a);
                        emit progress(QString("PROG: Wysłano %1 znaków").arg(length));
						emit progress(int((float)subArrayNum/(cu->blockSize())*100));
                        if (length == (CODE_BYTE_ARRAY_LENGTH + XMODEM_EXTRA_DATA_NUM)) {
                            state = WAIT_FOR_ACK;
                            subArrayNum++;
                            xBlockNum++;
                        } else {
                            processFlag = PORT_ERROR;
                        }
                    } else {
                        processFlag = CONFIG_ERROR;
                    }
                } else {
                    state = STOP_EOT;
                }
                break;
            case WAIT_FOR_ACK:
                waitForSymbol(ACK,TIME_TO_WAIT_FOR_ACK,SEND_DATA,"Oczekiwanie na ACK","Otrzymano ACK");
                break;
            case STOP_EOT:
                sendSymbol(EOT,"Wysyłanie sygnału EOT",STOP_EOT_ACK);
                break;
            case STOP_EOT_ACK:
				//waitForSymbol(ACK,TIME_TO_WAIT_FOR_ACK,STOP_ETB,"Oczekiwanie na ACK","Otrzymano ACK"); 	//z ETB
                waitForSymbol(ACK,TIME_TO_WAIT_FOR_ACK,STOP,"Oczekiwanie na ACK","Otrzymano ACK"); 			//bez ETB
                break;
            case STOP_ETB:
                sendSymbol(ETB,"Wysyłanie sygnału ETB",STOP_ETB_ACK);
                break;
            case STOP_ETB_ACK:
                waitForSymbol(ACK,TIME_TO_WAIT_FOR_ACK,STOP,"Oczekiwanie na ACK","Otrzymano ACK");
                break;
            case STOP:
                processFlag = FINISHED;
                emit progress(100);
                break;
        }
        msleep(1);
    }

    switch (processFlag) {
        case CANCEL:
            emit progress(QString("PROG: Proces programowania przerwany przez użytkownika"),QString("red"));
            break;
        case TIMEOUT:
            emit progress(QString("PROG: Proces programowania przerwany z powodu przekroczonego czasu oczekiwania"),QString("red"));
            break;
        case CONFIG_ERROR:
            emit progress(QString("PROG: Proces programowania przerwany z powodu błędu konfiguracyjnego"),QString("red"));
            break;
        case PORT_ERROR:
            emit progress(QString("PROG: Proces programowania przerwany z powodu problemów z komunikacją"),QString("red"));
            break;
        default:
            emit progress(QString("PROG: Programowanie zakończone - Czas: %1 sekund").arg((int)(progTime.elapsed()/1000)));
            break;
    }
}

/** @brief Oczekuje na symbol sterujący transmisją.

    Możliwe wartości symboli znajdują się w wyliczeniu \ref XMODEM_SYMBOL.

    @param waitSymbol symbol, na który oczekuje automat
    @param waitTime czas, po którym wystąpi timeout jeżeli nie zostanie odebrany symbol
    @param stateForOk stan, do którego przejdzie automat po odebraniu symbolu
    @param entryString ciąg znaków, który zostanie wpisanych do logu przy pierwszym wejściu do funkcji.
    @param receivedString ciąg znaków, który zostanie wpisanych do logu po odebraniu symbolu.
*/
void CodeUpdateThread::waitForSymbol(XMODEM_SYMBOL waitSymbol,int waitTime, XMODEM_STATES stateForOk,QString entryString,QString receivedString) {
    char symbol;
    if (timeoutTimerActive) {
        if (port->getChar(&symbol)) {
             if (symbol == waitSymbol) {
                //timer.stop();
                //emit stopTimeoutTimer();
                stopTimeoutTimer();
                emit progress(receivedString.prepend("PROG: "));
                state = stateForOk;
             }
        }
    } else {
        emit progress(entryString.prepend("PROG: ").append(QString(" Czekam: %1 msek.").arg(waitTime)));
        startTimeoutTimer(waitTime);
        //timeoutActive=startTimer(waitTime);
        //emit startTimeoutTimer(waitTime);
        //timer.start(waitTime);
        //while(!timer.isActive());
    }
}

/** @brief Wysyła symbol sterujący transmisją.

    Możliwe wartości symboli znajdują się w wyliczeniu \ref XMODEM_SYMBOL.

    @param symbol symbol transmisji do wysłania
    @param entryString ciąg znaków wyświetlany w logu
    @param nextState stan do, którego przejdzie automat po wysłaniu symbolu
*/
void CodeUpdateThread::sendSymbol(XMODEM_SYMBOL symbol,QString entryString,XMODEM_STATES nextState){
    bool ok;
    emit progress(entryString.prepend("PROG: "));
    ok = port->putChar(symbol);
    if (ok) {
        state = nextState;
    } else {
        processFlag = PORT_ERROR;
    }
}

/** @brief Ustawia obiekt odpowiedzialny za przygotowanie pliku do załadowania.

    @param cu wskaźnik do obiektu
*/
 void CodeUpdateThread::setCodeSource(CodeUpdate* cu) {
     this->cu = cu;
 }

 void CodeUpdateThread::stopTimeoutTimer() {
     if (timeoutTimerActive) {
         emit stopTimeoutTimerSig();
         timeoutTimerActive=false;
     }
 }

 void CodeUpdateThread::startTimeoutTimer(int interval) {
     if (!timeoutTimerActive) {
         emit startTimeoutTimerSig(interval);
         timeoutTimerActive=true;
     }
 }

/** @brief W przypadku otrzymania sygnału przerwania operacji przez użytkownika odpowiednio ustawia zmienną @ref processFlag.

    Zakończenie wątku nastąpi przy następnej iteracji.
*/
 void CodeUpdateThread::cancel() {
    processFlag = CANCEL;
    stopTimeoutTimer();
 }

/** @brief W przypadku wystąpienia timeoutu odpowiednio ustawia zmienną @ref processFlag.

    Zakończenie wątku nastąpi przy następnej iteracji.
*/
 void CodeUpdateThread::timeout() {
    processFlag = TIMEOUT;
    stopTimeoutTimer();
 }

/** @brief Przypisuje port obiektowi.

    @param port wskaźnik do obiektu
*/
void CodeUpdateThread::setPort(QextSerialPort* port) {
	this->port = port;
}

/** @brief Oblicza CRC bloku danych.

    @param ptr wskaźnik do bloku danych
    @param count ilość bajtów wliczona do CRC
*/
int CodeUpdateThread::calculateCRC(char *ptr, int count)
{
    int  crc;
    char i;

    crc = 0;
    while (--count >= 0)
    {
        crc = crc ^ (int) *ptr++ << 8;
        i = 8;
        do
        {
            if (crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
        } while(--i);
    }
    return (crc);
}

//void CodeUpdateThread::timerEvent(QTimerEvent *event)
// {
//    if (event->timerId() == timeoutActive) {
//        timeout();
//    }
// }
