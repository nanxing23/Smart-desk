/******************************************************************
录音的底层
*******************************************************************/
#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioRecorder>
#include <QAudioProbe>
#include <QAudioBuffer>

class AudioRecorder : public QObject
{
    Q_OBJECT

public:
    AudioRecorder(QWidget *parent = nullptr);
    ~AudioRecorder();

private:
    /* 录音类 */
    QAudioRecorder *m_audioRecorder = nullptr;/*它提供了录制音频的基本功能，允许开发者在应用程序中集成音频录制的能力*/

    /* 用于探测缓冲区的level */
    QAudioProbe *m_probe = nullptr;/*用于监视正在播放或录制的音频数据*/

    /* 录音设置容器，保存录音设备的可用信息 */
    QList<QVariant>devicesVar;
    QList<QVariant>codecsVar;
    QList<QVariant>containersVar;
    QList<QVariant>sampleRateVar;
    QList<QVariant>channelsVar;
    QList<QVariant>qualityVar;
    QList<QVariant>bitratesVar;

    /* 清空录音level */
    void clearAudioLevels();

public slots:
    /* 开始录音槽函数 */
    void startRecorder();

    /* 停止录音槽函数 */
    void stopRecorder();

    /* 更新录音时长 */
    void updateProgress(qint64);

    /* 更新录音level */
    void processBuffer(const QAudioBuffer&);
};
#endif // AUDIORECORDER_H
