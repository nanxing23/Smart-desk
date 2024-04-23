/*创建闹钟模块*/
#ifndef MYCLOCK_H
#define MYCLOCK_H

#include<QFrame>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "timeselect.h"


class myclock : public QWidget
{
    Q_OBJECT
public:
    myclock(QWidget *parent = nullptr);
    ~myclock();

    void setmytime(QString timer);
    void setxy(int x, int y);
    void settime(int h, int m);
signals:
    void showouttime();

private:
    QFrame* myframe;
    QPushButton* mytime;/*显示时间*/
    QPushButton* myswitch;/*闹钟开关*/
    QPushButton* mydel;/*删除闹钟按钮*/
    QTimer* my_time;/*定时器每秒检测一次*/
    QFrame* changetime;/*改变时间按钮（显示时间）*/
    timeSelect* mytimehour;/*两个数字选择器*/
    timeSelect* mytimeminute;
    QPushButton* changetimeok;/*确认改变时间*/
    QPushButton* changetimeclose;/*关闭并且不改变*/
    int hour,min;

private slots:
    void myswitcButtonClicked(bool);/*闹钟开关*/
    void mycloseButtonClicked();/*闹钟close*/
    void timerpd();/*对比时间*/
    void mytimeButtonClicked();/*重定义时间*/
    void changetimeokClicked();/*确认改变时间*/
    void changetimecloseClicked();/*关闭并且不改变*/

};

#endif // MYCLOCK_H
