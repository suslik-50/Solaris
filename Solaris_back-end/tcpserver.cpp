#include "tcpserver.h"
#include <QTimer>


TcpServer::TcpServer(main_module *man_constructor, DataConteiner *dc_constructor)
{
    main = man_constructor;
    dc = dc_constructor;
}

void TcpServer::StartServer()
{
    port = file_setting.Get_tcp_port();

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "[-] Tcp Server is not started";
    }
    else
    {
        qDebug() << "[+] Tcp Server started";
    }
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    TcpSocketThread *userconnect = new TcpSocketThread(socketDescriptor, main, dc);
    connect(userconnect, SIGNAL(finished()), userconnect, SLOT(deleteLater()));
    userconnect->start();
}

