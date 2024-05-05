/**
 * 可拖动的按钮
 * 1、设置图片型的
 * 2、单独文字的可拖拽
 * 3、可设置移动的区域的，即设置四周的距离
 */
#include "ydragbutton.h"
YDragButton::YDragButton(QWidget *parent) : QPushButton(parent)
{

    isPressed = false;
    isMoved = false;
    lastPoint = QPoint();
    x_left_distance = 0;
    x_right_distancce =0;
    y_top_distance =0;
    y_bottom_distance=0;
    this->installEventFilter(this);
}

YDragButton::~YDragButton()
{

}


void YDragButton::setMargin(int left, int top, int right, int bottom)
{
    x_left_distance = left;
    y_top_distance = top;
    x_right_distancce = right;
    y_bottom_distance = bottom;
}

/** 识别鼠标绑定事件
 * @brief YDragButton::eventFilter
 * @param watched
 * @param event
 * @return
 */
bool YDragButton::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    switch(event->type())
    {
    case QEvent::MouseButtonPress:
    {
        if (mouseEvent->button() == Qt::LeftButton) {
            lastPoint = mouseEvent->pos();
            isPressed = true;
        }
        break;
    }
    case QEvent::MouseMove:
    {
        if (isPressed) {
            int dx = mouseEvent->pos().x() - lastPoint.x();
            int dy = mouseEvent->pos().y() - lastPoint.y();
            int x1 = this->x()+dx;
            int y1 = this->y()+dy;
            int right_distance = this->parentWidget()->width() -2*x_right_distancce-this->width();
            int bottom_distance =this->parentWidget()->height() -2*y_bottom_distance -this->height();
            if(x1>x_left_distance &&x1< right_distance &&y1>y_top_distance &&y1<bottom_distance)
                this->move(this->x() + dx, this->y() + dy);
            isMoved = true;
        }
        break;
    }
    case QEvent::MouseButtonRelease:
    {
        if(isMoved !=true){
            emit clicked();
            emit toggled(!isChecked);
            isChecked = !isChecked;
        }else{
            isMoved = false;
        }
        isPressed = false;
        break;
    }
    case QEvent::MouseButtonDblClick:
        emit doubleClicked();
        break;
    default:
        break;
    }
    return QWidget::eventFilter(watched,event);
}

