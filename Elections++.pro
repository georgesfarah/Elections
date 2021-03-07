QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    adminwindow.cpp \
    candidat.cpp \
    electeur.cpp \
    electionwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    tuto.cpp

HEADERS += \
    about.h \
    adminwindow.h \
    candidat.h \
    electeur.h \
    electionwindow.h \
    mainwindow.h \
    tuto.h

FORMS += \
    about.ui \
    adminwindow.ui \
    electionwindow.ui \
    mainwindow.ui \
    tuto.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../About_1/About_1.pro

DISTFILES +=

RESOURCES += \
    lang.qrc
