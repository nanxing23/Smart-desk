/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *shezhi;
    QPushButton *ledpwm;
    QPushButton *timebutton;
    QPushButton *time;
    QPushButton *near;
    QPushButton *week;
    QPushButton *capturebutton;
    QPushButton *aichat;
    QPushButton *file;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        Widget->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -2, 801, 482));
        frame->setMinimumSize(QSize(801, 482));
        frame->setMaximumSize(QSize(801, 482));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{background-image: url(:/aaa.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 340, 200, 100));
        label->setMinimumSize(QSize(200, 100));
        label->setMaximumSize(QSize(200, 100));
        label->setStyleSheet(QString::fromUtf8("QLabel{background-color: rgb(114, 159, 207);font-size:24px;}\n"
""));
        shezhi = new QPushButton(frame);
        shezhi->setObjectName(QString::fromUtf8("shezhi"));
        shezhi->setGeometry(QRect(160, 150, 100, 100));
        shezhi->setMinimumSize(QSize(100, 100));
        shezhi->setMaximumSize(QSize(100, 100));
        shezhi->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/set.png);}"));
        ledpwm = new QPushButton(frame);
        ledpwm->setObjectName(QString::fromUtf8("ledpwm"));
        ledpwm->setGeometry(QRect(50, 150, 100, 100));
        ledpwm->setMinimumSize(QSize(100, 100));
        ledpwm->setMaximumSize(QSize(100, 100));
        ledpwm->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/image/led.png);}\n"
""));
        ledpwm->setCheckable(false);
        timebutton = new QPushButton(frame);
        timebutton->setObjectName(QString::fromUtf8("timebutton"));
        timebutton->setGeometry(QRect(50, 40, 210, 100));
        timebutton->setMinimumSize(QSize(210, 100));
        timebutton->setMaximumSize(QSize(210, 100));
        timebutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"background-image: url(:/image/timebright.png);\n"
"border-radius: 15px;\n"
"}"));
        time = new QPushButton(frame);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(50, 40, 150, 75));
        time->setMinimumSize(QSize(150, 75));
        time->setMaximumSize(QSize(150, 75));
        time->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"background:transparent;\n"
"border-radius: 15px;\n"
"font-size:48px;\n"
"color: rgb(255, 255, 255);\n"
"}"));
        near = new QPushButton(frame);
        near->setObjectName(QString::fromUtf8("near"));
        near->setGeometry(QRect(50, 115, 100, 25));
        near->setMinimumSize(QSize(100, 25));
        near->setMaximumSize(QSize(100, 25));
        near->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"background:transparent;\n"
"font-size:15px;\n"
"color: rgb(255, 255, 255);\n"
"}"));
        week = new QPushButton(frame);
        week->setObjectName(QString::fromUtf8("week"));
        week->setGeometry(QRect(150, 115, 50, 25));
        week->setMinimumSize(QSize(50, 25));
        week->setMaximumSize(QSize(50, 25));
        week->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"background:transparent;\n"
"font-size:15px;\n"
"color: rgb(255, 255, 255);\n"
"}"));
        capturebutton = new QPushButton(frame);
        capturebutton->setObjectName(QString::fromUtf8("capturebutton"));
        capturebutton->setGeometry(QRect(320, 40, 100, 100));
        capturebutton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/capture.png);\n"
"}"));
        aichat = new QPushButton(frame);
        aichat->setObjectName(QString::fromUtf8("aichat"));
        aichat->setGeometry(QRect(430, 40, 100, 100));
        aichat->setMinimumSize(QSize(100, 100));
        aichat->setMaximumSize(QSize(100, 100));
        aichat->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/AI.png);\n"
"}"));
        file = new QPushButton(frame);
        file->setObjectName(QString::fromUtf8("file"));
        file->setGeometry(QRect(590, 40, 100, 100));
        file->setMinimumSize(QSize(100, 100));
        file->setMaximumSize(QSize(100, 100));
        file->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/file.png);\n"
"}"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        shezhi->setText(QString());
        ledpwm->setText(QString());
        timebutton->setText(QString());
        time->setText(QString());
        near->setText(QString());
        week->setText(QString());
        capturebutton->setText(QString());
        aichat->setText(QString());
        file->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
