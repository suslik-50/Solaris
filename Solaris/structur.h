#ifndef STRUCTUR_H
#define STRUCTUR_H
#include <QString>
#include<QDateTime>
using namespace std;

struct satellite
{
    int id_satellite;
    QString name_satellite;
    int id_orbit;
    double x;
    double y;
};

struct correction_sun_panel
{
    int id_correction_sun_panel;
    int id_satellite;
    double angle_i_x_do_correction;
    double angle_i_y_do_correction;
    double angle_i_x_posle_correction;
    double angle_i_y_posle_correction;
    QDateTime dt;
};

struct orbit
{
    int id_orbit;
    int number_orbit;
    double height_orbit;
    double angel_i;
};

struct correction_orbit
{
    int id_correction_orbit;
    int id_orbit;
    double heiht_orbit_do_correction;
    double angel_i_do_correction;
    double heiht_orbit_posle_correction;
    double angel_i_posle_correction;
    QDateTime dt;
};

#endif // STRUCTUR_H
