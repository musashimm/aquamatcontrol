# #####################################################################
# Automatically generated by qmake (2.01a) ?r. lis 11 14:50:38 2009
# #####################################################################
TEMPLATE = app
TARGET = aquamatcontrol
DESTDIR = dist
DEPENDPATH += . \
    src
CONFIG += release
CONFIG -= debug_and_release \
    debug
win32 {
    LIBS += -L..\fancy_widgets\dist \
        -L..\qextserialport\src\build
    LIBS += -lfancywidgets1 \
        -lqextserialport1
    INCLUDEPATH += . \
        src \
        ..\fancy_widgets\src \
        ..\qextserialport\src
}
unix {
    QMAKE_EXTRA_TARGETS += docs
    docs.commands = doxygen files/Doxyfile
    docs.path = docs
    docs.depends = FORCE
    LIBS += -lfancywidgets \
        -lqextserialport
    INCLUDEPATH += . \
        src \
        /usr/local/include
}
OBJECTS_DIR = obj
MOC_DIR = obj
UI_DIR = src
RCC_DIR += resources

# Input
HEADERS += src/aboutDialog.h \
    src/codeUpdateThread.h \
    src/CodeUpdateDialog.h \
    src/codeUpdate.h \
    src/comboBoxOuts.h \
    src/comboBoxWeekDay.h \
    src/command.h \
    src/commandProcessor.h \
    src/commandsDefs.h \
    src/commonDefs.h \
    src/main.h \
    src/mainWindow.h \
    src/outDisplay.h \
    src/outSettings.h \
    src/refreshThread.h \
    src/tempDisplay.h \
    src/temperature.h \
    src/tempSettings.h \
    src/timersSettings.h \
    src/timersvSettings.h \
    src/processingTemp.cpp \
    src/processingTime.cpp \
    src/processingAlarm.cpp \
    src/processingOut.cpp \
    src/processingTopOff.cpp \
    src/processingTimers.cpp \
    src/processingTimersv.cpp \
    src/processingEvents.cpp \
    src/comboBoxQButtons.h
FORMS += src/aboutDialog.ui \
    src/mainWindow.ui \
    src/outSettings.ui \
    src/tempSettings.ui \
    src/timersSettings.ui \
    src/timersvSettings.ui \
    src/codeUpdateDialog.ui
SOURCES += src/aboutDialog.cpp \
    src/codeUpdateThread.cpp \
    src/CodeUpdateDialog.cpp \
    src/codeUpdate.cpp \
    src/comboBoxOuts.cpp \
    src/comboBoxWeekDay.cpp \
    src/command.cpp \
    src/commandProcessor.cpp \
    src/main.cpp \
    src/mainWindow.cpp \
    src/mainWindowAbout.cpp \
    src/mainWindowUpdate.cpp \
    src/outDisplay.cpp \
    src/outSettings.cpp \
    src/processingAlarm.cpp \
    src/processingEvents.cpp \
    src/processingOut.cpp \
    src/processingTemp.cpp \
    src/processingTime.cpp \
    src/processingTimers.cpp \
    src/processingTimersv.cpp \
    src/processingTopOff.cpp \
    src/refreshThread.cpp \
    src/tempDisplay.cpp \
    src/temperature.cpp \
    src/tempSettings.cpp \
    src/timersSettings.cpp \
    src/timersvSettings.cpp \
    src/comboBoxQButtons.cpp
RESOURCES += resources/aquamatcontrol.qrc
OTHER_FILES += Makefile \
    Makefile.Release \
    README \
    files/Doxyfile \
    README.PL \
    README.EN
