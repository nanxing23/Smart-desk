#include "myclock.h"
#include <QDebug>
#include "mymain.h"

int outtimeflash = 0;
myclock::myclock(QWidget *parent)
        : QWidget(parent)
{
    /*初始化闹钟的界面控件*/
    my_time = new QTimer();
    myframe = new QFrame(this);
    mytime = new QPushButton(myframe);
    myswitch = new QPushButton(myframe);
    mydel = new QPushButton("删除",myframe);
    myswitch->setCheckable(true);
    myswitch->setStyleSheet("QPushButton{border-image: url(:/image/switchopen.png);border: none;}");
    mytime->setGeometry(10,2,200,51);
    mytime->setText("0:0");
    mytime->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);border: none;}");
    mydel->setGeometry(230,2,50,50);
    myswitch->setGeometry(300,2,75,51);
    mydel->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);border: none;}");
    myframe->setStyleSheet("QFrame{background-color: rgb(255, 255, 255);border-radius: 10px;}");
    myframe->setMaximumSize(380,55);


    /*初始化更改时间*/
    changetime = new QFrame();
    changetime->setGeometry(200,140,400,200);
    changetime->setStyleSheet("QFrame{ background-color: rgb(255, 255, 255);}");
    changetime->hide();
    mytimehour = new timeSelect(changetime);/*定义两个数字选择器*/
    mytimeminute = new timeSelect(changetime);
    mytimehour->setRange(0,23);
    mytimehour->setCurValue(5);
    mytimehour->setGeometry(0,0,200,150);
    mytimeminute->setRange(0,59);
    mytimeminute->setGeometry(200,0,200,150);
    changetimeok = new QPushButton("确认",changetime);;/*确认改变时间*/
    changetimeok->setGeometry(0,150,100,50);
    changetimeclose = new QPushButton("关闭",changetime);;/*关闭并且不改变*/
    changetimeclose->setGeometry(300,150,100,50);


    my_time->start(1000);
    connect(myswitch, SIGNAL(clicked(bool)), this, SLOT(myswitcButtonClicked(bool)));/*闹钟开关*/
    connect(mytime, SIGNAL(clicked()), this, SLOT(mytimeButtonClicked()));/*闹钟重定义时间*/
    connect(mydel, SIGNAL(clicked()), this, SLOT(mycloseButtonClicked()));/*删除闹钟按钮*/
    connect(my_time,SIGNAL(timeout()),this,SLOT(timerpd()));//定时每秒1次
    connect(changetimeok, SIGNAL(clicked()), this, SLOT(changetimeokClicked()));/*确认改变时间*/
    connect(changetimeclose, SIGNAL(clicked()), this, SLOT(changetimecloseClicked()));/*关闭并且不改变*/


}

myclock::~myclock(){}

void myclock::setxy(int x, int y){
    myframe->setGeometry(x,y,380,55);
}

void myclock::setmytime(QString timer){
    mytime->setText(timer);
}
void myclock::settime(int h, int m){
    hour = h;
    min = m;
    mytimehour->setCurValue(hour);/*设置当前数字选择器的值*/
    mytimeminute->setCurValue(min);
//    qDebug()<< hour <<endl;
//    qDebug()<< min <<endl;
}

void myclock::timerpd(){
    QDateTime time = QDateTime::currentDateTime();
    QString qhour = time.toString("hh");
    QString qmin = time.toString("mm");
    int ihour = qhour.toInt();
    int imin = qmin.toInt();
    qDebug()<< ihour <<endl;
    qDebug()<< imin <<endl;
    /*判断时间到　　　写一个信号量用来在ｍｙｔｉｍｅｒ显示弹窗*/
    if(ihour == hour){
        if(imin == min && outtimeflash == 0){
            outtimeflash = 1;
            qDebug()<< "时间到" <<endl;
            emit showouttime();
        }if(imin != min && outtimeflash == 1){
            outtimeflash = 0;
        }
    }
}

void myclock::myswitcButtonClicked(bool start)/*闹钟开关*/
{
    if (start){
        myswitch->setStyleSheet("QPushButton{border-image: url(:/image/switch close.png);}");
        my_time->stop();
    }else{
        myswitch->setStyleSheet("QPushButton{border-image: url(:/image/switchopen.png);}");
        my_time->start(1000);
    }
}
void myclock::mycloseButtonClicked(){
    clockflash--;
    my_time->stop();
    this->close();
}

void myclock::mytimeButtonClicked(){
    mytimehour->setCurValue(hour);/*设置当前数字选择器的值*/
    mytimeminute->setCurValue(min);
    changetime->show();/*位于图层最上方*/
    changetime->raise();/*位于图层最上方*/
}
void myclock::changetimeokClicked(){/*确认改变时间*/
    QString clocktime;/*闹钟显示*/
    QString h = mytimehour->getValueStr();
    QString m = mytimeminute->getValueStr();
    hour = mytimehour->readValue();
    min = mytimeminute->readValue();
    clocktime.append(h);
    clocktime.append(":");
    clocktime.append(m);
    this->setmytime(clocktime);
    changetime->hide();
}


void myclock::changetimecloseClicked(){/*关闭并且不改变*/
    changetime->hide();
}
