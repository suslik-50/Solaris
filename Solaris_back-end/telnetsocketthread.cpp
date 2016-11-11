#include "telnetsocketthread.h"
#include <QStringList>
#include <structur.h>
#include <command_parser.h>


void TelnetSocketThread::parser(QString command)
{
    command_parser parser_cmd(*main);
    /// если булева переменная true возращаем с кодировкой 1251
    /// если false то как обычно
    if (win==true){
        QTextCodec *codec = QTextCodec::codecForName("IBM 866");
        QByteArray encodedString = codec->fromUnicode(parser_cmd.command(command));
        socket->write(encodedString);
    }else{
        socket->write(parser_cmd.command(command));
    }

}

TelnetSocketThread::TelnetSocketThread(int ID, QObject *parent, main_module *main_m)
{
    this->socketDescriptor = ID;
    main=main_m;
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
    setAccess(false);
    exec();
}

bool TelnetSocketThread::access() const
{
    return m_access;
}

void TelnetSocketThread::readyRead()
{


    QByteArray data = socket->readAll();
    QString str(data);
    ///если четыре последних символа не "\r\n" то это windows ставим bool переменную win=true
    ///eсли четыре последних символа не "\r\n" то это unix ставим bool переменную win=false
    /// и обрабатываем как обычно

    if (first)
    {
        if (str.right(2) == "\r\n")
        {
            win=false;
            qDebug()<<"Winfalse";
        }
        else
        {
            win=true;
            qDebug()<<"Wintrue";
        }
        first = false;
    }
    if (win==true){
        if (str != "\r\n")
        {
            command += str;
            return;
        }

        if (command == "exit")
        {
            socket->deleteLater();
            command = "";
            exit(0);
        }

        if (str == "\r\n")
        {
            parser(command);
            command = "";
        }


    }else
    {
        int leng = str.length();
        str = str.left(leng-2);
        if (str!="")
        {
            qDebug()<<"Command";
            parser(str);
        }

        if (str == "exit")
        {
            socket->deleteLater();
            str = "";
            exit(0);
        }
        str = "";
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


