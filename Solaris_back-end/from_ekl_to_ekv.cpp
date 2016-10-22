#include "from_ekl_to_ekv.h"
#include <math.h>
#include <QDateTime>
#include <QDebug>
#include <iostream>
using namespace std ;
From_ekl_to_ekv::From_ekl_to_ekv()
{

}


double From_ekl_to_ekv::e(double t)
{
    double e,de;//e - угол наклона между экватором и эквелептикой
    t=((((t/60)/60)/24)-10957)/365525; // коичество элианских веков прошедших с 2000 г
   // de=(46.363*t)-(0.00059*(t*t))+(0.001813*(t*t*t));
   // e=23.43916-de;
    e= 23.439291;
    return e;
}

double From_ekl_to_ekv::x_ekl_to_ekv(double x_ekv)
{
    double x_ekl;
    x_ekl=x_ekv;
    return x_ekl;
}

double From_ekl_to_ekv::y_ekl_to_ekv(double y_ekv, double z_ekv,double t)
{
    double y_ekl,ek;
    ek=e(t);
    y_ekl=y_ekv*cos(ek)-z_ekv*sin(ek);
    return y_ekl;
}

double From_ekl_to_ekv::z_ekl_to_ekv(double z_ekv,double y_ekv,double t)
{
    double z_ekl,ek;
    ek=e(t);
    z_ekl=y_ekv*sin(ek)+z_ekv*cos(ek);
    return z_ekl;
}
