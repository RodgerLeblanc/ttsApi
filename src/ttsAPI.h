/*
 * ttsAPI.h
 *
 *  Created on: 2014-10-06
 *      Author: Roger
 */

#ifndef TTSAPI_H_
#define TTSAPI_H_

#include <QObject>
#include <QtNetwork>

namespace bb {
    namespace multimedia {
        class MediaPlayer;
    }
}

class ttsAPI : public QObject
{
    Q_OBJECT

public:
    ttsAPI();
    virtual ~ttsAPI();

    Q_INVOKABLE void google_tts(const QString & message, const QString & language);
    Q_INVOKABLE void vozme_tts(const QString & message, const QString & gender, const QString & language);

public slots:

private slots:
    void onGoogleTtsResponse();
    void onVozmeTtsResponse1();
    void onVozmeTtsResponse2();
    void onPlaybackCompleted();

private:
    void writeMp3File(const QByteArray & mp3FileData);

    QNetworkAccessManager* m_networkAccessManager;
    bb::multimedia::MediaPlayer *mp;

    QFile lastMp3;

signals:
    void playbackCompleted();
};

#endif /* TTSAPI_H_ */
