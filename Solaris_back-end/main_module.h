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
#include <structur.h>
#include <QMap>
#include <corners_solar_battery.h>
#include <potoc_sun.h>
#include <drain_parametrs_solar_battery.h>
#include <databaseconnect.h>
#include <functiondb.h>
#include <structur.h>

class main_module: public QThread
{
    Q_OBJECT
public:main_module(potoc_sun & sun_p,drain_parametrs_solar_battery & drain_p);
    ///
private:bool qdebug;
private:QList <int> id_salleter;
private:QMap<QString,potoc_salleter2 *> L_potoc_sallete;
private:QMap<QString,corners_solar_battery *> L_corners_solar_battery;
private:QMap<QString,QThread *> T_potoc;
private:potoc_sun  *sun_potoc;
private:drain_parametrs_solar_battery  *drain;
private:setting setting_f;
private: functiondb dbf;
    ///
public slots :
    void run();
<<<<<<< HEAD
    void start_all_salleter();// старт всех  спктников
=======
    int start_all_salleter();// старт всех  спктников
>>>>>>> origin/master
    void qdebug_sun(bool y_t);
    void replay_sun(int replay);
    void qdebug_salleter(bool y_t);// устанавливает дебаг+
    void qdebug_corners_solar_battery(bool y_t); // устанавливает дебаг+
    void replay_salleter(double replay);// устанавливае количество секунд для повторения+
<<<<<<< HEAD
    void new_salleter(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);// добовление нового спутниак и его запуск после успешного дорбавления в бд
    void stop_salleter(QString name);//остановка вычесление какого-либо спутника+
    void start_salleter(QString name);//старт вычесление какого-либо спутника если он до этого был остановлен+
    void updata_salleter(double a,double e,double i,double dvu,double urp,double t0, QString name);//обнавление данных вычесление какого-либо спутника
=======
    int new_salleter(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);// добовление нового спутниак и его запуск после успешного дорбавления в бд
    int stop_salleter(QString name);//остановка вычесление какого-либо спутника+
    int start_salleter(QString name);//старт вычесление какого-либо спутника если он до этого был остановлен+
    int updata_salleter(double a,double e,double i,double dvu,double urp,double t0, QString name);//обнавление данных вычесление какого-либо спутника
>>>>>>> origin/master
    void stop_sun();//остановка вычеслений солнца+
    void start_sun();//запуск вычеслений солнца+
    int stop_all_salleter();//остановит все потоки вычислений спутника+
    int get_count_record_drain();// получение количество записей в пуле значений углов
    void clean_record_drain();//отчиска пула значенией углов+
    solar_battery_salleter get_value_corners_salleter(QString name);//получение значения углов спутника из пула по имени спутника
<<<<<<< HEAD
    void value_all_potoc();// вывод данных о всех запущенных потоках
    void set_new_salleter_to_date_base(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);//добавить новый спутник в бд
    void delete_potoc_salleter(QString name );
    void delete_salleter_form_dataBase(QString name);
=======
    int set_new_salleter_to_date_base(QString name, double time_uts, double a,double e, double i, double ark_per,double dolgota, double m);//добавить новый спутник в бд
    int delete_potoc_salleter(QString name );
    int delete_salleter_form_dataBase(QString name);
>>>>>>> origin/master

signals:
    void qdebug_sun_signal(bool y_t); // сигнал для включения выключения дебага потока для солнца
    void replay_sun_signal(int replay); //сигнал для изменнея повторения расчетов местоположения солнца
    void qdebug_salleter_signal(bool y_t);// сигнал для включения выключения дебага потока для спутника
    void replay_salleter_signal(double replay); //сигнал для изменнея повторения расчетов местоположения спутника
    void touch_salleter_signal(double touch); // сигнал для иззменения количества итераций
    void qdebug_corners_solar_battery_signal(bool y_t); // сигнал для включения выключения дебага потока хранения углов
<<<<<<< HEAD
    void messageslots(QString mess); // передает сообщение в слот
=======
>>>>>>> origin/master
    void stop_sun_signal();
    void start_sun_signal();
    void stop_all_salleter_signal();
    void stop_salleter_signal();
    void start_all_salleter_signal();
    void start_salleter_signal();
};
#endif // MAIN_MODULE_H
