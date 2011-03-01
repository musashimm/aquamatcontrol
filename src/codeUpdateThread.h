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

/** @file codeUpdateThread.h
 @brief Plik nagłówkowy - Implementacja wątku aktualizującego oprogramowanie
*/

#ifndef CODEUPDATETHREAD_H
#define CODEUPDATETHREAD_H

#include <QThread>
#include <QTime>
#include <QTimer>
#include "codeUpdate.h"
#include <qextserialport.h>

/** Czas oczekiwania na symbol ASCIIC.
*/
#define TIME_TO_WAIT_IN_START 6000

/** Czas oczekiwania na potwierdzenie.
*/
#define TIME_TO_WAIT_FOR_ACK 1000

/** Ilość znaków jaką musimy dopisać do bloku danych XMODEM.
*/
#define XMODEM_EXTRA_DATA_NUM 5

/** @brief Klasa wątku obsługującego aktualizację oprogramowania.

    Obsługa protokołu XMODEM zaimplementowana jest w postaciu oddzielnego wątku jako automat. Stany, w których może się znaleźć automat znajdują się w \ref XMODEM_STATES. Warunki działania wątku i ewentualne przyczyny jego zakończenia wymienione są w \ref THREAD_PROCESS.
*/
class CodeUpdateThread : public QThread {

    Q_OBJECT

    /** @brief Możiwe stany automatu.
    */
    enum XMODEM_STATES {START,SEND_DATA,WAIT_FOR_ACK,STOP_EOT,STOP_EOT_ACK,STOP_ETB,STOP_ETB_ACK,STOP};

    /** @brief Warunki działania i zakończenia działania wątku.
    */
    enum THREAD_PROCESS {CONTINUE,CANCEL,TIMEOUT,CONFIG_ERROR,FINISHED,PORT_ERROR};

    /** @brief Możiwe symbole protokołu XMODEM.
    */
    enum XMODEM_SYMBOL {SOH=0x01,EOT=0x04,ACK=0x06,NAK=0x15,ETB=0x17,CAN=0x18,ASCIIC=0x43};

    public:
        CodeUpdateThread();
        CodeUpdateThread(CodeUpdate*);
        void run();
        void setPort(QextSerialPort*);

    public slots:
        void cancel();
        void setCodeSource(CodeUpdate*);

    signals:
        void progress(QString);         /**< Sygnał wysyłany podczas pracy wątku. */
        void progress(QString,QString); /**< Sygnał wysyłany podczas pracy wątku. */
        void progress(int);             /**< Sygnał wysyłany podczas pracy wątku. */
        void startCodeUpdate();         /**< Sygnał wysyłany tuż przed pętlą aktualizującą transmisję. */
        void startTimeoutTimerSig(int);
        void stopTimeoutTimerSig(void);

    private slots:
        void timeout();
        void waitForSymbol(XMODEM_SYMBOL,int,XMODEM_STATES,QString,QString);
        void sendSymbol(XMODEM_SYMBOL,QString,XMODEM_STATES);

    protected:
        //void timerEvent(QTimerEvent *event);
        void stopTimeoutTimer();
        void startTimeoutTimer(int);

    private:
        int calculateCRC(char*, int);
        THREAD_PROCESS processFlag; /**< Warunki działania wątku. */
        XMODEM_STATES state;        /**< Aktualny stan automatu. */
        uchar xBlockNum;            /**< Numer wysyłanego bloku protokołu XMODEM. Zakres od 0 do 255. Modulo 256. Blok wysłany jako pierwszy ma numer 1. */
        int subArrayNum;            /**< Numer bloku danych przygotowany przez obiekt \ref CodeUpdate. Pierwszy pobrany blok ma numer 0. */
        CodeUpdate *cu;             /**< Wskaźnik na obiekt \ref CodeUpdate. */
        QTimer timeoutTimer;        /**< Obiekt \ref QTimer odliczający timeout. */
        bool timeoutTimerActive;
        QextSerialPort* port;       /**< Wskaźnik na obiekt realizujący komunikację z interfejsem szeregowym. */
 };

#endif
