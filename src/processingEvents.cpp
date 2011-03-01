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

/** @file processingEvents.cpp
@brief Funkcje związane ze zdarzeniami sterownika
*/

void MainWindow::eventsInit() {
	connect(ui.b_getEvents, SIGNAL(clicked()), this, SLOT(getEvents()));
	connect(ui.b_clearEvents, SIGNAL(clicked()), this, SLOT(clearEvents()));
    connect(ui.b_saveEvents, SIGNAL(clicked()), this, SLOT(saveEventsToFile()));
}

void MainWindow::enableGetEvents() {
    ui.eventViewer->scrollToTop();
	ui.b_getEvents->setEnabled(true);
}

void MainWindow::enableClearEvents() {
	ui.b_clearEvents->setEnabled(true);
}

void MainWindow::getEvents() {
	ui.b_getEvents->setEnabled(false);
	ui.eventViewer->clear();
	Command c(GUI_LOG_COMMAND,GUI_SUBCOMMAND_GET_STATUS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::saveEventsToFile() {

    QString fileName;

    if (ui.eventViewer->count()) {
    fileName = QFileDialog::getSaveFileName(this,tr("Zapisz historię do pliku"), ".", tr("Pliki konfiguracyjne (*.txt)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::WriteOnly|QFile::Text)) {
            QTextStream out(&file);
            for (int i=0;i<ui.eventViewer->count();i++) {
                out << ui.eventViewer->item(i)->text() << endl;
            }
            out << flush;
            statusBar()->showMessage(tr("Historia zapisana do pliku: ")+fileName);
            insertLogEntry(tr("Historia zapisana do pliku: ")+fileName);
        }
    }
    }else {
        statusBar()->showMessage(tr("Brak zdarzeń w historii"));
        insertLogEntry(tr("Brak zdarzeń w historii"));
    }
}

void MainWindow::clearEvents() {
	ui.b_clearEvents->setEnabled(false);
	ui.eventViewer->clear();
	Command c(GUI_LOG_COMMAND,GUI_SUBCOMMAND_CLEAR);
	c.end();
    cp.toQueue(c);
}

void MainWindow::addEvent(int year, int monthtype, int day,int hours, int minutes, int value1, int value2, int value3) {
	Temperature t(value2,value3);
	QString entry;
	int c = ui.eventViewer->count()+1;
	entry.append(QString("%1 - ").arg(c,4,10,QLatin1Char('0')));
	entry.append(QString("%1/").arg(year+2000,2));
	entry.append(QString("%1/").arg(((monthtype & 0xF0) >> 4),2,10,QLatin1Char('0')));
	entry.append(QString("%1 ").arg(day,2,10,QLatin1Char('0')));
	entry.append(QString("%1:").arg(hours,2,10,QLatin1Char('0')));
	entry.append(QString("%1 - ").arg(minutes,2,10,QLatin1Char('0')));

	switch (monthtype & 0x0F) {
		case LOG_EVENT_START: entry.append("Uruchomienie sterownika");
			break;
		case LOG_EVENT_ALARM_MAX:
			entry.append(eventsOffOn(value1));
			entry.append("Przekroczenie maksymalnej temperatury ");
			entry.append(eventsTempSensor(value1));
			break;
		case LOG_EVENT_ALARM_MIN:
			entry.append(eventsOffOn(value1));
			entry.append("Przekroczenie minimalnej temperatury ");
			entry.append(eventsTempSensor(value1));
			break;
		case LOG_EVENT_ALARM_SENSOR_FAILURE:
			entry.append(eventsOffOn(value1));
			entry.append("Uszkodzenie czujnika ");
			entry.append(eventsTempSensor(value1));
			break;
		case LOG_EVENT_TOP_OFF_MAX_RUN:
			entry.append(eventsOffOn(value1));
			entry.append("Przekroczenie czasu pracy automatycznej dolewki");
			break;
		case LOG_EVENT_TEMP_READ: 
			entry.append("Rejestracja temperatury ");
			entry.append(eventsTempSensor(value1));
			entry.append(t.toString());
			entry.append(" st. C");
			break;
		case LOG_EVENT_OUT_CHANGE:
			entry.append(tr("Zmiana stanu wyjścia: "));
			entry.append(eventsOut(value1));
			entry.append(QString("[%1] ").arg(pOutSettings[value1 & LOG_EVENT_DEVICE_MASK]->getLabel()));
			entry.append(eventsState(value1));
			break;
        case LOG_EVENT_TOP_OFF_MIN_RO:
            entry.append(eventsOffOn(value1));
            entry.append("Brak wody RO");
            break;
		default: entry.append("Zdarzenie nieznane");
	}
	ui.eventViewer->addItem(entry);
}

QString MainWindow::eventsTempSensor(int value) {
	return QString("- czujnik nr: %1 ").arg((value & LOG_EVENT_DEVICE_MASK)+1);
}

QString MainWindow::eventsOut(int value) {
	return QString(tr("- wyjście nr: %1 ")).arg((value & LOG_EVENT_DEVICE_MASK)+1);
}

QString MainWindow::eventsState(int value) {
	if (value & _BV(LOG_EVENT_START_STOP_FLAG)) {
		return tr("Włączenie (1) ");
	} else {
		return tr("Wyłączenie (0) ");
	}
}

QString MainWindow::eventsOffOn(int value) {
	if (value & _BV(LOG_EVENT_START_STOP_FLAG)) {
		return "!!! - ";
	} else {
		return "... - ";
	}
}

