/*Версия 0.0.2 от 10-07-2016
 *  Фунции для работы с базой данных
 *  Нуриев Руслан Равилевич
 *  Email-suslik-50@yandex.ru
 */
#include "functiondb.h"
#include <iostream>
#include<QSql>
#include "QSql"
#include<QString>
#include<datebaseconnect.h>
#include <QSqlQuery>
#include<QSqlRecord>
#include <QVariant>
#include<QDateTime>
#include <structur.h>
using namespace std ;

QSqlDatabase Datebase;

functiondb::functiondb(QSqlDatabase datebase)
{
Datebase=datebase;
}
///
/// \brief functiondb::creat_db
/// \return
///
QString functiondb::creat_db(){ // функция создания базы данных
    QSqlQuery query;

    //Создание таблицы орбит
   QString sco=" CREATE TABLE ORBIT ("" ID_ORBIT INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "NUMBER_ORBIT INTEGER,"
        "HEIGHT_ORBIT DOUBLE,"
        "ANGLE_I      DOUBLE"" );";

   // Создание таблицы корректировка орбиты
  QString sct="   CREATE TABLE DATA_CORRECTION_ORBIT (""ID_DATA_CORRECTION_ORBIT INTEGER  PRIMARY KEY NOT NULL,"
       "ORBIT_ID  INTEGER  REFERENCES ORBIT (ID_ORBIT),"
       "HEIGHT_ORBIT_DO_CORRECTION    DOUBLE,"
      " ANGLE_I_DO_CORRECTION         DOUBLE,"
      " HEIGHT_ORBIT_POSLE_CORRECTION DOUBLE,"
      "ANGLE_I_POSLE_CORRECTION      DOUBLE,"
     "  DATE_TIME_DT                DATETIME"" );";

  //Создание таблицы спутника
 QString sss=" CREATE TABLE SATELLITE (""ID_SATELLITE   INTEGER      PRIMARY KEY NOT NULL,"
      "NAME_SATELLITE VARCHAR (45) ,"
      "ORBIT_ID       INTEGER REFERENCES ORBIT (ID_ORBIT),"
     " ALIGLE_I_X     DOUBLE,"
      "ALIGLE_I_Y     DOUBLE"");";

   //Создание таблицы коректировки олнечных панелей
 QString scsp="CREATE TABLE DATE_CORRECTION_SUN_PANEL (""ID_DATE_CORRECTION_SUN_PANEL INTEGER  PRIMARY KEY NOT NULL,"
            "SATELLITE_ID                 INTEGER  REFERENCES SATELLITE (ID_SATELLITE),"
             "ANGLE_I_X_DO_CORRECTION      DOUBLE,"
             "ANGLE_I_Y_DO_CORRECTION      DOUBLE,"
             "ANGLE_I_X_POSLE_CORRECTION   DOUBLE,"
             "ANGLE_I_Y_POSLE_CORRECTION   DOUBLE,"
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
///
/// \brief functiondb::insert_to_orbit
/// \param numer
/// \param height
/// \param i
///
void functiondb::insert_to_orbit(int numer,double height,double i) // функция добавления данных в таблицу 'ORBIT'
{
    QSqlQuery query;
    if (query.exec("SELECT NUMBER_ORBIT FROM ORBIT;"))
    {
       QSqlRecord rec = query.record();
       int nNumber ;
       int n=0;
       QString r;
       while(query.next())
       {
         nNumber = query.value(rec.indexOf("NUMBER_ORBIT")).toInt();
         if (nNumber==numer){
            n++;
            }
        }

       if (n==0){
           QSqlQuery query2;
           query2.prepare("INSERT INTO ORBIT (NUMBER_ORBIT, HEIGHT_ORBIT, ANGLE_I) VALUES(:num,:heig,:angel)");
           query2.bindValue(":num",numer);
           query2.bindValue(":heig",height);
           query2.bindValue(":angel",i);

           if (query2.exec())
           {
               cout<<"[+]Данные добавлены в таблицу'ORBIT'"<<endl;
           }
           else {
                    cout<<"[-]Данные не добавлены в таблицу'ORBIT'"<<endl;
           }
       }
       else{
           cout<<"[!]занито"<<endl;
       }

    }
}
///
/// \brief functiondb::inset_to_sputnik
/// \param name
/// \param id_orb
/// \param x
/// \param y
///
void functiondb::inset_to_sputnik(QString name,int id_orb,double x,double y) // функция добавления данных в таблицу 'SATELLITE'
{
    QSqlQuery query2;
    if (query2.exec("SELECT NAME_SATELLITE FROM SATELLITE;"))
    {
       QSqlRecord rec = query2.record();
       QString NAME ;
       int n=0;
       while(query2.next())
       {
         NAME = query2.value(rec.indexOf("NAME_SATELLITE")).toString();
         if (NAME==name){
            n++;
            }
        }

       if (n==0){
           QSqlQuery query;
           query.prepare("INSERT INTO SATELLITE (NAME_SATELLITE,ORBIT_ID,ALIGLE_I_X,ALIGLE_I_Y) VALUES (:name,:id,:x,:y)");
           query.bindValue(":name",name);
           query.bindValue(":id",id_orb);
           query.bindValue(":x",x);
           query.bindValue(":y",y);

           if (query.exec())
           {
               cout<<"[+]Данные добавлены в таблицу 'SATELLITE'"<<endl;
         }
           else {
                    cout<<"[-]Данные не добавлены в таблицу'SATELLITE'"<<endl;
           }
       }
       else{
           cout<<"[!]занито"<<endl;
       }

    }
}
///
/// \brief functiondb::update_to_sputnik
/// \param name
/// \param id_orb
/// \param new_x
/// \param new_y
///
void functiondb::update_to_sputnik(QString name,int id_orb,double new_x,double new_y)// функция обновления данных в таблице 'SATELLITE'
{
    QSqlQuery query;
    query.prepare("SELECT ID_SATELLITE ,ALIGLE_I_X ,ALIGLE_I_Y FROM SATELLITE WHERE NAME_SATELLITE =:name_s;");
    query.bindValue(":name_s",name);
     double x=0;
     double y=0;
     int id;
     if(query.exec())
     {
      QSqlRecord rec = query.record();
        while(query.next())
        {
         id=query.value(rec.indexOf("ID_SATELLITE")).toInt();
         x=query.value(rec.indexOf("ALIGLE_I_X")).toDouble();
         y=query.value(rec.indexOf("ALIGLE_I_Y")).toDouble();
        }
        if (insert_to_correct_sputnik(id,x,y,new_x,new_y)){
         QSqlQuery query2;
         query2.prepare("UPDATE SATELLITE SET ALIGLE_I_X=:a_i_x,ALIGLE_I_Y=:a_i_y WHERE NAME_SATELLITE =:name_s;");
         query2.bindValue(":a_i_x",new_x);
         query2.bindValue(":a_i_y",new_y);
         query2.bindValue(":name_s",name);
         if(query2.exec())
         {
             cout<<"[+] Данные в таблице  'SATELLITE' обновлены"<<endl;
         }
         else
         {
             cout<<"[-] Данные в таблице  'SATELLITE' не обновлены"<<endl;
         }
        }
     }
     else
     {
         cout<<"[-]"<<endl;
     }

}

///
/// \brief functiondb::insert_to_corectorbit
/// \param orbit_id
/// \param HEIGHT_ORBIT_POSLE_CORRECTION
/// \param ANGLE_I_POSLE_CORRECTION
///
void functiondb::update_to_orbit(int orbit_num,double new_height,double new_angle_i)//функция обновления данных в таблице 'SATELLITE'
{
    QSqlQuery query;
    query.prepare("SELECT HEIGHT_ORBIT,ANGLE_I FROM ORBIT WHERE NUMBER_ORBIT=:or_num;");
    query.bindValue(":or_num",orbit_num);
     double ai=0;
     double ho=0;
     if(query.exec())
     {
      QSqlRecord rec = query.record();
        while(query.next())
        {
         ho=query.value(rec.indexOf("HEIGHT_ORBIT")).toDouble();
         ai=query.value(rec.indexOf("ANGLE_I")).toDouble();
        }
       if (insert_to_correct_orbit(orbit_num,new_height,new_angle_i,ho,ai))
       {
           QSqlQuery query2;
           query2.prepare("UPDATE ORBIT SET HEIGHT_ORBIT=:h_o,ANGLE_I=:a_i WHERE NUMBER_ORBIT=:or_num;");
           query2.bindValue(":h_o", new_height);
           query2.bindValue(":a_i",new_angle_i);
           query2.bindValue(":or_num",orbit_num);
           if (query2.exec())
           {
                cout<<"[+] Обновление данных Орбиты прошло успешно"<<endl;
           }
           else
           {
                 cout<<"[-] Обновление данных Орбиты не удалость"<<endl;
           }
       }
     }
     else{
         cout<<"[-] запрос не прошел"<<endl;
     }
}
///
/// \brief functiondb::insert_to_correct_sputnik
/// \param sputnik_id
/// \param x_do
/// \param y_do
/// \param x_po
/// \param y_po
/// \return
///
bool functiondb::insert_to_correct_sputnik(int sputnik_id,double x_do,double y_do, double x_po, double y_po)//функция добавления данных в таблицу 'DATE_CORRECTION_SUN_PANEL'
{
    QDateTime DateTime;
    DateTime=QDateTime::currentDateTime();
    QSqlQuery query;
    query.prepare("INSERT INTO DATE_CORRECTION_SUN_PANEL (SATELLITE_ID, ANGLE_I_X_DO_CORRECTION , ANGLE_I_Y_DO_CORRECTION ,ANGLE_I_X_POSLE_CORRECTION,ANGLE_I_Y_POSLE_CORRECTION,DATE_TIME_DT) VALUES (:sal_id,:a_i_x_d,:a_i_y_d,:a_i_x_p,:a_i_y_p,:d_t_dt)");
    query.bindValue("sal_id",sputnik_id);
    query.bindValue(":a_i_x_d",x_do);
    query.bindValue(":a_i_y_d,",y_do);
    query.bindValue(":a_i_x_p",x_po);
    query.bindValue(":a_i_y_p",y_po);
    query.bindValue(":d_t_dt",DateTime.toString("dd.MM.yyyy hh:mm:ss"));
    if (query.exec())
    {
    cout<<"[+] Данные добавлены в таблицу 'DATE_CORRECTION_SUN_PANEL'"<<endl;
    return true;
    }
    else {
       cout<<"[-] Данные не добавлены в таблицу 'DATE_CORRECTION_SUN_PANEL'"<<endl;
       return false;
    }
}

///
/// \brief functiondb::insert_to_correct_orbit
/// \param orbit_num
/// \param new_height
/// \param new_angle_i
/// \param old_heigt
/// \param old_angle_i
/// \return
///
bool functiondb::insert_to_correct_orbit(int orbit_num,double new_height,double new_angle_i,double old_heigt,double old_angle_i)//функция добавления данных  таблицу ' CREATE TABLE SATELLITE'
{
    QDateTime DateTime;
    DateTime=QDateTime::currentDateTime();
    QSqlQuery query;
    query.prepare("INSERT INTO DATA_CORRECTION_ORBIT (ORBIT_ID, HEIGHT_ORBIT_DO_CORRECTION, ANGLE_I_DO_CORRECTION ,HEIGHT_ORBIT_POSLE_CORRECTION,ANGLE_I_POSLE_CORRECTION,DATE_TIME_DT) VALUES (:or_num,:h_o_d_c,:a_i_d_c,:h_o_p_c,:a_i_p_c,:d_t_dt)");
    query.bindValue(":or_num",orbit_num);
    query.bindValue(":h_o_d_c",old_heigt);
    query.bindValue(":a_i_d_c",old_angle_i);
    query.bindValue(":h_o_p_c",new_height);
    query.bindValue(":a_i_p_c",new_angle_i);
    query.bindValue(":d_t_dt",DateTime.toString("dd.MM.yyyy hh:mm:ss"));
    if (query.exec())
    {
          cout<<"[+] Данные добавлены в табцу 'DATA_CORRECTION_ORBIT'"<<endl;
          return true;
    }
    else {
         cout<<"[-] Данные не добавлены в табцу 'DATA_CORRECTION_ORBIT'"<<endl;
         return false;
    }
}
///
/// \brief functiondb::get_sputnuk
/// \param id
/// \return
///
satellite functiondb:: get_sputnuk(int id)//возращает данные о спутнике 1
{
    satellite sputnik;
    QSqlQuery query;
    query.prepare("SELECT NAME_SATELLITE,ALIGLE_I_X ,ALIGLE_I_Y,ORBIT_ID FROM SATELLITE WHERE ID_SATELLITE=:id_s;");
    query.bindValue(":id_s",id);
    if (query.exec())
    {
        while(query.next())
        {
            QSqlRecord rec = query.record();
            sputnik.id_satellite=id;
            sputnik.name_satellite=query.value(rec.indexOf("NAME_SATELLITE")).toString();
            sputnik.x=query.value(rec.indexOf("ALIGLE_I_X")).toDouble();
            sputnik.y=query.value(rec.indexOf("ALIGLE_I_Y")).toDouble();
            sputnik.id_orbit=query.value(rec.indexOf("ORBIT_ID")).toInt();

        }
          cout<<"[+]"<<endl;
        return sputnik;
    }
    else
    {
        cout<<"[-]"<<endl;
    }
}
///
/// \brief functiondb::get_sputnuk
/// \param name
/// \return
///
satellite functiondb:: get_sputnuk(QString name )//возращает данные о спутнике 2
{
    satellite sputnik;
    QSqlQuery query;
    query.prepare("SELECT  ID_SATELLITE,ALIGLE_I_X ,ALIGLE_I_Y,ORBIT_ID FROM SATELLITE WHERE NAME_SATELLITE=:name_s;");
    query.bindValue("name_s",name);
    if (query.exec())
    {
        while(query.next())
        {
            QSqlRecord rec = query.record();
            sputnik.id_satellite= sputnik.id_orbit=query.value(rec.indexOf("ID_SATELLITE")).toInt();
            sputnik.name_satellite=name;
            sputnik.x=query.value(rec.indexOf("ALIGLE_I_X")).toDouble();
            sputnik.y=query.value(rec.indexOf("ALIGLE_I_Y")).toDouble();
            sputnik.id_orbit=query.value(rec.indexOf("ORBIT_ID")).toInt();

        }
          cout<<"[+]"<<endl;
        return sputnik;
    }
    else
    {
        cout<<"[-]"<<endl;
    }
}


///
/// \brief functiondb::get_orbit
/// \param id
/// \return
///
orbit functiondb::get_orbit(int id) //возращает данные о орбите 1
{
    orbit orbita;
    QSqlQuery query;
    query.prepare("SELECT  NUMBER_ORBIT,HEIGHT_ORBIT, ANGLE_I  FROM ORBIT WHERE ID_ORBIT=:id_orb");
    query.bindValue(":id_orb",id);
    if (query.exec())
    {  while(query.next())
        {
         QSqlRecord rec = query.record();
         orbita.id_orbit=id;
         orbita.number_orbit=query.value(rec.indexOf("NUMBER_ORBIT")).toInt();
         orbita.height_orbit=query.value(rec.indexOf("HEIGHT_ORBIT")).toDouble();
         orbita.angel_i=query.value(rec.indexOf("ANGLE_I")).toDouble();
        }
        cout<<"[+]"<<endl;
        return orbita;
    }
    else
    {
         cout<<"[-]"<<endl;
    }
}
///
/// \brief functiondb::get_orbit
/// \param num
/// \param number
/// \return
///
orbit functiondb::get_orbit(char num,int number)//возращает данные о орбите 2
{
    orbit orbita;
    QSqlQuery query;
    query.prepare("SELECT ID_ORBIT,HEIGHT_ORBIT, ANGLE_I  FROM ORBIT WHERE NUMBER_ORBIT =:num_orbit");
    query.bindValue(":num_orbit",number);
    if (query.exec())
    {  while(query.next())
        {
         QSqlRecord rec = query.record();
         orbita.number_orbit=number;
         orbita.id_orbit=query.value(rec.indexOf("ID_ORBIT")).toInt();
         orbita.height_orbit=query.value(rec.indexOf("HEIGHT_ORBIT")).toDouble();
         orbita.angel_i=query.value(rec.indexOf("ANGLE_I")).toDouble();
        }
        cout<<"[+]"<<endl;
        return orbita;
    }
    else
    {
         cout<<"[-]"<<endl;
    }
}
///
/// \brief functiondb::delete_orbit
/// \param num
///
void functiondb::delete_orbit(int num) // удаляет обиту
{
    QSqlQuery query;
    int id;
    query.prepare("SELECT ID_ORBIT FROM ORBIT where NUMBER_ORBIT=:NUM;"); // айди орбиты
    query.bindValue(":NUM",num);
    if(query.exec())
    {
        QSqlRecord rec = query.record();
        while(query.next())
        {
            id=query.value(rec.indexOf("ID_ORBIT")).toInt();
        }
    }
    query.prepare("UPDATE SATELLITE SET ORBIT_ID='' where ORBIT_ID=:ID;"); // сброс орбиты у спутника
    query.bindValue(":ID",id);
    if(query.exec())
    {
    }
    query.prepare("DELETE FROM DATA_CORRECTION_ORBIT where ORBIT_ID=:ID;"); // удаление данных корректировки
    query.bindValue(":ID",id);
    if(query.exec())
     {
         query.prepare("DELETE FROM ORBIT where ID_ORBIT=:ID;"); // удаление орбиты
         query.bindValue(":ID",id);
         if(query.exec())
         {
            cout<<"[+] Данные об орбите удалены."<< endl;
         }
         else
         {
            cout<<"[-] Сбой.  Данные все о орбите не удалены."<< endl;
         }
     }
     else
     {
        cout<<"[-] Сбой. Данные о орбите не удалены."<< endl;
     }
}
///
/// \brief functiondb::delete_sputnik
/// \param name
///
void functiondb::delete_sputnik(QString name)
{
    QSqlQuery query;
    int id;
    query.prepare("SELECT ID_SATELLITE FROM SATELLITE where NAME_SATELLITE=:name_s;"); // поиск айди спутника
    query.bindValue(":name_s",name);
    if(query.exec())
    {
        QSqlRecord rec = query.record();
        while(query.next())
        {
            id=query.value(rec.indexOf("ID_SATELLITE")).toInt();
        }
    }
    query.prepare("DELETE FROM SATELLITE where NAME_SATELLITE=:name_s;"); // удаление спутника
    query.bindValue(":name_s",name);
     if(query.exec())
     {
         query.prepare("DELETE FROM DATE_CORRECTION_SUN_PANEL where SATELLITE_ID=:set_id;"); // удаление данных корректировки
         query.bindValue(":set_id",id);
         if(query.exec())
         {
            cout<<"[+] Данные о спутнике удалены."<< endl;
         }
         else
         {
            cout<<"[-] Сбой.  Данные о спутнике не удалены."<< endl;
         }
     }
     else
     {
        cout<<"[-] Сбой. Данные о спутнике не удалены."<< endl;
     }
}


///
/// \brief functiondb::read_sputnik
///
void functiondb::read_sputnik()//служебная фукция для отладки
{
    QSqlQuery query;
    if (query.exec("SELECT *FROM SATELLITE ;"))
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
///
/// \brief functiondb::read_orbit
///
void functiondb::read_orbit()//служебная фукция для отладки
{
    QSqlQuery query;
    if (query.exec("SELECT NUMBER_ORBIT FROM ORBIT where NUMBER_ORBIT=1;"))
    {
        cout<<"[+]'ORBIT'"<<endl;
       QSqlRecord rec = query.record();
        float nNumber = 0;
       QString r;
        while(query.next()){
         nNumber = query.value(rec.indexOf("NUMBER_ORBIT")).toFloat();
         cout<<(r.setNum(nNumber)).toStdString()<<endl;

        }

    }
}
