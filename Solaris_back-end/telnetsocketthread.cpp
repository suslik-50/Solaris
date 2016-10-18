#include "telnetsocketthread.h"
#include <QStringList>
#include <structur.h>
#include <command_parser.h>


void TelnetSocketThread::parser(QString command)
{
    command_parser parser_cmd(*main);
    socket->write(parser_cmd.command(command));

}

TelnetSocketThread::TelnetSocketThread(int ID, QObject *parent, main_module *main_m)
{
    this->socketDescriptor = ID;
    main=main_m;  
    connect(main,SIGNAL(messageslots(QString)),this,SLOT(Message_slot(QString)));
}

void TelnetSocketThread::run()
{
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);


    QByteArray data("Введите команду \r\n");
    socket->write(data);
    Message_slot("Все команды help");
    setAccess(false);
    exec();
}

bool TelnetSocketThread::access() const
{
    return m_access;
}

void TelnetSocketThread::Message_slot(QString message)
{
    qDebug()<<message;
    QByteArray ba;
    ba+=(message+"\r\n");
    socket->write(ba);
    ba.clear();
}

void TelnetSocketThread::readyRead()
{

    QByteArray data = socket->readAll();
    QString str(data);
    int leng = str.length();
    str = str.left(leng-2);
    if (str!="")
    {
        parser(str);
    }

    if (str == "exit")
    {
        socket->deleteLater();
        exit(0);
    }


}
void TelnetSocketThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}

void TelnetSocketThread::setAccess(bool access)
{
    if (m_access == access)
        return;
    m_access = access;
    emit accessChanged(access);
}


