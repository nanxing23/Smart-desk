/********************************************************************************
** Form generated from reading UI file 'capture.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURE_H
#define UI_CAPTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_capture
{
public:
    QFrame *frame;
    QLabel *videoLabel;
    QPushButton *startCaptureButton;
    QPushButton *return_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *checkBox1;
    QRadioButton *checkBox2;
    QPushButton *pushButton;

    void setupUi(QWidget *capture)
    {
        if (capture->objectName().isEmpty())
            capture->setObjectName(QString::fromUtf8("capture"));
        capture->resize(800, 480);
        capture->setMinimumSize(QSize(800, 480));
        capture->setMaximumSize(QSize(800, 480));
        frame = new QFrame(capture);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -2, 801, 482));
        frame->setMinimumSize(QSize(801, 482));
        frame->setMaximumSize(QSize(801, 482));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{background-image: url(:/aaa.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        videoLabel = new QLabel(frame);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setGeometry(QRect(80, 0, 640, 480));
        videoLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(85, 87, 83);\n"
"}"));
        startCaptureButton = new QPushButton(frame);
        startCaptureButton->setObjectName(QString::fromUtf8("startCaptureButton"));
        startCaptureButton->setGeometry(QRect(330, 440, 151, 41));
        startCaptureButton->setCheckable(true);
        startCaptureButton->setChecked(false);
        return_2 = new QPushButton(frame);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(-1, -2, 111, 101));
        return_2->setMinimumSize(QSize(111, 101));
        return_2->setMaximumSize(QSize(111, 101));
        return_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/return.png);\n"
"}"));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(720, 160, 81, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox1 = new QRadioButton(layoutWidget);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: blue;\n"
"}\n"
"QRadioButton:indicator {\n"
"	width: 30; \n"
"	height: 30;\n"
"}"));
        checkBox1->setCheckable(true);
        checkBox1->setChecked(true);
        checkBox1->setAutoExclusive(false);

        verticalLayout->addWidget(checkBox1);

        checkBox2 = new QRadioButton(layoutWidget);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));
        checkBox2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: blue;\n"
"}\n"
"QRadioButton:indicator {\n"
"	width: 30; \n"
"	height: 30;\n"
"}"));
        checkBox2->setCheckable(true);
        checkBox2->setChecked(false);
        checkBox2->setAutoExclusive(false);

        verticalLayout->addWidget(checkBox2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(700, 380, 100, 100));
        pushButton->setMinimumSize(QSize(100, 100));
        pushButton->setMaximumSize(QSize(100, 100));

        retranslateUi(capture);

        QMetaObject::connectSlotsByName(capture);
    } // setupUi

    void retranslateUi(QWidget *capture)
    {
        capture->setWindowTitle(QApplication::translate("capture", "Form", nullptr));
        videoLabel->setText(QString());
        startCaptureButton->setText(QApplication::translate("capture", "\345\274\200\345\247\213\351\207\207\351\233\206\346\221\204\345\203\217\345\244\264\346\225\260\346\215\256", nullptr));
        return_2->setText(QString());
        checkBox1->setText(QApplication::translate("capture", "1", nullptr));
        checkBox2->setText(QApplication::translate("capture", "2", nullptr));
        pushButton->setText(QApplication::translate("capture", "\346\243\200\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class capture: public Ui_capture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_H
