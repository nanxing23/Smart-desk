/********************************************************************************
** Form generated from reading UI file 'set.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_H
#define UI_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set
{
public:
    QFrame *frame;
    QSlider *brightness;
    QPushButton *return_2;
    QPushButton *zzjc;
    QLabel *label;
    QLabel *label_2;
    QSlider *music;

    void setupUi(QWidget *set)
    {
        if (set->objectName().isEmpty())
            set->setObjectName(QString::fromUtf8("set"));
        set->resize(800, 480);
        set->setMinimumSize(QSize(800, 480));
        set->setMaximumSize(QSize(800, 480));
        frame = new QFrame(set);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -2, 801, 482));
        frame->setMinimumSize(QSize(801, 482));
        frame->setMaximumSize(QSize(801, 482));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{background-image: url(:/aaa.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        brightness = new QSlider(frame);
        brightness->setObjectName(QString::fromUtf8("brightness"));
        brightness->setGeometry(QRect(690, 90, 70, 300));
        brightness->setMinimumSize(QSize(70, 300));
        brightness->setMaximumSize(QSize(70, 300));
        brightness->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical{border: 0px solid #bbb;}\n"
"QSlider::add-page:vertical{background-color: rgb(32, 74, 135);border-radius: 15px; }\n"
"QSlider::sub-page:vertical{background-color: rgb(114, 159, 207);border-radius: 15px;}\n"
"QSlider::handle:vertical {border-image: url(:/image/brightness.png);height: 60px; margin-top:-30px;margin-bottom:-30px;}\n"
"QSlider::handle:vertical:hover{border-image: url(:/image/brightness.png);height: 60px;margin-top:-30px;margin-bottom:-30px;}"));
        brightness->setMaximum(25);
        brightness->setPageStep(1);
        brightness->setValue(0);
        brightness->setOrientation(Qt::Vertical);
        return_2 = new QPushButton(frame);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(-1, -2, 111, 101));
        return_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/return.png);\n"
"}"));
        zzjc = new QPushButton(frame);
        zzjc->setObjectName(QString::fromUtf8("zzjc"));
        zzjc->setGeometry(QRect(30, 110, 150, 100));
        zzjc->setMinimumSize(QSize(150, 100));
        zzjc->setMaximumSize(QSize(150, 100));
        zzjc->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	border-image: url(:/image/switch close.png);\n"
"}"));
        zzjc->setCheckable(true);
        zzjc->setChecked(false);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 110, 100, 100));
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:none;\n"
"background:transparent;\n"
"border-radius: 15px;\n"
"font-size:24px;\n"
"color: rgb(238, 238, 236);\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 270, 200, 100));
        label_2->setMinimumSize(QSize(200, 100));
        label_2->setMaximumSize(QSize(200, 100));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{background-color: rgb(114, 159, 207);font-size:24px;}\n"
""));
        music = new QSlider(frame);
        music->setObjectName(QString::fromUtf8("music"));
        music->setGeometry(QRect(550, 90, 70, 300));
        music->setMinimumSize(QSize(70, 300));
        music->setMaximumSize(QSize(70, 300));
        music->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical{\n"
"border: 0px solid #bbb;\n"
"}\n"
"QSlider::add-page:vertical{\n"
"background-color: rgb(32, 74, 135);\n"
"border-radius: 15px; \n"
"}\n"
"QSlider::sub-page:vertical{\n"
"background-color: rgb(114, 159, 207);\n"
"border-radius: 15px;\n"
"}\n"
"QSlider::handle:vertical {\n"
"border-image: url(:/image/music.png);\n"
"height: 60px; \n"
"margin-top:-30px;\n"
"margin-bottom:-30px;\n"
"}\n"
"QSlider::handle:vertical:hover{\n"
"border-image: url(:/image/music.png);\n"
"height: 60px;\n"
"margin-top:-30px;\n"
"margin-bottom:-30px;\n"
"}"));
        music->setMaximum(25);
        music->setPageStep(1);
        music->setValue(0);
        music->setOrientation(Qt::Vertical);

        retranslateUi(set);

        QMetaObject::connectSlotsByName(set);
    } // setupUi

    void retranslateUi(QWidget *set)
    {
        set->setWindowTitle(QApplication::translate("set", "Form", nullptr));
        return_2->setText(QString());
        zzjc->setText(QString());
        label->setText(QApplication::translate("set", "\345\235\220\345\247\277\346\243\200\346\265\213", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class set: public Ui_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_H
