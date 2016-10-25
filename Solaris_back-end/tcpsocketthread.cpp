#include "tcpsocketthread.h"
#include <command_parser.h>

TcpSocketThread::TcpSocketThread(int ID, drain_parametrs_solar_battery *darin_p, main_module *main_m) :
     m_nNextBlockSize(0)
{
    this->socketDescriptor = ID;
    drain_ = darin_p;
    main=main_m;

}


void TcpSocketThread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);
    connect(drain_, SIGNAL(data_solar_battery(QMap<QString,solar_battery_salleter>)),
            this, SLOT(sendClient(QMap<QString,solar_battery_salleter>)),Qt::DirectConnection);
    connect(this, SIGNAL(getDatadreain()), drain_, SLOT(get_data()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(get()),Qt::DirectConnection);
        timer->start(1000);

    exec();
}

void TcpSocketThread::get()
{
   emit getDatadreain();
}

void TcpSocketThread::sendClient(QMap<QString,solar_battery_salleter> data_sbs)
{
    QString str("tabel");
    QStringList list;
    foreach (QString key, data_sbs.keys())
    {
        QDateTime date;
        QString time;
        date.setTime_t(data_sbs[key].time);
        time = date.toString("yy/MM/dd:hh:mm:ss");
        qDebug() << data_sbs[key].a;
        list.append(data_sbs[key].name + "," + QString::number(data_sbs[key].a) + "," +
                    QString::number(data_sbs[key].b) + "," + time + ",");
    }

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << str << list;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);

    list.clear();
}

void TcpSocketThread::pars(QString com)
{
    QByteArray  arr;
    command_parser parser_cmd(*main);
    arr = parser_cmd.command(com);
    QString str(arr);
    QStringList list;
    list.append(com);
    str = "config";

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << str << list;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
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

    qDebug() << massage;
    pars(massage);


}


void TcpSocketThread::disconnected()
 {
     qDebug() << socketDescriptor << " Disconnected";

     socket->deleteLater();
     exit(0);
}


