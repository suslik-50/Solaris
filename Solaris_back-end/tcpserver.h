#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include "tcpsocketthread.h"
#include "main_module.h"
#include "drain_parametrs_solar_battery.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:TcpServer(drain_parametrs_solar_battery *darin_p);

    void StartServer();
signals:

public slots:
    void get();
protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
   drain_parametrs_solar_battery *drain;

};

#endif // TCPSERVER_H
