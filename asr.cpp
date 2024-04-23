/******************************************************************
聊天ＡＩ挂在ＡＰＩ
*******************************************************************/
#include "asr.h"
#include <QCoreApplication>

Asr::Asr(QWidget *parent)
    : QWidget(parent)
{
    networkAccessManager = new QNetworkAccessManager(this);/* 网络管理的类 */

    tokenUrl = QString(token_org).arg(api_key).arg(secret_key);/* 获取token的 Url */

    QByteArray requestData;
    requestData.clear();

    requestNetwork(tokenUrl, requestData);/* 请求网络 */
}

Asr::~Asr()
{
}

/* 请求网络 */
void Asr::requestNetwork(QString url, QByteArray requestData)
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

    /* 设置访问的地址 */
    networkRequest.setUrl(url);

    /* 网络响应 */
    QNetworkReply *newReply = networkAccessManager->post(networkRequest, requestData);

    connect(newReply, SIGNAL(finished()), this, SLOT(replyFinished()));/* 请求完成处理，释放对象 */
    connect(newReply, SIGNAL(readyRead()), this, SLOT(readyReadData()));/* 读取数据 */

}

/* 读取数据 */
void Asr::readyReadData()
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
            qDebug()<<"获取token失败，请检查您的APP SECRET和APPKEY！"<<endl;
        }
    }

    if (reply->url() == QUrl(serverApiUrl)) {/*处理结果*/
        QString key = "result";

        QString temp = getJsonValue(data, key);

        emit asrReadyData(temp);
        qDebug()<<temp<<endl;
    }

}

/* 请求完成处理，释放对象 */
void Asr::replyFinished()
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
void Asr::getTheResult(QString content)
{
    QJsonArray messagesArray;
    QJsonObject messageObject;
    messageObject["role"] = "user";
    messageObject["content"] = content;
    messagesArray.append(messageObject);
    QJsonObject jsonObject;
    jsonObject["messages"] = messagesArray;
    QByteArray body = QJsonDocument(jsonObject).toJson(QJsonDocument::Indented);
    qDebug() << body;

    serverApiUrl = QString(server_api).arg(accessToken);

    requestNetwork(serverApiUrl, body);/* 请求网络 */
}

/* Json解释分离数据 */
QString Asr::getJsonValue(QByteArray ba, QString key)
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

/* 准备识别 */
void Asr::readyToDetection(QString user)
{
    if (accessToken.isEmpty()) {
        qDebug() << "未获取到token!已返回！" <<endl;
        return;
    }
    getTheResult(user);/* 开始识别 */
}
