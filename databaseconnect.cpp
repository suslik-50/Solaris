/*Версия 0.0.2 от 07-07-2016
 *  Объект создания подключения к базе данных
 *  Нуриев Руслан Равилевич
 *  Email-suslik-50@yandex.ru
 */
#include "databaseconnect.h"

using namespace std ;

QSqlDatabase DateBaseConnect::DBConnect()
{

    QString puthdb; // переменная в которой храниться путь к файлу
    QSqlDatabase Datebase=QSqlDatabase::addDatabase("QSQLITE"); // объект для подключения к бд
    QFile FileConnectDB; // пременная для проверки на существование файла настроек подключения к бд
    QFile FileDateBase; // перменная для проверки существования файла базы данных
    setting FileDb; // объект для чтения настроек
    FileConnectDB.setFileName("setting.ini");// указание файла для провеки
    if (!FileConnectDB.exists()) // проверка на существование файла
    {
        qDebug()<<"[-] Нет файла настроек для подключения к Базе данных"<<endl; //  вывод в консоль
        qDebug()<<"[!] Файл будит создан автоматически"<<endl; //
        qDebug()<<"[!] В файле вписаны настройки по умолчанию"<<endl;
        FileDb.CreateFile_DB();//вызов функции для автоматичекого создания файла с настройками
        qDebug()<<"[?] Изменить стандартный путь к базе данных '"<<FileDb.ReadPuthDB()<<"' Да/Нет(Y/N)"<<endl;
        string otvet; //  переменная для ответа
        cin>>otvet; // ввод ответа
        if (otvet=="y"||otvet=="Y") // определение ответа
        {
            qDebug()<<"[!] Путь файла Базаы дынных '"<<FileDb.ReadPuthDB()<<"' "<<endl;
            qDebug()<<"[!] Введите новый путь к файлу базы данных"<<endl;
            string newputh;
            cin>>newputh; // внесениение в переменню нового путя
            QString NewPuth =QString::fromStdString(newputh); // Переменная для записи путя
            FileDb.WritePuthDB(NewPuth); // функция записи нового путя заданного пользователем в файл
            qDebug()<<"[!] Новый путь к файлу бд'"<<FileDb.ReadPuthDB()<<"'"<<endl;
        }
    }
    FileDateBase.setFileName(FileDb.ReadPuthDB()); // укзание путя для провеки существования файла базы данных
    if (!FileDateBase.exists()) // проверка на существование файла бд
    {
        qDebug()<<"[-]Нет фала базы данных по указанному пути '"<<FileDb.ReadPuthDB()<<"'"<<endl;
        qDebug()<<"[?]Создать базу данных(пустую) Да/Нет(Y/N)"<<endl;
        string otvet; //  переменная для ответа
        cin>>otvet; // ввод ответа
        if (otvet=="y"||otvet=="Y") // определение ответа
        {
            puthdb = FileDb.ReadPuthDB();// чтение путя к файлу базы данных
            Datebase.setDatabaseName(puthdb);//установление путя к файлу бд для подключения
            Datebase.open(); // открытие базы данных
            functiondb Fdb; // создание объекта для работы с бд
            Fdb.creat_db(); // вызов функции создания бд
            return Datebase;
        }
    }
    else
    {
        puthdb = FileDb.ReadPuthDB();// чтение путя к файлу базы данных
        Datebase.setDatabaseName(puthdb);//установление путя к файлу бд для подключения
        if (Datebase.open()) // открытие подключения к базе данных
        {
            qDebug()<<"[+]Соединение с базой данных установлено"<<endl;
            return Datebase; //возращает открытое соединение
        }
        else {
            qDebug()<<"[-]Нет соединения с базой данных"<<endl;
            qDebug()<<"[!]Проверте настройки подключения к базе данных в файле 'SettinDB.ini' "<<endl;
        }
    }
    return  Datebase;
}


