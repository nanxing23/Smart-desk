/*ＬＥＤ灯的界面*/
#include "led_pwm.h"
#include "ui_led_pwm.h"
#include "widget.h"
#include "mymain.h"
#include "show.h"

led_pwm::led_pwm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::led_pwm)
{
    ui->setupUi(this);

    ui->closeled->setStyleSheet("QPushButton{border-image: url(:/image/led0.png);}");

}

led_pwm::~led_pwm()
{
    delete ui;
}

void led_pwm::on_ledslider_valueChanged(int value)
{
    qDebug()<< value <<endl;
    value = value*1000;
    QString text = QString::number(value);
    processled->start("/home/root/device/device/pwm_led",QStringList() << "1" << "100000" << text);
    if(value == 0)ui->closeled->setStyleSheet("QPushButton{border-image: url(:/image/led0.png);}");
    else ui->closeled->setStyleSheet("QPushButton{border-image: url(:/image/led.png);}");
}

void led_pwm::on_closeled_clicked()
{
    ui->ledslider->setValue(0);
    //processled->start("/home/root/device/device/pwm_led",QStringList() << "1" << "100000" << "0");
}


