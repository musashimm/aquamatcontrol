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

/** @file processingTimersv.cpp
@brief Funkcje związane z zarządzaniem timerami interwałowymi.
*/

void MainWindow::timersvInit() {
	for(int i=0;i<2;i++) {
		for (int j=0;j<4;j++) {
			TimersvSettings *timersvSettings = new TimersvSettings(i*4+j,pOutSettings);
			ui.timersvSettingsLayout->addWidget(timersvSettings,i,j);
			pTimersvSettings[i*4+j]=timersvSettings;
		}
	}
	connect(ui.b_timersvGetSettings, SIGNAL(clicked()), this, SLOT(getTimersv()));
	connect(ui.b_timersvSetSettings, SIGNAL(clicked()), this, SLOT(setTimersv()));
}

void MainWindow::getTimersv() {
	Command c(GUI_TIMERSV_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setTimersv() {
	for (int i=0;i<TIMERSV_NUM;i++) {
		Command c(GUI_TIMERSV_COMMAND,GUI_SUBCOMMAND_SET);	
		c.add(i);
		c.add(pTimersvSettings[i]->getTimeOff());
		c.add(pTimersvSettings[i]->getTimeOn());
		c.add(pTimersvSettings[i]->getOut());
		c.add(pTimersvSettings[i]->getFlags());
		c.end();
        cp.toQueue(c);
	}
}

TimersvSettings* MainWindow::getPTimersv(int id) {
	return pTimersvSettings[id];
}
