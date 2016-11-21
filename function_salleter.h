#ifndef FUNCTION_SALLETER_H
#define FUNCTION_SALLETER_H
#include <structur.h>
#include <math.h>
#include <timejd.h>
const double pi=3.14159265358979324;
const double E_n =3.986005*pow(10.0,5.0);
const  double Re=6378.1;

vector_salleter position_salleter(double a,double e,double i, double dvu0,double urp0,double T0,double realtime_utc,QString name,double replay);

#endif // FUNCTION_SALLETER_H
