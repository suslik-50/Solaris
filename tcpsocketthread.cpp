#include "tcpsocketthread.h"
#include <QMetaType>
#include "qprogniz.h"

TcpSocketThread::TcpSocketThread(int ID, main_module *main_constructor, DataConteiner *dc_constructor) :
    m_nNextBlockSize(0)
{
    this->socketDescriptor = ID;

    main = main_constructor;
    dc = dc_constructor;
      qRegisterMetaType<QMap<QString,QList<data_salleter>>>("R");
      connect(main, SIGNAL(data(QMap<QString,QList<data_salleter>>)),this , SLOT(raschet(QMap<QString,QList<data_salleter>>)), Qt::DirectConnection);
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
    byteArr(dc->tabledata, false);
}

void TcpSocketThread::pars(QString com)
{
    command_parser parser_cmd(*main);
    QStringList list;
    list.append(parser_cmd.command(com));
    keyWord = "config";

    qDebug() << list;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);

    out << quint16(0) << keyWord << list;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket->write(arrBlock);
}

void TcpSocketThread::sendSetting()
{
    QStringList list;
    keyWord = "setting";

    list.append(QString::number(main->get_replay_salleter()));
    list.append(QString::number(main->get_replay_sun()));
    list.append(QString::number(main->get_telnet_port()));
    list.append(QString::number(main->get_tcp_port()));

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);

    out << quint16(0) << keyWord << list;

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

void TcpSocketThread::raschet(QMap<QString, QList<data_salleter> > data)
{
    keyWord = "prognoz";
    qProgniz prognoz;

     foreach (QString key, data.keys()) {
           QList<data_salleter> newdata;
           newdata=data.value(key);
           for(int i=0;i<newdata.count();i++)
           {
//               qDebug()<<newdata[i].battary.a<<"a";
//               qDebug()<<newdata[i].battary.b<<"b";
//               qDebug()<<newdata[i].battary.time<<"time";
//               qDebug()<<newdata[i].position.name<<"name";
//               qDebug()<<newdata[i].position.x<<"x";
               prognoz.b_name.append(data[key][i].battary.name);
               prognoz.b_a.append(QString::number(data[key][i].battary.a));
               prognoz.b_b.append(QString::number(data[key][i].battary.b));
               prognoz.b_time.append(QString::number(data[key][i].battary.time));
               prognoz.p_name.append(data[key][i].position.name);
               prognoz.p_time.append(QString::number(data[key][i].position.time));
               prognoz.p_v.append(QString::number(data[key][i].position.V));
               prognoz.p_vx.append(QString::number(data[key][i].position.vx));
               prognoz.p_vy.append(QString::number(data[key][i].position.vy));
               prognoz.p_vz.append(QString::number(data[key][i].position.vz));
               prognoz.p_x.append(QString::number(data[key][i].position.x));
               prognoz.p_y.append(QString::number(data[key][i].position.y));
               prognoz.p_z.append(QString::number(data[key][i].position.z));
           }
     }

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);

    out << quint16(0) << keyWord << prognoz ;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket->write(arrBlock);
}

void TcpSocketThread::proverka()
{
    keyWord = "12";
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << keyWord;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket->write(arrBlock);
}

void TcpSocketThread::byteArr(qTableData list, bool b)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);

    if (b)
    {
        QStringList upName, upTime, upA, upE, upI, upArk_per, upDolgote;

        functiondb f;
        satellite sputnik[100];
        QStringList list1 = f.nameSatellite();
        for (int i = 0; i < f.countSatellite(); ++i)
        {
            sputnik[i] = f.get_satellite_per(list1[i]);
            upName.append(sputnik[i].stl_name);
            upTime.append(QString::number(sputnik[i].stl_time_uts));
            upA.append(QString::number(sputnik[i].stl_a));
            upE.append(QString::number(sputnik[i].stl_e));
            upI.append(QString::number(sputnik[i].stl_i));
            upArk_per.append(QString::number(sputnik[i].stl_ark_per));
            upDolgote.append(QString::number(sputnik[i].stl_dolgota));
        }

        out << quint16(0) << keyWord << list << upName << upTime << upA << upE << upI << upArk_per << upDolgote;
    }
    else
    {
        out << quint16(0) << keyWord << list;
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket->write(arrBlock);
}

