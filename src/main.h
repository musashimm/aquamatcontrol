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

/** @file main.h
@brief Plik nagłówkowy aplikacji
*/

/** @namespace Ui
  @brief Przestrzeń nazw związana z komponentami interfejsu użytkownika
*/

#ifndef MAIN_H
#define MAIN_H

#include "commonDefs.h"

#define STRINGIFY2(x) #x
#define STRINGIFY(x) STRINGIFY2(x)

#define PROJECT_NAME "AquamatControl"
#define PROJECT_VERSION_MAIN 1
#define PROJECT_VERSION_MAJOR 5
#define PROJECT_VERSION_MINOR 0
#define PROJECT_LOGO ":/resources/logocontrol.png"
#define PROJECT_AUTHOR "Copyright (C) 2009 Wojciech Todryk"

#define PROJECT_VERSION  STRINGIFY(PROJECT_VERSION_MAIN) "." STRINGIFY(PROJECT_VERSION_MAJOR) "." STRINGIFY(PROJECT_VERSION_MINOR)
#define PROJECT_FULL_NAME PROJECT_NAME " " PROJECT_VERSION

void centerWindow (QWidget * widget);

/**
@file main.h Plik nagłówkowy

 @mainpage Dokumentacja projektu AquamatControl

 @section introduction Wstęp

Projekt <em>AquamatControl</em> jest interfejsem graficznym do konfiguracji i monitorowania pracy sterownika akwariowego <em>Aquamat</em> Protokół komunikacji programu i sterownika został opisany w rozdziale @ref protocol.

Projekt jest objety licencją GPLv2. Pełny tekst licencji znajduje się w pliku COPYING.

Projekt rozwijany jest dla dwóch platform: Linuksa i Windows.

W projekcie zostały wykorzystane zewnętrzne kody źródłowe:
- Qt - biblioteka graficzna - (http://qt.nokia.com/) - wersja 4.6
- Fancy Widgets - moja własna niewielka biblioteka komponentów QT - (http://todryk.pl/fancy-widgets) - wersja 1.1.0
- QExtSerialPort - biblioteka interfejsu szeregowego - (http://code.google.com/p/qextserialport) wersja 1.2.0

 @image html functions.png

 @section installation Instalacja

 @verbatim
    qmake;
    make clean;
    make;
 @endverbatim

 @section running Uruchomienie

Żeby program zadziałał pod Win32 niezbędne są następujące pliki:
- aquamatcontrol.exe
- fancywidgets1.dll
- libgcc_s_dw2-1.dll
- mingwm10.dll
- qextserialport1.dll
- QtCore4.dll
- QtGui4.dll

Pod Linuksem odpowiedniki powyższych bibliotek muszą być zainstalowane w systemie W rozdziale @ref ldd wylistowano wszystkie biblioteki dołączane dynamicznie w systemie Linux.

 @section structure Struktura katalogów i plików projektu

- dist - miejse na wersję binarną projektu
- docs - katalog dokumentacji
- files - pliki związane z projektem
- src - źródła projektu
- templates - wzorce plików
- aquamatcontrol.pro - plik z opisem projektu dla qmake'a
- COPYING - pełny tekst licencji GPLv2
- Makefile - wiadomo

 @section other Dodatkowe strony

- @ref protocol
- @ref ldd
- @ref history

 @page history Historia zmian

- 1.3.11
 - usunięcie wysyłanie znaku ETB w przy programowaniu pamięci

- 1.3.10
 - poprawki w dialogu postępu programowania

- 1.3.0
 - aktualizacja oprogramowania poprzez bootloader

- 1.2.6
 - poprawki w konfiguracji transmisji

- 1.2.5
 - sygnalizacja sprzętowej blokady automatycznej dolewki
 - poprawa wyświetlania adresu czujników temperatury
 - poprawka wyświetlania historii
 - poprawki w obsłudze QExtSerialPort

- 1.2.0
 - wykorzystanie biblioteki QExtSerialPort
 - zapis i odczyt parametrów konfiguracyjnych pracy sterownika (domyślne miejsce zapisu zależy od platformy, można też wskazać dowolny plik
 - zapis do pliku historii zdarzeń pracy sterownika

- 1.1.0
 - rozdzielenie biblioteki komponentów Fancy Widgets od głównego projektu

- 1.0.0
 - pierwsza wersja

 @page ldd Biblioteki współdzielone

 Poniżej przedstawiono bibliteki dołączane w czasie uruchamiania programu:

  @verbatim
   linux-gate.so.1 =>  (0xffffe000)
   libfancywidgets.so => /usr/local/lib/libfancywidgets.so (0xb781e000)
   libqextserialport.so.1 => /usr/local/lib/libqextserialport.so.1 (0xb7811000)
   libQtGui.so.4 => /usr/lib/qt4/libQtGui.so.4 (0xb6d9a000)
   libQtCore.so.4 => /usr/lib/qt4/libQtCore.so.4 (0xb6b16000)
   libgthread-2.0.so.0 => /usr/lib/libgthread-2.0.so.0 (0xb6b10000)
   librt.so.1 => /lib/librt.so.1 (0xb6b06000)
   libglib-2.0.so.0 => /usr/lib/libglib-2.0.so.0 (0xb6a36000)
   libpthread.so.0 => /lib/libpthread.so.0 (0xb6a1f000)
   libstdc++.so.6 => /usr/lib/gcc/i686-pc-linux-gnu/4.4.3/libstdc++.so.6 (0xb692f000)
   libm.so.6 => /lib/libm.so.6 (0xb690a000)
   libgcc_s.so.1 => /usr/lib/gcc/i686-pc-linux-gnu/4.4.3/libgcc_s.so.1 (0xb68eb000)
   libc.so.6 => /lib/libc.so.6 (0xb67b3000)
   libQtScript.so.4 => /usr/lib/qt4/libQtScript.so.4 (0xb650e000)
   libQtXml.so.4 => /usr/lib/qt4/libQtXml.so.4 (0xb64c8000)
   libpng12.so.0 => /usr/lib/libpng12.so.0 (0xb64a4000)
   libfreetype.so.6 => /usr/lib/libfreetype.so.6 (0xb6421000)
   libgobject-2.0.so.0 => /usr/lib/libgobject-2.0.so.0 (0xb63e3000)
   libSM.so.6 => /usr/lib/libSM.so.6 (0xb63da000)
   libICE.so.6 => /usr/lib/libICE.so.6 (0xb63c2000)
   libXrender.so.1 => /usr/lib/libXrender.so.1 (0xb63ba000)
   libXrandr.so.2 => /usr/lib/libXrandr.so.2 (0xb63b4000)
   libfontconfig.so.1 => /usr/lib/libfontconfig.so.1 (0xb6386000)
   libXext.so.6 => /usr/lib/libXext.so.6 (0xb6375000)
   libX11.so.6 => /usr/lib/libX11.so.6 (0xb625d000)
   libz.so.1 => /lib/libz.so.1 (0xb624d000)
   libdl.so.2 => /lib/libdl.so.2 (0xb6249000)
   libQtDesigner.so.4 => /usr/lib/qt4/libQtDesigner.so.4 (0xb5b46000)
   /lib/ld-linux.so.2 (0xb7849000)
   libexpat.so.1 => /usr/lib/libexpat.so.1 (0xb5b25000)
   libxcb.so.1 => /usr/lib/libxcb.so.1 (0xb5b0a000)
   libXau.so.6 => /usr/lib/libXau.so.6 (0xb5b07000)
   libXdmcp.so.6 => /usr/lib/libXdmcp.so.6 (0xb5b02000)
 @endverbatim


*/

#endif

