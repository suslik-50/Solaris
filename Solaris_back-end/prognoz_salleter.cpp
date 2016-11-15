#include "prognoz_salleter.h"


prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd)
{
    timeT0=timeTT0;
    time_end=time_endd;
    type_ras=1;
}

prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd, int stepp)
{
    timeT0=timeTT0;
    time_end=time_endd;
    step=stepp;
    type_ras=2;
}

prognoz_salleter::prognoz_salleter(double timee)
{
    time=timee;
    type_ras=3;
}

prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd, QString Name)
{
    timeT0=timeTT0;
    time_end=time_endd;
    name=Name;
    type_ras=4;
}

prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd, QString Name, int stepp)
{
    timeT0=timeTT0;
    time_end=time_endd;
    step=stepp;
    name=Name;
    type_ras=5;
}

prognoz_salleter::prognoz_salleter(double timee, QString Name)
{
    time=timee;
    name=Name;
    type_ras=6;
}

prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd, QList<QString> Namesalleter)
{
    timeT0=timeTT0;
    time_end=time_endd;
    namesalleter=Namesalleter;
    type_ras=7;
}

prognoz_salleter::prognoz_salleter(double timeTT0, double time_endd, int stepp, QList<QString> Namesalleter)
{
    timeT0=timeTT0;
    time_end=time_endd;
    step=stepp;
    namesalleter=Namesalleter;
    type_ras=8;
}

prognoz_salleter::prognoz_salleter(double timee, QList<QString> Namesalleter)
{
    time=timee;
    namesalleter=Namesalleter;
    type_ras=9;
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

QMap<QString, QList<data_salleter>> prognoz_salleter::pos_salleter_all(double timeT0, double realtime)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    int step=1;
    double time0=timeT0;
    double time=realtime;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0){
        id_salleter=dbf.get_list_id_satellite();
        for (int i=0;i<koll_sputnik;i++)
        {
            sputnik=dbf.get_satellite(id_salleter[i]);
            QList<data_salleter> position;
            while(time0!=time || time0>=time){
                position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                         sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
                time0=time0+step;
            }
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

QMap<QString, QList<data_salleter>> prognoz_salleter::pos_salleter_all(double timeT0, double realtime, int step)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    double time0=timeT0;
    double time=realtime;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0){
        id_salleter=dbf.get_list_id_satellite();
        for (int i=0;i<koll_sputnik;i++)
        {
            sputnik=dbf.get_satellite(id_salleter[i]);
            QList<data_salleter> position;
            while(time0!=time || time0>=time){
                position.append(get_data(sputnik.stl_a,sputnik.stl_e,
                                         sputnik.stl_i,sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
                time0=time0+step;
            }
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::pos_salleter_all(double time_end)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0){
        id_salleter=dbf.get_list_id_satellite();
        for (int i=0;i<koll_sputnik;i++)
        {
            sputnik=dbf.get_satellite(id_salleter[i]);
            QList<data_salleter> position;
            position.append(get_data(sputnik.stl_a,sputnik.stl_e,i,
                                     sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time_end));
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::pos_salleter(double timeT0, double realtime, QString name)
{
    QMap<QString, QList<data_salleter>> salleter;
    satellite sputnik;
    int step=1;
    double time0=timeT0;
    double time=realtime;

    sputnik=dbf.get_satellite(name);
    QList<data_salleter> position;
    while(time0!=time || time0>=time){
        position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                 sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
        time0=time0+step;
    }
    salleter.insert(sputnik.stl_name,position);

    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::pos_salleter(double timeT0, double realtime, QString name, int step)
{
    QMap<QString, QList<data_salleter>> salleter;
    satellite sputnik;
    double time0=timeT0;
    double time=realtime;

    sputnik=dbf.get_satellite(name);
    QList<data_salleter> position;
    while(time0!=time || time0>=time){
        position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                 sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
        time0=time0+step;
    }
    salleter.insert(sputnik.stl_name,position);

    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::pos_salleter(double time_end, QString name)
{
    QMap<QString, QList<data_salleter>> salleter;
    satellite sputnik;
    int  koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0){
        sputnik=dbf.get_satellite(name);
        QList<data_salleter> position;
        position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,
                                 sputnik.stl_name,time_end));
        salleter.insert(sputnik.stl_name,position);
    }
    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::grup_pos_salleter(double timeT0, double time_end, QList<QString> namesalleter)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    int step=1;
    double time0=timeT0;
    double time=time_end;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0 && koll_sputnik>=namesalleter.count()){
        for (int i=0;i<namesalleter.count();i++)
        {
            sputnik=dbf.get_satellite(namesalleter[i]);
            QList<data_salleter> position;
            while(time0!=time || time0>=time){
                position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                         sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
                time0=time0+step;
            }
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::grup_pos_salleter(double timeT0, double time_end, int step, QList<QString> namesalleter)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    double time0=timeT0;
    double time=time_end;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0 && koll_sputnik>=namesalleter.count()){
        for (int i=0;i<namesalleter.count();i++)
        {
            sputnik=dbf.get_satellite(namesalleter[i]);
            QList<data_salleter> position;
            while(time0!=time || time0>=time){
                position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                         sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time0));
                time0=time0+step;
            }
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

QMap<QString, QList<data_salleter> > prognoz_salleter::grup_pos_salleter(double time, QList<QString> namesalleter)
{
    QMap<QString, QList<data_salleter>> salleter;
    int koll_sputnik;
    satellite sputnik;
    koll_sputnik=dbf.count_record_satellite();
    if (koll_sputnik!=0 && koll_sputnik>=namesalleter.count()){
        for (int i=0;i<namesalleter.count();i++)
        {
            sputnik=dbf.get_satellite(namesalleter[i]);
            QList<data_salleter> position;
            position.append(get_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,
                                     sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name,time));
            salleter.insert(sputnik.stl_name,position);
        }
    }
    return salleter;
}

void prognoz_salleter::run()
{
    QMap<QString,QList<data_salleter>> salleter;
    if (type_ras==1) salleter=pos_salleter_all(timeT0, time_end);
    if (type_ras==2) salleter=pos_salleter_all(timeT0,time_end,step);
    if (type_ras==3) salleter=pos_salleter_all(time);
    if (type_ras==4) salleter=pos_salleter(timeT0,time_end,name);
    if (type_ras==5) salleter=pos_salleter(timeT0,time_end,name,step);
    if (type_ras==6) salleter=pos_salleter(time,name);
    if (type_ras==7) salleter=grup_pos_salleter(timeT0,time_end,namesalleter);
    if (type_ras==8) salleter=grup_pos_salleter(timeT0,time_end,step,namesalleter);
    if (type_ras==9) salleter=grup_pos_salleter(time,namesalleter);
    emit data(salleter);
}


