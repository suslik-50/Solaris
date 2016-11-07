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
private:vector_salleter sputnik;
private:vec san;
private:double a,b;
private:double buffer;
private:bool sostaunie_salleter,sostaunie_san;
private:void datapotoc();
private:bool qdebug=false;
private:solar_battery_salleter cornes(vec san,vector_salleter salleter);
private:void datacornes(solar_battery_salleter salleter);
public:corners_solar_battery();

public slots:
    void  run();
    void position_salleter(vector_salleter salleter);
    void position_sun(double x,double y,double z);
    void debug(bool y_n);
signals:
    void data (double a,double b,double time,QString name);
};




#endif // CORNERS_SOLAR_BATTERY_H
