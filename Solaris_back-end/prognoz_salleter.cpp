#include "prognoz_salleter.h"

prognoz_salleter::prognoz_salleter()
{

}

data_salleter prognoz_salleter::get_data(double a, double e, double i, double dvu, double urp, double T0, QString name, double timer_utc_ras)
{
 vector_salleter salleter=position_salleter(a,e,i,dvu,urp,T0,timer_utc_ras,name,1);
 vec san=position_sun(timer_utc_ras);
 solar_battery_salleter panel=fun_cornes(san, salleter);
 data_salleter data;
 data.battary=panel;
 data.position=salleter;
 return data;
}

void prognoz_salleter::run()
{
      exec();
}


