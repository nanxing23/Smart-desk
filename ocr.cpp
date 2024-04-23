/*人像检测，检测坐姿*/
#include "ocr.h"
#include <QCoreApplication>
#include <QBuffer>

Ocr::Ocr(QObject *parent)
    : QObject(parent)
{
    /* 网络管理 */
    networkAccessManager = new QNetworkAccessManager(this);

    /* 获取token的 Url */
    tokenUrl = QString(token_org).arg(api_key).arg(secret_key);

    QByteArray requestData;
    requestData.clear();

    /* 开始获取tokenUrl */
    requestNetwork(tokenUrl, requestData);/* 请求网络 */
}

Ocr::~Ocr()
{
}

/* 请求网络 */
void Ocr::requestNetwork(QString url, QByteArray requestData)
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

    connect(newReply, SIGNAL(finished()), this, SLOT(replyFinished()));
    connect(newReply, SIGNAL(readyRead()), this, SLOT(readyReadData()));

}

/* 读取数据 */
void Ocr::readyReadData()
{
    QNetworkReply *reply = (QNetworkReply *)sender();
    QByteArray data = reply->readAll();

    if (reply->url() == QUrl(tokenUrl)) {

        qDebug()<<QString(data)<<endl;
        QString key = "access_token";

        QString temp = getJsonValue(data, key);/* Json解释分离数据 */
        accessToken = temp;

        qDebug()<<accessToken<<endl;
        if (!data.contains("error")) {
            qDebug()<<"获取token成功，可以调用readyToDetection发送图片返回结果"<<endl;
        } else {
            accessToken = nullptr;
            qDebug() << "获取token失败，请检查您的APP SECRET和APPKEY，或者是否开通了车牌识别服务！"<<endl;
        }
    }

    if (reply->url() == QUrl(serverApiUrl)) {
//        qDebug()<<QString(data)<<endl;
        QString key1 = "person_info";
        QString key2 = "body_parts";
        QString key3 = "nose";
        QString key4 = "left_wrist";
        getJsonValue(data, key1, key2,key3,0);/* Json解释分离数据nose */
        getJsonValue(data, key1, key2,key4,1);/* Json解释分离数据left_wrist */
        if(qAbs(numy[1]-numy[0])<240){
            emit ocrReadyData("坐姿不正确");
        }else {
            emit ocrReadyData("坐姿正确");
        }
    }
}

/* 请求完成处理，释放对象 */
void Ocr::replyFinished()
{
    QNetworkReply *reply = (QNetworkReply *)sender();
    reply->deleteLater();
    reply = nullptr;
}

/* 开始识别 */
void Ocr::getTheResult(QString fileName)/*将图像文件内容转换为Base64编码*/
{
    QFile file;
    file.setFileName(fileName);
    if (!file.exists()) {
        qDebug()<<fileName<<"不存在!"<<endl;
        return;
    }

    QByteArray requestData;

    file.open(QIODevice::ReadOnly);
    requestData = file.readAll();
    file.close();

    /* 转成buf64 */
    QByteArray buf64 = requestData.toBase64().toPercentEncoding();
    QByteArray body = "image=" + buf64;

    serverApiUrl = QString(server_api).arg(accessToken);

    requestNetwork(serverApiUrl, body);/* 请求网络 */
}

/* 开始识别 */
void Ocr::getTheResult(QImage image)
{
    QByteArray requestData;

    QBuffer buffer(&requestData);

    buffer.open(QIODevice::WriteOnly);

    image.save(&buffer, "JPEG", -1);

    /* 转成buf64 */
    QByteArray buf64 = requestData.toBase64().toPercentEncoding();
    QByteArray body = "image=" + buf64;

    serverApiUrl = QString(server_api).arg(accessToken);

    requestNetwork(serverApiUrl, body);/* 请求网络 */
}

/* Json解释分离数据 */
QString Ocr::getJsonValue(QByteArray ba, QString key)
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

/* Json解释分离数据 */
QString Ocr::getJsonValue(QByteArray ba, QString key1, QString key2)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba, &parseError);

    if (parseError.error == QJsonParseError::NoError) {

        if (jsonDocument.isObject()) {
            /* jsonDocument转化为json对象 */
            QJsonObject jsonObj = jsonDocument.object();

            if (jsonObj.contains(key1)) {
                QJsonObject jsonArrObj = jsonObj.value(key1).toObject();
                if (jsonArrObj.contains(key2)) {
                    return jsonArrObj.value(key2).toString();
                } else { qDebug() << "not contains " + key2 << endl;}
            } else { qDebug() << "not contains " + key1 << endl;}
        } else { qDebug() << "is not an Object" << endl;}
    }

    return nullptr;
}

int Ocr::getJsonValue(QByteArray ba, QString key1, QString key2,QString key3,int x)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba, &parseError);

    if (parseError.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            /* jsonDocument转化为json对象 */
            QJsonObject jsonObj = jsonDocument.object();
            if (jsonObj.contains(key1)) {
                QJsonArray jsonObj1 = jsonObj.value(key1).toArray();
                if (!jsonObj1.isEmpty()) {
                    QJsonObject jsonObj2 = jsonObj1.at(0).toObject().value(key2).toObject();
                    if(jsonObj2.contains(key3)){
                        QJsonObject jsonObj3 = jsonObj2.value(key3).toObject();
                        numx[x] = jsonObj3.value("x").toDouble();
                        numy[x] = jsonObj3.value("y").toDouble();
                        qDebug() <<"x"<<x<< numx[x] << endl;
                        qDebug()<<"y"<<x << numy[x] << endl;
                    }else{qDebug() << "not contains3 " + key3 << endl;}
                }else { qDebug() << "not contains2 " + key2 << endl;}
            } else { qDebug() << "not contains1 " + key1 << endl;}
        } else { qDebug() << "is not an Object" << endl;}
    }

    return 0;
}

/* 准备识别 */
void Ocr::readyToDetection(QString imagePath)
{
    if (accessToken.isEmpty()) {
        qDebug() << "未获取到token!已返回！" <<endl;
        return;
    }
    getTheResult(imagePath);/* 开始识别 */
}

/* 准备识别 */
void Ocr::readyToDetection(QImage image)
{
    if (accessToken.isEmpty()) {
        qDebug() << "未获取到token!已返回！" <<endl;
        return;
    }
    getTheResult(image);/* 开始识别 */
}
