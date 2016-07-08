#include <QCoreApplication>
#include <QSql>
#include<iostream>
#include <datebaseconnect.h>
#include<functiondb.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase Test;
    DateBaseConnect test;
    Test=test.DBConnect();
   // functiondb fn(Test);
    //fn.insert_to_orbit(35,6.0,1.0);
    //fn.read_orbit();

    //fn.read_sputnik();
    return a.exec();
}
