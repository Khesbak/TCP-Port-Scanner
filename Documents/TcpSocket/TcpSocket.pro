QT       += core
QT       += network
QT       -= gui
QT       += widgets
QT       += concurrent



TARGET = QTcpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH += .

SOURCES += \
    dialog.cpp \
    main.cpp \
    mytcpsocket.cpp

HEADERS += \
    dialog.h \
    mytcpsocket.h

FORMS += \
    dialog.ui
