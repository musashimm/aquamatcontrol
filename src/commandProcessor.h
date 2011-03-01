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

/** @file commandProcessor.h
@brief Plik nagłówkowy - Klasa CommandProcessor
*/

#ifndef CLASSCOMMANDPROCESSOR_H
#define CLASSCOMMANDPROCESSOR_H

#include <QString>
#include <QQueue>
#include "commandsDefs.h"
#include "command.h"
#include <QObject>
#include <QHash>
#include <QTimer>

#define TRANSMIT_INTERVAL 500
#define RECEIVE_INTERVAL 50
#define MAX_SIZE_RECEIVE_COMMAND_QUEUE 10
#define MAX_SIZE_RECEIVED_BUFFER 300

class MainWindow;

class CommandProcessor : public QObject
{

	Q_OBJECT

	public:
		CommandProcessor();
        CommandProcessor(int,int);
		void setParent(MainWindow*);
        void toQueue(Command);
        Command fromQueue();
        void changeIntervals(int,int);

		void processCommand(Command*);
		QString paramsReceived(Command *c);
        int receiveCommandQueueCount();
        int receivedBufferCount();

		void analyzeEventResponse(Command *c);
		void analyzeTimersvResponse(Command *c);
		void analyzeTimersResponse(Command *c);
		void analyzeTempStatusResponse(Command *c);
		void analyzeTempSettingsResponse(Command *c);
		void analyzeTempDiscoverResponse(Command *c);
		void analyzeStatusResponse(Command *c);
		void analyzeAlarmStatusResponse(Command *c);

        int getSessionSize();
        void putToSession(Command*);
        void putToReceivedSession(Command*);
        int getSessionProgress();
        void sessionStart();
        void sessionFillingStop();

    public slots:
        void stopProcessing();
        void startProcessing();

    private slots:
        void transmit();
        void receive();


	private:
        QHash<int, int> commandsSession;
        QHash<int, int> commandsReceivedSession;
        bool commandsSessionFilling;
        bool commandsSessionInProgress;
		MainWindow *parent;
		QByteArray received;
        QQueue<Command> transmitCommandQueue;
        QQueue<Command> receiveCommandQueue;
        QTimer transmitTimer;
        QTimer receiveTimer;

};

#endif

