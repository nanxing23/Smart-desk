/********************************************************************************
** Form generated from reading UI file 'led_pwm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LED_PWM_H
#define UI_LED_PWM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "myslider.h"

QT_BEGIN_NAMESPACE

class Ui_led_pwm
{
public:
    QFrame *frame;
    MySlider *ledslider;
    QPushButton *closeled;

    void setupUi(QWidget *led_pwm)
    {
        if (led_pwm->objectName().isEmpty())
            led_pwm->setObjectName(QString::fromUtf8("led_pwm"));
        led_pwm->resize(800, 480);
        led_pwm->setMinimumSize(QSize(800, 480));
        led_pwm->setMaximumSize(QSize(800, 480));
        frame = new QFrame(led_pwm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -2, 801, 482));
        frame->setMinimumSize(QSize(801, 482));
        frame->setMaximumSize(QSize(801, 482));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{background-image: url(:/aaa.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ledslider = new MySlider(frame);
        ledslider->setObjectName(QString::fromUtf8("ledslider"));
        ledslider->setGeometry(QRect(160, 130, 500, 70));
        ledslider->setMinimumSize(QSize(500, 70));
        ledslider->setMaximumSize(QSize(500, 70));
        ledslider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal{border: 0px solid #bbb;}\n"
"QSlider::add-page:horizontal{background-color: rgb(186, 189, 182);  border-radius: 15px; }\n"
"QSlider::sub-page:horizontal{background-color: rgb(238, 238, 236);  border-radius: 15px;}\n"
"QSlider::handle:horizontal{border-image: url(:/image/led.png); width: 80px;margin-left:-40px;margin-right:-40px;}\n"
"QSlider::handle:horizontal:hover{border-image: url(:/image/led.png);width: 80px; }\n"
""));
        ledslider->setValue(0);
        ledslider->setOrientation(Qt::Horizontal);
        closeled = new QPushButton(frame);
        closeled->setObjectName(QString::fromUtf8("closeled"));
        closeled->setGeometry(QRect(350, 270, 100, 100));
        closeled->setMinimumSize(QSize(100, 100));
        closeled->setMaximumSize(QSize(100, 100));
        closeled->setStyleSheet(QString::fromUtf8("QPushButton{border:none;background-color: rgb(114, 159, 207);}\n"
""));
        closeled->setCheckable(false);

        retranslateUi(led_pwm);

        QMetaObject::connectSlotsByName(led_pwm);
    } // setupUi

    void retranslateUi(QWidget *led_pwm)
    {
        led_pwm->setWindowTitle(QApplication::translate("led_pwm", "Form", nullptr));
        closeled->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class led_pwm: public Ui_led_pwm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LED_PWM_H
