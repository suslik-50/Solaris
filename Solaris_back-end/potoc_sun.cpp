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
    time=QDateTime::currentDateTime().toTime_t();
    sun_dan=sun_pull(time);
    if (false)              //для отладки
    {
        qDebug()<<sun_dan.x<<"x-экваториальная солнца";
        qDebug()<<sun_dan.y<<"y-экваториальная солнца";
        qDebug()<<sun_dan.z<<"z-экваториальная солнца";
    }

    sunposition();
}

void potoc_sun::sunposition()
{
    emit positionsun(sun_dan.x,sun_dan.y,sun_dan.z);
}
double potoc_sun::MeanObliquity (double TT) // угол наклона между экватором и эквелептикой
{
    double T;
    T=((((TT/60)/60)/24)-10957)/365525;
    return ( 23.43929111-(46.8150+(0.00059-0.001813*T)*T)*T/3600.0 );
}
vec potoc_sun::sun_pull(double newtime )
{
    double t_earth;
    timejd retime;
    time=retime.get_convert_date(newtime); // преобразование из UTC в юлианскую дату
    t_earth = (time - 2451545) / 365250;
    double Xs,Ys,Zs;
    Xs=pos.getEarth_X(t_earth);  // получение координат земли
    Ys=pos.getEarth_Y(t_earth);  //
    Zs=pos.getEarth_Z(t_earth);  //

/*
    Xs=-1*Xs; // получение экваториальных координат солнца
    Ys=-1*Ys; //
    Zs=-1*Zs; //
*/
    Xs*=-1; // получение экваториальных координат солнца
    Ys*=-1; //
    Zs*=-1; //

    double XSik,YSik,ZSik; // экваториальные координаты солнца
    double EE;//угол наклона между экватором и эквелептикой

    EE=MeanObliquity(time);

    //получение  координат солнца
    XSik=Xs;
    YSik=Ys*cos(EE)+Zs*sin(EE);
    ZSik=Ys*sin(EE)+Zs*cos(EE);

    //нормирование
    double normirovanie= sqrt((XSik*XSik)+(YSik*YSik)+(ZSik*ZSik));

    vec sonche;
    sonche.x=XSik/normirovanie;
    sonche.y=YSik/normirovanie;
    sonche.z=ZSik/normirovanie;

    return sonche;
}


