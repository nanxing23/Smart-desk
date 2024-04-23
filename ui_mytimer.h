/********************************************************************************
** Form generated from reading UI file 'mytimer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTIMER_H
#define UI_MYTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mytimer
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *NaoZhong;
    QPushButton *pushButton;
    QWidget *settime;
    QPushButton *close;
    QPushButton *ok;
    QPushButton *return_2;
    QWidget *JiShi;

    void setupUi(QWidget *Mytimer)
    {
        if (Mytimer->objectName().isEmpty())
            Mytimer->setObjectName(QString::fromUtf8("Mytimer"));
        Mytimer->resize(800, 480);
        Mytimer->setMinimumSize(QSize(800, 480));
        Mytimer->setMaximumSize(QSize(800, 480));
        frame = new QFrame(Mytimer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-1, -2, 801, 482));
        frame->setMinimumSize(QSize(801, 482));
        frame->setMaximumSize(QSize(801, 480));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"background-color: rgb(211, 215, 207);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-1, -2, 801, 482));
        tabWidget->setMinimumSize(QSize(801, 482));
        tabWidget->setMaximumSize(QSize(804, 482));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{\n"
"	background-color: rgb(247, 247, 247);\n"
"    font-size:30pt;\n"
"	min-width: 400px;\n"
"	height:70px;\n"
"}\n"
"QTabBar::tab:selected{\n"
"	background-color: rgb(247, 247, 247);\n"
"	color: rgb( 70,144,221);\n"
"	font-size:30pt;\n"
"}\n"
"QTabWidget::pane {\n"
"	border:none;\n"
"}\n"
" "));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        NaoZhong = new QWidget();
        NaoZhong->setObjectName(QString::fromUtf8("NaoZhong"));
        NaoZhong->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(247, 247, 247);\n"
"}"));
        pushButton = new QPushButton(NaoZhong);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 330, 80, 80));
        pushButton->setMinimumSize(QSize(80, 80));
        pushButton->setMaximumSize(QSize(80, 80));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	border-image: url(:/image/+.png);\n"
"}"));
        settime = new QWidget(NaoZhong);
        settime->setObjectName(QString::fromUtf8("settime"));
        settime->setGeometry(QRect(200, 70, 400, 200));
        settime->setMinimumSize(QSize(400, 200));
        settime->setMaximumSize(QSize(400, 200));
        close = new QPushButton(settime);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(300, 150, 100, 50));
        close->setMinimumSize(QSize(100, 50));
        close->setMaximumSize(QSize(100, 50));
        ok = new QPushButton(settime);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(0, 150, 100, 50));
        ok->setMinimumSize(QSize(100, 50));
        ok->setMaximumSize(QSize(95, 50));
        return_2 = new QPushButton(NaoZhong);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(700, 320, 111, 101));
        return_2->setMinimumSize(QSize(111, 101));
        return_2->setMaximumSize(QSize(111, 101));
        return_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/return.png);\n"
"}"));
        tabWidget->addTab(NaoZhong, QString());
        pushButton->raise();
        return_2->raise();
        settime->raise();
        JiShi = new QWidget();
        JiShi->setObjectName(QString::fromUtf8("JiShi"));
        JiShi->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(247, 247, 247);\n"
"}"));
        tabWidget->addTab(JiShi, QString());

        retranslateUi(Mytimer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Mytimer);
    } // setupUi

    void retranslateUi(QWidget *Mytimer)
    {
        Mytimer->setWindowTitle(QApplication::translate("Mytimer", "Form", nullptr));
        pushButton->setText(QString());
        close->setText(QApplication::translate("Mytimer", "\345\205\263\351\227\255", nullptr));
        ok->setText(QApplication::translate("Mytimer", "\347\241\256\350\256\244", nullptr));
        return_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(NaoZhong), QApplication::translate("Mytimer", "\351\227\271\351\222\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(JiShi), QApplication::translate("Mytimer", "\350\256\241\346\227\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mytimer: public Ui_Mytimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIMER_H
