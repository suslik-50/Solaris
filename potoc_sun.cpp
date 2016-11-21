#include "potoc_sun.h"


potoc_sun::potoc_sun()
{
    qdebug=seting.Get_qdebug_sun();
    replay=seting.Get_replay_sun();
}

void potoc_sun::timerstart()
{
    timer.start(1000*replay);
}

void potoc_sun::timerstop()

{
    timer.stop();
}

void potoc_sun::run()
{
    QObject::connect(&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    timerstart();
    exec();
}

void potoc_sun::debug(bool y_n)
{
    qdebug=y_n;
}

void potoc_sun::upreplay(int i)
{
    replay=i;
}

void potoc_sun::slotNextValue()
{
    vec di=position_sun(QDateTime::currentDateTime().toTime_t());
    if (qdebug)              //для отладки
    {
        qDebug()<<di.x<<"x-экваториальная солнца"<<"2";
        qDebug()<<di.y<<"y-экваториальная солнца";
        qDebug()<<di.z<<"z-экваториальная солнца";
    }

    sunposition(di.x,di.y,di.z);
}

void potoc_sun::sunposition(double x, double y, double z)
{
     emit positionsun(x,y,z);
}





