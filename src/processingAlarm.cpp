
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

/** @file processingAlarm.cpp
@brief Funkcje związane z alarmami
*/


void MainWindow::alarmInit() {

	ui.alarmLayout->setContentsMargins(0,0,0,0);
	ui.alarmLayout->setSpacing(0);
	
	alarmTempMax = new Indicator(this,"Temperatura max.");
	ui.alarmLayout->addWidget(alarmTempMax);
	
	alarmTempMin = new Indicator(this,"Temperatura min.");
	ui.alarmLayout->addWidget(alarmTempMin);
	
	alarmTempFailure = new Indicator(this,"Uszk. czujnik temp.");
	ui.alarmLayout->addWidget(alarmTempFailure);
	
	alarmMinRo = new Indicator(this,"Min. poziom RO");
	ui.alarmLayout->addWidget(alarmMinRo);

	alarmAdMax = new Indicator(this,"Przek. czas pracy AD");
	ui.alarmLayout->addWidget(alarmAdMax);
	
	pIndicators[ALARM_FLAG_TEMP_MAX]=alarmTempMax;
	pIndicators[ALARM_FLAG_TEMP_MIN]=alarmTempMin;
	pIndicators[ALARM_FLAG_TEMP_SENSOR_FAILURE]=alarmTempFailure;
	pIndicators[ALARM_FLAG_TOP_OFF_MIN_RO]=alarmMinRo;
	pIndicators[ALARM_FLAG_TOP_OFF_MAX_RUN]=alarmAdMax;
	
	connect(ui.b_getAlarm, SIGNAL(clicked()), this, SLOT(getAlarm()));
	connect(ui.b_clearAlarm, SIGNAL(clicked()), this, SLOT(clearAlarm()));
	connect(ui.b_blockAlarm, SIGNAL(clicked()), this, SLOT(blockAlarm()));

	changeAlarmTitle(TRUE); 
}

void MainWindow::getAlarm() {
	Command c(GUI_ALARM_COMMAND,GUI_SUBCOMMAND_GET_STATUS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::clearAlarm() {
	Command c(GUI_ALARM_COMMAND,GUI_SUBCOMMAND_CLEAR);
	c.end();
    cp.toQueue(c);
	for (int i=0;i<ALARMS_TYPES_NUM;i++) {
		pIndicators[i]->inactive();
	}
}

void MainWindow::blockAlarm() {
	Command c(GUI_ALARM_COMMAND,GUI_SUBCOMMAND_SET_BLOCK);
	c.end();
    cp.toQueue(c);
}

void MainWindow::changeAlarmTitle(int state) {
	if (state) {
		ui.groupBox_alarms->setTitle(tr("Alarmy [pow. włączone]"));
	} else {
		ui.groupBox_alarms->setTitle(tr("Alarmy [pow. WYŁĄCZONE]"));
	}
}

void MainWindow::setUiAlarms(uchar flags) {
	for (int i=0;i<ALARMS_TYPES_NUM;i++) {
		if (flags & _BV(i)) {
			pIndicators[i]->activeBlink();
		} else {
			pIndicators[i]->inactive();
		}	
	}
}
