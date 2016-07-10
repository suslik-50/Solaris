#ifndef FUNCTION_TO_DATE_BASE_H
#define FUNCTION_TO_DATE_BASE_H
#include<QSql>
#include<QString>
#include "QSql"
#include<QString>
#include<datebaseconnect.h>
#include <structur.h>

class functiondb
{

public:functiondb(QSqlDatabase datebase);
public:QString creat_db();
public:void insert_to_orbit(int numer,double height,double i);
public:void inset_to_sputnik(QString name,int id_orb,double x,double y);
public:void read_orbit();
public:void read_sputnik();
public:satellite get_sputnuk(int id);
public:satellite get_sputnuk(QString name );
public:orbit get_orbit(int id);
public:orbit get_orbit(char num,int number);
public:void update_to_sputnik(QString name,int id_orb,double new_x,double new_y);
public:void update_to_orbit(int orbit_num,double height_orbit_posle_correction,double angle_i_posle_correction);
private:bool insert_to_correct_orbit(int orbit_num,double new_height,double new_angle_i,double old_heigt,double old_angle_i);
private:bool insert_to_correct_sputnik(int sputnik_id,double x_do,double y_do, double x_po, double y_po);
};

#endif // FUNCTION_TO_DATE_BASE_H
