#include "dataconteiner.h"
#include <QTimer>

DataConteiner::DataConteiner(drain_parametrs_solar_battery *darin_container)
{
    drain = darin_container;
    connect(drain, SIGNAL(data_solar_battery(QMap<QString,solar_battery_salleter>)),
            this, SLOT(getData(QMap<QString,solar_battery_salleter>)));

    connect(this, SIGNAL(getDatadreain()), drain, SLOT(get_data()));
    connect(drain, SIGNAL(new_data()), drain, SLOT(get_data()));
}


void DataConteiner::getData(QMap<QString,solar_battery_salleter> data_sbs)
{
    list.clear();
    foreach (QString key, data_sbs.keys())
    {
        QDateTime date;
        QString time;
        date.setTime_t(data_sbs[key].time);
        time = date.toString("MM.dd.yy hh:mm:ss");
        list.append(data_sbs[key].name + "," + QString::number(data_sbs[key].a) + "," +
                    QString::number(data_sbs[key].b) + "," + time +",");
    }

}

void DataConteiner::slot()
{
    emit getDatadreain();
}
