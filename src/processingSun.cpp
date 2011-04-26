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

/** @file processingSun.cpp
	@brief Funkcje związane ze scenariuszem Słońce.

Klawisze do wysyłania i odbierania konfiguracji w GUI:
* b_sunScenarioGetSettings
* b_sunScenarioSetSettings
*/

void MainWindow::sunsInit() {
	for(int i=0;i < SUN_NUM ;i++) {
		SunScenario *sunScenario = new SunScenario(i,tr("Słońce"),pPwmSettings);
		pSunScenario[i]=sunScenario;
		ui.sunScenarioLayout->addWidget(sunScenario);
	}
	connect(ui.b_sunGet,SIGNAL(clicked()),this,SLOT(sunGet()));
	connect(ui.b_sunSet,SIGNAL(clicked()),this,SLOT(sunSet()));
}

void MainWindow::sunGet() {
	Command c(GUI_SUN,GUI_GET);
	c.end();
    cp.toQueue(c);
}

void MainWindow::sunSet() {
	for(int i=0;i<SUN_NUM;i++) {
	    Command c(GUI_SUN,GUI_SET);
        c.append(pSunScenario[i]->getAsArray());
        c.end();
        cp.toQueue(c);
    }
}

void MainWindow::sunsSave(QSettings* s) {
    s->beginWriteArray("Suns");
	for (int i = 0; i < SUN_NUM; i++) {
        pSunScenario[i]->save(s);
	}
 	s->endArray();
}

void MainWindow::sunsLoad(QSettings* s) {
    s->beginReadArray("Suns");
	for (int i = 0; i < SUN_NUM; i++) {
	    pSunScenario[i]->load(s);
 	}
 	s->endArray();
}

