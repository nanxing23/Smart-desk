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
    ui->label_2->setAlignment(Qt::AlignCenter);/*设置文本居中*/

    /*获取当前屏幕的值，并设置滑块位置*/
    processbn->start("/home/root/device/device/brightness");
    processbn->waitForFinished();
    QString result = processbn->readAllStandardOutput();
    result.chop(1);
    int num = result.toInt();
    ui->brightness->setValue(num);

    connect(this,SIGNAL(sendjcflash(bool)),my_capture,SLOT(getjcflash(bool)));
    connect(mymain, SIGNAL(sendcputemp(QString)), this, SLOT(showcputemp(QString)));/*传递cpu温度信息*/

    my_YDragButton->show();
    my_YDragButton->raise();

}

set::~set()
{
    delete ui;
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

void set::showcputemp(QString temp){
    ui->label_2->setText(temp);
    ui->label_2->setAlignment(Qt::AlignCenter);/*设置文本居中*/
}
