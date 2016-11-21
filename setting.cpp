#include "setting.h"
#include <QFile>

QSettings setting_o ("setting.ini",QSettings::IniFormat);
setting::setting()
{ // проверяет если файл настроек, если нету создает
    QFile FileConnectDB;
    FileConnectDB.setFileName("setting.ini");
    if (!FileConnectDB.exists())
    {
        CreatFile();
    }
}
// создает файл настроек
void setting::CreatFile()// Функция создания файла с стандартными полями и указания значений по умолчанию
{
    setting_o.setValue("ConnectDB/Puth","DatаBase.db");
    setting_o.setValue("ConnectDB/UserName","");
    setting_o.setValue("ConnectDB/HostName","");
    setting_o.setValue("ConnectDB/Password","");
    setting_o.setValue("potoc_salleter/qdebug","false");
    setting_o.setValue("potoc_salleter/replay","3");
    setting_o.setValue("potoc_sun/qdebug","false");
    setting_o.setValue("potoc_sun/replay","5");
    setting_o.setValue("corners_solar_battery/qdebug","flase");
    setting_o.setValue("telnet/port","8085");
    setting_o.setValue("tcp/port","1234");
    setting_o.setValue("main_modul/qdebug","false");
}

bool setting::Get_qdebug_sun()
{
    bool y_n=setting_o.value("potoc_sun/qdebug","false").toBool();
    return y_n;
}

void setting::Set_qdebug_sun(bool y_n)
{
    setting_o.setValue("potoc_sun/qdebug",y_n);
}

double setting::Get_replay_sun()
{
    double replay=setting_o.value("potoc_sun/replay","5").toDouble();
    return replay;
}

void setting::Set_replay_sun(double replay)
{
    setting_o.setValue("potoc_sun/replay",replay);
}

bool setting::Get_qdebug_salleter()
{
    bool y_n=setting_o.value("potoc_salleter/qdebug","false").toBool();
    return y_n;
}

void setting::Set_qdebug_salleter(bool y_n)
{
    setting_o.setValue("potoc_salleter/qdebug",y_n);
}

int setting::Get_replay_salleter()
{
    int replay=setting_o.value("potoc_salleter/replay","3").toInt();
    return replay;
}

void setting::Set_replay_salleter(int replay)
{
    setting_o.setValue("potoc_salleter/replay",replay);
}

bool setting::Get_corners_solar_batter_qdebug()
{
    bool y_n=setting_o.value("corners_solar_battery/qdebug","false").toBool();
    return y_n;
}

void setting::Set_corners_solar_battery_qdebug(bool y_n)
{
    setting_o.setValue("corners_solar_battery/qdebug",y_n);
}

void setting::CreateFile_DB() // Функция создания файла с стандартными полями и указания значений по умолчанию
{
    CreatFile();
}

QString setting::ReadPuthDB() // Функция возращения путя файла базы данных
{
    QString Puth = setting_o.value("ConnectDB/Puth","DataBase.db").toString();
    return Puth;
}

void setting::WritePuthDB(QString Puth) // Функция записи путя файла
{
    setting_o.setValue("ConnectDB/Puth",Puth);
}

void setting::Set_telnet_port(int port)
{
    setting_o.setValue("telnet/port",port);
}

int setting::Get_telnet_port()
{
    int port = setting_o.value("telnet/port","8085").toInt();
    return port;
}

void setting::Set_tcp_port(int port)
{
    setting_o.setValue("tcp/port",port);
}

int setting::Get_tcp_port()
{
    int port = setting_o.value("tcp/port","8085").toInt();
    return port;
}

bool setting::Get_qdebug_main_modul()
{
    bool y_n=setting_o.value("main_modul/qdebug","false").toBool();
    return y_n;
}

void setting::Set_qdebug_main_modul(bool y_n)
{
    setting_o.setValue("main_modul/qdebug",y_n);
}









