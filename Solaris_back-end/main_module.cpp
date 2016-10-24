#include "main_module.h"
Q_DECLARE_METATYPE(sun)
main_module::main_module(potoc_sun &sun_p, drain_parametrs_solar_battery &drain_p)
{
    sun_potoc=&sun_p;
    drain=&drain_p;
    QObject::connect(this,SIGNAL(stop_sun_signal()),sun_potoc,SLOT(timerstop()));
    QObject::connect(this,SIGNAL(start_sun_signal()),sun_potoc,SLOT(timerstart()));
    QObject::connect(this,SIGNAL(qdebug_sun_signal(bool)),sun_potoc,SLOT(debug(bool)));
    QObject::connect(this,SIGNAL(replay_sun_signal(int)),sun_potoc,SLOT(upreplay(int)));
    qdebug=setting_f.Get_qdebug_main_modul();
}

void main_module::run()
{
    start_all_salleter();
    exec();
}

int main_module::start_all_salleter()
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
                L_potoc_sallete.insert(sputnik.stl_name, new potoc_salleter2);
                L_potoc_sallete.value(sputnik.stl_name)->load_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name);
                L_corners_solar_battery.insert(sputnik.stl_name, new corners_solar_battery);
                T_potoc.insert(sputnik.stl_name,new QThread);
                // связывающие сигналы (основные)
                QObject::connect(L_potoc_sallete.value(sputnik.stl_name),SIGNAL(data(vector_s,double,QString)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(position_salleter(vector_s,double,QString)));
                QObject::connect(sun_potoc,SIGNAL(positionsun(double,double,double,double)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(position_sun(double,double,double,double)));
                QObject::connect(L_corners_solar_battery.value(sputnik.stl_name),SIGNAL(data(double,double,double,QString)),drain,SLOT(data(double,double,double,QString)));
                //связывающие сигналы (второстепенные)
                QObject::connect(this,SIGNAL(qdebug_salleter_signal(bool)),L_potoc_sallete.value(sputnik.stl_name),SLOT(debug_t_f(bool)));
                QObject::connect(this,SIGNAL(replay_salleter_signal(double)),L_potoc_sallete.value(sputnik.stl_name),SLOT(upreplay(double)));
                QObject::connect(this,SIGNAL(qdebug_corners_solar_battery_signal(bool)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(debug(bool)));
                // сигналы на запуск
                QObject::connect(T_potoc.value(sputnik.stl_name),SIGNAL(started()),L_potoc_sallete.value(sputnik.stl_name),SLOT(run()));
                QObject::connect(T_potoc.value(sputnik.stl_name),SIGNAL(started()),L_corners_solar_battery.value(sputnik.stl_name),SLOT(run()));
                T_potoc.value(sputnik.stl_name)->start();
                return 0;
            }
        }
    }
    else{

        foreach ( potoc_salleter2* value , L_potoc_sallete.values())
        {
            QObject::connect(this,SIGNAL(start_all_salleter_signal()),value,SLOT(StartTimer()));
        }
        start_all_salleter_signal();
        return 1;
    }
    return 0;
}


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


int main_module::new_salleter(QString name, double time_uts, double a, double e, double i, double ark_per, double dolgota, double m)
{

    satellite sputnik;
    if(dbf.inset_to_satellite(name,time_uts,a,e,i,ark_per,dolgota,m))
    {
        sputnik=dbf.get_satellite(name);
        //
        L_potoc_sallete.insert(sputnik.stl_name, new potoc_salleter2);
        L_potoc_sallete.value(sputnik.stl_name)->load_data(sputnik.stl_a,sputnik.stl_e,sputnik.stl_i,sputnik.stl_dolgota,sputnik.stl_ark_per,sputnik.stl_time_uts,sputnik.stl_name);
        L_corners_solar_battery.insert(sputnik.stl_name, new corners_solar_battery);
        T_potoc.insert(sputnik.stl_name,new QThread);
        //

        // связывающие сигналы (основные)
        QObject::connect(L_potoc_sallete.value(sputnik.stl_name),SIGNAL(data(vector_s,double,QString)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(position_salleter(vector_s,double,QString)));
        QObject::connect(sun_potoc,SIGNAL(positionsun(double,double,double,double)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(position_sun(double,double,double,double)));
        QObject::connect(L_corners_solar_battery.value(sputnik.stl_name),SIGNAL(data(double,double,double,QString)),drain,SLOT(data(double,double,double,QString)));
        //связывающие сигналы (второстепенные)
        QObject::connect(this,SIGNAL(qdebug_salleter_signal(bool)),L_potoc_sallete.value(sputnik.stl_name),SLOT(debug_t_f(bool)));
        QObject::connect(this,SIGNAL(replay_salleter_signal(double)),L_potoc_sallete.value(sputnik.stl_name),SLOT(upreplay(double)));
        QObject::connect(this,SIGNAL(qdebug_corners_solar_battery_signal(bool)),L_corners_solar_battery.value(sputnik.stl_name),SLOT(debug(bool)));
        // сигналы на запуск
        QObject::connect(T_potoc.value(sputnik.stl_name),SIGNAL(started()),L_potoc_sallete.value(sputnik.stl_name),SLOT(run()));
        QObject::connect(T_potoc.value(sputnik.stl_name),SIGNAL(started()),L_corners_solar_battery.value(sputnik.stl_name),SLOT(run()));
        T_potoc.value(sputnik.stl_name)->start();
        return 0;
    }
    else {
        return 1;
    }
}

int main_module::stop_salleter(QString name)
{
    bool s_t=false;
    foreach ( potoc_salleter2* value , L_potoc_sallete.values())
    {
        if (value->Getname()==name){
            QObject::connect(this,SIGNAL(stop_salleter_signal()),value,SLOT(StopTimer()));
            emit stop_salleter_signal();
            QObject::disconnect(this,SIGNAL(stop_salleter_signal()),value,SLOT(StopTimer()));
            s_t =true;
            return 0;
            break;

        }

    }
    ///
    if ( s_t==false)
    {
        if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
        return 1;
    }
    return 0;
}


int main_module::start_salleter(QString name)
{
    bool s_t=false;

    foreach ( potoc_salleter2* value , L_potoc_sallete.values())
    {
        if (value->Getname()==name){
            QObject::connect(this,SIGNAL(start_salleter_signal()),value,SLOT(StartTimer()));
            emit start_salleter_signal();
            QObject::disconnect(this,SIGNAL(start_salleter_signal()),value,SLOT(StartTimer()));
            s_t =true;
            return 0;
            break;
        }
    }

    if ( s_t==false)
    {
        if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
        return 1;
    }
    return 1;
}

int main_module::updata_salleter(double a, double e, double i, double dvu, double urp, double t0, QString name)
{
    bool s_t=false;

    foreach ( potoc_salleter2* value , L_potoc_sallete.values())
    {
        if (value->Getname()==name){
            value->update(a,e,i,dvu,urp,t0);
            s_t=true;
            if(qdebug){
                qDebug()<<"Поток спутника-"<<name<<"данные потока обновлены";
            }
            return 0;
            break;
        }
    }
    if ( s_t==false)
    {
        if(qdebug){
            qDebug()<<"Поток спутника-"<<name<<" не найден";
        }
        return 1;
    }
    return 1;
}

void main_module::stop_sun()
{
    emit stop_sun_signal();
    if(qdebug){
        qDebug()<<"Поток вычисления местоположения солнца остановленны , данные не будут обновляться";
    }
}

void main_module::start_sun()
{
    emit start_sun_signal();
    if (qdebug){
        qDebug()<<"Поток вычисления местоположения солнца запущен";
    }
}

int main_module::stop_all_salleter()
{
    foreach ( potoc_salleter2* value , L_potoc_sallete.values())
    {
        QObject::connect(this,SIGNAL(stop_all_salleter_signal()),value,SLOT(StopTimer()));
    }

    if(qdebug){
        qDebug()<<"Все потоки вычесления спутника остановлены";
    }
    stop_all_salleter_signal();
    return 0;
}


int main_module::get_count_record_drain()
{
    return drain->count_drain();
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

        foreach (QString key,  drain->data_sbs.keys()) {
            if (key == name){
                corners.a=drain->data_sbs.value(name).a;
                corners.b=drain->data_sbs.value(name).b;
                corners.name=drain->data_sbs.value(name).name;
                corners.time=drain->data_sbs.value(name).time;
                s_t=true;
                break;
            }
        }

    }
    if ( s_t==false)
    {
        if(qdebug){
            qDebug()<<"Углы спутника "<<name<<" не найдены";
        }
    }
    return corners;
}




int main_module::set_new_salleter_to_date_base(QString name, double time_uts, double a, double e, double i, double ark_per, double dolgota, double m)
{

    if ( dbf.inset_to_satellite(name,time_uts,a,e,i,ark_per,dolgota,m)){
        if(qdebug){
            qDebug()<<"Спутник добавлен в бд";
        }
        return 0;
    }
    else
    {
        if(qdebug)
        {
            qDebug()<<"Ошибка!!!";
            qDebug()<<"Спутник не добавлен в бд";
        }
        return 1;
    }
}

int main_module::delete_potoc_salleter(QString name)
{
    bool t_f=false;
    foreach (QString key, L_potoc_sallete.keys()) {

        if (key==name){
            stop_salleter(name);
            L_potoc_sallete.value(key)->quit();
            L_potoc_sallete.value(key)->wait();
            L_potoc_sallete.value(key)->terminate();
            L_potoc_sallete.value(key)->wait();
            drain->deletedata(key);
            L_potoc_sallete.remove(key);
            t_f=true;
            return 0;
            break;
        }
    }

    if (t_f==false){
        return 1;
    }
    return 0;
}

int main_module::delete_salleter_form_dataBase(QString name)
{
    delete_potoc_salleter(name);
    if (name==dbf.get_satellite(name).stl_name){
        dbf.delete_satellite(name);
        return 0;
    }
    else{
        return 1;
    }
}


