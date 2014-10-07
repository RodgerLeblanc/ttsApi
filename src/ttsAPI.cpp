/*
 * ttsAPI.cpp
 *
 *  Created on: 2014-10-06
 *      Author: Roger Leblanc
 *
 *
 *  Don't forget to add this to your PRO file :
 *      QT += network
 *
 *
 */


#include "ttsAPI.h"
#include "Commons.h"
#include <bb/data/XmlDataAccess>
#include <bb/multimedia/MediaPlayer>

ttsAPI::ttsAPI():
    m_networkAccessManager(new QNetworkAccessManager(this)),
    mp(new bb::multimedia::MediaPlayer(this)),
    lastMp3("/accounts/1000/shared/documents/lastMp3.mp3")
{
    connect(mp, SIGNAL(playbackCompleted()), this, SLOT(onPlaybackCompleted()));
}

ttsAPI::~ttsAPI()
{
    m_networkAccessManager->deleteLater();
    mp->deleteLater();
}

void ttsAPI::google_tts(const QString & message, const QString & language) {
    qDebug() << "google_tts() :" << message << language;
    QNetworkRequest request(QString(GOOGLE_TTS_URL).arg(language.isEmpty() ? QLocale().name().mid(0, 2) : language.toLower(), message));

    qDebug() << request.url();

    QNetworkReply* replyGet = m_networkAccessManager->get(request);
    connect(replyGet, SIGNAL(finished()), this, SLOT(onGoogleTtsResponse()));
}

void ttsAPI::onGoogleTtsResponse() {
    qDebug() << "onGoogleTtsResponse()";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                writeMp3File(buffer);
            }
        } // end of : if (reply->error() == QNetworkReply::NoError)
        reply->deleteLater();
    }  // end of : if (reply)
}

void ttsAPI::vozme_tts(const QString & message, const QString & gender, const QString & language) {
    qDebug() << "vozme_tts() :" << message << gender << language;
    QNetworkRequest request(QString(VOZME_TTS_URL).arg(language.isEmpty() ? QLocale().name().mid(0, 2) : language.toLower(), gender.isEmpty() ? "ml" : gender.toLower(), message));

    qDebug() << request.url();

    QNetworkReply* replyGet = m_networkAccessManager->get(request);
    connect(replyGet, SIGNAL(finished()), this, SLOT(onVozmeTtsResponse1()));
}

void ttsAPI::onVozmeTtsResponse1() {
    qDebug() << "onVozmeTtsResponse1()";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());

                // This code is ugly but it works
                int temp = buffer.indexOf("<audio autoplay", 0);
                int start = buffer.indexOf("a href=", temp) + 8;
                int end = buffer.indexOf("\"", start);

                QString url = buffer.mid(start, end - start);

                qDebug() << "Mp3 URL :" << url;
                QNetworkRequest request(url);

                QNetworkReply* replyGet = m_networkAccessManager->get(request);
                connect(replyGet, SIGNAL(finished()), this, SLOT(onVozmeTtsResponse2()));
            }
        } // end of : if (reply->error() == QNetworkReply::NoError)
        reply->deleteLater();
    }  // end of : if (reply)
}

void ttsAPI::onVozmeTtsResponse2() {
    qDebug() << "onVozmeTtsResponse2()";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                writeMp3File(buffer);
            }
        } // end of : if (reply->error() == QNetworkReply::NoError)
        reply->deleteLater();
    }  // end of : if (reply)
}

void ttsAPI::writeMp3File(const QByteArray & mp3FileData) {
    if (lastMp3.exists())
        lastMp3.remove();

    if (lastMp3.open(QIODevice::ReadWrite))
    {
        // Write to the file
        lastMp3.write(mp3FileData);
        lastMp3.flush();
        lastMp3.close();
    }

    // Plays the audio as soon as it's available
    mp->reset();
    mp->setSourceUrl(lastMp3.fileName());
    mp->play();
}

void ttsAPI::onPlaybackCompleted() {
    emit playbackCompleted();
}
