QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../console/PSX.cpp \
    ../../console/PSXMSFS.cpp \
    ../../console/connect.cpp \
    ../../console/gui.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../console/Include/SimConnect.h \
    ../../console/PSXMSFS.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += \
    ../../console/Include

DISTFILES += \
    ../../console/Include/SimConnect.dll


win32: LIBS += -L$$PWD/../../console/Include/ -lSimConnect

INCLUDEPATH += $$PWD/../../console/Include
DEPENDPATH += $$PWD/../../console/Include

win32: LIBS += -LC:/Qt/Tools/mingw1120_64/x86_64-w64-mingw32/lib/ -lws2_32

INCLUDEPATH += C:/Qt/Tools/mingw1120_64/x86_64-w64-mingw32/include
DEPENDPATH += C:/Qt/Tools/mingw1120_64/x86_64-w64-mingw32/include
