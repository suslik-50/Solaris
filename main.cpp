#include <QCoreApplication>
#include <potoc_sun.h>
#include <drain_position_salleter.h>
#include <QThread>
#include <functiondb.h>
#include <databaseconnect.h>
#include <drain_parametrs_solar_battery.h>
#include <main_module.h>
#include <telnetserver.h>
#include <tcpserver.h>
#include <potoc_salleter2.h>
#include <earth_pos.h>
#include <corners_solar_battery.h>
#include <QObject>
#include <unistd.h>
#include <QDebug>
#include <stdio.h>
#include <clocale>
#include <QMetaType>
#include <structur.h>


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN
#include <windows>
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
#endif

    DateBaseConnect connect;
    connect.DBConnect();
    potoc_sun sun;
    QThread thread1;
    QObject::connect(&thread1,SIGNAL(started()),&sun,SLOT(run()));
    thread1.start();

    drain_parametrs_solar_battery c_s_b;
    c_s_b.start();

    drain_position_salleter position_salleter;
    position_salleter.start();
    DataConteiner dc(&c_s_b);
    main_module main_ma(sun,c_s_b,position_salleter);
    main_ma.start();

    TelnetServer server(&main_ma);
    server.StartServer();

    TcpServer servertcp(&main_ma, &dc);
    servertcp.StartServer();


#ifdef Q_OS_OSX

    //         if (getppid() != 1 && daemon(0, 0) == -1) {
    //         }
    //         #else
    //         if (daemon(0, 0) == -1) {
    //         }


#endif



#ifdef Q_OS_LINUX

    pid_t parpid, sid;

    parpid = fork(); //создаем дочерний процесс
    if(parpid < 0) {
        exit(1);
    } else if(parpid != 0) {
        exit(0);
    }
    umask(0);//даем права на работу с фс
    sid = setsid();//генерируем уникальный индекс процесса
    if(sid < 0) {
        exit(1);
    }
    if((chdir("/")) < 0) {//выходим в корень фс
        exit(1);
    }
#endif

    return a.exec();

}
