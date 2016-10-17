#ifndef DRAIN_PARAMETRS_SOLAR_BATTERY_H
#define DRAIN_PARAMETRS_SOLAR_BATTERY_H

#include <QObject>
#include <QThread>
#include <structur.h>
#include <QString>
#include <QList>

class drain_parametrs_solar_battery:public QThread
{
    Q_OBJECT
public:QList<solar_battery_salleter> data_sbs;
public:drain_parametrs_solar_battery();
public:int count_drain();
public:void clear();
public slots:
    void run();
    void data (solar_battery_salleter salleter_data);
    void get_data();
signals:
    void data_solar_battery(QList<solar_battery_salleter>);
};

#endif // DRAIN_PARAMETRS_SOLAR_BATTERY_H
