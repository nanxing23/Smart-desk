#ifndef SHOW_H
#define SHOW_H

#include "widget.h"
#include "led_pwm.h"
#include "set.h"
#include "mytimer.h"
#include "capture.h"
#include "aichat.h"
#include "slidepage.h"
#include "file.h"
#include "mymain.h"/*全局变量*/
#include <QWidget>


class Show :public QWidget
{
    Q_OBJECT
public:
    Show(QWidget *parent = nullptr);
    ~Show();

private slots:

    void gohome();
//    Widget *mymain;/*主界面*/
private:
    set *ser_t;
};

#endif // SHOW_H
