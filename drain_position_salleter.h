#ifndef DRAIN_POSITION_SALLETER_H
#define DRAIN_POSITION_SALLETER_H

#include <QObject>
#include <QThread>
#include <structur.h>
#include <QString>
#include <QList>
#include <QMap>

class drain_position_salleter:public QThread
{
     Q_OBJECT
public:drain_position_salleter();
public:QMap<QString,vector_salleter> data_salleter;
public:int count_drain();
public:void clear();
public slots:
    void run();
    void deletedata(QString name);
    void data(vector_salleter name);
    void data (double x,double y,double z,double vx, double vy,double vz,QString name,double time);
    void get_data();
signals:
    void data_salleter_signal(QMap<QString,vector_salleter>);
    void new_data();
};

#endif // DRAIN_POSITION_SALLETER_H
