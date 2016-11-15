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
    QStringList shortList = com.split(' ');
    if (shortList.first()=="prognoz"){

    /*
    //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
    //пример команды
    //prognoz pos_salleter_all 123456 678910
    if (""==""){
    double timeT0; timeT0=123456
    double time_end; time_end=678910
    prognoz_salleter *prognoz =new  prognoz_salleter(timeT0,time_end);
    }
    */

    //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг задается step
    //пример команды
    //prognoz pos_salleter_all 123456 678910 3
    /*
    if (""==""){
    double timeT0; timeT0=123456
    double time_end; time_end=678910
    int step; step=3
    prognoz_salleter prognoz(timeT0,time_end,step);
    }
    */

    //расчет всех местоположения спутников на время time
    //прмер команды
    //prognoz pos_salleter_all 123456
    /*
     if (""==""){
     ouble time; time=123456
     prognoz_salleter prognoz(time);
     }
    */

    /*//расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
      // пример команды
      // prognoz pos_salleter 12345 678910 salleter1
      if (""==""){
      double timeT0; timeT0=12345
      double time_end; time_end=678910
      QString name; name=salleter1;
      prognoz_salleter prognoz(timeT0,time_end,name);
      }
     * /


     /*
      //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг задается step
      // пример команды
      // prognoz pos_salleter 12345 678910 salleter2 1
    if (""=="")
    {
      double timeT0; timeT0=12345
      double time_end; time_end=678910
      QString name; name=salleter2;
      int step; step=1;
      prognoz_salleter prognoz(timeT0,time_end,name,step);
    }
    */

    /*
    //расчет местоположения спутника на время time
    // пример команды
    // prognoz pos_salleter 12345 salleter2
    if (""=="")
    {
      double time; time=12345
      QString name; name=salleter2;
      prognoz_salleter prognoz(time,name);
    }
    */

    /*
     //расчет для нескольких спутнкиков имена спутников задаются в QList<QString>
     //пример команды
     //prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
      if (""=="")
      {
      double timeT0; timeT0=12345
      double time_end; time_end=678910
      //перед добавление в QList спутников проверять на существование таких  в бд или дописать такую проверку в бд
      QList<QString> namesalleter;<-sputnik1 sputnik2 sputnik3
       prognoz_salleter prognoz(timeT0,time_end,namesalleter);
      }
     */

    /*
      //расчет местоположения группы спутников от начального времни timeT0 , до конечного time_end шаг задается step
      //пример команды
      //prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
      if (""=="")
      {
      double timeT0; timeT0=12345
      double time_end; time_end=678910
      int step;
      //перед добавление в QList спутников проверять на существование таких  в бд
      QList<QString> namesalleter;<-sputnik1 sputnik2 sputnik3
      prognoz_salleter prognoz(timeT0,time_end,step,namesalleter);
      }
     * /



     /*
     ////расчет местоположения группы спутников на время time
     //пример команды
     //prognoz grup_pos_salleter 12345  sputnik1 sputnik2 sputnik3
     if(""==""){
     double time; time=1245
     //перед добавление в QList спутников проверять на существование таких  в бд
     QList<QString> namesalleter;<-sputnik1 sputnik2 sputnik3
     prognoz_salleter prognoz(time,namesalleter);
     }
     */

   // потом раскоментировать
   // QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
   // prognoz.start();

    }

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

void TcpSocketThread::raschet(QMap<QString, QList<data_salleter> > data)
{
   //какимто раком разобрать и отправить в seket
   // socket->write(data);
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


