#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T12:01:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = BalloonGame
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    balloon.cpp \
    mytime.cpp \
    score.cpp \
    button.cpp \
    gameresult.cpp

HEADERS  += \
    game.h \
    balloon.h \
    mytime.h \
    score.h \
    button.h \
    gameresult.h

FORMS    +=

RESOURCES += \
    sounds.qrc
