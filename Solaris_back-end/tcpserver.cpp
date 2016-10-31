#include "tcpserver.h"
#include <QTimer>


TcpServer::TcpServer(drain_parametrs_solar_battery *darin_p, main_module *man_m)
{
    drain = darin_p;
    main = man_m;
}

void TcpServer::StartServer()
{
    port=file_setting.Get_tcp_port();
    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "[-] Tcp Server is not started";
    }
    else
    {
        qDebug() << "[+] Tcp Server started";
    }
}

void TcpServer::get()
{
   drain->get_data();
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    TcpSocketThread *userconnect = new TcpSocketThread(socketDescriptor, drain, main);
    userconnect->start();
    connect(userconnect, SIGNAL(finished()), userconnect, SLOT(deleteLater()));
    userconnect->start();

}

