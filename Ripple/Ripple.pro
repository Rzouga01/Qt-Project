QT += widgets charts uitools sql core gui quick network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

include(../QZXing/src/QZXing.pri)
include(../qtxlsx/QXlsx/QXlsx.pri)

CONFIG += c++11
INCLUDEPATH += $$PWD/portaudio/include
INCLUDEPATH += $$PWD/libsndfile/include
INCLUDEPATH += ../QZXing/src
SOURCES += ../QZXing/src/QZXing.cpp \
    chatbot.cpp \
    map.cpp \
    qrcodedialog.cpp

SOURCES += sms.cpp
HEADERS += sms.h \
    chatbot.h \
    map.h
INCLUDEPATH += $$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/include/c_api
DEPENDPATH  += $$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/include/c_api
INCLUDEPATH += $$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/include/cxx_api
DEPENDPATH  += $$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/include/cxx_api

LIBS += -lUser32 -lAdvapi32

# Add PortAudio library for release configuration
win32:CONFIG(release, debug|release) {
    LIBS += -L$$PWD/portaudio/build/Release -lportaudio
} else:win32:CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/portaudio/build/Debug -lportaudio
}

# Add PortAudio library for x64 platform
x64:CONFIG(release, debug|release) {
    LIBS += -L$$PWD/portaudio/build/Release -lportaudio
} else:x64:CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/portaudio/build/Debug -lportaudio
}
LIBS += -L$$PWD/libsndfile/lib

# Add library files for different configurations
win32:CONFIG(release, debug|release) {
    LIBS += -lsndfile
} else:win32:CONFIG(debug, debug|release) {
    LIBS += -lsndfile
}

x64:CONFIG(release, debug|release) {
    LIBS += -lsndfile
} else:x64:CONFIG(debug, debug|release) {
    LIBS += -lsndfile
}

TEMPLATE = app

SOURCES += \
    ../QZXing/src/QZXing.cpp \
    chatbot.cpp \
    qrcodedialog.cpp \
    sms.cpp \
    accident.cpp \
    client.cpp \
    SqlConn.cpp \
    contract.cpp \
    dashboard.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    arduino.cpp


HEADERS += \
    sms.h \
    chatbot.h \
    accident.h \
    client.h \
    sqlConn.h \
    contract.h \
    dashboard.h \
    employee.h \
    mainwindow.h \
    ../QZXing/src/QZXing.h \
    qrcodedialog.h \
    arduino.h

FORMS += \
    accident.ui \
    chatbot.ui \
    client.ui \
    contract.ui \
    dashboard.ui \
    employee.ui \
    mainwindow.ui \
    map.ui \
    qrcodedialog.ui

# Configuration for Windows platform
win32:CONFIG(release, debug|release) {
    LIBS += -L$$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/x64/Release/ -lMicrosoft.CognitiveServices.Speech.core
} else:win32:CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/x64/Release/ -lMicrosoft.CognitiveServices.Speech.core
}

# Configuration for x64 platform
x64:CONFIG(release, debug|release) {
    LIBS += -L$$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/x64/Release/ -lMicrosoft.CognitiveServices.Speech.core
} else:x64:CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/packages/Microsoft.CognitiveServices.Speech.1.37.0/build/native/x64/Release/ -lMicrosoft.CognitiveServices.Speech.core
}

# Configuration for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Menu.qml \
    MenuForm.ui.qml

RESOURCES += \
    Maps.qrc
