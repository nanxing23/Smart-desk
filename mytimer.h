/*闹钟界面*/
#ifndef MYTINER_H
#define MYTINER_H

#include <QWidget>
#include <QVBoxLayout>
#include "timeselect.h"
#include "ui_mytimer.h"
#include "myclock.h"


#include<QFrame>

namespace Ui {
class Mytimer;
}

class Mytimer : public QWidget
{
    Q_OBJECT

public:
    explicit Mytimer(QWidget *parent = nullptr);
    ~Mytimer();


private slots:

    void on_pushButton_clicked();

    void on_close_clicked();

    void on_ok_clicked();

    void showouttimeslot();/*闹钟时间到用来弹出提示窗口*/
    void outtimecloseslot();/*用来关闭提示窗口*/
    void outtimedelayslot();/*稍后提醒*/


private:
    Ui::Mytimer *ui;
    timeSelect* mytimehour;
    timeSelect* mytimeminute;
    myclock* my_clock[10];
    QVBoxLayout *layout; // 布局管理器
    std::vector<myclock*> alarms; // 用于保存闹钟控件指针的容器
    QWidget *outtime;//闹钟提示界面
    QTimer* my_delaytime;/*稍后提醒定时器*/
//    QFrame* myframe[10];
//    QPushButton* mytime[10];/*显示时间*/
//    QPushButton* myswitch[10];/*闹钟开关*/
};

#endif // MYTINER_H
