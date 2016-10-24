#ifndef FUNCTION_TO_DATE_BASE_H
#define FUNCTION_TO_DATE_BASE_H

#include <QSql>
#include <QDateTime>
#include <iostream>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <functiondb.h>
#include <databaseconnect.h>
#include <structur.h>
#include <QDebug>
#include <QList>


class functiondb
{

public:
    functiondb();
    void creat_db();
    bool insert_to_sun(double x, double y, double z, double time_uts);
    void update_to_sun(double x, double y, double z, double time_uts);
    bool inset_to_satellite(QString name, double time_uts, double a,
                            double e, double i, double ark_per,
                            double dolgota, double m);
    void update_to_satellite(QString name, double time_uts, double a,
                             double e, double i, double ark_per,
                             double dolgota, double m, QString editor);
    void delete_satellite(QString name);
    bool insert_to_correct_satellite(int satellite_id, double time_uts, double a,
                                     double e, double i, double ark_per,
                                     double dolgota, double m, QString editor);
    void read_satellite();
    satellite get_satellite(int id);
    satellite get_satellite(QString name );

    int count_record_satellite(); // Количесство спутников
    QList<int> get_list_id_satellite();
};

#endif // FUNCTION_TO_DATE_BASE_H
