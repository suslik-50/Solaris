#include "main_module.h"
#include <potoc_salleter.h>
#include <corners_solar_battery.h>
#include <potoc_sun.h>
#include <drain_parametrs_solar_battery.h>
#include <databaseconnect.h>
#include <functiondb.h>

main_module::main_module(potoc_sun &sun_p, drain_parametrs_solar_battery & drain_p)
{
    sun_potoc=&sun_p;
    drain=&drain_p;
    QObject::connect(this,SIGNAL(qdebug_sun_signal(bool)),sun_potoc,SLOT(debug(bool)));
    QObject::connect(this,SIGNAL(replay_sun_signal(int)),sun_potoc,SLOT(upreplay(int)));
    qdebug=setting_f.Get_qdebug_main_modul();
}

void main_module::run()
{
    start_all_salleter();
    exec();
}

void main_module::start_all_salleter()
{

 int koll_sputnik;
 koll_sputnik=dbf.count_record_satellite();
 satellite sputnik;
 qDebug()<<koll_sputnik<<"колличество спутников";
if (L_potoc_sallete.empty()){
 if (koll_sputnik!=0){
    id_salleter=dbf.get_list_id_satellite();
 for (int i=0;i<koll_sputnik;i++)
 {
     sputnik=dbf.get_satellite(id_salleter[i]);
     L_potoc_sallete.append(new potoc_salleter2);
     L_potoc_sallete[i]->load_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name);
     L_corners_solar_battery.append(new corners_solar_battery);
     T_potoc.append(new QThread);

// связывающие сигналы (основные)
     QObject::connect(L_potoc_sallete[i],SIGNAL(data(vector_s,double,QString)),L_corners_solar_battery[i],SLOT(position_salleter(vector_s,double,QString)));
     QObject::connect(sun_potoc,SIGNAL(positionsun(sun,double)),L_corners_solar_battery[i],SLOT(position_sun(sun)));
     QObject::connect(L_corners_solar_battery[i],SIGNAL(data(solar_battery_salleter)),drain,SLOT(data(solar_battery_salleter)));

//связывающие сигналы (второстепенные)
     QObject::connect(this,SIGNAL(qdebug_salleter_signal(bool)),L_potoc_sallete[i],SLOT(debug_t_f(bool)));
     QObject::connect(this,SIGNAL(replay_salleter_signal(double)),L_potoc_sallete[i],SLOT(upreplay(double)));
    // QObject::connect(this,SIGNAL(touch_salleter_signal(double)),L_potoc_sallete[i],SLOT(uptoch(double)));
     QObject::connect(this,SIGNAL(qdebug_corners_solar_battery_signal(bool)),L_corners_solar_battery[i],SLOT(debug(bool)));

// сигналы на запуск
     QObject::connect(T_potoc[i],SIGNAL(started()),L_potoc_sallete[i],SLOT(run()));
     QObject::connect(T_potoc[i],SIGNAL(started()),L_corners_solar_battery[i],SLOT(run()));
     T_potoc[i]->start();
    }
 }
}
else{
    for(int i=0 ; i<L_potoc_sallete.size();i++)
    {
            L_potoc_sallete[i]->StartTimer();
    }
}
}
 // управление переменными в потоках
void main_module::qdebug_sun(bool y_t)
{
    emit qdebug_sun_signal(y_t);
    setting_f.Set_qdebug_sun(y_t);

}

void main_module::replay_sun(int replay)
{

  emit replay_sun_signal(replay);
  setting_f.Set_replay_sun(replay);

}

void main_module::qdebug_salleter(bool y_t)
{

    emit qdebug_salleter_signal(y_t);
    setting_f.Set_qdebug_salleter(y_t);

}

void main_module::qdebug_corners_solar_battery(bool y_t)
{

    emit qdebug_corners_solar_battery_signal(y_t);
    setting_f.Set_corners_solar_battery_qdebug(y_t);
}

void main_module::replay_salleter(double replay)
{
    emit replay_salleter_signal(replay);
    setting_f.Set_replay_salleter(replay);
}

void main_module::touch_salleter(double touch)
{
    emit touch_salleter_signal(touch);
    setting_f.Set_touch_salleter(touch);
}

//не работает
void main_module::new_salleter(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m)
{
    double x=0;
    double y=0;
    double z=0;
    double vx=0;
    double vz=0;
    double vy=0;
    QString s_name;
    double aa;
    double ee;
    double ii;
    double dvudvu;
    double urpurp;
    double t;
    if(dbf.inset_to_satellite(name,time_uts,a,e,i,ark_per,dolgota,m))
    {
       // satellite  sputnik =dbf.get_satellite(name);
        double kolzapis;
        double kolpotoc;
        double kolsolar;
        //sputnik=dbf.get_satellite(id);
        s_name=name;
        qDebug()<<s_name;
        aa=a;
        ee=e;
        ii=i;
        dvudvu=dolgota;
        urpurp=ark_per;
        t=time_uts;
        kolzapis=L_potoc_sallete.count();
        L_potoc_sallete.append(new potoc_salleter2);
      //  L_potoc_sallete[kolzapis+1]->load_data(s_name,aa,ee,ii,dvudvu,urpurp,t);
        kolsolar= L_corners_solar_battery.count();
        L_corners_solar_battery.append(new corners_solar_battery);
        kolpotoc= T_potoc.count();
        T_potoc.append(new QThread);
   // связывающие сигналы (основные)
        QObject::connect(L_potoc_sallete[kolzapis+1],SIGNAL(data(vector_s,double,QString)),L_corners_solar_battery[kolsolar+1],SLOT(position_salleter(vector_s,double,QString)));
        QObject::connect(sun_potoc,SIGNAL(positionsun(sun,double)),L_corners_solar_battery[kolsolar+1],SLOT(position_sun(sun)));
        QObject::connect(L_corners_solar_battery[kolsolar+1],SIGNAL(data(solar_battery_salleter)),drain,SLOT(data(solar_battery_salleter)));
   //связывающие сигналы (второстепенные)
        QObject::connect(this,SIGNAL(qdebug_salleter_signal(bool)),L_potoc_sallete[kolzapis+1],SLOT(debug(bool)));
        QObject::connect(this,SIGNAL(replay_salleter_signal(double)),L_potoc_sallete[kolzapis+1],SLOT(upreplay(double)));
        QObject::connect(this,SIGNAL(touch_salleter_signal(int)),L_potoc_sallete[kolzapis+1],SLOT(uptoch(double)));
        QObject::connect(this,SIGNAL(qdebug_corners_solar_battery_signal(bool)),L_corners_solar_battery[kolsolar+1],SLOT(debug(bool)));
   // сигналы на запуск
        QObject::connect(T_potoc[kolpotoc+1],SIGNAL(started()),L_potoc_sallete[kolzapis+1],SLOT(run()));
        QObject::connect(T_potoc[kolpotoc+1],SIGNAL(started()),L_corners_solar_battery[kolsolar+1],SLOT(run()));
        T_potoc[kolpotoc+1]->start();
    }
}


void main_module::stop_salleter(QString name)
{
    bool s_t=false;
    for(int i=0 ; i<L_potoc_sallete.size();i++)
    {

        if (L_potoc_sallete[i]->Getname()==name  )
        {
            L_potoc_sallete[i]->StopTimer();
            s_t=true;
            if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<" остановлен";
            }
            break;
        }
    }
    if ( s_t==false)
    {
        if(qdebug){
        qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
    }

}

void main_module::start_salleter(QString name)
{
    bool s_t=false;
    for(int i=0 ; i<L_potoc_sallete.size();i++)
    {

        if (L_potoc_sallete[i]->Getname()==name  )
        {
            L_potoc_sallete[i]->StartTimer();
            s_t=true;
            if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<" запущен";
            }
            break;
        }
    }
    if ( s_t==false)
    {
        if(qdebug){
        qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
    }
}

void main_module::updata_salleter(double a,double e,double i,double dvu,double urp,double t0, QString name)
{
    bool s_t=false;
    for(int ii=0 ; ii<L_potoc_sallete.size();i++)
    {

        if (L_potoc_sallete[ii]->Getname()==name)
        {
            L_potoc_sallete[ii]->update(a,e,i,dvu,urp,t0);
            s_t=true;
            if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<"данные потока обновлены";
            }
            break;
        }
    }
    if ( s_t==false)
    {
        if(qdebug){
        qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
    }
}

void main_module::stop_sun()
{
        sun_potoc->stop();
        if(qdebug){
        qDebug()<<"Поток вычисления местоположения солнца остановленны , данные не будут обновляться";
        }
}

void main_module::start_sun()
{
    sun_potoc->start();
    if (qdebug){
    qDebug()<<"Поток вычисления местоположения солнца запущен";
    }
}

void main_module::stop_all_salleter()
{
    for(int i=0 ; i<L_potoc_sallete.size();i++)
    {
            L_potoc_sallete[i]->StopTimer();
    }
    if(qdebug){
    qDebug()<<"Все потоки вычесления спутника остановлены";
    }
}

int main_module::get_count_record_drain()
{
    int kol;
    kol=drain->count_drain();
    return kol;
}

void main_module::clean_record_drain()
{
    drain->clear();
}

solar_battery_salleter main_module::get_value_corners_salleter(QString name)
{
    bool s_t=false;
    solar_battery_salleter corners;
    for(int i=0 ; i< drain->data_sbs.size();i++)
    {

        if ( drain->data_sbs[i].name==name)
        {
            corners=drain->data_sbs[i];
            s_t=true;
            return corners;
        }
    }
    if ( s_t==false)
    {
        if(qdebug){
        qDebug()<<"Углы спутника "<<name<<" не найдены";
        }
        corners.a=0;
        corners.b=0;
    }
    return corners;
}

void main_module::value_all_potoc()
{
    if (sun_potoc->wait()!=true)
    {
        if(qdebug){
        qDebug()<<"Поток вычесления солнца запущен";
        }
    }
    else
    {
        if(qdebug){
        qDebug()<<"Поток вычесления солнца остановлен";
        }
    }
    if (drain->wait()!=true)
    {
        if(qdebug){
        qDebug()<<"Поток пула данных запущен";
        }
    }
    else
    {
        if(qdebug){
        qDebug()<<"Поток пула данных остановлен";
        }
    }
    if(qdebug){
    qDebug()<<"Колиичество потоков спутников-"<<L_potoc_sallete.size()+1;
    }

    for(int i=0 ; i<L_potoc_sallete.size();i++)
    {

        if (L_potoc_sallete[i]->wait()!=true )
        {
            if(qdebug){
            qDebug()<<"Поток спутника-"<<L_potoc_sallete[i]->Getname()<<" запущен";
            }
        }
        else
        {
            if(qdebug){
            qDebug()<<"Поток спутника-"<<L_potoc_sallete[i]->Getname()<<" остановлен";
            }
        }

        if (L_corners_solar_battery[i]->wait()!=true )
        {
            if(qdebug){
            qDebug()<<"Дополнительный поток спутника-"<<L_potoc_sallete[i]->Getname()<<" запущен";
            }
        }
        else
        {
            if(qdebug){
            qDebug()<<"Дополнительный поток спутника-"<<L_potoc_sallete[i]->Getname() <<" остановлен";
            }
        }
    }
}

sun main_module::get_earth_pos()
{
    sun earth;
   // earth=sun_potoc->get_earth_gel();
    return earth;
}

void main_module::set_new_salleter_to_date_base(QString name, double time_uts, double a, double e, double i, double ark_per, double dolgota, double m)
{
    double x=0;
    double y=0;
    double z=0;
    double vx=0;
    double vz=0;
    double vy=0;
   if ( dbf.inset_to_satellite(name,time_uts,a,e,i,ark_per,dolgota,m)){
       if(qdebug){
       qDebug()<<"Спутник добавлен в бд";
       }
   }
   else
   {
       if(qdebug)
       {
       qDebug()<<"Ошибка!!!";
       qDebug()<<"Спутник не добавлен в бд";
       }
   }
}





