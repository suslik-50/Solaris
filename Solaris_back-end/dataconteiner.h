#ifndef DATACONTEINER_H
#define DATACONTEINER_H

#include <QObject>
#include "drain_parametrs_solar_battery.h"
#include <QDebug>

class DataConteiner : public QObject
{
    Q_OBJECT
public:
    explicit DataConteiner(drain_parametrs_solar_battery *darin_container);
    QStringList list;
signals:
    void getDatadreain();
public slots:
    void getData(QMap<QString, solar_battery_salleter> data_sbs);
    void slot();

private:
    drain_parametrs_solar_battery *drain;
};

#endif // DATACONTEINER_H
