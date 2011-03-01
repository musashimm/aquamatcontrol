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

/** @file aboutDialog.cpp
@brief Implementacja klasy okna About
*/

#include "aboutDialog.h"
#include "main.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
  	ui.setupUi(this);
		centerWindow(this);
}

void AboutDialog::setProgramName(QString name) {
	ui.label_programName->setText(name);
}

void AboutDialog::setProgramVersion(QString version) {
	ui.label_programVersion->setText(version);
}

void AboutDialog::setAuthor(QString name) {
	ui.label_author->setText(name);
}

void AboutDialog::setLogo(QPixmap pixmap) {
	ui.logoLabel->setPixmap(pixmap);
}

