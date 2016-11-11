#ifndef PROGNOZ_SALLETER_H
#define PROGNOZ_SALLETER_H

#include <math.h>
#include <QString>
#include <QObject>
#include <QThread>
#include <function_salleter.h>
#include <function_sun.h>
#include <function_cornes.h>
class prognoz_salleter:public QThread
{
    Q_OBJECT
public:prognoz_salleter();
private:data_salleter get_data(double a,double e,double i, double dvu,double urp,double t0,QString name,double timer_ras);
public:data_salleter calculate_position(double a,double e,double i, double dvu,double urp,double t0,QString name,double timer_ras){
       return get_data(a,e,i,dvu,urp,t0,name,timer_ras);
 }

public:void run();
};

#endif // PROGNOZ_SALLETER_H
