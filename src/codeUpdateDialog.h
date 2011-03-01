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

/** @file codeUpdateDialog.h
@brief Plik nagłówkowy - Okienko postepu programowania
*/

#ifndef CLASSCODEUPDATEDIALOG_H
#define CLASSCODEUPDATEDIALOG_H

#include "ui_codeUpdateDialog.h"

class CodeUpdateDialog : public QDialog
{
	Q_OBJECT

public:
    CodeUpdateDialog(QWidget *parent = 0);

public slots:
	void cancelCodeUpdate();
	void setTitle(QString);
	void setProgress(int);

signals:
    void codeUpdateCanceled();

private:
  Ui::CodeUpdateDialog ui;
};

#endif
