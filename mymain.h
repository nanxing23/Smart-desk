#ifndef MYMAIN_H
#define MYMAIN_H
#include "widget.h"
#include <QStackedWidget>


extern Widget *mymain;
extern led_pwm *my_ledp;
extern set *my_set;
extern capture *my_capture;
extern Mytimer *my_timer;
extern AIchat *my_aichat;
extern File *my_file;/*文件夹界面*/
extern int clockflash;
#endif // MYMAIN_H
