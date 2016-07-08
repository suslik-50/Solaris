#include "functiondb.h"
#include <iostream>
#include<QSql>
#include "QSql"
#include<QString>
#include<datebaseconnect.h>
#include <QSqlQuery>
#include<QSqlRecord>
#include <QVariant>
using namespace std ;

QSqlDatabase Datebase;

functiondb::functiondb(QSqlDatabase datebase)
{
Datebase=datebase;
}

QString functiondb::creat_db(){
    QSqlQuery query;

    //Создание таблицы орбит
   QString sco=" CREATE TABLE ORBIT ("" ID_ORBIT INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "NUMBER_ORBIT INTEGER,"
        "HEIGHT_ORBIT REAL,"
        "ANGLE_I      REAL"" );";

   // Создание таблицы корректировка орбиты
  QString sct="   CREATE TABLE DATA_CORRECTION_ORBIT (""ID_DATA_CORRECTION_ORBIT INTEGER  PRIMARY KEY NOT NULL,"
       "ORBIT_ID  INTEGER  REFERENCES ORBIT (ID_ORBIT),"
       "HEIGHT_ORBIT_DO_CORRECTION    REAL,"
      " ANGLE_I_DO_CORRECTION         REAL,"
      " HEIGHT_ORBIT_POSLE_CORRECTION REAL,"
      "ANGLE_I_POSLE_CORRECTION      REAL,"
     "  DATE_TIME_DT                DATETIME"" );";

  //Создание таблицы спутника
 QString sss=" CREATE TABLE SATELLITE (""ID_SATELLITE   INTEGER      PRIMARY KEY NOT NULL,"
      "NAME_SATELLITE VARCHAR (45) ,"
      "ORBIT_ID       INTEGER REFERENCES ORBIT (ID_ORBIT),"
     " ALIGLE_I_X     REAL,"
      "ALIGLE_I_Y     REAL"");";

   //Создание таблицы коректировки олнечных панелей
 QString scsp="CREATE TABLE DATE_CORRECTION_SUN_PANEL (""ID_DATE_CORRECTION_SUN_PANEL INTEGER  PRIMARY KEY NOT NULL,"
            "SATELLITE_ID                 INTEGER  REFERENCES SATELLITE (ID_SATELLITE),"
             "ANGLE_I_X_DO_CORRECTION      REAL,"
             "ANGLE_I_Y_DO_CORRECTION      REAL,"
             "ANGLE_I_X_POSLE_CORRECTION   REAL,"
             "ANGLE_I_Y_POSLE_CORRECTION   REAL,"
             "DATE_TIME_DT                 DATETIME"");";

   if (query.exec(sco))
   {
       cout<<"[+] Cозданна таблица 'ORBIT'"<<endl;
       if (query.exec(sct))
       {
           cout<<"[+] Cозданна таблица 'DATA_CORRECTION_ORBIT'"<<endl;
           if (query.exec(sss))
           {
              cout<<"[+] Cозданна таблица 'SATELLITE'"<<endl;
              if(query.exec(scsp))
              {
                  cout<<"[+] Cозданна таблица 'DATE_CORRECTION_SUN_PANEL'"<<endl;
              }
              else {
                  cout<<"[-] Не cозданна таблица 'DATE_CORRECTION_SUN_PANEL'"<<endl;
              }
           }
           else{
               cout<<"[-] Не cозданна таблица 'SATELLITE'"<<endl;
           }
       }
       else {
           cout<<"[-] Не созданна таблица 'DATA_CORRECTION_ORBIT'"<<endl;
       }
   }
   else{
        cout<<"[-] Не созданна таблица 'ORBIT'"<<endl;
   }
}

void functiondb::insert_to_orbit(int numer,float height,float i)
{
    QSqlQuery query;

    QString str="INSERT INTO ORBIT (NUMBER_ORBIT, HEIGHT_ORBIT, ANGLE_I) VALUES('%1', '%2', '%3');";

    str.arg(numer)
           .arg(height)
            .arg(i);
    if (query.exec(str))
    {
        cout<<"[+]Данные добавлены в таблицу'ORBIT'"<<endl;

  }
    else {
             cout<<"[-]Данные не добавлены в таблицу'ORBIT'"<<endl;
    }

}

void functiondb::inset_to_sputnik(QString name,int id_orb )
{
    QSqlQuery query;
    query.prepare("INSERT INTO SATELLITE (NAME_SATELLITE,ORBIT_ID) VALUES (:name,:id)");
    query.bindValue(":name",name);
    query.bindValue(":id",id_orb);

    if (query.exec())
    {
        cout<<"[+]Данные добавлены в таблицу 'SATELLITE'"<<endl;
  }
    else {
             cout<<"[-]Данные не добавлены в таблицу'SATELLITE'"<<endl;
    }
}

void functiondb::read_sputnik()
{
    QSqlQuery query;
    if (query.exec("SELECT *FROM SATELLITE;"))
    {
        QSqlRecord rec = query.record();
        QString Name;

        int id = 0;
          while(query.next())
          {
              id = query.value(rec.indexOf("ORBIT_ID")).toInt();
              QString r;
              Name = query.value(rec.indexOf("NAME_SATELLITE")).toString();
              cout<<Name.toStdString()<<"-"<<(r.setNum(id)).toStdString()<<endl;

          }
    }

}

void functiondb::read_orbit()
{
    QSqlQuery query;
    if (query.exec("SELECT *FROM ORBIT;"))
    {
        cout<<"[+]'ORBIT'"<<endl;
       QSqlRecord rec = query.record();
        int nNumber = 0;
        while(query.next()){
         nNumber = query.value(rec.indexOf("NUMBER_ORBIT")).toInt();
         QString r;
         cout<<(r.setNum(nNumber)).toStdString()<<endl;
        }

    }
}
