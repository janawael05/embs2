QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    BookingConfirmation.cpp \
    BookingHistory.cpp \
    Event.cpp \
    EventBrowsingandBooking.cpp \
    User.cpp \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforadmins.cpp \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforuser.cpp \
    main.cpp \
    AdminDashboard.cpp \
    mainwindow.cpp

HEADERS += \
    Admin.h \
    AdminDashboard.h \
    BookingConfirmation.h \
    BookingHistory.h \
    Event.h \
    EventBrowsingandBooking.h \
    User.h \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforadmins.h \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforuser.h \
    mainwindow.h

FORMS += \
    AdminDashboard.ui \
    BookingConfirmation.ui \
    BookingHistory.ui \
    EventBrowsingandBooking.ui \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforadmins.ui \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/loginforuser.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
