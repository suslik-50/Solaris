#include <QCoreApplication>
#include <potoc_sun.h>
#include <QThread>
#include <functiondb.h>
#include <databaseconnect.h>
#include <drain_parametrs_solar_battery.h>
#include <main_module.h>
#include <telnetserver.h>
#include <potoc_salleter.h>
#include <earth_pos.h>
#include <tcpserver.h>
//
#include <unistd.h>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //daemon(0, 0);
    int pid;
    //создаем потомка
    pid = fork();

    if (pid == -1) // если не удалось запустить потомка
    {
        // выведем на экран ошибку и её описание
        qDebug()<<"Start Daemon Error: %s\n", strerror(errno);
        return -1;
    }


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

    TcpServer tcp(&c_s_b);
    tcp.StartServer();

    //c_s_b.get_data();
    return a.exec();
}
