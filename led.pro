QT       += core gui
QT       +=  network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aichat.cpp \
    asr.cpp \
    asryin.cpp \
    audiorecorder.cpp \
    capture.cpp \
    capture_thread.cpp \
    file.cpp \
    led_pwm.cpp \
    main.cpp \
    myclock.cpp \
    myslider.cpp \
    mytimer.cpp \
    ocr.cpp \
    set.cpp \
    show.cpp \
    slidepage.cpp \
    timeselect.cpp \
    widget.cpp \
    ydragbutton.cpp

HEADERS += \
    aichat.h \
    asr.h \
    asryin.h \
    audiorecorder.h \
    capture.h \
    capture_thread.h \
    file.h \
    led_pwm.h \
    myclock.h \
    mymain.h \
    myslider.h \
    mytimer.h \
    ocr.h \
    set.h \
    show.h \
    slidepage.h \
    timeselect.h \
    widget.h \
    ydragbutton.h

FORMS += \
    capture.ui \
    file.ui \
    led_pwm.ui \
    mytimer.ui \
    set.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc
