#include "show.h"

Show::Show(QWidget *parent)
{
    this->setParent(parent);
    this->setGeometry(0, 0, 800, 480);
    this->setMinimumSize(800, 480);
    my_YDragButton = new YDragButton(this);
    my_YDragButton->setStyleSheet("border-image: url(:/image/ydpushbuton.png);");
    my_YDragButton->setGeometry(700,40,100,100);
    my_YDragButton->setMargin(0,0,0,0);
    if(mymain == nullptr){mymain = new Widget(this);mymain->setVisible(false);}
    if(my_ledp == nullptr){my_ledp = new led_pwm(this);my_ledp->setVisible(false);}
    if(my_capture == nullptr){my_capture = new capture(this);my_capture->setVisible(false);}
    if(my_timer == nullptr){my_timer = new Mytimer(this);my_timer->setVisible(false);}
    if(my_aichat == nullptr){my_aichat = new AIchat(this);my_aichat->setVisible(false);}
    if(my_file == nullptr){my_file = new File(this);my_file->setVisible(false);}
    if(my_set == nullptr){my_set = new set(this);my_set->setVisible(false);}
    mymain->setVisible(true);

    connect(my_YDragButton,SIGNAL(clicked()),this,SLOT(gohome()));

}
Show::~Show()
{
}

void Show::gohome()
{
    mymain->setVisible(true);
    my_set->setVisible(false);
    my_ledp->setVisible(false);
    my_capture->setVisible(false);
    my_timer->setVisible(false);
    my_aichat->setVisible(false);
    my_file->setVisible(false);
    if(captureflash == 1){
        emit my_capture->sendwidget(0);
        captureflash = 0;
    }
}
