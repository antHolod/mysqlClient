QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Forms/Dialogs/emptypassdialog.cpp \
    Forms/connectionform.cpp \
    connectors/mysqlconnector.cpp \
    connectors/sqliteconnector.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Forms/Dialogs/emptypassdialog.h \
    Forms/connectionform.h \
    connectors/mysqlconnector.h \
    connectors/sqliteconnector.h \
    defines.h \
    mainwindow.h

FORMS += \
    Forms/Dialogs/emptypassdialog.ui \
    Forms/connectionform.ui \
    mainwindow.ui

TRANSLATIONS += \
    DBClient_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
