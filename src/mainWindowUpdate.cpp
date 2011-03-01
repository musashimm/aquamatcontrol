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

#include "mainWindow.h"

void MainWindow::chooseUpdateFile() {
    QString fileName;
    QFileInfo *fileInfo;
    ui.b_codeUpdate->setEnabled(false);
    fileName = QFileDialog::getOpenFileName(this,tr("Wybierz plik z oprogramowaniem"), ".", tr("Pliki Intel Hex (*.hex)"));
    if (!fileName.isEmpty()) {
        fileInfo = new QFileInfo(fileName);
        ui.l_updateFileName->setText(fileInfo->fileName());
        if (fileInfo->isReadable()) {
            codeUpdate.prepareFromIntelHex(fileName);

            ui.l_updateFileInfo->setText(QString("Format: %1, Rozmiar: %2 bajtów (%3 bl.)").arg(codeUpdate.getStatusString()).arg(codeUpdate.byteSize()).arg(codeUpdate.blockSize()));

            if (codeUpdate.getStatus() == CodeUpdate::INTELHEX) {
                ui.b_codeUpdate->setEnabled(true);
            }
        }
    }
}

void MainWindow::showUpdateDialog() {
    CodeUpdateDialog cud(this);
    cud.setTitle("Programowanie...");
    connect(&cud, SIGNAL(codeUpdateCanceled()), cut, SLOT(cancel()));
    connect(cut, SIGNAL(progress(int)), &cud, SLOT(setProgress(int)));
    connect(cut, SIGNAL(finished()), &cud, SLOT(close()));
    cud.exec();
}

//void MainWindow::runCodeUpdate() {
//    cut.start();
//}




