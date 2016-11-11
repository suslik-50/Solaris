#include "tcpsocketthread.h"

TcpSocketThread::TcpSocketThread(int ID, main_module *main_constructor, DataConteiner *dc_constructor) :
     m_nNextBlockSize(0)
{
    this->socketDescriptor = ID;

    main = main_constructor;
    dc = dc_constructor;
}


void TcpSocketThread::run()
{
    qDebug() << socketDescriptor << " Starting thread";

    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    QTimer *timer = new QTimer(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendTabelData()), Qt::DirectConnection);
    timer->start(1000);

    sendSetting();

    exec();
}

void TcpSocketThread::sendTabelData()
{
    keyWord = "tabel";
    byteArr(dc->list);
}

void TcpSocketThread::pars(QString com)
{
    command_parser parser_cmd(*main);
    QStringList list;
    list.append(parser_cmd.command(com));
    keyWord = "config";
    byteArr(list);
}

void TcpSocketThread::sendSetting()
{
    QStringList list;
    keyWord = "setting";

    list.append(QString::number(main->get_replay_salleter()));
    list.append(QString::number(main->get_replay_sun()));
    list.append(QString::number(main->get_telnet_port()));
    list.append(QString::number(main->get_tcp_port()));

    byteArr(list);
}

void TcpSocketThread::readyRead()
{
    QString massage;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;)
    {
        if (!m_nNextBlockSize) {
            if (socket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        if (socket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        in >> massage;
        m_nNextBlockSize = 0;
    }
    pars(massage);
}


void TcpSocketThread::disconnected()
 {
     qDebug() << socketDescriptor << " Disconnected";

     socket->deleteLater();
     exit(0);
}

void TcpSocketThread::byteArr(QStringList list)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << keyWord << list;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
}


