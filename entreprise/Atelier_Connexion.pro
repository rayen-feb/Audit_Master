#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT+= sql
QT += printsupport
QT +=charts
QT += widgets printsupport
QT       += core gui sql
QT       +=  core gui charts
QT += axcontainer
QT+ =sql
QT       += core gui sql printsupport network svg multimedia multimediawidgets
QT += widgets charts
LIBS += -L/path/to/qt/lib -lQt5Charts

QT       += core gui
QT += printsupport
QT += core gui sql
QT += network
QT += printsupport
QT += charts
QT +=multimedia
QT +=serialport
QT += widgets

QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
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
    arduino.cpp \
    auditeur.cpp \
    entreprise.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    normes.cpp \
    notification.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    randomstringgenerator.cpp \
    rapport.cpp \
    recaptcha.cpp \
    stmp.cpp \
    videoplayerwidget.cpp

HEADERS += \
    arduino.h \
    auditeur.h \
    entreprise.h \
        mainwindow.h \
    connection.h \
    normes.h \
    notification.h \
    qcustomplot.h \
    qrcode.h \
    qrcodegeneratorworker.h \
    qrwidget.h \
    randomstringgenerator.h \
    rapport.h \
    recaptcha.h \
    stmp.h \
    videoplayerwidget.h

FORMS += \
        mainwindow.ui \
        recaptcha.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
