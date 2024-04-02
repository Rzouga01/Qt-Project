QT += widgets charts uitools sql core gui quick network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


include(../QZXing/src/QZXing.pri)

include(../qtxlsx/QXlsx/QXlsx.pri)


CONFIG += c++11

INCLUDEPATH += ../QZXing/src
SOURCES += ../QZXing/src/QZXing.cpp \
    chatbot.cpp \
    qrcodedialog.cpp

SOURCES += sms.cpp
HEADERS += sms.h \
    chatbot.h

# The following line is not necessary if you are already including QZXing.pri,
# as it should handle the necessary includes and configurations.
# You can remove it unless you have specific reasons to keep it.
# INCLUDEPATH += /path/to/QZXing/headers

# Uncomment the following line if you want to disable deprecated APIs up to a certain version of Qt.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# You may want to add more directories to the INCLUDEPATH if needed for your project.

SOURCES += \
    accident.cpp \
    client.cpp \
    connection.cpp \
    contract.cpp \
    dashboard.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp


HEADERS += \
    accident.h \
    client.h \
    connection.h \
    contract.h \
    dashboard.h \
    employee.h \
    mainwindow.h \
    ../QZXing/src/QZXing.h \
    qrcodedialog.h

FORMS += \
    accident.ui \
    chatbot.ui \
    client.ui \
    contract.ui \
    dashboard.ui \
    employee.ui \
    mainwindow.ui \
    qrcodedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Menu.qml \
    MenuForm.ui.qml
