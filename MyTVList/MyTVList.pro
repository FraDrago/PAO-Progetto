#-------------------------------------------------
#
# Project created by QtCreator 2019-08-26T22:06:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTVList
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        GUI/aggiungielemento.cpp \
        GUI/generedocum.cpp \
        GUI/generetv.cpp \
        GUI/proxymodel.cpp \
        GUI/qlistmodel.cpp \
        GUI/tipotv.cpp \
        GUI/visualizzalayout.cpp \
        Gerarchia/completo.cpp \
        Gerarchia/documentario.cpp \
        Gerarchia/film.cpp \
        Gerarchia/serietv.cpp \
        main.cpp \
        mainwindow.cpp \
        modello.cpp

HEADERS += \
        GUI/aggiungielemento.h \
        GUI/generedocum.h \
        GUI/generetv.h \
        GUI/proxymodel.h \
        GUI/qlistmodel.h \
        GUI/tipotv.h \
        GUI/visualizzalayout.h \
        Gerarchia/completo.h \
        Gerarchia/documentario.h \
        Gerarchia/film.h \
        Gerarchia/qontainer.h \
        Gerarchia/serietv.h \
        mainwindow.h \
        modello.h

FORMS += \
        mainwindow.ui

RC_ICONS = ../MyTVList/icon/tv.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
