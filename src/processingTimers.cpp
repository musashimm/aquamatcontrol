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

/** @file processingTimers.cpp
@brief Funkcje związane z zarządzaniem timerami godzinowymi.
*/

void MainWindow::timersInit() {
	for(int i=0;i<2;i++) {
			for (int j=0;j<4;j++) {
				TimersSettings *timersSettings = new TimersSettings(i*4+j,pOutSettings);
				ui.timersSettingsLayout->addWidget(timersSettings,i,j);
				pTimersSettings[i*4+j]=timersSettings;
			}
	}
	connect(ui.b_timersGetSettings, SIGNAL(clicked()), this, SLOT(getTimers()));
	connect(ui.b_timersSetSettings, SIGNAL(clicked()), this, SLOT(setTimers()));
}

void MainWindow::getTimers() {
	Command c(GUI_TIMERS_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setTimers() {
		for (int i=0;i<TIMERS_NUM;i++) {
		Command c(GUI_TIMERS_COMMAND,GUI_SUBCOMMAND_SET);	
		c.add(i);
		c.add(pTimersSettings[i]->getTimeFrom().hour());
		c.add(pTimersSettings[i]->getTimeFrom().minute());
		c.add(pTimersSettings[i]->getTimeTo().hour());
		c.add(pTimersSettings[i]->getTimeTo().minute());
		c.add(pTimersSettings[i]->getOut());
		c.add(pTimersSettings[i]->getFlags());
		c.end();
        cp.toQueue(c);
	}
}

TimersSettings* MainWindow::getPTimers(int id) {
	return pTimersSettings[id];
}
