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

/** @file controlComponent.cpp
@brief Implementacja klasy bazowej dla wszystkich komponentów.
*/

#include <QWidget>
#include "controlComponent.h"

QList<ControlComponent*> ControlComponent::controls;

ControlComponent::ControlComponent(int id, QString name, QWidget *parent):QWidget(parent) {
  	this->id=id;
  	this->name=name;
  	controls << this;
}

int ControlComponent::getId() {
    return id;
}

bool ControlComponent::wasNameModified() {
    return wasNameModifiedFlag;
}

bool ControlComponent::wasModified() {
    return wasModifiedFlag;
}

QString ControlComponent::getName() {
    wasNameModifiedFlag = false;
    return name;
}

void ControlComponent::setName(QString name) {
    this->name = name;
    wasNameModifiedFlag = true;
}
