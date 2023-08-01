QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logging.cpp \
    main.cpp \
    psxmsfsclient.cpp

HEADERS += \
    PSXMSFS.h \
    logging.h \
    psxmsfsclient.h

FORMS += \
    psxmsfsclient.ui

QT += \
    concurrent
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../PSXMSFS/x64/release/ -lPSXMSFS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../PSXMSFS/x64/debug/ -lPSXMSFS

INCLUDEPATH += $$PWD/../../PSXMSFS/x64/Release
DEPENDPATH += $$PWD/../../PSXMSFS/x64/Release

RC_ICONS = plane.ico
