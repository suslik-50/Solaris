#include <QCoreApplication>
#include <QSql>
#include<iostream>
#include <datebaseconnect.h>
#include<functiondb.h>
#include <structur.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase Test;
    DateBaseConnect test;
    Test=test.DBConnect();
    functiondb fn(Test);
  //  fn.update_to_sputnik("sputnik1",1,44.1,4.0);
        satellite sputnik;
        orbit orbita;
    //    sputnik = fn.get_sputnuk(1);
       // sputnik=fn.get_sputnuk("sputnik1");
       // orbita = fn.get_orbit(1);
    return a.exec();
}
