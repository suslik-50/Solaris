#include <corners_solar_battery.h>
#include <QDebug>
#include<QDateTime>
#include <QDebug>
#include <math.h>
#define PI 3.14159265

corners_solar_battery::corners_solar_battery()
{
    San.x=0;
    sputnik.x=0;
    qdebug=seting.Get_corners_solar_batter_qdebug();
}

void corners_solar_battery::run()
{
    qDebug()<<"sd";
   exec();
}
void corners_solar_battery::cornes()
{
    //конечные рассчеты ;
    if (San.x!=0 && sputnik.x!=0 )
    {
/*
        Координаты и компоненты скорости применяются при вычислении ортов орбитальной системы координат
        (ОСК) er, etau, en, которые потом используются при вычислении единичного вектора направления на
        Солнце в ОСК S. Если в геоцентрической инерциальной экваториальной системе координат единичный
        вектор направления на Солнце равен s,
        то

        Sx = erx*sx+ery*sy+erz*sz,
        Sy = etaux*sx+etauy*sy+etauz*sz,
        Sz = enx*sx+eny*sy+enz*sz.

*/
        double Sx,Sy,Sz;

        Sx=sputnik.x*sputnik.vx*San.x+sputnik.x*sputnik.vy*San.y+sputnik.x*sputnik.vz*San.z;
        Sy=sputnik.y*sputnik.vx*San.x+sputnik.y*sputnik.vy*San.y+sputnik.y*sputnik.vz*San.z;
        Sz=sputnik.z*sputnik.vx+San.x+sputnik.z*sputnik.vy*San.y+sputnik.z*sputnik.vz*San.z;

        //
        double sinA,cosA,sinB,cosB;

        sinA=Sx;
        cosA=-sqrt(1-(Sx*Sx));
        sinB=-Sy/cosA;
        cosB=Sz/cosA;
        a=atan(sinA/cosA);
        b=atan2(sinB,cosB)*180*PI;



    if (qdebug)
    {
        qDebug()<<name<<"-имя спутника";
        qDebug()<<a<<"-угол а(альфа)";
        qDebug()<<b<<"-угол б(бетта)";
        qDebug()<<QDateTime::fromTime_t(time).time();
        qDebug()<<QDateTime::fromTime_t(time).date();
    }

     solar_battery_salleter salleter_data;
     salleter_data.a=a;
     salleter_data.b=b;
     salleter_data.name=name;
     salleter_data.time=time;
     emit data (salleter_data); // сигнал с новыми данными
    }
}
void corners_solar_battery::position_salleter(vector_s salleter,double time_s,QString name_s) // получение данных оспутнике
{
    name=name_s;
    sputnik=salleter;
    time=time_s;
    cornes();
}

void corners_solar_battery::position_sun(sun s) // получение данных о солнце
{
    San=s;
    qDebug()<<San.x;
    cornes();
}

void corners_solar_battery::debug(bool y_n) // получение команды о выводе данных в терменил
{
    qdebug=y_n;
}
