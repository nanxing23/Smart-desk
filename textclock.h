/*闹钟部件的类*/
#ifndef TEXTCLOCK_H
#define TEXTCLOCK_H

#include <QWidget>
#include <QFrame>
#include <QLabel>


class textclock : public QWidget
{
public:
    textclock();

    textclock(QWidget* parent = nullptr) : QWidget(parent) {
        QFrame* frame = new QFrame(this);
        frame->setStyleSheet("QFrame{background-color:blue}");
        frame->setGeometry(100,100,100,100);


        QLabel* label = new QLabel(frame);
        label->setGeometry(20, 30, 150, 30);

    }

};

#endif // TEXTCLOCK_H
