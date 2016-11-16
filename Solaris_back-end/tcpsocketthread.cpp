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
    byteArr(dc->list, false);
}

void TcpSocketThread::pars(QString com)
{
    QStringList shortList = com.split(' ');
    if (shortList.first()=="prognoz"){
        //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
        //пример команды
        //prognoz pos_salleter_all 123456 678910
        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==3){
                int timeT0;//'timeT0=123456
                int time_end; //time_end=678910
                if(shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        prognoz_salleter *prognoz =new  prognoz_salleter(timeT0,time_end);
                        QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                        prognoz->start();
                    }
                    else{
                        //time_end не double
                        QByteArray otvet;
                        otvet="time_end не double";
                        keyWord = "config";
                        //byteArr(otvet, true);
                        return;
                    }
                }
                else{
                    //timeT0 не double
                    QByteArray otvet;
                    otvet="time_T0 не double";
                    keyWord = "config";
                    //  byteArr(otvet, true);
                    return;
                }
            }
        }



        //расчет всех местоположения спутников от начального времни timeT0 , до конечного time_end шаг задается step
        //пример команды
        //prognoz pos_salleter_all 123456 678910 3
        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==4){
                int timeT0; //timeT0=123456
                int time_end; //time_end=678910
                int step; //step=3
                if(shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        if (shortList[4].toInt()){
                            step=shortList[4].toInt();
                            prognoz_salleter *prognoz=new  prognoz_salleter(timeT0,time_end,step);
                            QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                            prognoz->start();
                            return;
                        }
                        else{
                            //step int ошибка
                            return;
                        }
                    }
                    else{
                        //time_end ошибка
                        return;
                    }
                }
                else{
                    //timeT0 ошибка
                    return;
                }
            }
        }


        //расчет всех местоположения спутников на время time
        //прмер команды
        //prognoz pos_salleter_all 123456

        if (shortList[1]=="pos_salleter_all"){
            if (shortList.count()==2){
                if (shortList[2].toInt()){
                    int time; // time=123456
                    time=shortList[2].toInt();
                    prognoz_salleter *prognoz=new  prognoz_salleter(time);
                    QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                    prognoz->start();
                    return;
                }
                else{
                    //time ошибка
                    return;
                }
            }
        }



        //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг по умолчанию 1 секунда
        // пример команды
        // prognoz pos_salleter 12345 678910 salleter1
        if (shortList[1]=="pos_salleter"){
            int timeT0; //timeT0=12345
            int time_end; //time_end=678910
            QString name; //name=salleter1;
            if (shortList.count()==4){
                if (shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        // проверка на существование спутника вбд
                        name=shortList[4];
                        prognoz_salleter *prognoz=new  prognoz_salleter(timeT0,time_end,name);
                        QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                        prognoz->start();
                        return;
                    }
                    else{
                        //time_end ошибка
                        return;
                    }
                }
                else{
                    //time ошибка
                    return;
                }
            }
        }


        //расчет местоположения спутника от начального времни timeT0 , до конечного time_end шаг задается step
        // пример команды
        // prognoz pos_salleter 12345 678910  1 salleter2
        if (shortList[1]=="pos_salleter")
        {
            if (shortList.count()==5){
                int timeT0; //timeT0=12345
                int time_end; //time_end=678910
                QString name; //name=salleter2;
                int step; //step=1;
                if (shortList[2].toInt()){
                    timeT0=shortList[2].toInt();
                    if (shortList[3].toInt()){
                        time_end=shortList[3].toInt();
                        if (shortList[4].toInt()){
                            step=shortList[4].toInt();
                            name=shortList[5];
                            prognoz_salleter *prognoz=new  prognoz_salleter(timeT0,time_end,name,step);
                            QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                            prognoz->start();
                            return;
                        }
                        else{
                            //step ошибка
                            return;
                        }
                    }
                    else{
                        // time_end ошибка
                        return;
                    }
                }
                else{
                    //timeT0 ошибка
                    return;
                }
            }
        }



        //расчет местоположения спутника на время time
        // пример команды
        // prognoz pos_salleter 12345 salleter2
        if (shortList[1]=="pos_salleter")
        {
            if (shortList.count()==3){
                int time;
                QString name;
                if (shortList[2].toInt()){
                    time=shortList[2].toInt();
                    //проверка на существование спутиника
                    name=shortList[3];
                    prognoz_salleter *prognoz=new  prognoz_salleter(time,name);
                    QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                    prognoz->start();
                    return;
                }
                else{
                    //time ошибка
                    return;
                }
            }
        }

        //расчет для нескольких спутнкиков имена спутников задаются в QList<QString>
        //пример команды
        //prognoz grup_pos_salleter 12345 678910 1 sputnik1 sputnik2 sputnik3
        //или prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
        //или prognoz grup_pos_salleter 12345 sputnik1 sputnik2 sputnik3
        if (shortList[1]=="grup_pos_salleter")
        {
            if (shortList.count()>=4){
                int  timeT0; //timeT0=12345
                int  time_end; //time_end=678910
                int  step;
                QList<QString> namesalleter;//<-sputnik1 sputnik2 sputnik3
                // prognoz grup_pos_salleter 12345 678910 1 sputnik1 sputnik2 sputnik3
                if (shortList[2].toInt() && shortList[3].toInt() &&shortList[4].toInt()){
                    timeT0=shortList[2].toInt();
                    time_end=shortList[3].toInt();
                    step=shortList[4].toInt();
                    //перед добавление в QList спутников проверять на существование таких  в бд
                    for(int i=5;i<shortList.count();i++){
                        namesalleter.append(shortList[i]);
                    }
                    prognoz_salleter *prognoz=new  prognoz_salleter(timeT0,time_end,step,namesalleter);
                    QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                    prognoz->start();
                    return;
                }else
                {
                    // prognoz grup_pos_salleter 12345 678910 sputnik1 sputnik2 sputnik3
                    if (shortList[2].toInt() && shortList[3].toInt())
                    {
                        timeT0=shortList[2].toInt();
                        time_end=shortList[3].toInt();
                        for(int i=4;i<shortList.count();i++){
                            namesalleter.append(shortList[i]);
                        }
                        prognoz_salleter *prognoz=new  prognoz_salleter(timeT0,time_end,namesalleter);
                        QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                        prognoz->start();
                        return;
                    }
                    else
                    {
                        // prognoz grup_pos_salleter 12345 sputnik1 sputnik2 sputnik3
                        if (shortList[2].toInt())
                        {
                            timeT0=shortList[2].toInt();
                            for(int i=3;i<shortList.count();i++){
                                namesalleter.append(shortList[i]);
                            }
                            //перед добавление в QList спутников проверять на существование таких  в бд
                            QList<QString> namesalleter;//<-sputnik1 sputnik2 sputnik3
                            prognoz_salleter *prognoz = new  prognoz_salleter(timeT0,namesalleter);
                            QObject::connect(prognoz,SIGNAL(data(QMap<QString,QList<data_salleter> >)),this,SLOT(raschet(QMap<QString,QList<data_salleter> >)));
                            prognoz->start();
                            return;
                        }
                    }
                }
            }
        }
    }

    command_parser parser_cmd(*main);
    QStringList list;
    list.append(parser_cmd.command(com));
    keyWord = "config";

    byteArr(list, true);
}

void TcpSocketThread::sendSetting()
{
    QStringList list;
    keyWord = "setting";

    list.append(QString::number(main->get_replay_salleter()));
    list.append(QString::number(main->get_replay_sun()));
    list.append(QString::number(main->get_telnet_port()));
    list.append(QString::number(main->get_tcp_port()));

    byteArr(list, true);
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
        qDebug() << massage;
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

void TcpSocketThread::byteArr(QStringList list, bool b)
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

