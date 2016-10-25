#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include "tcpsocketthread.h"
#include "main_module.h"
#include "drain_parametrs_solar_battery.h"
#include <setting.h>

class TcpServer : public QTcpServer
{
    Q_OBJECT
    main_module *main;
public:TcpServer(drain_parametrs_solar_battery *darin_p, main_module *man_m);
private:setting file_setting;
private:int port;
public:void StartServer();
signals:

public slots:
    void get();
protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
   drain_parametrs_solar_battery *drain;

};

#endif // TCPSERVER_H
