#include "telnetserver.h"


void TelnetServer::parser()
{

}

TelnetServer::TelnetServer(main_module *man_m)
{
    main=man_m;
}

void TelnetServer::StartServer()
{
    port=file_setting.Get_telnet_port();
    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "[-] Server is't started";
    }
    else
    {
        qDebug() << "[+] Server is start";
    }
}

TelnetServer::~TelnetServer()
{
    this->close();
}

void TelnetServer::incomingConnection(qintptr socketDescriptor)
{
    TelnetSocketThread* thread =   new TelnetSocketThread((int)socketDescriptor, this,main);
    connect(thread, &TelnetSocketThread::finished, thread, &TelnetSocketThread::deleteLater);
    thread->start();
}
