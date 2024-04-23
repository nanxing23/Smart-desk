/******************************************************************
录制声音界面
*******************************************************************/
#include "aichat.h"
#include <QDebug>
#include <QSound>
#include <unistd.h>
#include <QTextCodec>
#include "mymain.h"

QString insertNewlinesEveryNCharacters(const QString &str, int n);/*强制加换行符*/

AIchat::AIchat(QWidget *parent)
    : QWidget(parent)
{

    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("background:#14161a");//14161a

    mainWidget = new QWidget(this);
    movieWidget = new QWidget(this);

    movieLabel = new QLabel(this);
    textLabel = new QLabel(this);

    return_2 = new QPushButton(this);
    return_2->setGeometry(-1,-2,111,101);
    return_2->setStyleSheet("QPushButton{border-image: url(:/image/return.png);}");

    userLabel = new QLabel(this);/*对板子说的话*/
    fanLabel = new QLabel(this);/*回话*/
    userLabel->setStyleSheet("color: white; font-size: 20px");
    fanLabel->setStyleSheet("color: white; font-size: 20px");
//    QString modifiedStr = insertNewlinesEveryNCharacters(str,16);
    userLabel->setText("我:\n");
    userLabel->setMinimumSize(240, 150);
    userLabel->move(400,0);

    fanLabel->setText("");
    fanLabel->setMinimumSize(240, 150);
    fanLabel->move(400,200);


    mainWidget->move(50,50);
    movieWidget->setMinimumWidth(240);
    textLabel->setMinimumSize(240, 50);
    textLabel->setStyleSheet("color: white; font-size: 20px");
    textLabel->setText("请点击，开始说话...");
    textLabel->setAlignment(Qt::AlignCenter);

    /* 安装事件过滤器 */
    movieLabel->installEventFilter(this);
    movieLabel->setFixedSize(240, 240);

    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();

    vBoxLayout->addWidget(movieWidget);
    vBoxLayout->addWidget(textLabel);
    vBoxLayout->setAlignment(Qt::AlignCenter);

    mainWidget->setLayout(vBoxLayout);

    hBoxLayout->addWidget(movieLabel);
    movieWidget->setLayout(hBoxLayout);


    myMovie = new QMovie(":/gif/voice_effect.gif");
    /* 设置播放速度，值越大越快 */
    myMovie->setSpeed(50);
    movieLabel->setMovie(myMovie);
    movieLabel->show();
    /* 设置设置化时显示第一帧 */
    myMovie->jumpToNextFrame();

    movieLabel->setAlignment(Qt::AlignHCenter);

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(onTimer1TimeOut()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(onTimer2TimeOut()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(onTimer3TimeOut()));
    connect(return_2,SIGNAL(clicked()),this,SLOT(on_return_2_clicked()));

    /* 自定义的录音类 */
    myAudioRecorder = new AudioRecorder(this);

    /* 自定义的百度云识别录音类 */
    myAsryin = new Asryin(this);

    asr = new Asr(this);/*聊天*/


    connect(myAsryin, SIGNAL(asrReadyData(QString)), this, SLOT(onAsrReadyData(QString)));/*读取完数据后发送信号,槽函数发送识别结果*/
    connect(asr, SIGNAL(asrReadyData(QString)), this, SLOT(onAsrReadyDatas(QString)));/*聊天ＡＩ处理完成发送信号,槽函数发送识别结果*/

}

AIchat::~AIchat()
{
}

bool AIchat::eventFilter(QObject *watched, QEvent *event){
    if (watched == movieLabel && event->type() == QEvent::MouseButtonPress) {
        QSound::play(":/audio/sound.wav");
        if (myMovie->state() != QMovie::Running) {
            /* 等待QSound播放完,1.5s后再录音 */
            timer2->start(1500);
            fanLabel->setText("");
            userLabel->setText("我:\n");
            textLabel->setText("请稍等...");
            myMovie->start();
        }
    }

    return QWidget::eventFilter(watched, event);
}

void AIchat::onTimer1TimeOut()/*定时器2里打开定时器1（8ｓ），录音8ｓ*/
{
    /* 停止录音，8s钟的短语音 */
    myAudioRecorder->stopRecorder();/*停止录音函数 */
    textLabel->setText("正在识别，请稍候...");
    timer1->stop();
    myMovie->stop();
    qDebug() << "开始识别" << endl;
    QString fileName = QCoreApplication::applicationDirPath() + "/16k.wav";
    myAsryin->getTheResult(fileName);/* 获取识别结果 */
    timer3->start(30000);
}

void AIchat::onTimer2TimeOut()/*按下中间球形打开定时器2（1.5ｓ），延迟1.5ｓ开始录音*/
{
    timer1->start(8000);
    textLabel->setText("正在听您说话，请继续...");
    /* 开始录音 */
    qDebug() << "开始录音" << endl;
    myAudioRecorder->startRecorder();/* 开始录音函数 */
    timer2->stop();
}

void AIchat::onTimer3TimeOut()
{
    textLabel->setText("请点击，开始说话...");
    timer3->stop();
}

void AIchat::on_return_2_clicked(){
    mymain->setVisible(true);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
}

void AIchat::onAsrReadyData(QString str)
{
    QString user = "我:\n";
    QString add = user + str;
    QString out = insertNewlinesEveryNCharacters(add,16);
    userLabel->setText(out);
    asr->readyToDetection(str);
    userLabel->adjustSize();
    myMovie->start();
}

void AIchat::onAsrReadyDatas(QString str)
{
    QString fan = "星星:\n";
    QString add = fan + str;
    QString out = insertNewlinesEveryNCharacters(add,16);/*插入换行*/
    QTextCodec *codecUtf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec *codecGbk = QTextCodec::codecForName("GBK");
    if (!codecGbk) {
        qDebug() << "GBK codec not supported!";
    } else{
        QByteArray utf8Bytes = codecUtf8->fromUnicode(str);
        QByteArray gbkBytes = codecGbk->fromUnicode(str);
        qDebug() << "GBK bytes:" << gbkBytes;
    }
    //processmusic->start("/home/root/device/device/music",QStringList() << gbkBytes);
    myMovie->stop();
    fanLabel->setText(out);
    fanLabel->adjustSize();
    textLabel->setText("请点击，开始说话...");
}

QString insertNewlinesEveryNCharacters(const QString &str, int n) {  /*强制加换行符*/
    QString result;
    int i = 0;
    while (i < str.length()) {
        // 复制当前位置开始的n个字符（或剩余所有字符）到结果字符串
        int nextNewlineIndex = str.indexOf('\n', i);
        if (nextNewlineIndex == -1 || nextNewlineIndex > i + n) {
            // 如果没有找到换行符，或者下一个换行符在n个字符之后
            result += str.mid(i, n); // 复制n个字符
            result += '\n'; // 添加换行符
            i += n; // 移动到下一个n个字符的起始位置
        } else {
            // 如果下一个换行符在n个字符之内，则直接复制到结果字符串，并移动到换行符之后的位置
            result += str.mid(i, nextNewlineIndex - i);
            result += '\n'; // 这个换行符已经存在于原始字符串中，但为了保持格式一致，仍然可以添加（如果需要的话）
            i = nextNewlineIndex + 1; // 移动到下一个字符的位置（即换行符之后）
        }
    }
    return result;
}
