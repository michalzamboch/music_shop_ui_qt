QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    artist.cpp \
    artistwindow.cpp \
    basewindow.cpp \
    detailemployeeform.cpp \
    detailform.cpp \
    employee.cpp \
    employeewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    record.cpp \
    recordwindow.cpp \
    selladdform.cpp

HEADERS += \
    Generic.h \
    artist.h \
    artistwindow.h \
    basewindow.h \
    detailemployeeform.h \
    detailform.h \
    employee.h \
    employeewindow.h \
    mainwindow.h \
    record.h \
    recordwindow.h \
    selladdform.h

FORMS += \
    detailemployeeform.ui \
    detailform.ui \
    mainwindow.ui \
    selladdform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
