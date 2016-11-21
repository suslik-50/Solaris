#include "potoc_salleter2.h"
#include <QDateTime>
#include <function_salleter.h>

potoc_salleter2::potoc_salleter2()
{
    qdebag = seting.Get_qdebug_salleter();
    replay = seting.Get_replay_salleter();
}

QString potoc_salleter2::Getname()
{
    return name;
}


void potoc_salleter2::update(double aa, double ee, double ii, double dvudvu, double urpurp, double TT0)
{
    a=aa;
    e=ee;
    i=ii;
    dvu0=dvudvu;
    urp0=urpurp;
    t0=TT0;

}

void potoc_salleter2::upreplay(double Upreplay)
{
    replay=Upreplay;
}

void potoc_salleter2::debug_t_f(bool y_n)
{
    qdebag=y_n;
}

void potoc_salleter2::run()
{
    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(slotNextValue()));
    timer.start(1000*replay);
    exec();
}

void potoc_salleter2::StopTimer()
{
    timer.stop();
}

void potoc_salleter2::StartTimer()
{
    timer.start();
}

void potoc_salleter2::load_data( double aa,double ee,double ii, double dvudvu,double urpurp,double TT0,QString Name)
{
    a=aa;
    e=ee;
    i=ii;
    dvu0=dvudvu;
    urp0=urpurp;
    t0=TT0;
    name=Name;
}

void potoc_salleter2::slotNextValue()
{
    t = QDateTime::currentDateTime().toTime_t(); // время в UTC
    salleter=position_salleter(a,e,i,dvu0,urp0,t0,t,name,replay);
    if (qdebag)
    {
        qDebug()<<salleter.name;
        qDebug()<<salleter.x<<"-x";
        qDebug()<<salleter.y<<"-y";
        qDebug()<<salleter.z<<"-z";
        qDebug()<<salleter.V<<"-V";
        qDebug()<<salleter.vx<<"vx-скорость по x";
        qDebug()<<salleter.vy<<"vy-скорость по y";
        qDebug()<<salleter.vz<<"vz-скорость по z";


    }

    emit  data_(salleter.x,salleter.y,salleter.z,salleter.vx,salleter.vy,salleter.vz,salleter.name,salleter.time);
    emit  data(salleter); // отправляет сигнал что данные обновились
}




