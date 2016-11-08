#include <corners_solar_battery.h>
#include <QDebug>
#include<QDateTime>
#include <QDebug>
#include <math.h>
#define PI 3.14159265

corners_solar_battery::corners_solar_battery()
{
    qdebug=seting.Get_corners_solar_batter_qdebug();
}

void corners_solar_battery::run()
{
    exec();
}
// перевод в орбитальные координаты


solar_battery_salleter corners_solar_battery::cornes(vec san,vector_salleter salleter)
{

    vec er,en,et,zv,s;
    double zvm;
    //er
    double r=sqrt((salleter.x*salleter.x)+(salleter.y*salleter.y)+(salleter.z*salleter.z));

    er.x=salleter.x/r;
    er.y=salleter.y/r;
    er.z=salleter.z/r;
    //en
    zv.x=salleter.y*salleter.vz- salleter.z*salleter.vy;
    zv.y=salleter.z*salleter.vx- salleter.x*salleter.vz;
    zv.z=salleter.x*salleter.vy- salleter.y*salleter.vx;

    zvm=sqrt((zv.x*zv.x)+(zv.y*zv.y)+(zv.z*zv.z));

    en.x=zv.x/zvm;
    en.y=zv.y/zvm;
    en.z=zv.z/zvm;
    //eтау
    et.x=en.y*er.z-en.z*er.y;
    et.y=en.z*er.x-en.x*er.z;
    et.z=en.x*er.y-en.y*er.z;
    //  S ocк
    s.x=san.x*er.x+san.y*er.y+san.z*er.z;
    s.y=san.x*et.x+san.y*et.y+san.z*et.z;
    s.z=san.x*en.x+san.y*en.y+san.z*en.z;

    //a,b
    double sinA=s.x;
    double cosA=sqrt(1-(s.x*s.x));

    double sinB;
    double cosB;
    //
    sinB=-(s.y/cosA);
    cosB=s.z/cosA;
    /*
    // возможно деление на ноль
    if (cosA!=0){
        sinB=-(s.y/cosA);
        cosB=s.z/cosA;
        buffer= cosA;
    }
    else
    {
        sinB=-(s.y/buffer);
        cosB=s.z/buffer;
    }
    */
    //
    // радианы
    a=atan2(sinA,cosA);
    b=atan2(sinB,cosB);
    // градусы
    /*
    a=a*(45.0/atan(1));
    b=b*(45.0/atan(1));
    */
    solar_battery_salleter corne;
    corne.a=a*(45.0/atan(1));
    corne.b=b*(45.0/atan(1));
    corne.name=salleter.name;
    corne.time=salleter.time;
    if (qdebug)
    {
//        qDebug()<<salleter.name<<"-имя спутника";
//        qDebug()<<a<<"-угол а(альфа)";
//        qDebug()<<b<<"-угол б(бетта)";
//        qDebug()<<QDateTime::fromTime_t(salleter.time).time();
//        qDebug()<<QDateTime::fromTime_t(salleter.time).date();
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
