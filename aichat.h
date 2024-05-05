/******************************************************************
录制声音界面
*******************************************************************/
#ifndef AICHAT_H
#define AICHAT_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QHBoxLayout>
#include <QPushButton>
#include <QProcess>
#include "audiorecorder.h"
#include "asryin.h"
#include "asr.h"

class Asryin;
class AudioRecorder;

class AIchat : public QWidget
{
    Q_OBJECT

public:
    AIchat(QWidget *parent = nullptr);
    ~AIchat();

private:

    QWidget *my_back;
    /* 主Widget */
    QWidget *mainWidget;

    /* gif底下的Widget */
    QWidget *movieWidget;

    /* gif动画画布 */
    QLabel *movieLabel;

    /* 用于显示识别结果 */
    QLabel *textLabel;
    QLabel *userLabel;
    QLabel *fanLabel;

    /* 垂直布局 */
    QVBoxLayout *vBoxLayout;

    /* 水平布局 */
    QHBoxLayout *hBoxLayout;

    /* 用于显示GIF动画 */
    QMovie *myMovie;

    /* 定时器 */
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;

    /* 事件过滤器 */
    bool eventFilter(QObject *watched, QEvent *event);

    /* 录音类 */
    AudioRecorder *myAudioRecorder;

    /* 声音识别转文字类 */
    Asryin *myAsryin;

    Asr *asr;/*聊天API*/

    QPushButton *return_2;
    QProcess *processmusic = new QProcess(this);/*led_pwm文件*/

private slots:
    void onTimer1TimeOut();
    void onTimer2TimeOut();
    void onTimer3TimeOut();
    void onAsrReadyData(QString);
    void onAsrReadyDatas(QString);


};
#endif // MAINWINDOW_H
