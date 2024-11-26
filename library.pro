QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminfirstpage.cpp \
    listofbooks.cpp \
    main.cpp \
    mainwindow.cpp \
    newaddedbooks.cpp \
    signinginforadmins.cpp \
    signinginforstrudents.cpp \
    signingupforadmins.cpp \
    signingupforstudents.cpp \
    studentfirstpage.cpp

HEADERS += \
    adminfirstpage.h \
    listofbooks.h \
    mainwindow.h \
    newaddedbooks.h \
    signinginforadmins.h \
    signinginforstrudents.h \
    signingupforadmins.h \
    signingupforstudents.h \
    studentfirstpage.h

FORMS += \
    adminfirstpage.ui \
    listofbooks.ui \
    mainwindow.ui \
    newaddedbooks.ui \
    signinginforadmins.ui \
    signinginforstrudents.ui \
    signingupforadmins.ui \
    signingupforstudents.ui \
    studentfirstpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
