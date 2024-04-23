#include "show.h"

Show::Show(QWidget *parent)
{
    this->setParent(parent);
    this->setGeometry(0, 0, 800, 480);
    this->setMinimumSize(800, 480);
    if(mymain == nullptr){mymain = new Widget(this);mymain->setVisible(false);}
    if(my_ledp == nullptr){my_ledp = new led_pwm(this);my_ledp->setVisible(false);}
    if(my_capture == nullptr){my_capture = new capture(this);my_capture->setVisible(false);}
    if(my_timer == nullptr){my_timer = new Mytimer(this);my_timer->setVisible(false);}
    if(my_aichat == nullptr){my_aichat = new AIchat();my_aichat->setVisible(false);}
    if(my_set == nullptr){my_set = new set(this);my_set->setVisible(false);}
    mymain->setVisible(true);

}
Show::~Show()
{
}
