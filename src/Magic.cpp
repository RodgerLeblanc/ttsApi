/*
 * Magic.cpp
 *
 *  Created on: 2014-10-06
 *      Author: Roger
 */

#include <src/Magic.h>
#include <bb/data/JsonDataAccess>

Magic::Magic():
    m_networkAccessManager(new QNetworkAccessManager(this))
{
    connect(this, SIGNAL(cityChanged()), this, SLOT(onGpsReady()));
}

Magic::~Magic()
{
    m_networkAccessManager->deleteLater();
    source->deleteLater();
}

void Magic::makeMagicHappen() {
    qDebug() << "makeMagicHappen()";
    // Get a GPS fix at startup
    source = QGeoPositionInfoSource::createDefaultSource(this);
    // saved boolean is there to save only once the location
    saved = false;
    if (source) {
        source->setProperty( "canRunInBackground", true );
        source->startUpdates();
        connect(source, SIGNAL(positionUpdated(const QGeoPositionInfo &)), this, SLOT(positionUpdated(const QGeoPositionInfo &)));
    }
}

void Magic::positionUpdated(const QGeoPositionInfo & pos)
{
    qDebug() << "positionUpdated()";

    // Get a GPS fix with an accuracy of less than 2000 meters and save the coordinates for further use
    qDebug() << pos.coordinate().latitude() << pos.coordinate().longitude();
    double accuracy = pos.attribute(QGeoPositionInfo::HorizontalAccuracy);
    qDebug() << accuracy;
    if (accuracy < 2000) {
        QString lat = QString::number(pos.coordinate().latitude());
        QString lon = QString::number(pos.coordinate().longitude());
        source->stopUpdates();
        if (!saved) {
            saved = true;
            QString gps = lat + "," + lon;
            setGpsInfo(gps);

            // Initialize QGeoSearchManager
            QGeoSearchManager* searchManager;
            QGeoServiceProvider* serviceProvider;
            QStringList serviceProviders = QtMobilitySubset::QGeoServiceProvider::availableServiceProviders();
            if ( serviceProviders.size() ) {
                serviceProvider = new QtMobilitySubset::QGeoServiceProvider(serviceProviders.at(0));
                searchManager = serviceProvider->searchManager();
            }

            // create GeoCoordinate from latitude and longitude
            QtMobilitySubset::QGeoCoordinate myCoord =  QtMobilitySubset::QGeoCoordinate(lat.toDouble(), lon.toDouble());

            // get reverseGeocode
            QGeoSearchReply* reply = searchManager->reverseGeocode(myCoord);

            QObject::connect(reply, SIGNAL(finished()), this, SLOT(readReverseGeocode()));
        }
    }
}

void Magic::readReverseGeocode()
{
    qDebug() << "readReverseGeocode()";
    QGeoSearchReply* reply = qobject_cast<QGeoSearchReply*>(sender());
    // Save the city name to Settings for further use
    if (reply->error() != QGeoSearchReply::NoError)
        return;

    QList<QGeoPlace> places = reply->places();
    if (places.length() == 0)
        return;
    else {
        QGeoAddress address = places[0].address();
        setCity(address.city());
    }
    disconnect(reply, SIGNAL(finished()), this,SLOT(readReverseGeocode()));
    reply->deleteLater();
}

void Magic::onGpsReady() {
    qDebug() << "onGpsReady()";

    // Send weather request
    // This is my personal apiKey, please create your own, it's free at forecast.io
    QString apiKey = "204c63addffcde9f9cf6b72936f788bb";
    QString units = "?units=si"; // replace by "" if you want imperial + you'll have to change some hard coded 'Celsius' strings
    QString url = "https://api.forecast.io/forecast/" + apiKey + "/" + getGpsInfo() + units;

    QNetworkRequest request(url);

    QNetworkReply* reply = m_networkAccessManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(onReadWeather()));
}

void Magic::onReadWeather() {
    qDebug() << "onReadMessage in";
    QVariantMap jsonreply;
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                bb::data::JsonDataAccess ja;
                const QVariant jsonva = ja.loadFromBuffer(buffer);
                jsonreply = jsonva.toMap();
            }
        } // end of : if (reply->error() == QNetworkReply::NoError)
        reply->deleteLater();
    }  // end of : if (reply)

    // Save all the weather data in different map for easy access
    QVariantMap currentlyMap = jsonreply.value("currently").toMap();
    QVariantMap minutelyMap = jsonreply.value("minutely").toMap();
    QVariantMap hourlyMap = jsonreply.value("hourly").toMap();
    QVariantMap dailyMap = jsonreply.value("daily").toMap();
    QVariantList dailyData = dailyMap.value("data").toList();

    // Build the weather summary that will be read
    QString summary;
    if (QTime::currentTime().toString("ap") == "am")
        summary.append("Good morning, it's ");
    else
        summary.append("Good afternoon, it's ");

    summary.append(QTime::currentTime().toString("h mm ap") + ". ");

    summary.append("Weather is " + QString::number(floor(currentlyMap.value("temperature").toDouble() + 0.5)));
    summary.append(" degree Celsius and " + currentlyMap.value("summary").toString() + " in " + getCity() + ". ");
    summary.append(hourlyMap.value("summary").toString() + " ");
    if (!dailyData.isEmpty()) {
        QVariantMap dailyDataMap = dailyData[0].toMap();
        summary.append("Today's high is " + QString::number(floor(dailyDataMap.value("temperatureMax").toDouble() + 0.5)) + " degree. ");
    }
    summary.append("Forecast for the week : ");
    summary.append(dailyMap.value("summary").toString());

    emit magicReady(summary);
}
