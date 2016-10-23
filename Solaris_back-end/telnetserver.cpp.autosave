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
        qDebug() << "[-] Telnet Server is not started";
    }
    else
    {
        qDebug() << "[+] Telnet Server started";
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
