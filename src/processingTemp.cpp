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

/** @file processingTemp.cpp
@brief Funkcje związane z kontrolą temperatury
*/

void MainWindow::tempInit() {
	for (int i=0;i<TEMP_SENSORS_NUM;i++) {
		TempDisplay *tempDisplay = new TempDisplay(i);
                tempDisplay->deactivate();
		ui.tempLayout->addWidget(tempDisplay);
		pTempDisplays[i]=tempDisplay;
		TempSettings *tempSettings = new TempSettings(i,pOutSettings);
		ui.tempSettingsLayout->addWidget(tempSettings);
		pTempSettings[i]=tempSettings;
		connect(pTempSettings[i], SIGNAL(currentTempChanged(Temperature)), pTempDisplays[i], SLOT(display(Temperature)));
                connect(pTempSettings[i], SIGNAL(deactivated()), pTempDisplays[i], SLOT(deactivate()));
                connect(pTempSettings[i], SIGNAL(activated()), pTempDisplays[i], SLOT(activate()));
	}
	connect(ui.b_tempGetSettings, SIGNAL(clicked()), this, SLOT(getTempSettings()));
	connect(ui.b_discoverSensors, SIGNAL(clicked()), this, SLOT(discoverTemp()));
	connect(ui.b_tempSetSettings, SIGNAL(clicked()), this, SLOT(setTempSettings()));
}

void MainWindow::discoverTemp() {
	Command c(GUI_TEMP_COMMAND,GUI_SUBCOMMAND_DISCOVER);
	c.end();
    cp.toQueue(c);
}

void MainWindow::getTempSettings() {
	Command c(GUI_TEMP_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setTempSettings() {
	for (int i=0;i<TEMP_SENSORS_NUM;i++) {
		Command c(GUI_TEMP_COMMAND,GUI_SUBCOMMAND_SET);
		c.add(i);
		c.add(pTempSettings[i]->getTargetTemp().getTens());
		c.add(pTempSettings[i]->getTargetTemp().getUnits());
		c.add(pTempSettings[i]->getTargetNightTemp().getTens());
		c.add(pTempSettings[i]->getTargetNightTemp().getUnits());
		c.add(pTempSettings[i]->getMaxTemp().getTens());
		c.add(pTempSettings[i]->getMaxTemp().getUnits());
		c.add(pTempSettings[i]->getMinTemp().getTens());
		c.add(pTempSettings[i]->getMinTemp().getUnits());
		c.add(pTempSettings[i]->getHisteresis().getUnits());
		c.add(pTempSettings[i]->getFlags());
		c.add(pTempSettings[i]->getOutCooling());
		c.add(pTempSettings[i]->getOutHeating());
		c.end();
        cp.toQueue(c);
	}
}

void MainWindow::getTemp() {
	Command c(GUI_TEMP_COMMAND,GUI_SUBCOMMAND_GET_STATUS);
	c.end();
    cp.toQueue(c);
}

TempSettings* MainWindow::getPTemp(int id) {
	return pTempSettings[id];
}
