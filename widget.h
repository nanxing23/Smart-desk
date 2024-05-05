/*主界面*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <QStackedWidget>


#include "led_pwm.h"
#include "set.h"
#include "mytimer.h"
#include "capture.h"
#include "aichat.h"
#include "file.h"
#include "ydragbutton.h"
#include "slidepage.h"
extern bool captureflash;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void sendwidget1(bool widgetchecked);/*按下摄像头按键直接开启摄像头，返回桌面自动关闭摄像头*/
    void sendcputemp(QString temp);
private slots:

    void updateOutput();

    void timerUpdate();/*更新时间*/

    void on_shezhi_clicked();

    void on_ledpwm_clicked();

    void on_timebutton_clicked();

    void on_time_clicked();

    void on_near_clicked();

    void on_week_clicked();

    void on_capturebutton_clicked();

    void on_aichat_clicked();

    void on_file_clicked();

private:
    Ui::Widget *ui;
    set *t_set;/*设置界面*/
    QProcess *process = new QProcess(this);
    QProcess *processr = new QProcess(this);/*mqtt文件*/
    QProcess *processled = new QProcess(this);/*led_pwm文件*/
    QTimer *timer_calendar = new QTimer(this);//new一个QTimer对象
};

#endif // WIDGET_H
