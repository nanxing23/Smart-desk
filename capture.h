#ifndef CAPTURE_H
#define CAPTURE_H

#include <QWidget>
#include "capture_thread.h"
#include <QDebug>
#include <QProcess>


namespace Ui {
class capture;
}

class capture : public QWidget
{
    Q_OBJECT

public:
    explicit capture(QWidget *parent = nullptr);
    bool tu_flash;/*用来判断图片是否刷新*/
    bool jc_flash;/*用来判断是否需要检测*/
    int time = 6;/*检测间隔时间ｓ*/
    ~capture();
    QImage jc;

private:
    Ui::capture *ui;
    Ocr *ocr;
    QTimer *my_Timer;/*定时器指针，用来定时检测坐姿*/
    QTimer *my_Timers;/*定时器指针，用来定时检测坐姿*/

    QProcess *processbeep = new QProcess(this);/*beep文件*/

/*按下摄像头按键直接开启摄像头，返回桌面自动关闭摄像头*/
signals:
    void sendwidget(bool widgetchecked);
public slots:
    void getwidget(bool widgetchecked) {
        emit sendwidget(widgetchecked);
    }
    void getjcflash(bool flash) {
        qDebug()<< flash <<endl;
        jc_flash = flash;
    }

private slots:
    /* 显示图像 */
    void showImage(QImage);
    /* 按钮点击开始获取结果 */
    void pushButtonClicked();
    /* 处理检测结果 */
    void disPlaylprResult(QString);
    void handleTimeout();  //超时处理函数
    void handlesTimeout();  //超时处理函数
    void on_return_2_clicked();
    void on_startCaptureButton_clicked(bool checked);
};



#endif // CAPTURE_H
