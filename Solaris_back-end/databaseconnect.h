#ifndef DATEBASECONNECT_H
#define DATEBASECONNECT_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <functiondb.h>
#include <iostream>
#include <qfile.h>
#include <setting.h>

class DateBaseConnect
{
public:
    QSqlDatabase DBConnect();
};

#endif // DATEBASECONNECT_H
