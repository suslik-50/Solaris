/*Версия 0.0.1 от 6-07-2016
 *  Модуль создания подключения к базе данных
 *  Нуриев Руслан Равилевич
 *  Email-suslik-50@yandex.ru
 */
#include "datebaseconnect.h"
#include "QSql"
#include <iostream>
#include<qfile.h>
#include <xml.h>
using namespace std ;

QSqlDatabase DateBaseConnect::DBConnect()
{
    QString puthdb; // переменная в которой храниться путь к файлу
    QSqlDatabase Datebase=QSqlDatabase::addDatabase("QSQLITE"); // объект для подключения к бд
    QFile FileConnectDB; // пременная для проверки на существование файла настроек подключения к бд
    Xml FileDb; // объект необходимый для работы с Xml (xml.cpp)
    FileConnectDB.setFileName("ConnectDB.xml");// указание файла для провеки
    if (!FileConnectDB.exists()) // проверка на существование файла
    {
        cout<<"[-] Нет файла настроек для подключения к Базе данных"<<endl; //  вывод в консоль
        cout<<"[!] Файл будит создан автоматически"<<endl; //
        cout<<"[!] В файле вписаны настройки по умолчанию"<<endl;
        FileDb.XmlCreatFile();//вызов функции для автоматичекого создания файла с настройками
        cout<<"[!] Изменить стандартный путь к базе данных '"<<(FileDb.XmlReadPutFile()).toStdString()<<"' Да/Нет(y/n)"<<endl;
        string otvet; //  переменная для ответа
        cin>>otvet; // ввод ответа
        if (otvet=="y"||otvet=="Y") // определение ответа
        {
         cout<<"[!] Путь файла Базаы дынных"<<(FileDb.XmlReadPutFile()).toStdString()<<endl;
         cout<<"[!] Введите новый путь к файлу базы данных"<<endl;
        string newputh;
         cin>>newputh; // внесениение в переменню нового путя
         QString NewPuth =QString::fromStdString(newputh); // Переменная для записи путя
         FileDb.XmlWritePutFile(NewPuth); // функция записи нового путя заданного пользователем в файл
         cout<<"[!] Новый путь к файлу бд'"<<(FileDb.XmlReadPutFile()).toStdString()<<"'"<<endl;
        }

    }
    puthdb = FileDb.XmlReadPutFile();// чтение путя к файлу базы данных из xml
    Datebase.setDatabaseName(puthdb);//установление путя к файлу бд для подключения
    if (Datebase.open()) // открытие подключения к базе данных
    {
        cout<<"[+]Соединение с базой данных установлено"<<endl;
        return Datebase; //возращает открытое соединение
    }
    else {
        cout<<"[-]Нет соединения с базой данных"<<endl;
        cout<<"[!]Проверте настройки подключения к базе данных в файле 'ConnectDB.xml' "<<endl;
    }
}
