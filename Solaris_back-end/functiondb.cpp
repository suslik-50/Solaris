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

    // Создание таблицы "СОЛНЦЕ"
    QString sct="CREATE TABLE SUN ("
                "ID_SUN       INTEGER PRIMARY KEY AUTOINCREMENT"
                "                     NOT NULL,"
                "SUN_X        DOUBLE,"
                "SUN_Y        DOUBLE,"
                "SUN_Z        DOUBLE,"
                "SUN_TIME_UTS DOUBLE"
                ");";

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
    QString sca=
            "CREATE TABLE AUTHORIZATION ("
            "ID_AUTHORIZATION INTEGER     PRIMARY KEY AUTOINCREMENT"
            "                              NOT NULL,"
            "LOGIN            STRING (30),"
            "PASSWORD         STRING (30),"
            "SOLL_PASSWORD    VARCHAR"
            ");";

    if (query.exec(sct))
    {
        cout<<"[+] Cозданна таблица 'СОЛНЦЕ'"<<endl;
        if (query.exec(sss))
        {
            cout<<"[+] Cозданна таблица 'СПУТНИК'"<<endl;
            if(query.exec(scs))
            {
                cout<<"[+] Cозданна таблица 'КОРРЕКТИРОВКА СПУТНИКА'"<<endl;
                if (query.exec(sca))
                {
                    cout<<"[+] Cозданна таблица 'АВТОРИЗАЦИЯ'"<<endl;
                }
                else
                {
                    cout<<"[-] Не созданна таблица 'АВТОРИЗАЦИЯ'"<<endl;
                }
            }
            else
            {
                cout<<"[-] Не cозданна таблица корректировка 'СПУТНИК'"<<endl;
            }
        }
        else
        {
            cout<<"[-] Не cозданна таблица 'СПУТНИК'"<<endl;
        }
    }
    else
    {
        cout<<"[-] Не созданна таблица 'СОЛНЦЕ'"<<endl;
    }

}

bool functiondb::insert_to_sun(double x, double y,
                               double z, double time_uts) // Функция добавления данных в таблицу СОЛНЦЕ
{
    QSqlQuery query;
    query.prepare("INSERT INTO SUN (SUN_X, SUN_Y, SUN_Z, SUN_TIME_UTS) "
                  "VALUES(:SUN_X, :SUN_Y, :SUN_Z, :SUN_TIME_UTS)");
    query.bindValue(":SUN_X",x);
    query.bindValue(":SUN_Y",y);
    query.bindValue(":SUN_Z",z);
    query.bindValue(":SUN_TIME_UTS",time_uts);
    if (query.exec())
    {
        cout<<"[+] Данные добавлены в таблицу солнца"<<endl;
    }
    else
    {
        cout<<"[-] Данные не добавлены в таблицу солнца"<<endl;
    }
}

bool functiondb::inset_to_satellite(QString name, double time_uts, double a,
                                    double e, double i, double ark_per,
                                    double dolgota, double m)
{
    QSqlQuery query;
    query.prepare("SELECT STL_NAME FROM SATELLITE WHERE STL_NAME=:name;"); // Поиск одинаковой записи
    query.bindValue(":name",name);
    QString NAME;
    if (query.exec())
    {
        query.next();
        QSqlRecord rec = query.record();
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
        query.bindValue(":STL_M",m);
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
                insert_to_correct_satellite(id, time_uts, // Добавление данных в корректировку данных
                                            a, e, i, ark_per, dolgota, m, "Человек");
            }
            cout<<"[+] Данные добавлены в таблицу 'СПУТНИК'"<<endl;
            return true;
        }
        else
        {
            cout<<"[-] Данные не добавлены в таблицу 'СПУТНИК'"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"[!] Занято"<<endl;
        return false;
    }
    return false;
}

void functiondb::update_to_satellite(QString name, double time_uts, double a,
                                     double e, double i, double ark_per,
                                     double dolgota, double m, QString editor)
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
        if (insert_to_correct_satellite(id, time_uts, a, e ,i, ark_per, dolgota, m, editor))
        {
            QSqlQuery query2;
            query2.prepare("UPDATE SATELLITE SET STL_NAME=:STL_NAME, "
                           "STL_TIME_UTS=:STL_TIME_UTS, STL_A=:STL_A, STL_E=:STL_E,"
                           "STL_I=:STL_I, STL_ARK_PER=:STL_ARK_PER, STL_DOLGOTA=:STL_DOLGOTA,"
                           "STL_M=:STL_M WHERE STL_NAME =:STL_NAME;");

            query2.bindValue(":STL_NAME",name);
            query2.bindValue(":STL_TIME_UTS",time_uts);
            query2.bindValue(":STL_A",a);
            query2.bindValue(":STL_E",e);
            query2.bindValue(":STL_I",i);
            query2.bindValue(":STL_ARK_PER",ark_per);
            query2.bindValue(":STL_DOLGOTA",dolgota);
            query2.bindValue(":STL_M",m);
            if(query2.exec())
            {
                cout<<"[+] Данные в таблице  'спутник' обновлены"<<endl;
            }
            else
            {
                cout<<"[-] Данные в таблице  'спутник' не обновлены"<<endl;
            }
        }
        else
        {
            cout<<"[-] Данные не добавлены в таблицу 'КОРРЕКТИРОВКА СПУТНИКА'";
        }
    }
    else
    {
        cout<<"[-] Ошибка"<<endl;
    }
}


void functiondb::update_to_sun(double x, double y, double z, double time_uts) // Функция изменения данных таблицы 'СОЛНЦЕ'
{

    QSqlQuery query2;
    query2.prepare("UPDATE SUN SET SUN_X=:SUN_X, SUN_Y=:SUN_Y, SUN_Z=:SUN_Z, SUN_TIME_UTS=:SUN_TIME_UTS"
                   " WHERE SUN_TIME_UTS=:SUN_TIME_UTS;");
    query2.bindValue(":SUN_X", x);
    query2.bindValue(":SUN_Y", y);
    query2.bindValue(":SUN_Z", z);
    query2.bindValue(":SUN_TIME_UTS", time_uts);
    if (query2.exec())
    {
        cout<<"[+] Обновление данных солнца прошло успешно"<<endl;
    }
    else
    {
        cout<<"[-] Обновление данных солнца не удалость"<<endl;
    }
}

bool functiondb::insert_to_correct_satellite(int satellite_id, double time_uts, double a,
                                             double e, double i, double ark_per,
                                             double dolgota, double m, QString editor)
{
    QSqlQuery query;
    query.prepare("INSERT INTO CORRECT_SATELLITE (SATELLITE_ID, C_TIME_UTS, "
                  "C_A, C_E, C_I, C_ARK_PER, "
                  "C_DOLGOTA, C_M, EDITOR) VALUES (:SATELLITE_ID, :C_TIME_UTS, "
                  ":C_A, :C_E, :C_I, :C_ARK_PER, "
                  ":C_DOLGOTA, :C_M, :EDITOR)");

    query.bindValue(":SATELLITE_ID",satellite_id);
    query.bindValue(":C_TIME_UTS",time_uts);
    query.bindValue(":C_A",a);
    query.bindValue(":C_E",e);
    query.bindValue(":C_I",i);
    query.bindValue(":C_ARK_PER",ark_per);
    query.bindValue(":C_DOLGOTA",dolgota);
    query.bindValue(":C_M",m);
    query.bindValue(":EDITOR",editor);

    if (query.exec())
    {
        cout<<"[+] Данные добавлены в таблицу "<<endl;
        return true;
    }
    else
    {
        cout<<"[-] Данные не добавлены в таблицу "<<endl;
        return false;
    }
}

satellite functiondb::get_satellite(int id) // Возращает данные о спутнике 1
{
    satellite sputnik;
    QSqlQuery query;
    query.prepare("SELECT ID_SATELLITE, STL_NAME, STL_TIME_UTS, "
                  "STL_A, STL_E, STL_I, STL_ARK_PER, STL_DOLGOTA, STL_M FROM SATELLITE"
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
            sputnik.stl_m=query.value(rec.indexOf("STL_M")).toDouble();
        }
        /*
        cout << "Айди спуника:     " << sputnik.id_satellite << endl;
        cout << "Имя спутника:     " << sputnik.stl_name.toStdString() << endl;
        cout << "X:                " << sputnik.stl_x << endl;
        cout << "Y:                " << sputnik.stl_y << endl;
        cout << "Z:                " << sputnik.stl_z << endl;
        cout << "VX:               " << sputnik.stl_ << endl;
        cout << "VY:               " << sputnik.stl_vy << endl;
        cout << "VZ:               " << sputnik.stl_vz << endl;
        cout << "Время:            " << sputnik.stl_time_uts<< endl;
        cout << "Большая полуось:  " << sputnik.stl_a << endl;
        cout << "Экцентрисистент:  " << sputnik.stl_e << endl;
        cout << "Наклое:           " << sputnik.stl_i << endl;
        cout << "Аргумент перегея: " << sputnik.stl_ark_per << endl;
        cout << "Долгота:          " << sputnik.stl_dolgota << endl;
        cout << "Средняя аномалия: " << sputnik.stl_m << endl;
*/
        return sputnik;
    }
    else
    {
        cout<<"[-]"<<endl;
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
            sputnik.stl_m=query.value(rec.indexOf("STL_M")).toDouble();
        }
        return sputnik;

    }
    else
    {
        cout<<"[-]"<<endl;
        return sputnik;
    }
}

int functiondb::count_record_satellite()
{
    QSqlQuery query;
    if (!query.exec("SELECT COUNT(DISTINCT STL_NAME) FROM SATELLITE"))
    {
        cout << "[-] Запрос не прошел" << endl;
    }
    else
    {
        query.next();
        cout << "[!] Количество спутников = " << query.value(0).toInt() << endl;
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
        cout<<"[+] Cпутник удалены."<< endl;
        query.prepare("DELETE FROM CORRECT_SATELLITE where SATELLITE_ID=:set_id;"); // удаление данных корректировки
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
            cout<<Name.toStdString()<<"-"<<(r.setNum(id)).toStdString()<<endl;
        }
    }
}

QList<int> functiondb::get_list_id_satellite()
{
    QSqlQuery query;
    QList<int>* arr = new QList<int>;
    if (!query.exec("SELECT ID_SATELLITE FROM SATELLITE;"))
    {
        cout << "Запрос не прошел";
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



