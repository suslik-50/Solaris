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

void drain_parametrs_solar_battery::deletedata(QString name)
{

    foreach (QString key, data_sbs.keys()) {
        if (key == name){
            data_sbs.remove(key);
        }
    }
}

void drain_parametrs_solar_battery::data(double a,double b,double time,QString name)
{
    solar_battery_salleter salleter_data ;
    salleter_data.a=a;
    salleter_data.b=b;
    salleter_data.time=time;
    salleter_data.name=name;
    bool t_f=false;
    if (data_sbs.empty()){
        data_sbs.insert(name,salleter_data);
    }
    else{

        foreach (QString key, data_sbs.keys()) {
            if (key == name){
                data_sbs.remove(key);
                data_sbs.insert(name,salleter_data);
                t_f=true;
                emit new_data();
            }
        }

        if (t_f==false)
        {
            data_sbs.insert(name,salleter_data);
            emit new_data();
        }
    }
}

void drain_parametrs_solar_battery::get_data()
{


    emit data_solar_battery(data_sbs);
    data_sbs.clear();
}

