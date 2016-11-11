#include "drain_position_salleter.h"

drain_position_salleter::drain_position_salleter()
{

}

int drain_position_salleter::count_drain()
{
     return data_salleter.count();
}
void drain_position_salleter::clear()
{
    data_salleter.clear();
}

void drain_position_salleter::run()
{
    exec();
}

void drain_position_salleter::deletedata(QString name)
{
    foreach (QString key, data_salleter.keys()) {
        if (key == name){
            data_salleter.remove(key);
        }
    }
}

void drain_position_salleter::data(vector_salleter salleter_data)
{
    bool t_f=false;
    if (data_salleter.empty()){
        data_salleter.insert(salleter_data.name,salleter_data);
    }
    else{

        foreach (QString key, data_salleter.keys()) {
            if (key == salleter_data.name){
                data_salleter.remove(key);
                data_salleter.insert(salleter_data.name,salleter_data);
                t_f=true;
                emit new_data();
            }
        }

        if (t_f==false)
        {
            data_salleter.insert(salleter_data.name,salleter_data);
            emit new_data();
        }
    }
}

void drain_position_salleter::data(double x, double y, double z, double vx, double vy, double vz, QString name, double time)
{
    vector_salleter salleter_data ;
    salleter_data.x=x;
    salleter_data.y=y;
    salleter_data.z=z;
    salleter_data.vx=vx;
    salleter_data.vy=vy;
    salleter_data.vz=vz;
    salleter_data.time=time;
    salleter_data.name=name;
    bool t_f=false;
    if (data_salleter.empty()){
        data_salleter.insert(name,salleter_data);
    }
    else{

        foreach (QString key, data_salleter.keys()) {
            if (key == name){
                data_salleter.remove(key);
                data_salleter.insert(name,salleter_data);
                t_f=true;
                emit new_data();
            }
        }

        if (t_f==false)
        {
            data_salleter.insert(name,salleter_data);
            emit new_data();
        }
    }
}

void drain_position_salleter::get_data()
{
     emit data_salleter_signal(data_salleter);
}

