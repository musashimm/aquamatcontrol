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

/** @file processingTimersSec.cpp
@brief Funkcje związane z zarządzaniem timerami sekundowymi.

    Pushbuttons

*/

void MainWindow::timersSecInit() {
	for(int i=0;i<TIMERSSEC_NUM;i++) {
        TimersSecSettings *timersSecSettings = new TimersSecSettings(i,pOutSettings);
		ui.timersSecSettingsLayout->addWidget(timersSecSettings,0,i);
		pTimersSecSettings[i]=timersSecSettings;
    }
	connect(ui.b_timersSecGetSettings, SIGNAL(clicked()), this, SLOT(timersSecGetSettings()));
	connect(ui.b_timersSecSetSettings, SIGNAL(clicked()), this, SLOT(timersSecSendSettings()));
}

void MainWindow::timersSecGetSettings() {
    Command c(GUI_TIMSEC,GUI_GET);
	c.end();
    cp.toQueue(c);
}

void MainWindow::timersSecSendSettings() {
	for(int i=0;i<TIMERSSEC_NUM;i++) {
        Command c(GUI_TIMSEC,GUI_SET);
        c.append(pTimersSecSettings[i]->getSettingsArray());
        c.end();
        cp.toQueue(c);
    }
}

TimersSecSettings* MainWindow::getTimersSecSetting(int id) {
        return pTimersSecSettings[id];
}

void MainWindow::timersSecSaveSettings(QSettings* s) {
    s->beginWriteArray("TimersSec");
	for (int i = 0; i < TIMERSSEC_NUM; i++) {
     	s->setArrayIndex(i);
     	s->setValue("from", pTimersSecSettings[i]->getTimeFrom().toString("hh:mm"));
     	s->setValue("duration", pTimersSecSettings[i]->getDuration());
     	s->setValue("wday", pTimersSecSettings[i]->getWday());
        s->setValue("out", pTimersSecSettings[i]->getOut());
     	s->setValue("active", pTimersSecSettings[i]->isActive());
 	}
 	s->endArray();
}

void MainWindow::timersSecLoadSettings(QSettings* s) {
    s->beginReadArray("TimersSec");
	for (int i = 0; i < TIMERSSEC_NUM; i++) {
     	s->setArrayIndex(i);
     	if (s->value("active").toBool()) {
     	    pTimersSecSettings[i]->enable();
     	}
     	pTimersSecSettings[i]->setTimeFrom(QTime::fromString(s->value("from").toString(),"hh:mm"));
     	pTimersSecSettings[i]->setDuration(s->value("duration").toInt());
     	pTimersSecSettings[i]->setWday(s->value("wday").toInt());
     	pTimersSecSettings[i]->setOut(s->value("out").toInt());
 	}
 	s->endArray();
}
