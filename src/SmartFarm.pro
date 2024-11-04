#include<QDebug>
QT+=sql
QT += network
#include <QMessageBox>
CONFIG += c ++11
QT +=printsupport
QT +=  core gui   serialport
#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT += core gui network
QT += serialport
QT += printsupport


QT += charts
QT += core gui printsupport charts
TARGET = ChatBox

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartFarm
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
    STMP/src/emailaddress.cpp \
    STMP/src/mimeattachment.cpp \
    STMP/src/mimecontentformatter.cpp \
    STMP/src/mimefile.cpp \
    STMP/src/mimehtml.cpp \
    STMP/src/mimeinlinefile.cpp \
    STMP/src/mimemessage.cpp \
    STMP/src/mimemultipart.cpp \
    STMP/src/mimepart.cpp \
    STMP/src/mimetext.cpp \
    STMP/src/quotedprintable.cpp \
    arduino.cpp \
    arduino1.cpp \
    chatbot.cpp \
    chatbox.cpp \
    client.cpp \
    dialog.cpp \
    employes.cpp \
    image.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    numberformatdelegate.cpp \
    numero.cpp \
    oublie_pwd.cpp \
    plante.cpp \
    produit.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtpclient.cpp\
    animaux.cpp \
    dialog3.cpp \
    dialog4.cpp \
    dialog5.cpp \
    clientclass.cpp \
    connectdialogc.cpp \
    mymessage.cpp \
    serverclass.cpp \

HEADERS += \
    STMP/src/SmtpMime \
    STMP/src/emailaddress.h \
    STMP/src/mimeattachment.h \
    STMP/src/mimecontentformatter.h \
    STMP/src/mimefile.h \
    STMP/src/mimehtml.h \
    STMP/src/mimeinlinefile.h \
    STMP/src/mimemessage.h \
    STMP/src/mimemultipart.h \
    STMP/src/mimepart.h \
    STMP/src/mimetext.h \
    STMP/src/quotedprintable.h \
    STMP/src/smtpexports.h \
    arduino.h \
    arduino1.h \
    chatbot.h \
    chatbox.h \
    client.h \
    dialog.h \
    employes.h \
    image.h \
    mainwindow.h \
    connection.h \
    numberformatdelegate.h \
    numero.h \
    oublie_pwd.h \
    plante.h \
    produit.h \
    qcustomplot.h \
    qrcode.h \
    smtpclient.h\
    animaux.h \
    dialog3.h \
    dialog4.h \
    dialog5.h \
    clientclass.h \
    connectdialogc.h \
    mymessage.h \
    serverclass.h \

FORMS += \
    chatbot.ui \
        dialog.ui \
        mainwindow.ui \
        oublie_pwd.ui\
        dialog3.ui \
        dialog4.ui \
        dialog5.ui \
        ConnectDialog.ui \
        chatbox.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    STMP/SMTPEmail.pro

DISTFILES += \
    STMP/LICENSE \
    STMP/README.md

RESOURCES += \
    images.qrc
