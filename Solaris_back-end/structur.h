#ifndef STRUCTUR_H
#define STRUCTUR_H
#include <QString>
#include<QDateTime>
using namespace std;




struct sun
{
    double x;
    double y;
    double z;
};

struct sun2
{
    double x;
    double y;
    double z;
};

struct vector_s
{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

struct solar_battery_salleter
{
    double a;
    double b;
    double time;
    QString name;
};

struct satellite //структура для спутника
{
    int id_satellite;
    QString stl_name;
    double stl_x;
    double stl_y;
    double stl_z;
    double stl_vx;
    double stl_vy;
    double stl_vz;
    double stl_time_uts;
    double stl_a;
    double stl_e;
    double stl_i;
    double stl_ark_per;
    double stl_dolgota;
    double stl_m;
};

struct correction_sun_panel // структура для корректировки спутника
{
    int id_correction_satellite;
    int id_satellite;
    double c_x;
    double c_y;
    double c_z;
    double c_vx;
    double c_vy;
    double c_vz;
    double c_time_uts;
    double c_a;
    double c_e;
    double c_i;
    double c_ark_per;
    double c_dolgota;
    double c_m;
    QString editer;
};



#endif // STRUCTUR_H
