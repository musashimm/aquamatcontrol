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

/** @file processingOut.cpp
@brief Funkcje związane z wyjściami
*/

void MainWindow::outInit() {
	for(int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			OutDisplay *outDisplay = new OutDisplay(i*4+j);
			OutSettings *outSettings = new OutSettings(i*4+j,"abcde");
			ui.outLayout->addWidget(outDisplay,i,j);
			ui.outSettingsLayout->addWidget(outSettings,i,j);
			pOutDisplays[i*4+j]=outDisplay;
			pOutSettings[i*4+j]=outSettings;
			connect(pOutSettings[i*4+j], SIGNAL(activeChanged(int,int,int)), this, SLOT(setOutState(int,int,int)));
			connect(pOutSettings[i*4+j], SIGNAL(blockChanged(int,int,int)), this, SLOT(setOutBlock(int,int,int)));
			connect(pOutSettings[i*4+j], SIGNAL(labelChanged(int,QString)), this, SLOT(setOutLabel(int,QString)));
			connect(pOutSettings[i*4+j], SIGNAL(newSettings(int,QString,int)), this, SLOT(sendOutSettings(int,QString,int)));
		}
	}
	connect(ui.b_outAllActive, SIGNAL(clicked()), this, SLOT(setOutAllActive()));
	connect(ui.b_outAllInactive, SIGNAL(clicked()), this, SLOT(setOutAllInactive()));
	connect(ui.b_outAllBlock, SIGNAL(clicked()), this, SLOT(setOutAllBlock()));
	connect(ui.b_outAllUnblock, SIGNAL(clicked()), this, SLOT(setOutAllUnblock()));
	connect(ui.b_getOutSettings,SIGNAL(clicked()), this, SLOT(getOutSettings()));
}

void MainWindow::getOut() {
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_GET_STATUS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::getOutSettings() {
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setOutSettings() {
    for(int i=0;i<OUTPUTS_NUM;i++) {
       sendOutSettings(i,pOutSettings[i]->getLabel(),pOutSettings[i]->getQButton());
    }
}

void MainWindow::setUiOutState(int i,uchar b) {
	pOutSettings[i]->setState(b);
}

void MainWindow::setUiOutLabel(int outId,QString label) {
	QString s = label;
	for (int i=0;i<s.size();i++) {
		if (!(isprint(s[i].toAscii()))) {
			s.replace(i,1,QChar('?'));
		} 
	}
	pOutSettings[outId]->setLabel(s);
}

void MainWindow::setOutState(int id, int state,int clicked) {

	if (state) {
		pOutDisplays[id]->active();
	}	else {
		pOutDisplays[id]->inactive();
	}

	if (clicked) {
		Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_STATE);
		c.append((uchar)id);
		c.append((uchar)state);
		c.end();
        cp.toQueue(c);
	}
}

void MainWindow::setOutLabel(int id, QString label) {
	
	topOffOut->changeLabel(id,label);

	pOutDisplays[id]->setLabel(label);

	for (int i=0;i<TEMP_SENSORS_NUM;i++) {
		pTempSettings[i]->changeOutLabel(id,label);
	}
	
	for (int i=0;i<TIMERS_NUM;i++) {
		pTimersSettings[i]->changeOutLabel(id,label);
 	}
	
	for (int i=0;i<TIMERSV_NUM;i++) {
		pTimersvSettings[i]->changeOutLabel(id,label);
 	}
}

void MainWindow::sendOutSettings(int id, QString label,int qb) {
	QString s;
	for(int i=0;i<OUTPUTS_NAME_LENGTH;i++) {
		s.append(" ");
		if (i<label.size()) {
			s.replace(i,1,label.at(i));
		}
	}
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET);
	c.append((uchar)id);
	c.append(qb);
	c.append(s);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setOutBlock(int id, int state, int clicked) {
	
	if (state) {
		pOutDisplays[id]->block();
	}	else {
		pOutDisplays[id]->unblock();
	}

	if (clicked) {
		Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_BLOCK);
		c.append((uchar)id);
		c.append((uchar)state);
		c.end();
        cp.toQueue(c);
	}
}

void MainWindow::setOutAllActive() {
		for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
			pOutSettings[i]->active();
		}
		Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_STATE_ALL);
		c.add(ON);
		c.end();
        cp.toQueue(c);
}

void MainWindow::setOutAllInactive() {
	for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
		pOutSettings[i]->inactive();
	}
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_STATE_ALL);
	c.add(OFF);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setOutAllBlock() {
	for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
		pOutSettings[i]->block();
	}
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_BLOCK_ALL);
	c.add(ON);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setOutAllUnblock() {
	for (int i=0;i<OUTPUTS_DEVICES_NUM*OUTPUTS_NUM_PER_DEVICE;i++) {
		pOutSettings[i]->unblock();
	}
	Command c(GUI_OUT_COMMAND,GUI_SUBCOMMAND_SET_BLOCK_ALL);
	c.add(OFF);
	c.end();
    cp.toQueue(c);
}

OutSettings* MainWindow::getPOut(int id) {
	return pOutSettings[id];
}
