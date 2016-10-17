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
    connect(drain_, SIGNAL(data_solar_battery(QList<solar_battery_salleter>)),
            this, SLOT(sendClient(QList<solar_battery_salleter>)));

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

void TcpSocketThread::sendClient(QList<solar_battery_salleter> data)
{

    QStringList list;
    for (int i = 0; i < data.length(); ++i) {
        list.append(data[i].name+ "," + QString::number(data[i].a)+ ","+
                    QString::number(data[i].b)+ "," + QString::number(data[i].time));
    }

    //list.append(QString::number(2)+ "," + QString::number(22)+ ","+ QString::number(222)+ "," + QString::number(2222));


    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << list;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
    qDebug()<< "Ok";
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
        //sendClient(str);
        m_nNextBlockSize = 0;
    }
}


void TcpSocketThread::disconnected()
 {
     qDebug() << socketDescriptor << " Disconnected";

     socket->deleteLater();
     exit(0);
}


