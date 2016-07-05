#include "datebaseconnect.h"
#include "QSql"
#include <iostream>
using namespace std ;

QSqlDatabase DateBaseConnect::DBConnect()
{
    string puthdb;
    QSqlDatabase Datebase=QSqlDatabase::addDatabase("QSQLITE");
    Datebase.setDatabaseName("");
    if (Datebase.open())
    {
        return Datebase;
    }
    else {
        cout<<"Нет соединения с базой данных";

    }

}
