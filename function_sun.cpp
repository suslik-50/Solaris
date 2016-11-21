#include "function_sun.h"
#include <QDebug>
double MeanObliquity (double timejd) // угол наклона между экватором и эквелептикой
{
    double jdpoch;
    jdpoch=((((timejd/60)/60)/24)-10957)/365525;
    return ( 23.43929111-(46.8150+(0.00059-0.001813*jdpoch)*jdpoch)*jdpoch/3600.0 );
}

vec position_sun(double time_utc)
{
    timejd retime;
    double time=retime.get_convert_date(time_utc); // преобразование из UTC в юлианскую дату
    double t_earth = (time - 2451545) / 365250;
    Earth_pos pos;
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

    double XSik,YSik,ZSik; // экваториальные координаты солнцаb
    double EE=MeanObliquity(time);//угол наклона между экватором и эквелептикой

    //получение  координат солнца
    XSik=Xs;
    YSik=Ys*cos(EE)+Zs*sin(EE);
    ZSik=Ys*sin(EE)+Zs*cos(EE);

    //нормирование
    double normirovanie= sqrt((XSik*XSik)+(YSik*YSik)+(ZSik*ZSik));

    vec san;
    san.x=XSik/normirovanie;
    san.y=YSik/normirovanie;
    san.z=ZSik/normirovanie;

    return san;
}
