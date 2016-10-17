#include "tcpserver.h"
#include <QTimer>


TcpServer::TcpServer(drain_parametrs_solar_battery *darin_p)
{
    drain = darin_p;
}

void TcpServer::StartServer()
{
    if(!this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "[-] Could not start server";
    }
    else
    {
        qDebug() << "[+] Listening...";
    }
}

void TcpServer::get()
{
   drain->get_data();
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    TcpSocketThread *thread = new TcpSocketThread(socketDescriptor, drain);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

