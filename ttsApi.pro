APP_NAME = ttsApi

CONFIG += qt warn_on cascades10

include(config.pri)

LIBS += -lbbmultimedia -lQtLocationSubset -lbbdata
QT += network