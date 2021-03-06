#ifndef PROGNOZ_SALLETER_H
#define PROGNOZ_SALLETER_H

#include <math.h>
#include <QString>
#include <QObject>
#include <QThread>
#include <function_salleter.h>
#include <function_sun.h>
#include <function_cornes.h>
#include <QMap>
#include <functiondb.h>
class prognoz_salleter
{

private: functiondb dbf;
private: QList<int>id_salleter;
private:QList<QString> namesalleter;
private:int step;
private:QString name;
private:int type_ras=0;
private:
    int  timeT0;
    int  time_end;
    int  time;

//расчет для всех спутников
public:prognoz_salleter(int  timeT0,int  time_end);//расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
public:prognoz_salleter(int  timeT0,int  time_end,int step );    //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг задается step
public:prognoz_salleter(int  time);   //расчет всех местоположения спутников на время time
//расчет для одного спутника
public:prognoz_salleter(int  timeT0,int  time_end,QString name); //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
public:prognoz_salleter(int  timeT0,int  time_end,QString name,int step);//расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг задается step
public:prognoz_salleter(int  time,QString name); //расчет всех местоположения спутника на время time
//расчет для нескольких спутнкиков имена спутников задаются в QList<QString>
public:prognoz_salleter(int  timeT0,int  time_end,QList<QString> namesalleter);//расчет местоположения группы спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
public:prognoz_salleter(int  timeT0,int  time_end,int step,QList<QString> namesalleter);//расчет местоположения группы спутников от начального времни timeT0 , до конечного time_end шаг задается step
public:prognoz_salleter(int  time,QList<QString> namesalleter);//расчет местоположения группы спутников на время time

private:data_salleter get_data(double  a,double e,double i, double dvu,double urp,double t0,QString name,double timer_ras);

//расчет для всех спутников
    //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
private: QMap<QString,QList<data_salleter>> pos_salleter_all( int timeT0, int time_end);
    //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг задается step
private: QMap<QString,QList<data_salleter>> pos_salleter_all( int timeT0, int time_end,int step );
    //расчет всех местоположения спутников на время time
private: QMap<QString,QList<data_salleter>> pos_salleter_all( int time);
//расчет для одного спутника
    //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
private: QMap<QString,QList<data_salleter>> pos_salleter( int timeT0, int time_end,QString name);
    //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг задается step
private: QMap<QString,QList<data_salleter>> pos_salleter( int timeT0, int time_end,QString name,int step);
    //расчет местоположения спутника на время time
private: QMap<QString,QList<data_salleter>> pos_salleter( int time,QString name);
//расчет для нескольких спутнкиков имена спутников задаются в QList<QString>
    //расчет местоположения группы спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
private: QMap<QString,QList<data_salleter>> grup_pos_salleter( int timeT0, int time_end,QList<QString> namesalleter);
     //расчет местоположения группы спутников от начального времни timeT0 , до конечного time_end шаг задается step
private: QMap<QString,QList<data_salleter>> grup_pos_salleter( int timeT0, int time_end,int step,QList<QString> namesalleter);
    //расчет местоположения группы спутников на время time
private: QMap<QString,QList<data_salleter>> grup_pos_salleter( int time,QList<QString> namesalleter);

public:
    QMap<QString,QList<data_salleter>>  process();
/*
// возращение данных
signals:
    void data(QMap<QString,QList<data_salleter>>);
    void finishd();
    */

public:
    QMap<QString,QList<data_salleter>> DATA;

};

#endif // PROGNOZ_SALLETER_H
