/*设置的界面*/
#include "set.h"
#include "ui_set.h"
#include "widget.h"
#include "mymain.h"

set::set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set)
{
    ui->setupUi(this);
    /*获取当前屏幕的值，并设置滑块位置*/
    processbn->start("/home/root/device/device/brightness");
    processbn->waitForFinished();
    QString result = processbn->readAllStandardOutput();
    result.chop(1);
    int num = result.toInt();
    ui->brightness->setValue(num);

    connect(this,SIGNAL(sendjcflash(bool)),my_capture,SLOT(getjcflash(bool)));

}

set::~set()
{
    delete ui;
}


void set::on_return_2_clicked()
{
    mymain->setVisible(true);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
}

void set::on_brightness_valueChanged(int value)
{
    QString text = QString::number(value);
    if(processbn->pid() > 0) return;
    else {processbn->start("/home/root/device/device/brightness",QStringList() << text);}
}

void set::on_brightness_sliderReleased()
{
    /*获取当前屏幕的值*/
    processbn->start("/home/root/device/device/brightness");
    processbn->waitForFinished();
    QString result = processbn->readAllStandardOutput();
    result.chop(1);
    int num = result.toInt();

    int Value = ui->brightness->value();/*获取当前ｕｉ的值*/
    if(num != Value){/*如果滑块值与屏幕亮度不匹配*/
        QString text = QString::number(Value);
        processbn->start("/home/root/device/device/brightness",QStringList() << text);
    }
}

void set::on_zzjc_clicked(bool checked)
{
    emit sendjcflash(checked);
    if(checked){
        ui->zzjc->setStyleSheet("QPushButton{border-image: url(:/image/switchopen.png);}");
    }else{
        ui->zzjc->setStyleSheet("QPushButton{border-image: url(:/image/switch close.png);}");
    }
}
