#include <QCoreApplication>
#include <QSql>
#include<iostream>
#include <datebaseconnect.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase Test;
    DateBaseConnect test;
    Test=test.DBConnect();
    return a.exec();
}
