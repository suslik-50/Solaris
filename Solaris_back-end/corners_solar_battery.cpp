#include <corners_solar_battery.h>
#include <QDebug>
#include<QDateTime>
#include <QDebug>
#include <math.h>
#include <function_cornes.h>
#define PI 3.14159265

corners_solar_battery::corners_solar_battery()
{
    qdebug=seting.Get_corners_solar_batter_qdebug();
    san.x=0 ;
    sputnik.x=0;
}

void corners_solar_battery::run()
{
    exec();
}
// перевод в орбитальные координаты


solar_battery_salleter corners_solar_battery::cornes(vec san,vector_salleter salleter)
{


    solar_battery_salleter corne;
    corne =fun_cornes(san,salleter);
    if (false)
    {
        qDebug()<<salleter.name<<"-имя спутника";
        qDebug()<<corne.a<<"-угол а(альфа)";
        qDebug()<<corne.b<<"-угол б(бетта)";
        qDebug()<<QDateTime::fromTime_t(salleter.time).time();
        qDebug()<<QDateTime::fromTime_t(salleter.time).date();
    }

    return corne;
}

void corners_solar_battery::datacornes(solar_battery_salleter salleter)
{
    emit data (salleter.a,salleter.b,salleter.time,salleter.name); // сигнал с новыми данными
}

void corners_solar_battery::position_salleter(vector_salleter salleter) // получение данных оспутнике
{
    sputnik=salleter;
    datapotoc();
}

void corners_solar_battery::position_sun(double x, double y, double z)
{
    san.x=x;
    san.y=y;
    san.z=z;
    datapotoc();
}

void corners_solar_battery::debug(bool y_n) // получение команды о выводе данных в терменил
{
    qdebug=y_n;
}

void corners_solar_battery::datapotoc(){


    if ( san.x!=0 && sputnik.x!=0)
    {

        datacornes(cornes(san,sputnik));
        san.x=0;
        sputnik.x=0;

    }
}
