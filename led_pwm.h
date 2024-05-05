/*ＬＥＤ灯的界面*/
#ifndef LED_PWM_H
#define LED_PWM_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class led_pwm;
}

class led_pwm : public QWidget
{
    Q_OBJECT

public:
    explicit led_pwm(QWidget *parent = nullptr);
    ~led_pwm();

private slots:

    void on_ledslider_valueChanged(int value);/*ledpwm控制亮度*/

    void on_closeled_clicked();/*led_pwm关灯*/

private:
    Ui::led_pwm *ui;

    QProcess *processled = new QProcess(this);/*led_pwm文件*/
};

#endif // LED_PWM_H
