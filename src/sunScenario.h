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

/** @file sunScenario.h
@brief Plik nagłówkowy - Scenariusz Słońce.

@image html sunScenario.png

@section sunScenario_components Komponenty GUI

- QTimeEdit/sunriseTime (srt)- godzina, o której zaczyna się wschód słońca
- QTimeEdit/sunsetTime (sst) - godzina, o której zaczyna się zachód słońca
- QSpinBox/minPower (mnp) - minimalna moc
- QSpinBox/maxPower (mxp)- maksymalna moc
- QCheckBox/keepPower (kp)- czy przy maksymalnej mocy, wyłączyć wyjście(czyli obsługujemy sam wschód i zachód)
- QSpinBox/numberOfSteps (nos) - liczba kroków przejścia
- QSpinBox/stepDuration (sd) - czas jednego kroku

@verbatim

	FLAGS

    7654|3210
    	    X - keepPower
    	    0 - nie
    	    1 - tak
	@endverbatim

Czas trwania wschodu/zachodu = numberOfSteps * stepDuration.

keepPower - przełącznik służy do wyłączenia wyjścia, kiedy już osiągnięto maxPower. W wiekszości przypadków wtedy już pracują inne źródła światła o wiele mocniejsze i nie ma sensu trzymać włączone np. diody LED.

@section sunScenario_gui Komendy

- pobranie konfiguracji

@verbatim

Komenda: <GUI_SUN><GUI_GET><CRC><GUI_EOC>
    Odp: <GUI_SUN><GUI_GET(RESPONSE_FLAG)><SRT_H><SRT_M><SST_H><SST_M><MNP><MXP><NOS><SD><FLAGS><CRC><GUI_EOC>

@endverbatim

- wysłanie konfiguracji

@verbatim

Komenda: <GUI_SUN><GUI_SET><SRT_H><SRT_M><SST_H><SST_M><MNP><MXP><NOS><SD><FLAGS><GUI_EOC>
    Odp: <GUI_SUN><GUI_SET(RESPONSE_FLAG)><GUI_EOC>

@endverbatim


*/

#ifndef CLASSSUNSCENARIO_H
#define CLASSSUNSCENARIO_H

#include "controlComponent.h"
#include "ui_sunScenario.h"
#include "comboBoxPwms.h"

#define SUN_COMPONENT_ID 0x94
#define SUN_COMPONENT_DESC "Sun"
#define KEEP_POWER_FLAG 0

class SunScenario :public ControlComponent {

	Q_OBJECT

	public:
		SunScenario(int,QString,PwmSettings* ppwms[],QWidget *parent = 0);

		static int getComponentId();
		static QString getComponentDesc();

        int getFlags();
		void setFlags(int);
        bool isActive();
        bool isBlocked();
        QByteArray getAsArray();
        void setAsArray(QByteArray);
        void changeOutputName(int,QString);
        void save(QSettings*);
        void load(QSettings*);

	private:
		Ui::SunScenario ui;
		ComboBoxPwms *pwm;
};

#endif
