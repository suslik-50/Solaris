#ifndef TCPSOCKETTHREAD_H
#define TCPSOCKETTHREAD_H

#include "main_module.h"
#include "dataconteiner.h"
#include "command_parser.h"
#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <prognoz_salleter.h>
#include <structur.h>
#include <QMap>
class TcpSocketThread : public QThread
{
    Q_OBJECT
public:
    TcpSocketThread(int ID, main_module *main_constructor, DataConteiner* dc_constructor);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);
    void getDatadreain();

private slots:
    void sendTabelData();
    void readyRead();
    void disconnected();
    void raschet(QMap<QString, QList<data_salleter>>  data);

private:
    QTcpSocket *socket;
    int socketDescriptor;
    QString keyWord;
    quint16 m_nNextBlockSize;
    DataConteiner* dc;
    main_module *main;

    void byteArr(QStringList list, bool b);
    void pars(QString com);
    void sendSetting();
};

#endif // TCPSOCKETTHREAD_H
