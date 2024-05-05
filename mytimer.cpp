/*闹钟界面*/
#include "mytimer.h"
#include "ui_mytimer.h"
#include "widget.h"
#include "mymain.h"
#include <QDebug>

int clockflash = 0;
QString clockstring;/*闹钟*/
int clockh;/*闹钟h*/
int clocksm;/*闹钟m*/



Mytimer::Mytimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mytimer)
{
    ui->setupUi(this);

    /*设置闹钟时间到的提示*/
    outtime = new QFrame();
    outtime->setGeometry(150,50,500,300);
    outtime->setStyleSheet("QFrame{background:white;border-radius: 20px 20px 20px 20px;}");
    QLabel* outtimelable = new QLabel("闹钟时间到啦",outtime);
    outtimelable->setGeometry(0,0,500,200);
    outtimelable->setAlignment(Qt::AlignCenter);/*居中*/
    outtimelable->setStyleSheet("color: black; font-size: 52px");
    QPushButton* outtimeclose = new QPushButton("关闭",outtime);
    outtimeclose->setGeometry(50,200,150,50);
    QPushButton* outtimedelay = new QPushButton("稍后提醒",outtime);
    outtimedelay->setGeometry(300,200,150,50);

    /*设置　设置时间的类*/
    mytimehour = new timeSelect(ui->settime);
    mytimeminute = new timeSelect(ui->settime);
    QWidget *layoutlWidget = new QWidget(ui->NaoZhong);
    layoutlWidget->setGeometry(0,0,800,320);
    layout = new QVBoxLayout(layoutlWidget);
    layout->setSpacing(10);
    mytimehour->setRange(0,23);
    mytimehour->setGeometry(0,0,200,150);
    mytimeminute->setRange(0,59);
    mytimeminute->setGeometry(200,0,200,150);


    my_delaytime = new QTimer();

    ui->settime->hide();
    outtime->hide();

connect(outtimeclose,SIGNAL(clicked()),this,SLOT(outtimecloseslot()));
connect(outtimedelay,SIGNAL(clicked()),this,SLOT(outtimedelayslot()));
connect(my_delaytime,SIGNAL(timeout()),this,SLOT(showouttimeslot()));//定时每秒1次


}

Mytimer::~Mytimer()
{
    delete ui;
}



void Mytimer::on_pushButton_clicked()
{
    ui->settime->show();
    ui->settime->raise();/*位于图层最上方*/
}

void Mytimer::on_close_clicked()
{
    ui->settime->hide();
}

void Mytimer::on_ok_clicked()
{
    QString clocktime;/*闹钟显示*/
    if(clockflash < 4){
        QString h = 0;
        QString m = 0;
        h = mytimehour->getValueStr();
        m = mytimeminute->getValueStr();
        clockh = mytimehour->readValue();
        clocksm = mytimeminute->readValue();
        clocktime.append(h);
        clocktime.append(":");
        clocktime.append(m);
        clockflash++;
        myclock *my_clock= new myclock;
        layout->addWidget(my_clock);
        alarms.push_back(my_clock);/*加入容器*/
        my_clock->setmytime(clocktime);/*设置时间*/
        my_clock->settime(clockh, clocksm);/*发送时间*/
        connect(my_clock,SIGNAL(showouttime()),this,SLOT(showouttimeslot()));
    }
    ui->settime->hide();
}
void Mytimer::showouttimeslot(){
    qDebug()<< "showouttimeslot" <<endl;
    outtime->show();
    outtime->raise();/*位于图层最上方*/
    my_delaytime->stop();
}

void Mytimer::outtimecloseslot(){/*关闭弹出界面*/
    outtime->hide();
}

void Mytimer::outtimedelayslot(){/*关闭弹出界面，稍后重新提醒*/
    my_delaytime->start(5*60*1000);
    outtime->hide();
}
