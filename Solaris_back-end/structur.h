#ifndef STRUCTUR_H
#define STRUCTUR_H
#include <QString>
#include<QDateTime>
#include <QMetaType>
using namespace std;


struct vec{
    double x;
    double y;
    double z;
};
struct vector_salleter
{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    QString name;
    double time;
    double V;
};
Q_DECLARE_METATYPE(vector_salleter);

struct solar_battery_salleter
{
    double a;
    double b;
    double time;
    QString name;
};
Q_DECLARE_METATYPE(solar_battery_salleter);
struct data_salleter{
   vector_salleter position;
   solar_battery_salleter battary;
};
Q_DECLARE_METATYPE(data_salleter);

struct variables{
    double Px;
    double Py;
    double Pz;
    double Qx;
    double Qy;
    double Qz;

};

struct satellite //структура для спутника
{
    int id_satellite;
    QString stl_name;
    double stl_time_uts;
    double stl_a;
    double stl_e;
    double stl_i;
    double stl_ark_per;
    double stl_dolgota;

};

struct correction_sun_panel // структура для корректировки спутника
{
    int id_correction_satellite;
    int id_satellite;
    double c_time_uts;
    double c_a;
    double c_e;
    double c_i;
    double c_ark_per;
    double c_dolgota;
    double c_m;
    QString editer;
};

static struct RegisterTypes {
    RegisterTypes()
    {
        qRegisterMetaType<vector_salleter>("vector_salleter");
        qRegisterMetaType<solar_battery_salleter>("solar_battery_salleter");
        qRegisterMetaType<data_salleter>("data_salleter");
       // qRegisterMetaType<QMap<QString,QList<data_salleter>>>("QMap<QString,QList<data_salleter>>");
    }
} RegisterTypes;


#endif // STRUCTUR_H
