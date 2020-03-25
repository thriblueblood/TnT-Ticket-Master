#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T11:53:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
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
        ariana_grande.cpp \
        ariana_seat.cpp \
        ed_seat.cpp \
        ed_sheeran.cpp \
        history.cpp \
        login_1.cpp \
        main.cpp \
        mainwindow.cpp \
        payment.cpp \
        pictur_display.cpp \
        register.cpp \
        savage.cpp \
        savage_seat.cpp \
        stage_show.cpp \
        the_vamps.cpp \
        theend.cpp \
        vamps_seat.cpp

HEADERS += \
        ariana_grande.h \
        ariana_seat.h \
        ed_seat.h \
        ed_sheeran.h \
        history.h \
        login_1.h \
        mainwindow.h \
        payment.h \
        pictur_display.h \
        register.h \
        savage.h \
        savage_seat.h \
        stage_show.h \
        the_vamps.h \
        theend.h \
        vamps_seat.h

FORMS += \
        ariana_grande.ui \
        ariana_seat.ui \
        ed_seat.ui \
        ed_sheeran.ui \
        history.ui \
        login_1.ui \
        mainwindow.ui \
        payment.ui \
        register.ui \
        savage.ui \
        savage_seat.ui \
        stage_show.ui \
        the_vamps.ui \
        theend.ui \
        vamps_seat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
