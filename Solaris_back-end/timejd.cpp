#include "timejd.h"
#include <QDateTime>
#include <math.h>
timejd::timejd()
{

}

double timejd::get_convert_date(double t)
{
    convert_date(t);
}

double timejd::get_convert_date(double t, int toch)
{
    convert_date(t,toch);
}
// Перевод из даты и времени в юлианскую дату
double timejd::DateToJD(int year,int month, int day,int hour, int min,int sec) // перевод в юлианскую дату
{
    double jd;
    double hour_jd = (double)hour;
    hour_jd += ((double)min/60);
    hour_jd +=  ((double)sec/3600);

    double ggg = 1;
    if( year < 1582 )
    {
        ggg = 0;
    }
    if( year <= 1582 && month < 10 )
    {
        ggg = 0;
    }
    if( year <= 1582 && month == 10 && day < 5 )
    {
        ggg = 0;
    }
    jd = -1 * (int)(7 * ((int)((month + 9) / 12) + year) / 4);
    int s = 1;
    if ((month - 9) < 0) { s = -1; }
    int a = month - 9;
    if ( a < 0 ) { a *= -1; }
    double j1 = (int)(year + s * (int)(a / 7));
    j1 = -1 * (int)((floor(j1 / 100) + 1) * 3 / 4);
    jd = jd + (int)(275 * month / 9) + day + (ggg * j1);
    jd = jd + 1721027 + 2 * ggg + 367 * year - 0.5;
    jd = jd + (hour_jd / 24);
    jd=roundTo(jd,3);
    return jd;
}
// Перевод из даты и времени в юлианскую дату , с заданной точность
double timejd::DateToJD(int year, int month, int day, int hour, int min, int sec, double toch)
{
    double jd;
    double hour_jd = (double)hour;
    hour_jd += ((double)min/60);
    hour_jd +=  ((double)sec/3600);

    double ggg = 1;
    if( year < 1582 )
    {
        ggg = 0;
    }
    if( year <= 1582 && month < 10 )
    {
        ggg = 0;
    }
    if( year <= 1582 && month == 10 && day < 5 )
    {
        ggg = 0;
    }
    jd = -1 * (int)(7 * ((int)((month + 9) / 12) + year) / 4);
    int s = 1;
    if ((month - 9) < 0) { s = -1; }
    int a = month - 9;
    if ( a < 0 ) { a *= -1; }
    double j1 = (int)(year + s * (int)(a / 7));
    j1 = -1 * (int)((floor(j1 / 100) + 1) * 3 / 4);
    jd = jd + (int)(275 * month / 9) + day + (ggg * j1);
    jd = jd + 1721027 + 2 * ggg + 367 * year - 0.5;
    jd = jd + (hour_jd / 24);
    jd=roundTo(jd,toch);
    return jd;
}

// Функция для перевода даты , для потока солнца с тремя знаками после запятой
//
double timejd::convert_date(double t) // получение переменных из UTC
{
    int Y,M,D,H,Min,S;
    QDateTime date ;
    date.setTime_t(t);
    QDate day=date.date();
    Y=day.year();
    M=day.month();
    D=day.day();
    QTime time = date.time();
    H=time.hour();
    Min=time.minute();
    S=time.second();
    t=DateToJD(Y,M,D,H,Min,S);
    return t;
}
// Функция для перевода даты , для потоков спутника с задаваемым количеством знака после запятой
//
double timejd::convert_date(double t, int toch)
{
    int Y,M,D,H,Min,S;
    QDateTime date ;
    date.setTime_t(t);
    QDate day=date.date();
    Y=day.year();
    M=day.month();
    D=day.day();
    QTime time = date.time();
    H=time.hour();
    Min=time.minute();
    S=time.second();
    if (toch>7){
        toch=7;
    }
    if (toch<=2){
        toch=3;
    }
    t=DateToJD(Y,M,D,H,Min,S,toch);
    return t;
}
//Oкругление числа до нужных знаков после запятой
double timejd::roundTo(double inpValue, int inpCount)
{
    double outpValue;
    double tempVal;
    tempVal=inpValue*pow(10,inpCount);
    if (double(int(tempVal))+0.5==tempVal)
    {
        if (int(tempVal)%2==0)
        {
            outpValue=double(floor(tempVal))/pow(10,inpCount);
        }
        else
        {
            outpValue=double(ceil(tempVal))/pow(10,inpCount);
        }
    }
    else
    {
        if (double(int(tempVal))+0.5>tempVal)
        {
            outpValue=double(ceil(tempVal))/pow(10,inpCount);
        }
        else
        {
            outpValue=double(floor(tempVal))/pow(10,inpCount);
        }
    }
    return(outpValue);
}
