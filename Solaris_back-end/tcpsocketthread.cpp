#include "tcpsocketthread.h"
#include <QTimer>

TcpSocketThread::TcpSocketThread(int ID, drain_parametrs_solar_battery *darin_p) :
    QThread(darin_p), m_nNextBlockSize(0)
{
    this->socketDescriptor = ID;
    drain_ = darin_p;
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
            this, SLOT(sendClient(QMap<QString,solar_battery_salleter>)));

    qDebug() << socketDescriptor << " Client connected";

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(get()));
    timer->start(1000*10);

    // make this thread a loop
    exec();
}

void TcpSocketThread::get()
{
   drain_->get_data();
}

void TcpSocketThread::sendClient(QMap<QString, solar_battery_salleter> data_sbs)
{

    QStringList list;
    foreach (QString key, data_sbs.keys())
    {
        QDateTime date;
        QString time;
        date.setTime_t(data_sbs[key].time);
        time = date.toString("yy/MM/dd:hh:mm:ss");
        qDebug() << data_sbs[key].a;
        list.append(data_sbs[key].name + "," + QString::number(data_sbs[key].a) + "," +
                    QString::number(data_sbs[key].b) + "," + time);
    }
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << list;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
    list.clear();
}

void TcpSocketThread::readyRead()
{
    QString massage, id;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;)
    {
        if (!m_nNextBlockSize) { // ???????? ?? ?????? ???????
            if (socket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        if (socket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        in >> id >> massage;
        m_nNextBlockSize = 0;
    }
}


void TcpSocketThread::disconnected()
 {
     qDebug() << socketDescriptor << " Disconnected";

     socket->deleteLater();
     exit(0);
}


