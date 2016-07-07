#ifndef SETTINGSDB_H
#define SETTINGSDB_H
#include <QString>

class SettingsDB
{
public:
    SettingsDB();
public: void CreatFile();
public: QString ReadPuthDB();
public: void WritePuthDB(QString Puth);
};

#endif // SETTINGSDB_H
