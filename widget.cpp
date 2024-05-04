/*主界面*/
#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>
#include "mymain.h"     /*全局变量*/
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);/*设置文本居中*/
    ui->time->setText("wait…");
    connect(timer_calendar,SIGNAL(timeout()),this,SLOT(timerUpdate()));//连接槽函数
    timer_calendar->start(1000);//每一秒溢出一次进入槽函数

    processr->start("/home/root/device/mqtt/mqttClient");/*打开ｍｑｔｔ程序*/
    connect(processr, &QProcess::readyRead,this, &Widget::updateOutput);/*连接到信号，有值时触发*/
    connect(this, SIGNAL(sendwidget1(bool)),my_capture, SLOT(getwidget(bool)));
}


Widget::~Widget()
{
    delete ui;
}


void Widget:: timerUpdate()/*刷新时间*/
{
    QDateTime time = QDateTime::currentDateTime();
    QString week = time.toString("ddd");
    QString near = time.toString("yyyy.MM.dd");
    QString timer = time.toString("hh:mm");
    ui->time->setText(timer);
    ui->near->setText(near);
    ui->week->setText(week);
}

void Widget::updateOutput(){
    QByteArray output = processr->readAll();
    QString text = QString::fromLocal8Bit(output); // 根据需要转换编码
    QString cpu = "CPU";
    QString led = "LED";
    text.chop(1);
    if(text.indexOf(cpu) != -1 )ui->label->setText(text);// 更新标签文本
    
    if(text.indexOf(led) != -1 ){
        
    }
    ui->label->setAlignment(Qt::AlignCenter);

}

void Widget::on_shezhi_clicked()/*触发按键转移到设置*/
{
    mymain->setVisible(false);
    my_set->setVisible(true);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);


}


void Widget::on_ledpwm_clicked()/*触发按键转移到ｌｅｄ灯*/
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(true);//
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);

}


/*触发按键转移到时间*/
void Widget::on_timebutton_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(true);
    my_aichat->setVisible(false);

}
void Widget::on_time_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(true);
    my_aichat->setVisible(false);

}
void Widget::on_near_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(true);
    my_aichat->setVisible(false);

}
void Widget::on_week_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(true);
    my_aichat->setVisible(false);

}


void Widget::on_capturebutton_clicked()/*按键进入摄像头*/
{
    bool n = 1;
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(true);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
    emit sendwidget1(n);
}

void Widget::on_aichat_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(true);
}



void Widget::on_file_clicked()
{
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
    my_file->setVisible(true);
}
