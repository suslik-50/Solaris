#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "tcpsocketthread.h"
#include "main_module.h"
#include "setting.h"
#include "dataconteiner.h"
#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(main_module *man_constructor, DataConteiner *dc_constructor);

    void StartServer();
signals:

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

private:
    main_module *main;
    setting file_setting;
    drain_parametrs_solar_battery *drain;
    DataConteiner* dc;

    int port;
};

#endif // TCPSERVER_H
