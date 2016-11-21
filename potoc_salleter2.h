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
    double i,urp0,dvu0,a,E,M,t,t0,e,m;
    QString name;
private:vector_salleter salleter;
private:setting seting;
public:potoc_salleter2();
public:QString Getname();
public:void load_data(double aa,double ee,double ii, double dvudvu,double urpurp,double TT0,QString name);
public slots:
    void update (double aa,double ee,double ii, double dvudvu,double urpurp,double TT0);
    void upreplay (double Upreplay);
    void run();
    void StopTimer();
    void StartTimer();
    void slotNextValue();
    void debug_t_f(bool y_n);
signals:
    void  data(vector_salleter);
    void  speed_error();
    void data_(double x,double y,double z,double vx, double vy,double vz,QString name,double time);
    void  kontrol_sum(int);
};

#endif // POTOC_SALLETER2_H
