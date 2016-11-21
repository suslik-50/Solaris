#ifndef DRAIN_PARAMETRS_SOLAR_BATTERY_H
#define DRAIN_PARAMETRS_SOLAR_BATTERY_H

#include <QObject>
#include <QThread>
#include <structur.h>
#include <QString>
#include <QList>
#include <QMap>


class drain_parametrs_solar_battery:public QThread
{
    Q_OBJECT
public:QMap<QString,solar_battery_salleter> data_sbs;
public:drain_parametrs_solar_battery();
public:int count_drain();
public:void clear();
private:void set_data(double a,double b,double time,QString name);
public slots:
    void run();
    void deletedata(QString name);
    void data (double a,double b,double time,QString name);

    void get_data();
signals:
    void data_solar_battery(QMap<QString,solar_battery_salleter>);
    void new_data();
};

#endif // DRAIN_PARAMETRS_SOLAR_BATTERY_H
