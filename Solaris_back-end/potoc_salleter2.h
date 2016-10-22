#ifndef POTOC_SALLETER2_H
#define POTOC_SALLETER2_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QTimer>
#include <setting.h>
#include <structur.h>
#include <math.h>
#include <timejd.h>
#include <QDateTime>
#include <QDebug>
class potoc_salleter2:public QThread
{

    Q_OBJECT
    const double pi=3.14159265358979324;
    const double E_n =3.986005*pow(10.0,5.0);
    const  double Re=6378.1; // радиус земли
    QTimer timer;
    bool qdebag=true;

    /* oe-ξ,on-η,Px,Py,Pz,Qx,Qy,Qz(орбитальные кординаты необхходимые для упращения вычеслений)
 * r - радиус
 * a - большая полуась орбиты
 * E - эксцентрическая аномалия
 * M - средняя аномалия
 * n - средние движение
 * e - эксцентриситет
 * i - угол наклон орбиты
 * t - эпоха на которую производиться
 * t0 - начальная эпоха, на которую производятся вычисления
 * dvu0 - Ω (долгота восходящ'его узла),начальное
 * urp0 - ω (угловое расстояние перицента),начальное
 */
    double replay;
    double oe,on,r,a,E,M,t,t0,n,e,tjd;
    double Px,Py,Pz,Qx,Qy,Qz,i,dvu0,urp0,dvu,urp;
    double x,y,z,V,v,p,vr,vn,vx,vy,vz;
    QString name;
private:vector_s salleter;
private:setting seting;

public:potoc_salleter2();
private:double EccAnom(double M,double e);
private:double Getdvu(double t);
private:double Geturp(double t);
private:void OrbitalCoordinat();
public:QString Getname();
public:void load_data(double aa,double ee,double ii, double dvudvu,double urpurp,double TT0,QString name);
private:void Additional_variables();
private:double Frac (double x)
    {
        return x-floor(x);
    }
private:double Modulo (double x, double y)
    {
        return y*Frac(x/y);
    }
public slots:
    void update (double aa,double ee,double ii, double dvudvu,double urpurp,double TT0);
    void upreplay (double Upreplay);
    void run();
    void StopTimer();
    void StartTimer();
    void slotNextValue();
    void debug_t_f(bool y_n);
signals:
    void  data(vector_s,double,QString);
    void  speed_error();
    void  kontrol_sum(int);
};

#endif // POTOC_SALLETER2_H
