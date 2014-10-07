/*
 * Magic.h
 *
 *  Created on: 2014-10-06
 *      Author: Roger
 */

#ifndef MAGIC_H_
#define MAGIC_H_

#include <QObject>
#include <QtNetwork>
#include <QtLocationSubset/QGeoPositionInfo>
#include <QtLocationSubset/QGeoPositionInfoSource>
#include <QtLocationSubset/QGeoSearchManager>
#include <QtLocationSubset/QGeoServiceProvider>

using namespace QtMobilitySubset;

class Magic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gpsInfo READ getGpsInfo WRITE setGpsInfo NOTIFY gpsInfoChanged);
    Q_PROPERTY(QString city READ getCity WRITE setCity NOTIFY cityChanged);
    Q_PROPERTY(QString summary READ getSummary WRITE setSummary NOTIFY summaryChanged);

public:
    Magic();
    virtual ~Magic();

    Q_INVOKABLE void makeMagicHappen();
    void setSummary(const QString & newValue) { m_summary = newValue; emit summaryChanged(); }

    private slots:
        void positionUpdated(const QGeoPositionInfo & pos);
        void readReverseGeocode();
        void onGpsReady();
        void onReadWeather();

    private:
        QString getGpsInfo() { return m_gpsInfo; }
        void setGpsInfo(const QString & newValue) { m_gpsInfo = newValue; emit gpsInfoChanged(); }
        QString getCity() { return m_city; }
        void setCity(const QString & newValue) { m_city = newValue; emit cityChanged(); }
        QString getSummary() { return m_summary; }

        QNetworkAccessManager* m_networkAccessManager;
        QGeoPositionInfoSource *source;

        bool saved;
        QString m_city;
        QString m_gpsInfo;
        QString m_summary;

signals:
    void gpsInfoChanged();
    void cityChanged();
    void summaryChanged();
    void magicReady(const QString&);
};

#endif /* MAGIC_H_ */
