#include "file.h"
#include "ui_file.h"
#include "mymain.h"
#include <QFileDialog>
#include <QDebug>

QString pwd;

File::File(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);

    /*弹窗*/
    fileok = new QFrame();
    fileoklable = new QLabel("文件传输成功",fileok);
    fileokopen = new QPushButton("打开",fileok);
    fileokclose = new QPushButton("关闭",fileok);
    fileok->setGeometry(150,50,500,300);
    fileoklable->setGeometry(0,0,500,200);
    fileoklable->setAlignment(Qt::AlignCenter);
    fileoklable->setStyleSheet("font-size: 52px");
    fileokopen->setGeometry(50,200,150,50);
    fileokclose->setGeometry(300,200,150,50);

    /*文件界面*/
    textEdit = new QTextEdit(this);
    openPushButton = new QPushButton("打开",this);
    closePushButton = new QPushButton("关闭",this);//200 500 430
    textEdit->setGeometry(5,5,790,420);
    openPushButton->setGeometry(200,430,100,50);
    closePushButton->setGeometry(500,430,100,50);


    processfile = new QProcess(this);
    processfile->start("/home/root/device/device/fuwufile");    /*打开ｍｑｔｔ程序*/

    /* 设置关闭按钮为不可用属性，需要打开文件才设置为可用属性 */
    closePushButton->setEnabled(false);



    /* 信号槽连接 */
    connect(openPushButton, SIGNAL(clicked()),
            this, SLOT(openFile()));
    connect(closePushButton, SIGNAL(clicked()),
            this, SLOT(closeFile()));
    connect(fileokopen, SIGNAL(clicked()),
            this, SLOT(fileokopenopenfile()));
    connect(fileokclose, SIGNAL(clicked()),
            this, SLOT(closeFileokclose()));
    connect(processfile, &QProcess::readyRead,this, &File::receiveok);/*连接到信号，有值时触发*/


    fileok->hide();
}

File::~File()
{
    delete ui;
}


void File::fileokopenopenfile(){/*打开文件*/
    fileok->hide();
    mymain->setVisible(false);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
    my_file->setVisible(true);
    openFile(pwd);
}
void File::closeFileokclose(){/*关闭弹窗*/
    fileok->hide();
}
void File::receiveok(){
    QByteArray output = processfile->readAll();
    QString text = QString::fromLocal8Bit(output); // 根据需要转换编码

    QString filename = "filename";
    if(text.indexOf(filename) != -1 ){/*处理函数*/
        QStringList list = text.split("=");
        pwd = list[1];
        pwd.chop(1);
        qDebug() << pwd << endl;
        fileok->show();
    }
}

bool File::openFile()
{
    /* 获取文件的路径 */
    QString fileName = QFileDialog::getOpenFileName(this);

    /* 指向文件 */
    openfile.setFileName(fileName);

    /* 判断文件是否存在 */
    if (!openfile.exists())
        return false;

    /* 以读写的方式打开 */
    if (!openfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    /* 读取文本到textEdit */
    textEdit->setPlainText(openfile.readAll());

    /* 设置打开按钮不可用，需要关闭再打开 */
    openPushButton->setEnabled(false);

    /* 设置关闭按钮为可用属性 */
    closePushButton->setEnabled(true);

    /* 关闭文件 */
    openfile.close();

    return true;
}
bool File::openFile(QString fileName)
{
    /* 指向文件 */
    openfile.setFileName(fileName);

    /* 判断文件是否存在 */
    if (!openfile.exists())
        return false;

    /* 以读写的方式打开 */
    if (!openfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    /* 读取文本到textEdit */
    textEdit->setPlainText(openfile.readAll());

    /* 设置打开按钮不可用，需要关闭再打开 */
    openPushButton->setEnabled(false);

    /* 设置关闭按钮为可用属性 */
    closePushButton->setEnabled(true);

    /* 关闭文件 */
    openfile.close();

    return true;
}
void File::closeFile()
{
    /* 检测打开按钮是否可用，不可用时，说明已经打开了文件 */
    if (!openPushButton->isEnabled()) {
        /* 获取textEdit的文本内容 */
        QString str = textEdit->toPlainText();

        /* 以只读的方式打开 */
        if (!openfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        /* 转换为字节数组 */
        QByteArray strBytes = str.toUtf8();

        /* 写入文件 */
        openfile.write(strBytes, strBytes.length());

        /* 清空textEdit的显示内容 */
        textEdit->clear();

        /* 关闭文件 */
        openfile.close();

        /* 重新设置打开和关闭按钮的属性 */
        openPushButton->setEnabled(true);
        closePushButton->setEnabled(false);
    }
}


