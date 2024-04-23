/*数字滑块的类*/
#ifndef TIMESELECT_H
#define TIMESELECT_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>



class timeSelect : public QWidget
{
    Q_OBJECT
public:
    explicit timeSelect(QWidget *parent = nullptr);
    ~timeSelect();
public:
    void setRange(int min, int max);//设置范围
    int readValue(); //获取当前值
    QString getValueStr();//获取当前值
    void setFormat(QString prefix,QString suffix);//设定显示格式，前缀和后缀
    void setCurValue(int Value);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent * m_painter);
    void paintNum(QPainter &painter,int num,int deviation,bool isMiddle); //绘制数字

private:
    int m_minRange; //最小值
    int m_maxRange; //最大值
    int m_currentValue; //当前选中的值
    bool isDragging; //鼠标是否按下
    int m_deviation; //偏移量，记录鼠标按下后移动的垂直距离
    int m_mouseSrcPos; //鼠标源Y轴座标，用来计算偏移量
    int m_numSize; //计算所得的数字字符尺寸，以最长的情况为准
    bool isMiddle; //是否是中间的数字
    QString m_prefix;//显示格式前缀
    QString m_suffix;//显示格式后缀
    QPropertyAnimation *homingAni;//QPropertyAnimation 是一个控制动画效果的类

    void homing(); //使选中的数字回到屏幕中间

signals:
    void currentValueChanged(int value); //当前数值改变信号
    void deviationChange(float deviation); //偏移量改变信号
private slots:
    void slotChoseFinshed();
};

#endif // TIMESELECT_H
