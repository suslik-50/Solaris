#ifndef POTOC_SALLETER_H
#define POTOC_SALLETER_H

#include <QObject>
#include <QThread>
#include <structur.h>
#include <ed_vector_salleter.h>
#include <QString>
#include <QTimer>
#include <setting.h>
class potoc_salleter:public QThread
{
    Q_OBJECT
//переменные
private:setting seting;
private:double replay=3;
private:double touch=10;
private:double  oe,on,r,a,E,M,t,t0,n,e; //ξ -oe ,η-on  (орбитальные кординаты необхходимые для упращения вычеслений)
private:double Px,Py,Pz,Qx,Qy,Qz,i,dvu,urp;   //Ω - dvu(долгота восходящего узла) ω-urp(угловое расстояние перицента от узла)
private:double  kontrolsum, kontrolsum2, kontrolsum3;
private:double x,y,z;
private:ed_vector_salleter vector;
private:double V,v,p,vr,vn,vx,vy,vz;
private:vector_s  salleter;
public:QString name;
public:bool qdebag=true;

//процедуры
public: potoc_salleter();
public:void load_data(QString name,double aa,double ee,double ii,double dvudvu,double urpurp,double t0);
private:double Ek(double M);
private:void dopperemen();
public:QTimer timer;
public slots:
    void update (double aa,double ee,double ii, double dvudvu,double urpurp,double t0,QString Name);
    void upreplay (double t);
    void uptoch(double uptouch);
    void run();
    void positionsputnik();
    void debug(bool y_n);
    void position();
    void startsal();
    void stop();
signals:
    void  data(vector_s,double,QString);
    void  speed_error();
    void  kontrol_sum(int);
};

#endif // POTOC_SALLETER_H
