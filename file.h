#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QProcess>
#include <QLabel>

namespace Ui {
class File;
}

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();

private slots:

    void receiveok();

    /* 打开文本文件 */
    bool openFile();

    bool openFile(QString fileName);

    /* 关闭文本文件 */
    void closeFile();

    void fileokopenopenfile();/*打开文件*/

    void closeFileokclose();/*关闭弹窗*/

private:
    Ui::File *ui;
    /* 用于读取文件后显示 */
    QTextEdit *textEdit;

    /* QFile类型对象 */
    QFile openfile;

    /* 打开文件按钮 */
    QPushButton *openPushButton;

    /* 关闭文件按钮 */
    QPushButton *closePushButton;

    /*返回桌面*/
    QPushButton *return_1;

    /*控制接受文件*/
    QProcess *processfile;

    /*文件传输成功后弹窗*/
    QFrame *fileok;

    /* 文件弹窗打开按钮 */
    QPushButton *fileokopen;

    /* 关闭弹窗按钮 */
    QPushButton *fileokclose;

    QLabel* fileoklable;



};

#endif // FILE_H
