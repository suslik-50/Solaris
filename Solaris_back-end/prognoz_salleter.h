#ifndef PROGNOZ_SALLETER_H
#define PROGNOZ_SALLETER_H
#include <math.h>
#include <QString>
#include <function_salleter.h>
#include <function_sun.h>
#include <function_cornes.h>
class prognoz_salleter
{
public:prognoz_salleter();
private:data_salleter get_data(double aa,double ee,double ii, double dvudvu,double urpurp,
                  double TT0,QString name,double timer_ras);
};

#endif // PROGNOZ_SALLETER_H
