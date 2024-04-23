/*摄像头界面*/
#include "capture.h"
#include "ui_capture.h"
#include "widget.h"
#include "mymain.h"
#include <QDebug>

capture::capture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::capture)
{
    ui->setupUi(this);

    ocr = new Ocr(this);/*检测算法*/
    my_Timer = new QTimer(this);/*定时器*/
    my_Timers = new QTimer(this);/*定时器*/

    CaptureThread *captureThread = new CaptureThread(this);

    /* 信号槽连接 */
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButtonClicked()));
    connect(ocr, SIGNAL(ocrReadyData(QString)), this, SLOT(disPlaylprResult(QString)));

    connect(my_Timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));/*定时器一分钟检测一次坐姿*/
    connect(my_Timers, SIGNAL(timeout()), this, SLOT(handlesTimeout()));/*定时器当作延迟*/
    connect(ui->startCaptureButton, SIGNAL(clicked(bool)), captureThread, SLOT(setThreadStart(bool)));
    connect(this, SIGNAL(sendwidget(bool)), captureThread, SLOT(setThreadStart(bool)));/*主函数进入摄像头直接打开摄像头,返回的按键控制摄像头关闭*/
    connect(captureThread, SIGNAL(imageReady(QImage)), this, SLOT(showImage(QImage)));/*传递图片信息*/
    connect(ui->checkBox1, SIGNAL(clicked(bool)), captureThread, SLOT(setLocalDisplay(bool)));
    connect(ui->checkBox2, SIGNAL(clicked(bool)), captureThread, SLOT(setBroadcast(bool)));

    my_Timer->start(time*1000); /*每一分钟进行一次中断*/

}

capture::~capture()
{
    delete ui;
}

/*定时器服务函数，两个服务函数一起实现对坐姿的检测*/
void capture::handleTimeout()
 {
    //qDebug()<<"aaaa\n";
    if(jc_flash){/*如果打开检测*/

        emit sendwidget(1);
        qDebug()<<"Enter timeout processing function\n";
        my_Timers->start(1*1000);
    }
 }

void capture::handlesTimeout()
 {
    if(tu_flash == 1){
        tu_flash = 0;
        ocr->readyToDetection(jc);
    }else{qDebug()<<"error\n";}
    emit sendwidget(0);
    my_Timers->stop();
 }


void capture::showImage(QImage image)/*获取图片的槽函数*/
{
    ui->videoLabel->setPixmap(QPixmap::fromImage(image));
    jc = image;
    tu_flash = 1;
}

void capture::pushButtonClicked()/*按下按键后传送图片给ｏｃｒ，ｏｃｒ进行处理*/
{
    /* 识别的图片为可执行程序路径下的image文件夹下的carlpr.jpg */
    ocr->readyToDetection(jc);
}

void capture::disPlaylprResult(QString result)/*打印出坐姿是否规范*/
{
    if(result == "坐姿不正确"){
        time = 2;
        processbeep->start("/home/root/device/device/beep");
    }else{
        time = 60;
    }
    my_Timer->stop();
    my_Timer->start(time*1000);
     qDebug()<< result <<endl;
}

void capture::on_startCaptureButton_clicked(bool checked)
{
    if (checked)
        ui->startCaptureButton->setText("停止采集摄像头数据");
    else
        ui->startCaptureButton->setText("开始采集摄像头数据");
}

void capture::on_return_2_clicked()
{
    mymain->setVisible(true);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
    emit sendwidget(0);
}

