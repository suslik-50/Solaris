#ifndef TELNETSERVER_H
#define TELNETSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <telnetsocketthread.h>
#include <main_module.h>
#include <setting.h>

class TelnetServer : public QTcpServer
{
    Q_OBJECT
    main_module *main;
private:setting file_setting;
private:int port;
private:void parser();
public: TelnetServer(main_module *man_m);
    void StartServer();
    ~TelnetServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
};

#endif // TELNETSERVER_H
