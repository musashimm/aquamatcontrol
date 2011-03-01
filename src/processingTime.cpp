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

/** @file processingTime.cpp
@brief Implementacja głównego okna - funkcje związane z zarządzaniem czasem.

*/


void MainWindow::setUiDateTime(Command* c) {
	
	QString DW[] = {"Brak","Pn","Wt",tr("Śr"),"Cz","Pt","So","Ni"};
	int year = c->first();
	int month = c->next();
	int day = c->next();
	int hours = c->next();
	int minutes	= c->next();

	QDate date(year+2000,month,day);
	QTime time(hours,minutes);
	ui.e_dateTime->setDate(date);
	ui.e_dateTime->setTime(time);

	ui.l_dateTime->setText(QString("%1-%2-%3").arg(date.year(),2,10,QLatin1Char('0')).arg(date.month(),2,10,QLatin1Char('0')).arg(date.day(),2,10,QLatin1Char('0')));
	ui.l_dateTimeHour	->setText(QString("%1:%2 %3").arg(time.hour(),2,10,QLatin1Char('0')).arg(time.minute(),2,10,QLatin1Char('0')).arg(DW[date.dayOfWeek()]));
}

void MainWindow::setUiTimeDay(Command* c) {

	int hours_from = c->first();
	int minutes_from = c->next();
	int hours_to = c->next();
	int minutes_to = c->next();

	QTime time_from(hours_from,minutes_from);
	QTime time_to(hours_to,minutes_to);
	ui.e_timeDayFrom->setTime(time_from);
	ui.e_timeDayTo->setTime(time_to);

	//ui.l_timeDay->setText(QString("(%1:%2 - %3:%4)").arg(time_from.hour(),2,10,QLatin1Char('0')).arg(time_from.minute(),2,10,QLatin1Char('0')).arg(time_to.hour(),2,10,QLatin1Char('0')).arg(time_to.minute(),2,10,QLatin1Char('0')));
}

void MainWindow::setDateTime() {
	QDate date = ui.e_dateTime->date();
	QTime time = ui.e_dateTime->time();
	Command c(GUI_DATETIME_COMMAND,GUI_SUBCOMMAND_SET);
	c.add(date.year()-2000);
	c.add(date.month());
	c.append(date.day());
	if (date.dayOfWeek() == 7) {	//różnica między Qt a PCF8563
		c.add(0);
	} else {
		c.add(date.dayOfWeek());
	}
	c.add(time.hour());
	c.add(time.minute());
	c.end();
    cp.toQueue(c);
}

void MainWindow::setTimeDay() {
	QTime time;
	Command c(GUI_DAYTIME_COMMAND,GUI_SUBCOMMAND_SET);
	time = ui.e_timeDayFrom->time();
	c.add(time.hour());
	c.add(time.minute());
	time = ui.e_timeDayTo->time();
	c.add(time.hour());
	c.add(time.minute());
	c.end();
    cp.toQueue(c);
}

void MainWindow::getDateTime() {
	Command c(GUI_DATETIME_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::getTimeDay() {
	Command c(GUI_DAYTIME_COMMAND,GUI_SUBCOMMAND_GET_SETTINGS);
	c.end();
    cp.toQueue(c);
}

