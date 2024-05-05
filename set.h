/*设置的界面*/
#ifndef SET_H
#define SET_H

#include <QWidget>
#include <QProcess>



namespace Ui {
class set;
}

class set : public QWidget
{
    Q_OBJECT

signals:
    void sendjcflash(bool flash);/*控制检测坐姿的开关*/

public:
    explicit set(QWidget *parent = nullptr);
    ~set();

private slots:

    /* 显示ｃｐｕ温度 */
    void showcputemp(QString);
    void on_brightness_valueChanged(int value);

    void on_brightness_sliderReleased();

    void on_zzjc_clicked(bool checked);

private:
    Ui::set *ui;
    QProcess *processbn = new QProcess(this);
};

#endif // SET_H
