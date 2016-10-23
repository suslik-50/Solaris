#ifndef CORNERS_SOLAR_BATTERY_H
#define CORNERS_SOLAR_BATTERY_H

#include <QObject>
#include <QThread>
#include <structur.h>
#include <QString>
#include <setting.h>
class corners_solar_battery:public QThread
{
    Q_OBJECT
private:setting seting;
private:vector_s sputnik;
private:sun San;
private:QString name;
private:double a,b,time;
private:bool qdebug=false;
private:void cornes();
public:corners_solar_battery();
public slots:
    void  run();
    void position_salleter(vector_s salleter,double time,QString name_s);
    void position_sun(double x,double y,double z,double t);
    void debug(bool y_n);
signals:
    void data (double a,double b,double time,QString name);
};




#endif // CORNERS_SOLAR_BATTERY_H