#ifndef TCPSOCKETTHREAD_H
#define TCPSOCKETTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <structur.h>
#include "drain_parametrs_solar_battery.h"
#include <main_module.h>
#include <QTimer>
#include <QMap>

class TcpSocketThread : public QThread
{
    Q_OBJECT
    main_module *main;
    QTimer* timer;
   QMap<QString,solar_battery_salleter> olddata;
public:
    explicit TcpSocketThread(int ID, drain_parametrs_solar_battery *darin_p, main_module *main_m);

    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
    void getDatadreain();

public slots:
    void get();
    void readyRead();
    void disconnected();
    void sendClient(QMap<QString,solar_battery_salleter> data_sbs);

private:
    QTcpSocket *socket;
    int socketDescriptor;
    quint16 m_nNextBlockSize;
    drain_parametrs_solar_battery *drain_;
    void pars(QString com);
    void sendSettingClent();
};

#endif // TCPSOCKETTHREAD_H
