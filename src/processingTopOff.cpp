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

/** @file processingTopOff.cpp
@brief Funkcje związane z automatyczną dolewką.
*/

/** @todo
  nie widać stanu pinu zablokowania pracy automatyczej dolewki
  */

void MainWindow::topOffInit() {
	topOff_max_sump_status = new Indicator(this,"Maksymalny poziom");
	ui.adStatusLayout->addWidget(topOff_max_sump_status);
	topOff_min_sump_status = new Indicator(this,"Minimalny poziom");
	ui.adStatusLayout->addWidget(topOff_min_sump_status);
	
    topOff_block_by_pin = new IndicatorL(this,"Blokada sprzętowa");
    ui.topOffIndicatorsLayout->addWidget(topOff_block_by_pin);

	topOff_max_sump = new Indicator(ui.topOffGroupBox,"Maks. poziom");
	topOff_max_sump->setGeometry(QRect(28, 140, 132, 35));
	topOff_min_sump = new Indicator(ui.topOffGroupBox,"Min. poziom");
	topOff_min_sump->setGeometry(QRect(28, 232, 132, 35));
	topOff_min_ro = new IndicatorL(ui.topOffGroupBox,"Min. poziom RO");
    topOff_min_ro->setGeometry(QRect(600, 200, 140, 35));
    topOff_max_run_indicator = new IndicatorL(ui.topOffGroupBox,"Przekr. czas pracy");
    //topOff_max_run_indicator->setGeometry(QRect(588, 224, 132, 35));
	topOff_running = new Indicator(this,"Praca AD");
	ui.topOffLayout->insertWidget(0,topOff_running);
	topOffOut = new ComboBoxOuts(pOutSettings,this);
	ui.topOffLayout->insertWidget(2,topOffOut);
    ui.topOffLayout->insertWidget(1,topOff_max_run_indicator);


	connect(ui.b_getTopOff, SIGNAL(clicked()), this, SLOT(getTopOff()));
	connect(ui.b_setTopOff, SIGNAL(clicked()), this, SLOT(setTopOff()));
	connect(ui.b_clearTopOff, SIGNAL(clicked()), this, SLOT(clearTopOff()));
}

void MainWindow::getTopOff() {
	Command c(GUI_TOP_OFF_COMMAND,GUI_SUBCOMMAND_GET_STATUS);
	c.end();
    cp.toQueue(c);
}

void MainWindow::setUiTopOff(Command* c) {
	uchar flags = c->first();
	uchar out = c->next();
	uchar max_run = c->next();

   ui.topOff_block->setChecked(flags & _BV(TOP_OFF_BLOCK));

   if (flags & _BV(TOP_OFF_BLOCK_BY_PIN)) {
       topOff_block_by_pin->block();
   } else {
       topOff_block_by_pin->inactive();
   }

	if (flags & _BV(TOP_OFF_BLOCK_MIN_RO)) {
		ui.topOff_block_min_ro->setCheckState(Qt::Checked);
		topOff_min_ro->block();
	} else {
		ui.topOff_block_min_ro->setCheckState(Qt::Unchecked);
		if (flags & _BV(TOP_OFF_MIN_RO)) {
			topOff_min_ro->activeBlink();
		} else {
			topOff_min_ro->inactive();
		}
	}
	if (flags & _BV(TOP_OFF_MAX_RUN_REACHED)) {
		topOff_max_run_indicator->activeBlink();
	} else {
		topOff_max_run_indicator->inactive();
	}
	if (flags & _BV(TOP_OFF_MAX_SUMP)) {
		topOff_max_sump->active();
		topOff_max_sump_status->active();
	} else {
		topOff_max_sump->inactive();
		topOff_max_sump_status->inactive();
	}
	if (flags & _BV(TOP_OFF_MIN_SUMP)) {
		topOff_min_sump->active();
		topOff_min_sump_status->active();
	} else {
		topOff_min_sump->inactive();
		topOff_min_sump_status->inactive();
	}
	if (flags & _BV(TOP_OFF_MIN_RO)) {
		topOff_min_ro->activeBlink();
	} else {
		topOff_min_ro->inactive();
	}
	if (flags & _BV(TOP_OFF_RUNNING)) {
		topOff_running->active();
	} else {
		topOff_running->inactive();
	}
	topOffOut->set(out);
	ui.topOff_max_run->setValue(max_run);
}

void MainWindow::setTopOff() {
	uchar flags = 0;
	Command c(GUI_TOP_OFF_COMMAND,GUI_SUBCOMMAND_SET);
	
	if (ui.topOff_block_min_ro->isChecked()){
		flags |= _BV(TOP_OFF_BLOCK_MIN_RO);
	}
	if (ui.topOff_block->isChecked()){
		flags |= _BV(TOP_OFF_BLOCK);
	}
	c.add(flags);
	c.add(topOffOut->get());
	c.add(ui.topOff_max_run->value());
	c.end();
    cp.toQueue(c);
}

void MainWindow::clearTopOff() {
	Command c(GUI_TOP_OFF_COMMAND,GUI_SUBCOMMAND_CLEAR);
	c.end();
    cp.toQueue(c);
}
