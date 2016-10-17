#include "drain_parametrs_solar_battery.h"

#include <QDebug>

drain_parametrs_solar_battery::drain_parametrs_solar_battery()
{

}

int drain_parametrs_solar_battery::count_drain()
{
    return data_sbs.count();
}

void drain_parametrs_solar_battery::clear()
{
    data_sbs.clear();
}

void drain_parametrs_solar_battery::run()
{
    exec();
}

void drain_parametrs_solar_battery::data(solar_battery_salleter salleter_data)
{
    bool t_f=false;
    if (data_sbs.empty())
    {
        data_sbs<<salleter_data;
    }
    else
    {
        for(int i=0;i<data_sbs.size();i++)
        {
          if (data_sbs[i].name==salleter_data.name)
            {
                data_sbs[i]=salleter_data;
                t_f=true;
            }
        }
        if (t_f==false)
        {
            data_sbs<<salleter_data;
        }
    }
}

void drain_parametrs_solar_battery::get_data()
{

    solar_battery_salleter slr;
    slr.a = 0.100000001;
    slr.b = 0.100000011;
    slr.name = "satel-1";
    slr.time = 111111111;
    data_sbs.append(slr);
    slr.a = 0.200000002;
    slr.b = 0.200000022;
    slr.name = "Satel-2";
    slr.time = 222222222;
    data_sbs.append(slr);

    emit data_solar_battery(data_sbs);
    data_sbs.clear();
}

