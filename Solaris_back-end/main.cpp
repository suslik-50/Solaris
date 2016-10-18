#include <QCoreApplication>
#include <potoc_sun.h>
#include <QThread>
#include <functiondb.h>
#include <databaseconnect.h>
#include <drain_parametrs_solar_battery.h>
#include <main_module.h>
#include <telnetserver.h>
#include <potoc_salleter2.h>
#include <earth_pos.h>
#include <corners_solar_battery.h>
#include <QObject>
#include <unistd.h>
#include <QDebug>
#include <stdio.h>
#include <tcpserver.h>

int main(int argc, char *argv[])
{

#ifdef Q_OS_OSX

//         if (getppid() != 1 && daemon(1, 0) == -1) {
//          qDebug()<<"-+";
//         }
//         #else
//         if (daemon(1, 0) == -1) {
//         qDebug()<<"++";
//         }


#endif

//#ifdef Q_OS_LINUX

//    pid_t parpid, sid;

//    parpid = fork(); //создаем дочерний процесс
//    if(parpid < 0) {
//        exit(1);
//    } else if(parpid != 0) {
//        exit(0);
//    }
//    umask(0);//даем права на работу с фс
//    sid = setsid();//генерируем уникальный индекс процесса
//    if(sid < 0) {
//        exit(1);
//    }
//    if((chdir("/")) < 0) {//выходим в корень фс
//        exit(1);
//    }
//#endif

    QCoreApplication a(argc, argv);
    DateBaseConnect connect;
    connect.DBConnect();
    potoc_sun s;
    QThread thread1;
    QObject::connect(&thread1,SIGNAL(started()),&s,SLOT(run()));
    thread1.start();


    drain_parametrs_solar_battery c_s_b;
    c_s_b.start();
    main_module main_ma(s,c_s_b);
    main_ma.start();


    TelnetServer server(&main_ma);
    server.StartServer();

    TcpServer tcp(&c_s_b);
    tcp.StartServer();

    c_s_b.get_data();
    return a.exec();

}
