#ifndef FUNCTION_TO_DATE_BASE_H
#define FUNCTION_TO_DATE_BASE_H
#include<QSql>
#include<QString>
#include "QSql"
#include<QString>
#include<datebaseconnect.h>

class functiondb
{
public:void insert_to_orbit(int numer,float height,float i);
public:functiondb(QSqlDatabase datebase);
public:void inset_to_sputnik(QString name,int id_orb );
public:void read_orbit();
public:void read_sputnik();
public:QString creat_db();
};

#endif // FUNCTION_TO_DATE_BASE_H
