#ifndef TCPSOCKETTHREAD_H
#define TCPSOCKETTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <structur.h>
#include "drain_parametrs_solar_battery.h"

class TcpSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpSocketThread(int ID, drain_parametrs_solar_battery *darin_p);

    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void get();
    void readyRead();
    void disconnected();
    void sendClient(QList<solar_battery_salleter> data);

private:
    QTcpSocket *socket;
    int socketDescriptor;
    quint16 m_nNextBlockSize;
    drain_parametrs_solar_battery *drain_;
};

#endif // TCPSOCKETTHREAD_H
