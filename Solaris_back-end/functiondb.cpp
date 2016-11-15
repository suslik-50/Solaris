/*Версия 0.0.3 от 11-07-2016
 *  Фунции для работы с базой данных
 *  Нуриев Руслан Равилевич
 *  Email-suslik-50@yandex.ru
 *
 */
#include "functiondb.h"

using namespace std ;

QSqlDatabase Datebase;

functiondb::functiondb()
{

}

void functiondb::creat_db()  // функция создания базы данных
{
    QSqlQuery query;

    //Создание таблицы "СПУТНИК"
    QString sss="CREATE TABLE SATELLITE ("
                "ID_SATELLITE INTEGER PRIMARY KEY AUTOINCREMENT"
                "                     NOT NULL,"
                "STL_NAME     STRING (100), "
                "STL_TIME_UTS DOUBLE,"
                "STL_A        DOUBLE,"
                "STL_E        DOUBLE,"
                "STL_I        DOUBLE,"
                "STL_ARK_PER  DOUBLE,"
                "STL_DOLGOTA  DOUBLE,"
                "STL_M        DOUBLE"
                ");";

    //Создание таблицы "КОРРЕКТИРОВКА СПУТНИКА"
    QString scs="CREATE TABLE CORRECT_SATELLITE ("
                "ID_CORRECT_SATELLITE INTEGER       PRIMARY KEY AUTOINCREMENT"
                "                                   NOT NULL,"
                "SATELLITE_ID         INTEGER       REFERENCES SATELLITE (ID_SATELLITE),"
                "C_TIME_UTS           DOUBLE,"
                "C_A                  DOUBLE,"
                "C_E                  DOUBLE,"
                "C_I                  DOUBLE,"
                "C_ARK_PER            DOUBLE,"
                "C_DOLGOTA            DOUBLE,"
                "C_M                  DOUBLE,"
                "EDITOR               STRING [30]"
                ");";

        if (query.exec(sss))
        {
            qDebug()<<"[+] Cозданна таблица 'СПУТНИК'"<<endl;
            if(query.exec(scs))
            {
                qDebug()<<"[+] Cозданна таблица 'КОРРЕКТИРОВКА СПУТНИКА'"<<endl;
            }
            else
            {
                qDebug()<<"[-] Не cозданна таблица корректировка 'СПУТНИК'"<<endl;
            }
        }
        else
        {
            qDebug()<<"[-] Не cозданна таблица 'СПУТНИК'"<<endl;
        }



}



bool functiondb::inset_to_satellite(QString name, double time_uts, double a,
                                    double e, double i, double ark_per,
                                    double dolgota)
{
    QSqlQuery query;
    query.prepare("SELECT STL_NAME FROM SATELLITE WHERE STL_NAME=:name;"); // Поиск одинаковой записи
    query.bindValue(":name",name);
    QString NAME;
    if (query.exec())
    {
           QSqlRecord rec;
        query.next();
        try{
         rec = query.record();
        }
        catch(...){

        }

        NAME = query.value(rec.indexOf("STL_NAME")).toString();
    }
    if (NAME!=name)
    {
        query.prepare("INSERT INTO SATELLITE (STL_NAME, STL_TIME_UTS, "
                      "STL_A, STL_E, STL_I, STL_ARK_PER, "
                      "STL_DOLGOTA, STL_M) VALUES (:STL_NAME, "
                      ":STL_TIME_UTS, :STL_A, "
                      ":STL_E, :STL_I, :STL_ARK_PER, "
                      ":STL_DOLGOTA, :STL_M)");
        query.bindValue(":STL_NAME",name);
        query.bindValue(":STL_TIME_UTS",time_uts);
        query.bindValue(":STL_A",a);
        query.bindValue(":STL_E",e);
        query.bindValue(":STL_I",i);
        query.bindValue(":STL_ARK_PER",ark_per);
        query.bindValue(":STL_DOLGOTA",dolgota);
      //  query.bindValue(":STL_M",m);
        if (query.exec())
        {
            int id;
            if (query.exec("SELECT MAX(ID_SATELLITE), ID_SATELLITE FROM SATELLITE;")) //Нахождение айди последней созданной записи
            {
                while(query.next())
                {
                    QSqlRecord rec = query.record();
                    id=query.value(rec.indexOf("ID_SATELLITE")).toInt();
                }
                insert_to_correct_satellite(id, time_uts,a, e, i, ark_per, dolgota, "Человек");
            }
            qDebug()<<"[+] Данные добавлены в таблицу 'СПУТНИК'"<<endl;
            return true;
        }
        else
        {
            qDebug()<<"[-] Данные не добавлены в таблицу 'СПУТНИК'"<<endl;
            return false;
        }
    }
    else
    {
        qDebug()<<"[!] Занято"<<endl;
        return false;
    }
    return false;
}

void functiondb::update_to_satellite(QString name, double time_uts, double a,
                                     double e, double i, double ark_per,
                                     double dolgota, QString editor)
{
    QSqlQuery query;
    query.prepare("SELECT ID_SATELLITE, STL_NAME, "
                  "STL_TIME_UTS, STL_A, STL_E, STL_I, STL_ARK_PER, STL_DOLGOTA, STL_M FROM SATELLITE "
                  "WHERE STL_NAME=:STL_NAME;");
    query.bindValue(":STL_NAME",name);
    int id;
    if(query.exec())
    {
        QSqlRecord rec = query.record();
        while(query.next())
        {
            id=query.value(rec.indexOf("ID_SATELLITE")).toInt();
        }
        if (insert_to_correct_satellite(id, time_uts, a, e ,i, ark_per, dolgota, editor))
        {
            QSqlQuery query2;
            query2.prepare("UPDATE SATELLITE SET STL_NAME=:STL_NAME, "
                           "STL_TIME_UTS=:STL_TIME_UTS, STL_A=:STL_A, STL_E=:STL_E,"
                           "STL_I=:STL_I, STL_ARK_PER=:STL_ARK_PER, STL_DOLGOTA=:STL_DOLGOTA,"
                           "WHERE STL_NAME =:STL_NAME;");

            query2.bindValue(":STL_NAME",name);
            query2.bindValue(":STL_TIME_UTS",time_uts);
            query2.bindValue(":STL_A",a);
            query2.bindValue(":STL_E",e);
            query2.bindValue(":STL_I",i);
            query2.bindValue(":STL_ARK_PER",ark_per);
            query2.bindValue(":STL_DOLGOTA",dolgota);

            if(query2.exec())
            {
                qDebug()<<"[+] Данные в таблице  'спутник' обновлены"<<endl;
            }
            else
            {
                qDebug()<<"[-] Данные в таблице  'спутник' не обновлены"<<endl;
            }
        }
        else
        {
            qDebug()<<"[-] Данные не добавлены в таблицу 'КОРРЕКТИРОВКА СПУТНИКА'";
        }
    }
    else
    {
        qDebug()<<"[-] Ошибка"<<endl;
    }
}




bool functiondb::insert_to_correct_satellite(int satellite_id, double time_uts, double a,
                                             double e, double i, double ark_per,
                                             double dolgota, QString editor)
{
    QSqlQuery query;
    query.prepare("INSERT INTO CORRECT_SATELLITE (SATELLITE_ID, C_TIME_UTS, "
                  "C_A, C_E, C_I, C_ARK_PER, "
                  "C_DOLGOTA, EDITOR) VALUES (:SATELLITE_ID, :C_TIME_UTS, "
                  ":C_A, :C_E, :C_I, :C_ARK_PER, "
                  ":C_DOLGOTA, :EDITOR)");

    query.bindValue(":SATELLITE_ID",satellite_id);
    query.bindValue(":C_TIME_UTS",time_uts);
    query.bindValue(":C_A",a);
    query.bindValue(":C_E",e);
    query.bindValue(":C_I",i);
    query.bindValue(":C_ARK_PER",ark_per);
    query.bindValue(":C_DOLGOTA",dolgota);
    //query.bindValue(":C_M",m);
    query.bindValue(":EDITOR",editor);

    if (query.exec())
    {
        qDebug()<<"[+] Данные добавлены в таблицу "<<endl;
        return true;
    }
    else
    {
        qDebug()<<"[-] Данные не добавлены в таблицу "<<endl;
        return false;
    }
}

satellite functiondb::get_satellite(int id) // Возращает данные о спутнике 1
{
    satellite sputnik;
    QSqlQuery query;
    query.prepare("SELECT ID_SATELLITE, STL_NAME, STL_TIME_UTS, "
                  "STL_A, STL_E, STL_I, STL_ARK_PER, STL_DOLGOTA FROM SATELLITE"
                  " WHERE ID_SATELLITE=:ID_SATELLITE;");
    query.bindValue(":ID_SATELLITE",id);
    if (query.exec())
    {
        while(query.next())
        {
            QSqlRecord rec = query.record();
            sputnik.id_satellite=id;
            sputnik.stl_name=query.value(rec.indexOf("STL_NAME")).toString();
            sputnik.stl_time_uts=query.value(rec.indexOf("STL_TIME_UTS")).toDouble();
            sputnik.stl_a=query.value(rec.indexOf("STL_A")).toDouble();
            sputnik.stl_e=query.value(rec.indexOf("STL_E")).toDouble();
            sputnik.stl_i=query.value(rec.indexOf("STL_I")).toDouble();
            sputnik.stl_ark_per=query.value(rec.indexOf("STL_ARK_PER")).toDouble();
            sputnik.stl_dolgota=query.value(rec.indexOf("STL_DOLGOTA")).toDouble();
            //sputnik.stl_m=query.value(rec.indexOf("STL_M")).toDouble();
        }
        /*
        qDebug() << "Айди спуника:     " << sputnik.id_satellite << endl;
        qDebug() << "Имя спутника:     " << sputnik.stl_name.toStdString() << endl;
        qDebug() << "X:                " << sputnik.stl_x << endl;
        qDebug() << "Y:                " << sputnik.stl_y << endl;
        qDebug() << "Z:                " << sputnik.stl_z << endl;
        qDebug() << "VX:               " << sputnik.stl_ << endl;
        qDebug() << "VY:               " << sputnik.stl_vy << endl;
        qDebug() << "VZ:               " << sputnik.stl_vz << endl;
        qDebug() << "Время:            " << sputnik.stl_time_uts<< endl;
        qDebug() << "Большая полуось:  " << sputnik.stl_a << endl;
        qDebug() << "Экцентрисистент:  " << sputnik.stl_e << endl;
        qDebug() << "Наклое:           " << sputnik.stl_i << endl;
        qDebug() << "Аргумент перегея: " << sputnik.stl_ark_per << endl;
        qDebug() << "Долгота:          " << sputnik.stl_dolgota << endl;
        qDebug() << "Средняя аномалия: " << sputnik.stl_m << endl;
*/
        return sputnik;
    }
    else
    {
        qDebug()<<"[-]"<<endl;
        return sputnik;
    }
}

satellite functiondb::get_satellite(QString name ) // Возращает данные о спутнике 2
{
    satellite sputnik;
    QSqlQuery query;
    query.prepare("SELECT * FROM SATELLITE WHERE STL_NAME=:name_s;");
    query.bindValue(":name_s",name);
    if (query.exec())
    {
        QSqlRecord  rec = query.record();
        int id;
        while(query.next())
        {
            id = query.value(rec.indexOf("ID_SATELLITE")).toInt();
            sputnik.id_satellite=query.value(rec.indexOf("ID_SATELLITE")).toInt();
            sputnik.stl_name=name;
            sputnik.stl_time_uts=query.value(rec.indexOf("STL_TIME_UTS")).toDouble();
            sputnik.stl_a=query.value(rec.indexOf("STL_A")).toDouble();
            sputnik.stl_e=query.value(rec.indexOf("STL_E")).toDouble();
            sputnik.stl_i=query.value(rec.indexOf("STL_I")).toDouble();
            sputnik.stl_ark_per=query.value(rec.indexOf("STL_ARK_PER")).toDouble();
            sputnik.stl_dolgota=query.value(rec.indexOf("STL_DOLGOTA")).toDouble();
            //sputnik.stl_m=query.value(rec.indexOf("STL_M")).toDouble();
        }
        return sputnik;
    }
    else
    {
        qDebug()<<"[-]"<<endl;
        return sputnik;
    }
}

int functiondb::count_record_satellite()
{
    QSqlQuery query;
    if (!query.exec("SELECT COUNT(DISTINCT STL_NAME) FROM SATELLITE"))
    {
        qDebug() << "[-] Запрос не прошел" << endl;
    }
    else
    {
        query.next();
        qDebug() << "[!] Количество спутников = " << query.value(0).toInt() << endl;
    }

    int count;
    count=query.value(0).toInt();
    return count;
}


void functiondb::delete_satellite(QString name) // Удаление данных 'СПУТНИК'
{
    QSqlQuery query;
    int id;
    query.prepare("SELECT ID_SATELLITE FROM SATELLITE where STL_NAME=:name_s;"); // поиск айди спутника
    query.bindValue(":name_s",name);
    if(query.exec())
    {
        QSqlRecord rec = query.record();
        while(query.next())
        {
            id=query.value(rec.indexOf("ID_SATELLITE")).toInt();
        }
    }
    query.prepare("DELETE FROM SATELLITE where STL_NAME=:name_s;"); // удаление спутника
    query.bindValue(":name_s",name);
    if(query.exec())
    {
        qDebug()<<"[+] Cпутник удалены."<< endl;
        query.prepare("DELETE FROM CORRECT_SATELLITE where SATELLITE_ID=:set_id;"); // удаление данных корректировки
        query.bindValue(":set_id",id);
        if(query.exec())
        {
            qDebug()<<"[+] Данные о спутнике удалены."<< endl;
        }
        else
        {
            qDebug()<<"[-] Сбой.  Данные о спутнике не удалены."<< endl;
        }
    }
    else
    {
        qDebug()<<"[-] Сбой. Данные о спутнике не удалены."<< endl;
    }
}

void functiondb::read_satellite() //служебная фукция для отладки
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM SATELLITE WHERE STL_NAME='R-S-1'"))
    {
        QSqlRecord rec = query.record();
        QString Name;
        int id = 0;
        while(query.next())
        {
            id = query.value(rec.indexOf("ID_SATELLITE")).toInt();
            QString r;
            Name = query.value(rec.indexOf("STL_NAME")).toString();
            qDebug()<<Name<<"-"<<r.setNum(id)<<endl;
        }
    }
}

QList<int> functiondb::get_list_id_satellite()
{
    QSqlQuery query;
    QList<int>* arr = new QList<int>;
    if (!query.exec("SELECT ID_SATELLITE FROM SATELLITE;"))
    {
        qDebug() << "Запрос не прошел";
    }
    else
    {
        QSqlRecord rec = query.record();
        int id = 0;
        while(query.next())
        {
            id = query.value(rec.indexOf("ID_SATELLITE")).toInt();
            arr->append(id);
        }
    }
    return *arr;
}



