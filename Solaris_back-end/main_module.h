#ifndef MAIN_MODULE_H
#define MAIN_MODULE_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QVector>
#include <setting.h>
#include <potoc_salleter2.h>
#include <corners_solar_battery.h>
#include <potoc_sun.h>
#include <drain_parametrs_solar_battery.h>
#include <setting.h>
#include <functiondb.h>

class main_module:public QThread
{
    Q_OBJECT
private:bool qdebug;
private:QList <int> id_salleter;
private:QList<potoc_salleter2 *> L_potoc_sallete;
private:QList<corners_solar_battery *> L_corners_solar_battery;
private:QList<QThread *> T_potoc;
private:potoc_sun  *sun_potoc;
public:drain_parametrs_solar_battery  *drain;
private:setting setting_f;
private: functiondb dbf;
public:main_module(potoc_sun & sun_p,drain_parametrs_solar_battery & drain_p);
 public slots :
    void run();
    void start_all_salleter();// старт всех потоков спутника+
    void qdebug_sun(bool y_t);// устанавливает дебаг+
    void replay_sun(int replay);//устанавливает значение повторений для солнца+
    void qdebug_salleter(bool y_t);// устанавливает дебаг+
    void qdebug_corners_solar_battery(bool y_t); // устанавливает дебаг+
    void replay_salleter(double replay);// устанавливае количество секунд для повторения+
    void touch_salleter(double touch); // устанавливает значение итераций+
    void new_salleter(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);// добовление нового спутниак и его запуск после успешного дорбавления в бд
    void stop_salleter(QString name);//остановка вычесление какого-либо спутника+
    void start_salleter(QString name);//старт вычесление какого-либо спутника если он до этого был остановлен+
    void updata_salleter(double a,double e,double i,double dvu,double urp,double t0, QString name);//обнавление данных вычесление какого-либо спутника
    void stop_sun();//остановка вычеслений солнца+
    void start_sun();//запуск вычеслений солнца+
    void stop_all_salleter();//остановит все потоки вычислений спутника+
    int get_count_record_drain();// получение количество записей в пуле значений углов
    void clean_record_drain();//отчиска пула значенией углов+
    solar_battery_salleter get_value_corners_salleter(QString name);//получение значения углов спутника из пула по имени спутника+
    void value_all_potoc();// вывод данных о всех запущенных потоках
    sun get_earth_pos();//получение координат земли в гелиоцентрической системе координат +
    // получение коодинат спутника +
    void set_new_salleter_to_date_base(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);//добавить новый спутник в бд
    // пул данных с координатами спутников?




 signals:
    void qdebug_sun_signal(bool y_t); // сигнал для включения выключения дебага потока для солнца
    void replay_sun_signal(int replay); //сигнал для изменнея повторения расчетов местоположения солнца
    void qdebug_salleter_signal(bool y_t);// сигнал для включения выключения дебага потока для спутника
    void replay_salleter_signal(double replay); //сигнал для изменнея повторения расчетов местоположения спутника
    void touch_salleter_signal(double touch); // сигнал для иззменения количества итераций
    void qdebug_corners_solar_battery_signal(bool y_t); // сигнал для включения выключения дебага потока хранения углов

};

#endif // MAIN_MODULE_H
