#include "widget.h"
#include "led_pwm.h"
#include "set.h"
#include "mymain.h"
#include "aichat.h"
#include "show.h"


#include <QApplication>

Widget *mymain = nullptr;/*主界面*/
led_pwm *my_ledp= nullptr;/*ｌｅｄ灯界面*/
set *my_set= nullptr;/*设置界面*/
capture *my_capture= nullptr;/*摄像头界面*/
Mytimer *my_timer= nullptr;/*时间界面*/
AIchat  *my_aichat = nullptr;/*声音界面*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    mymain = new Widget();
//    my_ledp = new led_pwm();
//    my_set = new set();
//    my_capture = new capture();
//    my_timer = new Mytimer();
//    my_aichat = new AIchat();
    Show w;
    w.show();
    return a.exec();
}
