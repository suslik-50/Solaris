/*Версия 0.0.1 от 07-07-16
 * Модуль для работы с настройками подключения к бд
 * Нуриев Руслан
 * suslik-50@yandex.ru
 */
#include "settingsdb.h"
#include <QString>
#include <QSettings>

SettingsDB::SettingsDB()
{


}

void SettingsDB::CreatFile() // Функция создания файла с стандартными полями и указания значений по умолчанию
{
    QSettings setting ("SettinDB.ini",QSettings::IniFormat);
    setting.setValue("ConnectDB/Puth","DateBase.db");
    setting.setValue("ConnectDB/UserName","");
    setting.setValue("Connect/HostName","");
    setting.setValue("Connect/Password","");
}

QString SettingsDB::ReadPuthDB() // Функция возращения путя файла базы данных
{
    QString Puth;
    QSettings setting ("SettinDB.ini",QSettings::IniFormat);
    Puth = setting.value("ConnectDB/PuthDB","DateBase.db").toString();
    return Puth;
}

void SettingsDB::WritePuthDB(QString Puth) // Функция записи путя файла
{
      QSettings setting ("SettinDB.ini",QSettings::IniFormat);
        setting.setValue("ConnectDB/PuthDB",Puth);
}


