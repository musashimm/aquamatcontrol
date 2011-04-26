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

/** @file processingPwm.cpp
	@brief Funkcje związane z wyjściami PWM.
*/

void MainWindow::pwmInit() {
	for(int i=0;i < PWM_NUM ;i++) {
		PwmSettings *pwmSettings = new PwmSettings(i,"abcde");
		pPwmSettings[i]=pwmSettings;
		ui.pwmSettingsLayout->addWidget(pwmSettings,0,i);
		connect(pPwmSettings[i],SIGNAL(stateChanged(int,int,int)),this,SLOT(pwmStateChanged(int,int,int)));
		connect(pPwmSettings[i],SIGNAL(nameChangedSignal(int,QString)),this,SLOT(pwmPropagateName(int,QString)));
	}
	connect(ui.b_pwmGetConfig,SIGNAL(clicked()),this,SLOT(pwmGetSettings()));
	connect(ui.b_pwmSendConfig,SIGNAL(clicked()),this,SLOT(pwmSendSettings()));
}

void MainWindow::pwmPropagateName(int id,QString name) {
	for (int i=0;i<SUN_NUM;i++) {
		pSunScenario[i]->changeOutputName(id,name);
	}
}

void MainWindow::pwmStateChanged(int id,int pwm,int flags) {
	Command c(GUI_PWM,GUI_SET);
	c.append((uchar)id);
	c.append((uchar)pwm);
	c.append((uchar)flags);
	c.end();
	cp.toQueue(c);
}

void MainWindow::pwmGetSettings() {
	Command c(GUI_PWM,GUI_GET|_BV(GUI_EXTRA_FLAG));
	c.end();
    cp.toQueue(c);
}

void MainWindow::pwmSendSettings() {
	for(int i=0;i<PWM_NUM;i++) {
	    if (pPwmSettings[i]->isNameChanged()) {
            Command c(GUI_PWM,GUI_SET|_BV(GUI_EXTRA_FLAG));
            c.append(pPwmSettings[i]->getSettingsArray());
            c.end();
            cp.toQueue(c);
	    }
	}
}

PwmSettings* MainWindow::getPwmSetting(int id) {
        return pPwmSettings[id];
}

void MainWindow::pwmSaveSettings(QSettings* s) {
    s->beginWriteArray("Pwms");
	for (int i = 0; i < PWM_NUM; i++) {
     	s->setArrayIndex(i);
     	s->setValue("pwm", pPwmSettings[i]->getPwm());
     	s->setValue("blocked", pPwmSettings[i]->isBlocked());
     	s->setValue("name", pPwmSettings[i]->getName());
 	}
 	s->endArray();
}

void MainWindow::pwmLoadSettings(QSettings* s) {
    int flags;
    s->beginReadArray("Pwms");
	for (int i = 0; i < PWM_NUM; i++) {
     	s->setArrayIndex(i);
     	flags = 0;
     	if (s->value("blocked").toBool()) {
     	    flags |= _BV(PWM_FLAG_BLOCKED);
     	}
     	pPwmSettings[i]->newSettings(s->value("pwm").toInt(),flags,s->value("name","?????").toString());
 	}
 	s->endArray();
}
