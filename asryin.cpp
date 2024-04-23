/******************************************************************
识别声音挂在ＡＰＩ
*******************************************************************/
#include "asryin.h"
#include <QCoreApplication>

Asryin::Asryin(QWidget *parent)
    : QWidget(parent)
{
    networkAccessManager = new QNetworkAccessManager(this);/* 网络管理的类 */

    QString fileName = QCoreApplication::applicationDirPath() + "/16k.wav";
    file.setFileName(fileName);

    if (file.exists())
        qDebug()<<fileName<<endl;

    tokenUrl = QString(token_org).arg(api_key).arg(secret_key);/* 获取token的 Url */

    QByteArray requestData;
    requestData.clear();

    requestNetwork(tokenUrl, requestData);/* 请求网络 */
}

Asryin::~Asryin()
{
}

/* 请求网络 */
void Asryin::requestNetwork(QString url, QByteArray requestData)
{
    /* 网络请求 */
    QNetworkRequest networkRequest;

    /* 开发板需要加一些安全配置才能访问https */
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1SslV3);
    networkRequest.setSslConfiguration(config);

    /* 以json格式返回 */
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,
                             "application/json;charset=UTF-8");

    /* 设置pcm编码，采样率为16000 */
    networkRequest.setRawHeader("Content-Type", QString("audio/pcm;rate=16000").toLatin1());

    /* 设置访问的地址 */
    networkRequest.setUrl(url);

    /* 网络响应 */
    QNetworkReply *newReply = networkAccessManager->post(networkRequest, requestData);

    connect(newReply, SIGNAL(finished()), this, SLOT(replyFinished()));/* 请求完成处理，释放对象 */
    connect(newReply, SIGNAL(readyRead()), this, SLOT(readyReadData()));/* 读取数据 */

}

/* 读取数据 */
void Asryin::readyReadData()
{
    QNetworkReply *reply = (QNetworkReply *)sender();
    QByteArray data = reply->readAll();

    if (reply->url() == QUrl(tokenUrl)) {

        qDebug()<<QString(data)<<endl;
        QString key = "access_token";

        QString temp = getJsonValue(data, key);
        accessToken = temp;

        qDebug()<<accessToken<<endl;
        if (!data.contains("error")) {
        qDebug()<<"获取token成功，可以调用getTheResult设置语音路径返回结果"<<endl;
        }else{
            accessToken = nullptr;
            qDebug()<<"获取token失败，请检查您的APP SECRET和APPKEY，或者是否开通了车牌识别服务！"<<endl;
        }
    }

    if (reply->url() == QUrl(serverApiUrl)) {/*处理结果*/
        qDebug()<<QString(data)<<endl;
        QString key = "result";

        QString temp = getJsonValue(data, key);

        emit asrReadyData(temp);
        qDebug()<<temp<<endl;
    }

}

/* 请求完成处理，释放对象 */
void Asryin::replyFinished()
{
    QNetworkReply *reply = (QNetworkReply *)sender();
    if (reply->url() == QUrl(tokenUrl) ) {
        //        QByteArray requestData;

        //        file.open(QIODevice::ReadOnly);
        //        requestData = file.readAll();
        //        file.close();

        //        serverApiUrl = QString(server_api).arg(QHostInfo::localHostName()).arg(accessToken);

        //        requestNetwork(serverApiUrl, requestData);
    }

    reply->deleteLater();
    reply = nullptr;
}

/* 获取识别结果 */
void Asryin::getTheResult(QString fileName)
{
    file.setFileName(fileName);
    if (!file.exists()) {
        qDebug()<<"已返回，文件"<<fileName<<"不存在"<<endl;
        return;
    }

    QByteArray requestData;

    file.open(QIODevice::ReadOnly);
    requestData = file.readAll();
    file.close();

    serverApiUrl = QString(server_api).arg(QHostInfo::localHostName()).arg(accessToken);

    requestNetwork(serverApiUrl, requestData);
}

/* Json解释分离数据 */
QString Asryin::getJsonValue(QByteArray ba, QString key)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba, &parseError);

    if (parseError.error == QJsonParseError::NoError) {

        if (jsonDocument.isObject()) {
            /* jsonDocument转化为json对象 */
            QJsonObject jsonObj = jsonDocument.object();

            if (jsonObj.contains(key)) {
                QJsonValue jsonVal= jsonObj.value(key);

                if (jsonVal.isString()) {
                    return jsonVal.toString();

                } else if (jsonVal.isArray()) {
                    /* 转换成jsonArray */
                    QJsonArray arr = jsonVal.toArray();
                    /* 获取第一个元素 */
                    QJsonValue jv = arr.at(0);
                    return jv.toString();
                }
            }
        }
    }

    return nullptr;
}
