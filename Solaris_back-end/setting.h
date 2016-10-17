#ifndef SETTING_H
#define SETTING_H

#include <QString>
#include <QSettings>

class setting
{
public:
    setting();
public:void CreatFile();
public:bool Get_qdebug_sun();
public:void Set_qdebug_sun(bool y_n);
public:double Get_replay_sun();
public:void Set_replay_sun(double replay);
public:bool Get_qdebug_salleter();
public:void Set_qdebug_salleter(bool y_n);
public:int Get_touch_salleter();
public:void Set_touch_salleter(int touch);
public:int Get_replay_salleter();
public:void Set_replay_salleter(int replay);
public:bool Get_corners_solar_batter_qdebug();
public:void Set_corners_solar_battery_qdebug(bool y_n);
public:void CreateFile_DB();
public:QString ReadPuthDB();
public:void WritePuthDB(QString Puth);
public:void Set_telnet_port(int port);
public:int Get_telnet_port();
public:bool Get_qdebug_main_modul();
public:void Set_qdebug_main_modul(bool y_n);
};

#endif // SETTING_H
